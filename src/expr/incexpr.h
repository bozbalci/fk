/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef INCEXPR_H
#define INCEXPR_H

#include "expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

class IncrementExpr : public FkExpr
{
    protected:
        int _increment;

    public:
        ~IncrementExpr() {}
        IncrementExpr(int increment) : _increment(increment) {}
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
};

#endif // INCEXPR_H
