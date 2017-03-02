/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "loopexpr.h"

void
LoopExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    // TODO: Implement me!
}

void
LoopExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "LoopExpr [" << std::endl;

    for (auto &expr : _exprs)
    {
        std::cout << std::string(level * 2, ' ');
        expr->debug_description(level + 1);
    }

    std::cout << std::string(level, ' ') << "]" << std::endl;
}
