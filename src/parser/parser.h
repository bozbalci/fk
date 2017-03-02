/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef PARSER_H
#define PARSER_H

#include "../expr/expr.h"

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <string>
#include <vector>

class FkParser
{
    protected:
        std::string _program_data;
        int _index;
        std::vector<FkExpr *> _exprs;
        void parse(std::vector<FkExpr *> &exprs);

    public:
        Parser(std::string source) :
            _program_data(source), _index(0) { parse(_exprs); }

        void generate_code(llvm::Module *M, llvm::IRBuilder<> &B);
};

#endif // PARSER_H
