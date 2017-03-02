/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef PRINTEXPR_H
#define PRINTEXPR_H

#include "expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

class PrintExpr : public FkExpr
{
    public:
        ~PrintExpr() {}
        PrintExpr() {}
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
}

#endif // PRINTEXPR_H
