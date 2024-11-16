#include <stdio.h>
#include <string.h>

// Función para cambiar el NIP
void cambiarNIP() {
    char celularInput[11];
    char nipInput[5];
    char nuevoNIP[5];
    char confirmacion;

    while (1) {
        printf("\n          -----| CAMBIAR NIP |----- \n");

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
            printf("Su NIP actual es: %s\n", nip);
            break;
        } else {
            printf("Datos incorrectos. Intente nuevamente.\n");
        }
    }

    while (1) {
        
        printf(" -->Ingrese su nuevo NIP (4 digitos): ");
        scanf("%s", nuevoNIP);

        if (strlen(nuevoNIP) != 4 || !validarEntradaNumerica(nuevoNIP, 4)) {
            printf("NIP no valido. Debe contener exactamente 4 digitos numericos.\n");
            continue;
        }

        // Confirmación del nuevo NIP
        printf("%cEs correcto el nuevo NIP ingresado? (S/N): ", 168);
        scanf(" %c", &confirmacion);  // Espacio antes de %c para limpiar el buffer

        if (confirmacion == 'S' || confirmacion == 's') {
            strcpy(nip, nuevoNIP);  // Actualizar el NIP global
            printf("NIP modificado exitosamente.\n");
            break;
        } else if (confirmacion == 'N' || confirmacion == 'n') {
            printf("Por favor ingrese nuevamente el nuevo NIP.\n");
        } else {
            printf("\nOpcion no valida. Intente nuevamente.\n");
        }
    }

    printf("Regresando al men%c principal...\n", 163);
}
