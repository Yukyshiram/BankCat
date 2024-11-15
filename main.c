#include <stdio.h>
#include < stdlib.h>

#include "opcion1.h"
#include "opcion2.h"
#include "opcion3.h"
#include "opcion4.h"
#include "opcion5.h"
#include "opcion6.h"

char nombre[50];
char apellidos[50];
char celular[11];
char numeroTarjeta[17];
char nip[5];
float saldo = 0.0;



void mostrarGatitos() {
system ( "color 02" );
    printf("      /\\_/\\       /\\_/\\\n");
    printf("     ( o.o )     ( o.o )\n");
    printf("      > ^ <       > ^ <\n");
    printf("\n");
    printf("  ¡Bienvenido a MIAU BANK, elija la operación a realizar!\n\n");

    system ( "color 07");
}

int main() {
    int opcion;

    do {
        printf("Menu:\n");
        printf("1. Registrar a un nuevo cliente\n");
        printf("2. Depositar dinero a cuenta propia\n");
        printf("3. Verificar saldo en tarjeta\n");
        printf("4. Transferir dinero a otras cuentas\n");
        printf("5. Recargar tiempo aire\n");
        printf("6. Cambiar NIP\n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                registrarUsuario();
                break;
            case 2:
                depositarDinero();
                break;
            case 3:
                verificarSaldo();
                break;
            case 4:
                transferirDinero();
                break;
            case 5:
                recargarTiempoAire();
                break;
            case 6:
                printf("Opcion 6 seleccionada\n");
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while(opcion != 7);

    printf("Gracias por usar nuestro servicio. Hasta luego!\n");
    return 0;
}
