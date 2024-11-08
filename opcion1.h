#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "global_sets.h"

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

void registrarUsuario() {

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    printf("Ingrese sus apellidos: ");
    scanf("%s", apellidos);

    do {
        printf("Ingrese su celular (10 digitos): ");
        scanf("%s", celular);
        if (!validarEntradaNumerica(celular, 10)) {
            printf("Celular invalido. Solo se aceptan 10 digitos numericos.\n");
        }
    } while (!validarEntradaNumerica(celular, 10));

    do {
        printf("Ingrese su numero de tarjeta (16 digitos): ");
        scanf("%s", numeroTarjeta);
        if (!validarEntradaNumerica(numeroTarjeta, 16)) {
            printf("Numero de tarjeta invalido. Solo se aceptan 16 digitos numericos.\n");
        }
    } while (!validarEntradaNumerica(numeroTarjeta, 16));

    do {
        printf("Ingrese su NIP (4 digitos): ");
        scanf("%s", nip);
        if (!validarEntradaNumerica(nip, 4)) {
            printf("NIP invalido. Solo se aceptan 4 digitos numericos.\n");
        }
    } while (!validarEntradaNumerica(nip, 4));

    printf("Registro exitoso. Bienvenido, %s!\n", nombre);
    printf("Datos registrados:\n");
    printf("Nombre: %s\n", nombre);
    printf("Apellidos: %s\n", apellidos);
    printf("Celular: %s\n", celular);
    printf("Numero de tarjeta: %s\n", numeroTarjeta);
    printf("NIP: %s\n", nip);
    
}