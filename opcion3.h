#include <stdio.h>
#include <string.h>

#include "global_sets.h"

void verificarSaldo() {
    char celularInput[11];
    char nipInput[5];

    while (1) {
        printf("Ingrese su número de celular: ");
        scanf("%s", celularInput);

        printf("Ingrese su NIP: ");
        scanf("%s", nipInput);

        // Verificar que el celular y NIP ingresados coincidan con los almacenados
        if (strcmp(celularInput, celular) == 0 && strcmp(nipInput, nip) == 0) {
            printf("Datos correctos.\n");
            printf("Bienvenido %s %s\n", nombre, apellidos);
            printf("Saldo disponible: %.2f\n", saldo);
            break;
        } else {
            printf("Datos incorrectos. Intente nuevamente.\n");
        }
    }
}
