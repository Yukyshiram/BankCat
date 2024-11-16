#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "opcion1.h"
#include "opcion2.h"
#include "opcion3.h"
#include "opcion4.h"
#include "opcion5.h"
#include "opcion6.h"

#include "cats.h"

char nombre[50] = "Invitado";
char apellidos[50] = "Cat";
char celular[11] = "0000000000";
char numeroTarjeta[17] = "1111111111111111";
char nip[5] = "1234";
float saldo = 0.0;

/*El buffer es una zona de memoria temporal que se utiliza para almacenar datos antes de que se procesen o se transfieran. Es como una "sala de espera" donde los datos se acumulan hasta que estén listos para ser usados. */
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Vacía el búfer
}

int main() {
    int opcion;

    do {
        mostrarGatitos();
        printf("Menu:\n");
        printf("1. Registrar a un nuevo cliente\n");
        printf("2. Depositar dinero a cuenta propia\n");
        printf("3. Verificar saldo en tarjeta\n");
        printf("4. Transferir dinero a otras cuentas\n");
        printf("5. Recargar tiempo aire\n");
        printf("6. Cambiar NIP\n");
        printf("7. Salir\n");
        printf("\nIngrese una opcion: ");
        

        /* Este lo agregamos porque cuando el usuario ingresaba una letra el bucle se hacia infinito */
        if (scanf("%d", &opcion) != 1) {
    
            printf("\n---->| Entrada no v%clida. Por favor, ingrese un n%cmero. |<----\n\n", 160, 163); // á, ú luego no me acuerdo
            limpiarBuffer();
            continue;
        }

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
                cambiarNIP();
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("\n---->| Opcion no v%clida. Intente nuevamente |<----\n\n", 160);
                break;
        }
    } while(opcion != 7);

    seYouNextTime();
    getch();
    return 0;
}
