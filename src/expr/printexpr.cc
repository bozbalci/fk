/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "printexpr.h"

void
PrintExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::LLVMContext &context = M->getContext();

    llvm::Value *Args[] = {
        B.CreateLoad(
            B.CreateGEP(
                B.CreatePointerCast(
                    FkExprGlobals::instance()->get_cells_ptr(),
                    llvm::Type::getInt32Ty(context)->getPointerTo()
                ),
                B.CreateLoad(
                    FkExprGlobals::instance()->get_index_ptr()
                )
            )
        )
    };

    llvm::ArrayRef<llvm::Value *> ArgsArr(Args);

    B.CreateCall(
        FkExprGlobals::instance()->get_putchar_func(),
        ArgsArr
    );
}

void
PrintExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "PrintExpr" << std::endl;
}
