/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "readexpr.h"

void
ReadExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::LLVMContext &context = M->getContext();
    llvm::Type *GetCharArgs[] = 
    {
        llvm::Type::getInt32Ty(context),
        llvm::Type::getInt32PtrTy(context)
    };

    llvm::FunctionType *GetCharTy = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        GetCharArgs,
        false // not a vararg function
    );

    llvm::Function *GetCharF = llvm::cast<llvm::Function>
        (M->getOrInsertFunction("b_getchar", GetCharTy));

    llvm::Value *Args[] = 
    {
        B.CreateLoad(FkExprGlobals::instance()->get_index_ptr()),
        B.CreatePointerCast(
            FkExprGlobals::instance()->get_cells_ptr(),
            llvm::Type::getInt32Ty(context)->getPointerTo()
        )
    };

    llvm::ArrayRef<llvm::Value *> ArgsArr(Args);
    B.CreateCall(GetCharF, ArgsArr);
}

void
ReadExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "ReadExpr" << std::endl;
}
