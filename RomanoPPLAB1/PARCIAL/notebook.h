#include "marca.h"
#include "tipo.h"


#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED



typedef struct{

char modelo[20];
int idMarca;
int idTipo;
float precio;
int id;
int isEmpty;


}eNotebook;

void initNotebook(eNotebook notebooks[], int tamNotebook);
void hardcodeoDatosNotebook(eNotebook notebooks[] , int tamNotebook);
void clean();
void pause();
void limpiarBuffer();
int menu();
int buscarLibreNotebook(eNotebook notebooks[] , int tamNotebook);
void ingresoDatosNotebook(eNotebook notebooks[] , int tamNotebook);
int buscarNotebook(int id, eNotebook notebooks[], int tamNotebook);
void modificarNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
void printNotebook(eNotebook notebooks , eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
void mostrarNotebooks(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
void removerNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
int cargarDescripcionNotebook(char descripcion[] , eNotebook notebooks[] , int id , int tamNotebook);





#endif // NOTEBOOK_H_INCLUDED


