/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "loopexpr.h"

void
LoopExpr::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    llvm::LLVMContext &context = M->getContext();
    llvm::Function *LoopF = B.GetInsertBlock()->getParent();
    llvm::BasicBlock *StartBB, *LoopBB, *EndBB;

    StartBB = llvm::BasicBlock::Create(context, "LoopStart", LoopF);
    LoopBB = llvm::BasicBlock::Create(context, "LoopBody", LoopF);
    EndBB = llvm::BasicBlock::Create(context, "LoopEnd", LoopF);

    B.CreateBr(StartBB);
    B.SetInsertPoint(StartBB);
    llvm::IRBuilder<> StartB(StartBB);

    llvm::Value *IdxV = B.CreateLoad(
        FkExprGlobals::instance()->get_index_ptr()
    );

    llvm::Value *CellPtr = B.CreateGEP(
        B.CreatePointerCast(
            FkExprGlobals::instance()->get_cells_ptr(),
            llvm::Type::getInt32Ty(context)->getPointerTo()
        ),
        IdxV
    );

    llvm::Value *SGZeroCond = StartB.CreateICmpSGT(
        StartB.CreateLoad(CellPtr),
        StartB.getInt32(0) // constant zero to check against
    );

    StartB.CreateCondBr(SGZeroCond, LoopBB, EndBB);

    B.SetInsertPoint(LoopBB);
    llvm::IRBuilder<> LoopB(LoopBB);

    for (auto &expr : _exprs)
    {
        expr->generate_code(M, LoopB);
    }

    LoopB.CreateBr(StartBB);

    B.SetInsertPoint(EndBB);
}

void
LoopExpr::debug_description(int level)
{
    std::cout.width(level);
    std::cout << "LoopExpr [" << std::endl;

    for (auto &expr : _exprs)
    {
        std::cout << std::string(level * 2, ' ');
        expr->debug_description(level + 1);
    }

    std::cout << std::string(level, ' ') << "]" << std::endl;
}
