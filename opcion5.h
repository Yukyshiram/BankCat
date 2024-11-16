#include <stdio.h>
#include <string.h>

#include "global_sets.h"

void limpiarBuff() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Vacía el búfer
}

void recargarTiempoAire() {
    char celularInput[11];
    char nipInput[5];
    int compania;
    float monto;
    char celularRecarga[11];
    char confirmacion;

    while (1) {
        printf("\n          -----| RECARGAR TIEMPO AIRE |----- \n");

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

        if (strcmp(celularInput, celular) == 0 && strcmp(nipInput, nip) == 0) {
            printf("Datos correctos.\n");
            printf("Bienvenido %s %s\n", nombre, apellidos);
            printf("Saldo disponible: %.2f\n", saldo);
            break;
        } else {
            printf("Datos incorrectos. Intente nuevamente.\n");
        }
    }

    while (1) {
        printf("\nSeleccione la compa%cn%ca para la recarga:\n", 164, 161);
        printf("1. AT&T\n");
        printf("2. Telcel\n");
        printf("3. Movistar\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &compania);

        if (scanf("%d", &compania) != 1) {
    
            printf("\n---->| Entrada no v%clida. Por favor, ingrese un n%cmero. |<----\n\n", 160, 163);
            limpiarBuff();
            continue;
        }

        if (compania < 1 || compania >= 4) {
            printf("Compa%cn%ca no v%clida. Intente nuevamente.\n", 164, 161, 160);
            continue;
        }

        printf(" -->Ingrese el monto a recargar: ");
        scanf("%f", &monto);

        if (monto > saldo) {
            printf("\nError: El monto de la recarga excede el saldo disponible (%.2f).\n", saldo);
            printf("Por favor ingrese un monto valido.\n");
            continue;
        } else if (monto <= 0) {
            printf("El monto debe ser mayor a cero. Intente nuevamente.\n");
            continue;
        }

        do {
            printf("\n -->Ingrese el n%cmero de celular para la recarga (10 digitos): ", 163);
            scanf("%s", celularRecarga);
            if (!validarEntradaNumerica(celularRecarga, 10)) {
                printf("\nCelular invalido. Solo se aceptan 10 digitos numericos.\n");
            }
        } while (!validarEntradaNumerica(celularRecarga, 10));

        break;
    }

    while (1) {
        printf("\nConfirma la recarga de %.2f al n%cmero %s? (S/N): ", monto, 163, celularRecarga);
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer de entrada

        if (confirmacion == 'S' || confirmacion == 's') {

            printf("\n\nSaldo antes de la recarga: %.2f\n", saldo);
            saldo -= monto;
            printf("Recarga exitosa.\n");
            printf("\nRecargaste %.2f al n%cmero %s.\n", monto, 163, celularRecarga);
            printf("Nuevo saldo en tarjeta: %.2f\n\n", saldo);
            break;
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente todos los datos.\n");
            return recargarTiempoAire();  // Reiniciar el proceso si el usuario decide modificar los datos
        } else {
            printf("\nOpcion no valida. Intente nuevamente.\n");
        }
    }

    printf("Regresando al men%c principal...\n", 163);
}
