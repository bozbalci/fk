/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "parser/parser.h"

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>

#include <iostream>
#include <fstream>
#include <sstream>

int
main(int argc, char *argv[])
{
    // TODO: Make this more beautiful.
    // begin hack --------------------
    if (argc < 2)
    {
        std::cout << "usage: fk [filename]" << std::endl;
        return 1;
    }
    std::string filename(argv[1]);
    std::ifstream t(filename);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string program_data = buffer.str();
    // end hack --------------------

    FkParser parser(program_data);

    llvm::LLVMContext llvm_context;
    std::string module_name = "testmodule";

    llvm::ErrorOr<llvm::Module *> module_or_err
        = new llvm::Module(module_name, llvm_context);
    
    auto owner = std::unique_ptr<llvm::Module>(module_or_err.get());
    auto *module = owner.get();

    auto *MainF = llvm::cast<llvm::Function>(
        module->getOrInsertFunction(
             "main",
             llvm::Type::getInt32Ty(llvm_context),
             (llvm::Type *) 0
        )
    );

    llvm::BasicBlock *entry_block = llvm::BasicBlock::Create(
        llvm_context,
        "EntryBlock", // convention
        MainF
    );

    llvm::IRBuilder<> builder(entry_block);
    builder.SetInsertPoint(entry_block);
    parser.generate_code(module, builder);
    builder.CreateRet(builder.getInt32(0));

    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    std::string error_string;

    llvm::EngineBuilder *EB = new llvm::EngineBuilder(std::move(owner));
    llvm::ExecutionEngine *EE = EB->setErrorStr(&error_string)
        .setMCJITMemoryManager(std::unique_ptr<llvm::SectionMemoryManager>
                (new llvm::SectionMemoryManager())).create();

    if (!error_string.empty())
    {
        std::cerr << error_string << std::endl;
        exit(1);
    }

    EE->finalizeObject();
    std::vector<llvm::GenericValue> Args(0);
    llvm::GenericValue gv = EE->runFunction(MainF, Args);

    delete EE;
    llvm::llvm_shutdown();

    return 0;
}
