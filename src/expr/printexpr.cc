/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "printexpr.h"

void
PrintExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    // TODO: Implement me!
}

void
PrintExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "PrintExpr" << std::endl;
}
