/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "expr.h"

#include <vector>

FkExprGlobals *FkExprGlobals::_instance = nullptr;
llvm::GlobalVariable *FkExprGlobals::__fk_index_ptr = nullptr;
llvm::GlobalVariable *FkExprGlobals::__fk_cells_ptr = nullptr;
llvm::Function *FkExprGlobals::__fk_putchar_func = nullptr;
llvm::Function *FkExprGlobals::__fk_getchar_func = nullptr;

FkExprGlobals*
FkExprGlobals::instance()
{
    if (!FkExprGlobals::_instance)
    {
        FkExprGlobals::_instance = new FkExprGlobals();
    }

    return FkExprGlobals::_instance;
}

llvm::GlobalVariable*
FkExprGlobals::get_index_ptr()
{
    return __fk_index_ptr;
}

llvm::GlobalVariable*
FkExprGlobals::get_cells_ptr()
{
    return __fk_cells_ptr;
}

llvm::Function*
FkExprGlobals::get_putchar_func()
{
    return __fk_putchar_func;
}

llvm::Function*
FkExprGlobals::get_getchar_func()
{
    return __fk_getchar_func;
}

void
FkExprGlobals::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::LLVMContext &context = M->getContext();

    if (!__fk_index_ptr)
    {
        llvm::Type *Ty = llvm::Type::getInt32Ty(context);

        const llvm::APInt Zero = llvm::APInt(32, 0);

        llvm::Constant *InitV = llvm::Constant::getIntegerValue(Ty, Zero);

        FkExprGlobals::__fk_index_ptr = new llvm::GlobalVariable(*M, Ty, false,
            llvm::GlobalValue::WeakAnyLinkage, InitV, "fk.index");
    }
    
    if (!__fk_cells_ptr)
    {
        // TODO: Change the constant 100 to a number retrieved from
        // command-line arguments.
        llvm::ArrayType *ArrTy = llvm::ArrayType::get(
            llvm::Type::getInt32Ty(context), 100);

        std::vector<llvm::Constant *> constants(100, B.getInt32(0));

        llvm::ArrayRef<llvm::Constant *> Constants =
            llvm::ArrayRef<llvm::Constant *>(constants);

        llvm::Constant *InitPtr = llvm::ConstantArray::get(ArrTy, Constants);

        FkExprGlobals::__fk_cells_ptr = new llvm::GlobalVariable(*M, ArrTy,
            false, llvm::GlobalValue::WeakAnyLinkage, InitPtr, "fk.cells");
    }

    if (!__fk_putchar_func)
    {
        llvm::Type *PutCharArgs[] = {
            llvm::Type::getInt32Ty(context)
        };

        llvm::FunctionType *PutCharTy = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(context),
            PutCharArgs,
            false // not a vararg function
        );

        FkExprGlobals::__fk_putchar_func = llvm::cast<llvm::Function>(
            M->getOrInsertFunction("putchar", PutCharTy)
        );
    }
    
    if (!__fk_getchar_func)
    {
        llvm::FunctionType *GetCharTy = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(context),
            {}, // no arguments passed
            false // not a vararg function
        );

        FkExprGlobals::__fk_getchar_func = llvm::cast<llvm::Function>(
            M->getOrInsertFunction("getchar", GetCharTy)
        );
    }
}
