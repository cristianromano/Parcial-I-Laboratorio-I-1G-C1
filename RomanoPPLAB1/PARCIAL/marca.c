#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"
#include "trabajo.h"





void printMarcas(eMarca marcas[] , int tamMarcas)
{

  int i;

  printf("ID    MARCAS\n");
  for(i=0;i<tamMarcas;i++)
  {

     printf("%d     %s\n",marcas[i].id,marcas[i].marca);

  }

}

int cargarDescripcionMarcas(char descripcion[] , eMarca marcas[] , int id , int tamMarcas)
{

    int i , retorno;

    retorno = -1;

    for(i=0;i<tamMarcas;i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion,marcas[i].marca);
            retorno = 1;
        }

    }

    return retorno;

}
