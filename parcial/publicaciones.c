#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicaciones.h"
#include "utn.h"
#include "cliente.h"



//Funciones privadas
static int proximoId(void);
static int buscarPorId(Publicaciones* array,int limite, int id);
static int buscarLugarLibre(Publicaciones* array,int limite);
//__________________



/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int publicar_init(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicar_mostrarDebug(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            //printf("[DEBUG] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicar_mostrar(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;

        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %d - %s - %d \n",array[i].idPublicaciones, array[i].numeroRubro,array[i].texto, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicar_alta(Publicaciones* arrayP,int limite,
              Cliente* clientes, int lenClientes)
{
    int retorno = -1;
    int i;
    int idCli;
    int posCli;
    char auxTexto[64];
    int  auxNumero;

    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            // alta
            //TODO
            getValidInt("ID del cliente\n?","\nNumero no valido\n",&idCli,0,99999,2);
            posCli = cliente_buscarPorId(clientes,lenClientes,idCli);
            if(posCli>=0)
            {
                // la cliente existe, idPant es valido

                getValidInt("Numero de Rubro?","\nNumero no valido\n",&auxNumero,0,1000,2);
                getValidString("\nTexto? ","\nEso no es un texto","El maximo es 64",auxTexto,64,2);
                // hacer el resto
                arrayP[i].numeroRubro = auxNumero;
                strcpy(arrayP[i].texto,auxTexto);

                arrayP[i].idCliente = idCli; // relacion
                arrayP[i].isEmpty=0;
                arrayP[i].idPublicaciones= proximoId();

            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int publicar_baja(Publicaciones* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(array,limite,id);

    if(indiceAEliminar>=0)
    {

        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


static int buscarLugarLibre(Publicaciones* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


//int cliente_buscarPorId(Cliente* array,int limite, int id)
static int buscarPorId(Publicaciones* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


