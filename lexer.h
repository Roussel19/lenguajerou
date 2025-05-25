#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_EQUALS,
    TOKEN_STRING,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

typedef struct {
    Token *tokens;
    int count;
} TokenList;

TokenList tokenize(const char *line);
void free_tokens(TokenList *list);

#endif
