#ifndef PUBLICACIONES_H_INCLUDED
#define PUBLICACIONES_H_INCLUDED
typedef struct
{
    char texto[64];
    int idCliente;
    int numeroRubro;

    //------------
    int idPublicaciones;
    int isEmpty;
}Publicaciones;

#include "cliente.h"


int publicar_init(Publicaciones* array,int limite);
int publicar_mostrar(Publicaciones* array,int limite);
int publicar_mostrarDebug(Publicaciones* array,int limite);

int publicar_alta(Publicaciones* arrayC,int limite,
              Cliente* clientes, int lenClientes);

int publicar_baja(Publicaciones* array,int limite, int id);
int publicar_modificacion(Publicaciones* array,int limite, int id);
int publicar_ordenar(Publicaciones* array,int limite, int orden);
int publicar_ordenarCuit(Publicaciones* array,int limite, int orden);


int publicar_altaForzada(Publicaciones* arrayC,int limite,Cliente* clientes, int lenClientes,int idCliente,char* archivo,char* cuit,int dias);

#endif // PANTALLA_H_INCLUDED



