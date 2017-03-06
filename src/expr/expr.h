/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef EXPR_H
#define EXPR_H

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>

class FkExpr
{
    public:
        virtual ~FkExpr() {}
        virtual void generate_code(llvm::Module *M, llvm::IRBuilder<> &B) {}
        virtual void debug_description(int level) = 0;
};

class FkExprGlobals
{
    private:
        FkExprGlobals() {}

        static FkExprGlobals *_instance;
        static llvm::GlobalVariable *__fk_index_ptr;
        static llvm::GlobalVariable *__fk_cells_ptr;
        static llvm::Function *__fk_putchar_func;
        static llvm::Function *__fk_getchar_func;

    public:
        FkExprGlobals(FkExprGlobals const&) = delete;
        FkExprGlobals& operator=(FkExprGlobals const&) = delete;

        static FkExprGlobals* instance();
        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);

        llvm::GlobalVariable* get_index_ptr();
        llvm::GlobalVariable* get_cells_ptr();
        llvm::Function *get_putchar_func();
        llvm::Function *get_getchar_func();
};

#endif // EXPR_H
