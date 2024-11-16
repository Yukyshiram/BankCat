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
        printf("\n          -----| TRANSFERIR DINERO |----- \n");

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

        if (strcmp(celularInput, celular) == 0 && strcmp(nipInput, nip) == 0) { //Si ambas comparaciones devuelven 0, significa que las cadenas son iguales.
            printf("Datos correctos.\n");
            printf("Bienvenido %s %s\n", nombre, apellidos);
            printf("Saldo disponible: %.2f\n", saldo);
            break;
        } else {
            printf("Datos incorrectos. Intente nuevamente.\n");
        }
    }

    while (1) {
        char entrada[50];

        do {
            printf("\n -->Ingrese el nombre de la persona a la que va a transferir: ");
            scanf("%s", nombreDestinatario);
            if (!validarNombre(nombreDestinatario)) {
                printf("\nNombre invalido. No debe contener numeros y debe tener al menos 3 caracteres.\n");
            }
        } while (!validarNombre(nombreDestinatario));

        do {
            printf("\n -->Ingrese el n%cmero de tarjeta del destinatario (16 digitos): ", 163);
            scanf("%s", tarjetaDestinatario);
            if (!validarEntradaNumerica(tarjetaDestinatario, 16)) {
                printf("\nNumero de tarjeta invalido. Solo se aceptan 16 digitos numericos.\n");
            }
        } while (!validarEntradaNumerica(tarjetaDestinatario, 16));

        printf(" -->Ingrese el monto a transferir: ");
        scanf("%f", &entrada);

        if (!validarNumerico(entrada)) { // Validar si la entrada es numérica
            printf("Solo se permiten n%cmeros. Intente nuevamente.\n", 163);
            continue; // Regresar al inicio del ciclo
        }
        // Convertir la entrada a float
        monto = atof(entrada);

        // Verificar si el monto a transferir es válido
        if (monto > saldo) {
            printf("    -----| Error: El monto a transferir excede el saldo disponible (%.2f).\n", saldo);
            printf("    -----| Por favor ingrese un monto valido.\n");
        } else if (monto <= 0) {
            printf("El monto debe ser mayor a cero. Intente nuevamente.\n");
        } else {
            printf("\n    -----| Monto valido.\n");
            break;
        }
    }

    while (1) {
        printf("Confirma la transferencia de %.2f a %s (Tarjeta: %s)? (S/N): ", monto, nombreDestinatario, tarjetaDestinatario);
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer de entrada

        if (confirmacion == 'S' || confirmacion == 's') {
            // Realizar la transferencia y actualizar el saldo

            printf("\n\nSaldo antes de la transferencia: %.2f\n", saldo);
            saldo -= monto;
            printf("\nTransferencia exitosa.\n");
            printf("Transferiste %.2f a %s (Tarjeta: %s).\n", monto, nombreDestinatario, tarjetaDestinatario);
            printf("Nuevo saldo: %.2f\n\n", saldo);
            break;
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente todos los datos.\n");
            return transferirDinero();  // Reiniciar el proceso si el usuario decide modificar los datos
        } else {
            printf("Opcion no valida. Intente nuevamente.\n");
        }
    }

    printf("Regresando al men%c principal...\n", 163);
}
