#include <stdio.h>
#include <string.h>

#include "global_sets.h"

// Función para recargar tiempo aire
void recargarTiempoAire() {
    char celularInput[11];
    char nipInput[5];
    int compania;
    float monto;
    char celularRecarga[11];
    char confirmacion;

    while (1) {
        printf("Ingrese su número de celular: ");
        scanf("%s", celularInput);

        printf("Ingrese su NIP: ");
        scanf("%s", nipInput);

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
        printf("Seleccione la compañía para la recarga:\n");
        printf("1. AT&T\n");
        printf("2. Telcel\n");
        printf("3. Movistar\n");
        printf("Ingrese su opción: ");
        scanf("%d", &compania);

        if (compania < 1 || compania > 3) {
            printf("Compañía no válida. Intente nuevamente.\n");
            continue;
        }

        printf("Ingrese el monto a recargar: ");
        scanf("%f", &monto);

        if (monto > saldo) {
            printf("Error: El monto de la recarga excede el saldo disponible (%.2f).\n", saldo);
            printf("Por favor ingrese un monto válido.\n");
            continue;
        } else if (monto <= 0) {
            printf("El monto debe ser mayor a cero. Intente nuevamente.\n");
            continue;
        }

        printf("Ingrese el número de celular para la recarga: ");
        scanf("%s", celularRecarga);

        break;
    }

    while (1) {
        printf("Confirma la recarga de %.2f al número %s? (S/N): ", monto, celularRecarga);
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer de entrada

        if (confirmacion == 'S' || confirmacion == 's') {
            // Realizar la recarga y actualizar el saldo
            saldo -= monto;
            printf("Recarga exitosa.\n");
            printf("Recargaste %.2f al número %s.\n", monto, celularRecarga);
            printf("Nuevo saldo: %.2f\n", saldo);
            break;
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente todos los datos.\n");
            return recargarTiempoAire();  // Reiniciar el proceso si el usuario decide modificar los datos
        } else {
            printf("Opción no válida. Intente nuevamente.\n");
        }
    }

    printf("Regresando al menú principal...\n");
}
