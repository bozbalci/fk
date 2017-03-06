/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "readexpr.h"

void
ReadExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::ArrayRef<llvm::Value *> ArgsArr({}); // no arguments passed

    llvm::CallInst *GetCharCall = B.CreateCall(
        FkExprGlobals::instance()->get_getchar_func(),
        ArgsArr
    );

    GetCharCall->setTailCall(false);

    llvm::Value *GetCharResult = GetCharCall;

    /*
     * Usually, the returned value of i32 @getchar() is truncated
     * to i8 using an IR directive, for example
     *
     *     %4 = call i32 @getchar()
     *     %5 = trunc i32 %4 to i8
     *
     * and when calling i32 @putchar(i32), a sign extension is
     * performed, as such:
     *
     *     %6 = sext i8 %5 to i32
     *     %7 = call i32 @putchar(i32 %6)
     *
     * However, since we are storing 32-bit integers in our cells,
     * such truncation is not necessary. If this changes in the
     * future, the few lines below will truncate |GetCharResult|
     * to |TruncatedInt|.
     *
     * llvm::Value *TruncatedInt = B.CreateTrunc(
     *     GetCharResult, 
     *     llvm::Type::getInt8Ty(ontext)
     * );
    */

    llvm::Value *Idxs[] = {
        B.getInt32(0),
        B.CreateLoad(
            FkExprGlobals::instance()->get_index_ptr()
        )
    };

    llvm::ArrayRef<llvm::Value *> IdxsArr(Idxs);

    B.CreateStore(
        GetCharResult,
        B.CreateGEP(
            FkExprGlobals::instance()->get_cells_ptr(),
            IdxsArr
        )
    );
}

void
ReadExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "ReadExpr" << std::endl;
}
