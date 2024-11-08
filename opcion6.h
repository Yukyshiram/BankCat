#include <stdio.h>
#include <string.h>

#include "global_sets.h"

// Función para cambiar el NIP
void cambiarNIP() {
    char celularInput[11];
    char nipInput[5];
    char nuevoNIP[5];
    char confirmacion;

    while (1) {
        printf("Ingrese su número de celular: ");
        scanf("%s", celularInput);

        printf("Ingrese su NIP actual: ");
        scanf("%s", nipInput);

        if (strcmp(celularInput, celular) == 0 && strcmp(nipInput, nip) == 0) {
            printf("Datos correctos.\n");
            printf("Bienvenido %s %s\n", nombre, apellidos);
            printf("Su NIP actual es: %s\n", nip);
            break;
        } else {
            printf("Datos incorrectos. Intente nuevamente.\n");
        }
    }

    while (1) {
        printf("Ingrese su nuevo NIP (4 dígitos): ");
        scanf("%s", nuevoNIP);

        if (strlen(nuevoNIP) != 4 || !validarEntradaNumerica(nuevoNIP, 4)) {
            printf("NIP no válido. Debe contener exactamente 4 dígitos numéricos.\n");
            continue;
        }

        // Confirmación del nuevo NIP
        printf("¿Es correcto el nuevo NIP ingresado? (S/N): ");
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer

        if (confirmacion == 'S' || confirmacion == 's') {
            strcpy(nip, nuevoNIP);  // Actualizar el NIP global
            printf("NIP modificado exitosamente.\n");
            break;
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente el nuevo NIP.\n");
        } else {
            printf("Opción no válida. Intente nuevamente.\n");
        }
    }

    printf("Regresando al menú principal...\n");
}
