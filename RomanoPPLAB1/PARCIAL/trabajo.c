#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "trabajo.h"
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"



static int generarIdTrabajos()
{
	static int contadorId=600;
	contadorId++;
	return contadorId;
}

void initTrabajos(eTrabajo trabajos[], int tamTrabajos)
{
    int i;

    for(i=0; i<tamTrabajos; i++)
    {
        trabajos[i].isEmpty = 1;

    }
}

int buscarLibreTrabajos(eTrabajo trabajos[], int tamTrabajos)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamTrabajos; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }

    return retorno;

}


void ingresoDatosTrabajo(eTrabajo trabajos[] , int tamTrabajos , eFecha auxFecha[],eNotebook notebooks[],int tamNotebook, eTipo tipos[] , int tamTipo,eMarca marcas[] , int tamMarca , eServicio servicios[] , int tamServicios)
{

    int i = 0;
    int indice;
    int id = generarIdTrabajos();

    indice = buscarLibreTrabajos(trabajos,tamTrabajos);

    if(indice == -1)
    {
        printf("NO HAY MAS LUGAR.");
    }

    else
    {

        mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarca,tipos,tamTipo);
        printf("%d.ingrese idNotebook: ",i+1);
        scanf("%d",&trabajos[indice].idNotebook);
        fflush(stdin);

       printServicios(servicios,tamServicios);
        printf("%d.ingrese idServicio: ",i+1);
        scanf("%d",&trabajos[indice].idServicio);
        fflush(stdin);

        printf("%d.ingrese fecha de entrada xx/xx/xxxx: \n",i+1);
        scanf("%d/%d/%d",&auxFecha[indice].dia,&auxFecha[indice].mes,&auxFecha[indice].anio);
        fflush(stdin);

        trabajos[indice].fecha = auxFecha[indice];
        fflush(stdin);

        trabajos[indice].id = id;
        fflush(stdin);

        trabajos[indice].isEmpty = 0;
        fflush(stdin);


        printf("\n");
    }

}


void printTrabajos(eTrabajo trabajos , eNotebook notebooks[],int tamNotebook , eServicio servicios[] , int tamServicios)
{

    char descripcionNotebook[20];
    char descripcionServicio[20];

    cargarDescripcionNotebook(descripcionNotebook,notebooks,trabajos.idNotebook,tamNotebook);
    cargarDescripcionServicios(descripcionServicio,servicios,trabajos.idServicio,tamServicios);

    printf("%d   %10s %10s  %d/%d/%d \n",trabajos.id,descripcionNotebook,descripcionServicio,trabajos.fecha.dia,trabajos.fecha.mes,trabajos.fecha.anio);



}

void mostrarTrabajos(eTrabajo trabajos[] , int tamTrabajos ,eNotebook notebooks[],int tamNotebook , eServicio servicios[] , int tamServicios)
{
    int trigger = 0;
    int i;

    printf("**********************************************************************************\n");
    printf("  ID TRABAJO     MODELO       SERVICIO     FECHA    \n");
    for(i=0; i<tamTrabajos; i++)
    {

        if(trabajos[i].isEmpty == 0)
        {
            printTrabajos(trabajos[i],notebooks,tamNotebook,servicios,tamServicios);
            trigger = 1;
        }


    }

    if(trigger==0)
    {
        printf("no hay trabajos.\n");
    }

}
