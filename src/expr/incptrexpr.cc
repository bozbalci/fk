/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "incptrexpr.h"

void
IncrementPtrExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::Value *IdxV = B.CreateLoad(
        FkExprGlobals::instance()->get_index_ptr()
    );

    B.CreateStore(
        B.CreateAdd(
            IdxV,
            B.getInt32(_increment)
        ),
        FkExprGlobals::instance()->get_index_ptr()
    );
}

void
IncrementPtrExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "IncrementPtrExpr (" << _increment << ")" << std::endl;
}
