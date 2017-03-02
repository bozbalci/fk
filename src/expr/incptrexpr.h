/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef INCPTREXPR_H
#define INCPTREXPR_H

#include "expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <iostream>

class IncrementPtrExpr : public FkExpr
{
    protected:
        int _increment;

    public:
        ~IncrementPtrExpr() {}
        IncrementPtrExpr(int increment) : _increment(increment) {}
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
        void debug_description(int level);
};

#endif // INCPTREXPR_H
