/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "incexpr.h"

void
IncrementExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::Value *Idxs[] =
    {
        B.getInt32(0),
        B.CreateLoad(FkExprGlobals::instance()->get_index_ptr())
    };

    llvm::ArrayRef<llvm::Value *> IdxsArr(Idxs);

    llvm::Value *CellPtr = B.CreateGEP(
        FkExprGlobals::instance()->get_cells_ptr(),
        IdxsArr
    );

    llvm::Value *CellV = B.CreateLoad(CellPtr);

    B.CreateStore(
        B.CreateAdd(
            CellV,
            B.getInt32(_increment)
        ),
        CellPtr
    );
}

void
IncrementExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "IncrementExpr (" << _increment << ")" << std::endl;
}
