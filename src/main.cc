/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "parser/parser.h"

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>

#include <iostream>

int
main(int argc, char *argv[])
{
    std::string s = ">++++++++[<+++++++++>-]<.>>+>+>++>[-]" \
                    "+<[>[->+<<++++>]<<]>.+++++++..+++.>>+" \
                    "++++++.<<<[[-]<[-]>]<+++++++++++++++." \
                    ">>.+++.------.--------.>>+.>++++.";

    FkParser parser(s);

    parser.debug_description(0);

    return 0;
}
