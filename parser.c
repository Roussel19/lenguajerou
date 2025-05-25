#include "parser.h"
#include <stdlib.h>
#include <string.h>

Statement parse(TokenList list) {
    Statement stmt = {NULL, NULL};

    if (list.count >= 3 &&
        list.tokens[0].type == TOKEN_IDENTIFIER &&
        list.tokens[1].type == TOKEN_EQUALS &&
        list.tokens[2].type == TOKEN_STRING) {

        stmt.name = strdup(list.tokens[0].value);
        stmt.value = strdup(list.tokens[2].value);
    }

    return stmt;
}

void free_statement(Statement *stmt) {
    if (stmt->name) free(stmt->name);
    if (stmt->value) free(stmt->value);
}
