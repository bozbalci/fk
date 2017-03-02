/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "incptrexpr.h"

void
IncrementPtrExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    // TODO: Implement me!
}

void
IncrementPtrExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "IncrementPtrExpr (" << _increment << ")" << std::endl;
}
