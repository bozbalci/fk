/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef EXPR_H
#define EXPR_H

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

class FkExpr
{
    public:
        virtual ~FkExpr() {}
        virtual void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
};

#endif // EXPR_H
