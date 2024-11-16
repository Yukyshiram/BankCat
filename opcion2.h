#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "global_sets.h"

void depositarDinero() {
    char celularInput[11];
    char nipInput[5];
    float monto;
    char confirmacion;

    do {
        printf("          -----| DEPOSITAR DINERO |----- \n");

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

        // Verificar que el celular y NIP sean correctos
        if (strcmp(celularInput, celular) == 0 && strcmp(nipInput, nip) == 0) {
            printf("\nDatos correctos. Bienvenido %s %s!\n", nombre, apellidos);
            break; // Salir del ciclo si los datos son correctos
        } else {
            printf("\nDatos incorrectos. Intente nuevamente.\n\n");
        }
    } while (1); // Repetir hasta que los datos sean correctos

    do {
        char entrada[50];

        printf("\n -->Ingrese el monto a depositar: ");
        scanf("%s", entrada); // Leer la entrada como texto

        if (!validarNumerico(entrada)) { // Validar si la entrada es numérica
            printf("Solo se permiten n%cmeros. Intente nuevamente.\n", 163);
            continue; // Regresar al inicio del ciclo
        }

        // Convertir la entrada a float
        monto = atof(entrada);

        if (monto <= 0) {
            printf("El monto debe ser mayor a cero. Intente nuevamente.\n\n");
        }
    } while (monto <= 0);

    do {
        printf("%cTodo esta bien con el monto de %.2f? (S/N): ",168, monto);
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer de entrada

        if (confirmacion == 'S' || confirmacion == 's') {
            saldo += monto;	// Aumentar el saldo con el monto depositado
            printf("\nDeposito exitoso. Monto depositado: %.2f\n", monto);
            printf("N%cmero de tarjeta: %s\n",163, numeroTarjeta );
            break; 
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente el monto.\n");
        } else {
            printf("Opción no v%clida. Intente nuevamente.\n", 160);
        }
    } while (1); 

    printf("\nRegresando al men%c principal...\n\n", 163);
}
