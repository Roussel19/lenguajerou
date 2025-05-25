#include "interpreter.h"
#include <stdio.h>
#include <string.h>

void interpret(Statement stmt) {
    if (strcmp(stmt.name, "show") == 0) {
        printf("%s\n", stmt.value);
    }
}
