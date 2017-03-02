/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef INCEXPR_H
#define INCEXPR_H

#include "expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <iostream>

class IncrementExpr : public FkExpr
{
    protected:
        int _increment;

    public:
        ~IncrementExpr() {}
        IncrementExpr(int increment) : _increment(increment) {}
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
        void debug_description(int level);
};

#endif // INCEXPR_H
