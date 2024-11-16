#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "global_sets.h"
#include "validador.h"

void registrarUsuario() {

    printf("\n          -----| REGISTRO DE NUEVO CLIENTE |----- \n");

    do {
        printf("\n -->Ingrese su nombre: ");
        scanf("%s", nombre);
        if (!validarNombre(nombre)) {
            printf("\nNombre invalido. No debe contener numeros y debe tener al menos 3 caracteres.\n");
        }
    } while (!validarNombre(nombre));
    
    do {
        printf("\n -->Ingrese sus apellidos: ");
        scanf("%s", apellidos);
        if (!validarNombre(apellidos)) {
            printf("\nApellidos invalidos. No debe contener numeros y debe tener al menos 3 caracteres.\n");
        }
    } while (!validarNombre(apellidos));

    do {
        printf("\n -->Ingrese su celular (10 digitos): ");
        scanf("%s", celular);
        if (!validarEntradaNumerica(celular, 10)) {
            printf("\nCelular invalido. Solo se aceptan 10 digitos numericos.\n");
        }
    } while (!validarEntradaNumerica(celular, 10));

    do {
        printf("\n -->Ingrese su n%cmero de tarjeta (16 digitos): ", 163);
        scanf("%s", numeroTarjeta);
        if (!validarEntradaNumerica(numeroTarjeta, 16)) {
            printf("\nN%cmero de tarjeta invalido. Solo se aceptan 16 digitos numericos.\n", 163);
        }
    } while (!validarEntradaNumerica(numeroTarjeta, 16));

    do {
        printf("\n -->Ingrese su NIP (4 digitos): ");
        scanf("%s", nip);
        if (!validarEntradaNumerica(nip, 4)) {
            printf("NIP invalido. Solo se aceptan 4 digitos numericos.\n");
        }
    } while (!validarEntradaNumerica(nip, 4));

    printf("\nRegistro exitoso. Bienvenido, %s!\n\n", nombre);  
}