#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo.rou\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        // Buscamos si la línea comienza con "show = "
        if (strncmp(line, "show = ", 7) == 0) {
            // La línea debería tener formato: show = "Hola, mundo"
            // Buscamos la primera comilla
            char *start = strchr(line, '"');
            if (start) {
                start++; // Avanzar después de la comilla
                // Buscamos la siguiente comilla que cierra la cadena
                char *end = strchr(start, '"');
                if (end) {
                    // Extraemos el texto entre las comillas
                    *end = '\0'; // Cortamos la cadena aquí
                    printf("%s\n", start); // Imprimimos el texto
                }
            }
        }
    }

    fclose(file);
    return 0;
}
