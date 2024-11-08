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
        printf("Ingrese su numero de celular: ");
        scanf("%s", celularInput);
        printf("Ingrese su NIP: ");
        scanf("%s", nipInput);

        // Verificar que el celular y NIP sean correctos
        if (strcmp(celularInput, celular) == 0 && strcmp(nipInput, nip) == 0) {
            printf("Datos correctos. Bienvenido %s %s!\n", nombre, apellidos);
            break; // Salir del ciclo si los datos son correctos
        } else {
            printf("Datos incorrectos. Intente nuevamente.\n");
        }
    } while (1); // Repetir hasta que los datos sean correctos

    do {
        printf("Ingrese el monto a depositar: ");
        scanf("%f", &monto);

        if (monto <= 0) {
            printf("El monto debe ser mayor a cero. Intente nuevamente.\n");
        }
    } while (monto <= 0);

    do {
        printf("¿Todo esta bien con el monto de %.2f? (S/N): ", monto);
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer de entrada

        if (confirmacion == 'S' || confirmacion == 's') {
            saldo += monto;	// Aumentar el saldo con el monto depositado
            printf("Depósito exitoso. Monto depositado: %.2f\n", monto);
            printf("Número de tarjeta: %s\n", numeroTarjeta);
            break; 
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente el monto.\n");
        } else {
            printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (1); 

    printf("Regresando al menú principal...\n");
}
