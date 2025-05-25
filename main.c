#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo.rou\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        TokenList tokens = tokenize(line);
        Statement stmt = parse(tokens);
        interpret(stmt);
        free_tokens(&tokens);
        free_statement(&stmt);
    }

    fclose(file);
    return 0;
}
