/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef READEXPR_H
#define READEXPR_H

#include "expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

class ReadExpr : public FkExpr
{
    public:
        ~ReadExpr() {}
        ReadExpr() {}
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
}

#endif // READEXPR_H
