/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "incexpr.h"

void
IncrementExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    // TODO: Implement me!
}

void
IncrementExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "IncrementExpr (" << _increment << ")" << std::endl;
}
