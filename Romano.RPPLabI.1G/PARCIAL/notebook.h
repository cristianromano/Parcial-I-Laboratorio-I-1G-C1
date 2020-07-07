#include "marca.h"
#include "tipo.h"
#include "cliente.h"
#include "estado.h"

#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED



typedef struct{

char modelo[20];
int idMarca;
int idTipo;
int idCliente;
int idEstado;
float precio;
int id;
int isEmpty;


}eNotebook;

void initNotebook(eNotebook notebooks[], int tamNotebook);
void hardcodeoDatosNotebook(eNotebook notebooks[]);
void clean();
void pause();
void limpiarBuffer();
int menu();
int buscarLibreNotebook(eNotebook notebooks[] , int tamNotebook);
void ingresoDatosNotebook(eNotebook notebooks[] , int tamNotebook);
int buscarNotebook(int id, eNotebook notebooks[], int tamNotebook);
int cargarDescripcionNotebook(char descripcion[] , eNotebook notebooks[] , int id , int tamNotebook);

void printNotebook(eNotebook notebooks , eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] ,  int tamCliente,eEstado estados[] , int tamEstado);
void mostrarNotebooks(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] ,  int tamCliente,eEstado estados[] , int tamEstado);
void modificarNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] , int tamCliente,eEstado estados[] , int tamEstado);
void removerNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] , int tamCliente,eEstado estados[] , int tamEstado);



#endif // NOTEBOOK_H_INCLUDED


