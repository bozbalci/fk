/*
 * Copyright (c) 2017, Berk Ozbalci
 * All rights reserved.
*/

#ifndef TOKENS_H
#define TOKENS_H

typedef enum
{
    T_DEC_DATAPTR = '<',
    T_INC_DATAPTR = '>',
    T_INC         = '+',
    T_DEC         = '-',
    T_PRINT       = '.',
    T_READ        = ',',
    T_LOOP_LEFT   = '[',
    T_LOOP_RIGHT  = ']'
} FkToken;

#endif // TOKENS_H
