/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#include "parser.h"
#include "tokens.h"
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
    char c;

    while ((c = _program_data[_index++]))
    {
        FkExpr *expr = nullptr;

        switch (c)
        {
            case T_DEC_DATAPTR:
                expr = new IncrementPtrExpr(-1);
                break;

            case T_INC_DATAPTR:
                expr = new IncrementPtrExpr(1);
                break;

            case T_INC:
                expr = new IncrementExpr(1);
                break;

            case T_DEC:
                expr = new IncrementExpr(-1);
                break;

            case T_PRINT:
                expr = new PrintExpr();
                break;

            case T_READ:
                expr = new ReadExpr();
                break;

            case T_LOOP_LEFT:
            {
                std::vector<FkExpr *> loop_exprs;
                parse(loop_exprs);
                expr = new LoopExpr(loop_exprs);
            }
                break;

            case T_LOOP_RIGHT:
                return;

            default:
                break;
        }

        if (expr)
        {
            _exprs.push_back(expr);
        }
    }
}

void
FkParser::generate_code(llvm::Module *M, llvm::IRBuilder<> &B)
{
    FkExprGlobals::instance()->generate_code(M, B);

    for (auto &expr : _exprs)
    {
        expr->generate_code(M, B);
    }
}
