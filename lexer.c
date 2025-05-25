#include "lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

TokenList tokenize(const char *line) {
    TokenList list = {malloc(sizeof(Token) * 10), 0};  // simplificado
    const char *p = line;

    while (*p) {
        while (isspace(*p)) p++;

        if (isalpha(*p)) {
            const char *start = p;
            while (isalnum(*p)) p++;
            int len = p - start;
            Token t = {TOKEN_IDENTIFIER, strndup(start, len)};
            list.tokens[list.count++] = t;
        } else if (*p == '=') {
            Token t = {TOKEN_EQUALS, strdup("=")};
            list.tokens[list.count++] = t;
            p++;
        } else if (*p == '"') {
            p++;
            const char *start = p;
            while (*p && *p != '"') p++;
            int len = p - start;
            Token t = {TOKEN_STRING, strndup(start, len)};
            list.tokens[list.count++] = t;
            if (*p == '"') p++;
        } else {
            p++;
        }
    }

    Token t = {TOKEN_EOF, NULL};
    list.tokens[list.count++] = t;

    return list;
}

void free_tokens(TokenList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->tokens[i].value);
    }
    free(list->tokens);
}
