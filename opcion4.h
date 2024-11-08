#include <stdio.h>
#include <string.h>

#include "global_sets.h"

// Función para transferir dinero
void transferirDinero() {
    char celularInput[11];
    char nipInput[5];
    char nombreDestinatario[50];
    char tarjetaDestinatario[17];
    float monto;
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
        printf("Ingrese el nombre de la persona a la que va a transferir: ");
        scanf(" %[^\n]", nombreDestinatario);

        printf("Ingrese el número de tarjeta del destinatario (16 dígitos): ");
        scanf("%s", tarjetaDestinatario);

        printf("Ingrese el monto a transferir: ");
        scanf("%f", &monto);

        // Verificar si el monto a transferir es válido
        if (monto > saldo) {
            printf("Error: El monto a transferir excede el saldo disponible (%.2f).\n", saldo);
            printf("Por favor ingrese un monto válido.\n");
        } else if (monto <= 0) {
            printf("El monto debe ser mayor a cero. Intente nuevamente.\n");
        } else {
            printf("Monto válido.\n");
            break;
        }
    }

    while (1) {
        printf("Confirma la transferencia de %.2f a %s (Tarjeta: %s)? (S/N): ", monto, nombreDestinatario, tarjetaDestinatario);
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer de entrada

        if (confirmacion == 'S' || confirmacion == 's') {
            // Realizar la transferencia y actualizar el saldo

            printf("Saldo antes de la transferencia: %.2f\n", saldo);
            saldo -= monto;
            printf("Transferencia exitosa.\n");
            printf("Transferiste %.2f a %s (Tarjeta: %s).\n", monto, nombreDestinatario, tarjetaDestinatario);
            printf("Nuevo saldo: %.2f\n", saldo);
            break;
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente todos los datos.\n");
            return transferirDinero();  // Reiniciar el proceso si el usuario decide modificar los datos
        } else {
            printf("Opción no válida. Intente nuevamente.\n");
        }
    }

    printf("Regresando al menú principal...\n");
}
