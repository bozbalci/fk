/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef LOOPEXPR_H
#define LOOPEXPR_H

#include "expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <vector>

class LoopExpr : public FkExpr
{
    protected:
        std::vector<FkExpr *> _exprs;

    public:
        ~LoopExpr() {}
        LoopExpr(std::vector<FkExpr *> &exprs) : _exprs(exprs) {}
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
}

#endif // LOOPEXPR_H
