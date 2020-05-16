#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{

int dia;
int mes;
int anio;

}eFecha;

typedef struct{

int id;
int idNotebook;
int idServicio;
eFecha fecha;
int isEmpty;


}eTrabajo;

void initTrabajos(eTrabajo trabajos[], int tamTrabajos);
int buscarLibreTrabajos(eTrabajo trabajos[], int tamTrabajos);
void ingresoDatosTrabajo(eTrabajo trabajos[] , int tamTrabajos , eFecha auxFecha[],eNotebook notebooks[],int tamNotebook, eTipo tipos[] , int tamTipo,eMarca marcas[] , int tamMarca , eServicio servicios[] , int tamServicios);
void printTrabajos(eTrabajo trabajos ,eNotebook notebooks[],int tamNotebook , eServicio servicios[] , int tamServicios);
void mostrarTrabajos(eTrabajo trabajos[] , int tamTrabajos ,eNotebook notebooks[],int tamNotebook , eServicio servicios[] , int tamServicios);

#endif // TRABAJO_H_INCLUDED
