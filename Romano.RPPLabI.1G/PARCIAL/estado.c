#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"
#include "trabajo.h"
#include "informes.h"
#include "cliente.h"



void printEstado(eEstado estado[] , int tamEstado)
{

  int i;

  printf("ID       Estado\n");
  for(i=0;i<tamEstado;i++)
  {

     printf("%d     %s\n",estado[i].id,estado[i].estado);

  }

}

int cargarDescripcionEstado(char descripcion[] , eEstado estado[] , int id , int tamEstado)
{

    int i , retorno;

    retorno = -1;

    for(i=0;i<tamEstado;i++)
    {
        if(estado[i].id == id)
        {
            strcpy(descripcion,estado[i].estado);
            retorno = 1;
        }

    }

    return retorno;

}
