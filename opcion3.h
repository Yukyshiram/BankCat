#include <stdio.h>
#include <string.h>

#include "global_sets.h"

void verificarSaldo() {
    char celularInput[11];
    char nipInput[5];

    while (1) {
        printf("\n          -----| VERIFICAR SALDO |----- \n");

        do {
            printf("\n -->Ingrese su celular (10 digitos): ");
            scanf("%s", celularInput);
            if (!validarEntradaNumerica(celularInput, 10)) {
                printf("\nCelular invalido. Solo se aceptan 10 digitos numericos.\n");
            }
        } while (!validarEntradaNumerica(celularInput, 10));

        do {
            printf("\n -->Ingrese su NIP (4 digitos): ");
            scanf("%s", nipInput);
            if (!validarEntradaNumerica(nipInput, 4)) {
                printf("NIP invalido. Solo se aceptan 4 digitos numericos.\n");
            }
        } while (!validarEntradaNumerica(nipInput, 4));

        // Verificar que el celular y NIP ingresados coincidan con los almacenados
        if (strcmp(celularInput, celular) == 0 && strcmp(nipInput, nip) == 0) {
            printf("Datos correctos.\n");
            printf("\nBienvenido %s %s\n", nombre, apellidos);
            printf("Saldo disponible: %.2f\n\n", saldo);
            break;
        } else {
            printf("\nDatos incorrectos. Intente nuevamente.\n");
        }
    }
}
