#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct {
    char *name;
    char *value;
} Statement;

Statement parse(TokenList list);
void free_statement(Statement *stmt);

#endif
