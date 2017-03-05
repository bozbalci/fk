/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "printexpr.h"

void
PrintExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::LLVMContext &context = M->getContext();
    llvm::Type *PutCharArgs[] = 
    {
        llvm::Type::getInt32Ty(context),
        llvm::Type::getInt32PtrTy(context)
    };

    llvm::FunctionType *PutCharTy = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        PutCharArgs,
        false // not a vararg function
    );

    llvm::Function *PutCharF = llvm::cast<llvm::Function>
        (M->getOrInsertFunction("b_putchar", PutCharTy));

    llvm::Value *Args[] = 
    {
        B.CreateLoad(FkExprGlobals::instance()->get_index_ptr()),
        B.CreatePointerCast(
            FkExprGlobals::instance()->get_cells_ptr(),
            llvm::Type::getInt32Ty(context)->getPointerTo()
        )
    };

    llvm::ArrayRef<llvm::Value *> ArgsArr(Args);
    B.CreateCall(PutCharF, ArgsArr);
}

void
PrintExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "PrintExpr" << std::endl;
}
