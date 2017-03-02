/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "readexpr.h"

void
ReadExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    // TODO: Implement me!
}

void
ReadExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "ReadExpr" << std::endl;
}
