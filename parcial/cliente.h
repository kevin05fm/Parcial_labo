#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    int cuit;
    //------------
    int idCliente;
    int isEmpty;
}Cliente;
#endif // PANTALLA_H_INCLUDED


int cliente_init(Cliente* array,int limite);
int cliente_mostrar(Cliente* array,int limite);
int cliente_mostrarDebug(Cliente* array,int limite);
int cliente_alta(Cliente* array,int limite);
int cliente_baja(Cliente* array,int limite, int id);
int cliente_modificacion(Cliente* array,int limite, int id);
int cliente_ordenar(Cliente* array,int limite, int orden);
int cliente_buscarPorId(Cliente* array,int limite, int id);
int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido, int cuit);

int cliente_ordenarPorPrecio(Cliente* array,int limite, int orden);
int cliente_inferiorAMil(Cliente* array,int limite);
int cliente_totalPrecio(Cliente* array,int limite);
int cliente_PromedioPrecio(Cliente* array,int limite);
