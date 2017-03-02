/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef LOOPEXPR_H
#define LOOPEXPR_H

#include "expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <iostream>
#include <vector>

class LoopExpr : public FkExpr
{
    protected:
        std::vector<FkExpr *> _exprs;

    public:
        ~LoopExpr() {}
        LoopExpr(std::vector<FkExpr *> &exprs) : _exprs(exprs) {}
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
        void debug_description(int level);
};

#endif // LOOPEXPR_H
