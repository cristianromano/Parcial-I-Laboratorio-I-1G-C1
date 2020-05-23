#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"
#include "trabajo.h"
#include "cliente.h"


#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void menuDeInformes(eTrabajo trabajos[] , int tamTrabajos ,eNotebook notebooks[],int tamNotebook , eServicio servicios[] , int tamServicios , eMarca marcas[] ,
                    int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] , int tamCliente);


void menuParaInformes();
void informarPrecioXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);

void informeNotebookXTipo(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] , int tamCliente);

void informeNotebookMasBaratas(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);

void informeNotebooKListadoXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] , int tamCliente);

void informarTipoYMarcaNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo,eCliente clientes[] , int tamCliente);

void informeNotebooKListado(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo , eCliente clientes[] , int tamCliente);

void informarMarcaMasBarata(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);

int cargarTotalNotebooks(eNotebook notebooks[], int tam , int idMarca);

void informeMarcaMasElegida(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo);

void informeNotebooGamer(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
void aumentoPrecioMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
float cargarPrecioMarca(int tamNotebooks , eNotebook notebooks[] , int id);
void informarTotalPreciosXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
void informarTotalNotebooksXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);

void informarTrabajoXFecha(eTrabajo trabajos[],int tamTrabajos ,eServicio servicios[] , int tamServicios , eNotebook notebooks[] , int tamNotebook);
void hardcodeoDatosTrabajo(eTrabajo trabajos[]);
void informarTrabajosXServicios(eTrabajo trabajos[],int tamTrabajos ,eServicio servicios[] , int tamServicios , eNotebook notebooks[] , int tamNotebook);

void informarTrabajosXNotebook(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipos , eCliente clientes[] , int tamCliente);

void informarTrabajosXCostos(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipos , eCliente clientes[] , int tamCliente);

#endif // INFORMES_H_INCLUDED
