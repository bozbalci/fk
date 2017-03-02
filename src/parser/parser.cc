/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "parser.h"
#include "../expr/expr.h"
#include "../expr/incexpr.h"
#include "../expr/incptrexpr.h"
#include "../expr/loopexpr.h"
#include "../expr/printexpr.h"
#include "../expr/readexpr.h"

#include <vector>

void
FkParser::parse(std::vector<FkExpr *> &exprs)
{
    // TODO: Implement me!
}

void
FkParser::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    for (auto &expr : _exprs)
    {
        expr->generate_code(M, B);
    }
}
