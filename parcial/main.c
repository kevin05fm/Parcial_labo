#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "publicaciones.h"

#define CANT 100
#define LEN_CONT    1000

int main()
{
    Cliente array[CANT];
    Publicaciones arrayP[LEN_CONT];

    int menu;
    int auxiliarId;

    cliente_init(array,CANT);
    publicar_init(arrayP,LEN_CONT);


    do
    {
        getValidInt("\n\n1.Alta\n2.Modificar\n3.Baja\n4.Realizar una Publicacion\n5.Mostrar\n6.Pausar Publicacion\n7.Reanudar Publicacion\n8.Imprimir Clientes\n9.Imprimir Publicaciones \n10.Salir\n","\nNo valida\n",&menu,1,10,1);
        switch(menu)
        {
            case 1:
                cliente_alta(array,CANT);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(array,CANT,auxiliarId);

                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);

                cliente_baja(array,CANT,auxiliarId);
                break;
            case 4:
                publicar_alta(arrayP,LEN_CONT,
                array, CANT);

                break;
            case 5:





                break;
            case 6:


                break;
            case 7:
                cliente_mostrar(array,CANT);
                break;
            case 8:
                publicar_mostrar(arrayP,LEN_CONT);
                break;
            case 9:

                break;
            case 10:

               break;

        }

    }while(menu != 10);

    return 0;
}


