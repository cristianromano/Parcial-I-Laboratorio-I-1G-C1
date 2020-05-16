#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicios.h"
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "trabajo.h"


void printServicios(eServicio servicios[] , int tamServicios)
{


  int i;

  printf("ID    SERVICIOS     PRECIOS\n");
  for(i=0;i<tamServicios;i++)
  {

     printf("%d     %s      %.2f\n",servicios[i].id,servicios[i].servicios,servicios[i].precios);

  }

}


int cargarDescripcionServicios(char descripcion[] , eServicio servicios[] , int id , int tamServicios)
{

    int i , retorno;

    retorno = -1;

    for(i=0;i<tamServicios;i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion,servicios[i].servicios);
            retorno = 1;
        }

    }

    return retorno;





}
