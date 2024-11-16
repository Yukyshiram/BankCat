#ifndef VALIDADOR_H    // Si no está definida la constante VALIDADOR_H
#define VALIDADOR_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarNombre(const char *nombre) {
    int longitud = strlen(nombre);
    if (longitud < 3) {
        return 0; // Nombre demasiado corto
    }
    for (int i = 0; i < longitud; i++) {
        if (isdigit(nombre[i])) {
            return 0; // Contiene caracteres numéricos
        }
    }
    return 1; // Nombre válido
}

int validarEntradaNumerica(const char *entrada, int longitudEsperada) {
    int longitud = strlen(entrada);
    if (longitud != longitudEsperada) {
        return 0; // Longitud incorrecta
    }
    for (int i = 0; i < longitud; i++) {
        if (!isdigit(entrada[i])) {
            return 0; // Contiene caracteres no numéricos
        }
    }
    return 1; // Entrada válida
}

int validarNumerico(const char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i]) && entrada[i] != '.') { // Permite dígitos y punto decimal
            return 0; // Contiene caracteres no válidos
        }
    }
    return 1; // Es numérico
}

#endif 