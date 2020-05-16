#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hardcodeoDatos.h"
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"
#include "trabajo.h"


static int generarIdNotebook()
{
	static int contadorId=100;
	contadorId++;
	return contadorId;
}


void clean()
{
    system("cls");
}

void pause()
{
    system("pause");
}

void limpiarBuffer()
{
    fflush(stdin);
}


void initNotebook(eNotebook notebooks[], int tamNotebook)
{
    int i;

    for(i=0; i<tamNotebook; i++)
    {
        notebooks[i].isEmpty = 1;

    }
}


void hardcodeoDatosNotebook(eNotebook notebooks[] , int tamNotebook)
{

int i;



    for(i=0 ; i<tamNotebook ; i++)
    {

        strcpy(notebooks[i].modelo,modelos[i]);
        limpiarBuffer();
        notebooks[i].id = ids[i];
        notebooks[i].idMarca = idMarca[i];
        notebooks[i].idTipo = idTipo[i];
        notebooks[i].precio = precios[i];
         notebooks[i].isEmpty = 0;

    }

}

int menu()
{

    int opcion = 0;

    printf("1.INGRESAR NOTEBOOK\n");
    printf("2.MODIFICAR NOTEBOOK\n");
    printf("3.LISTAR NOTEBOOK\n");
    printf("4.REMOVER NOTEBOOK\n");
    printf("5.LISTAR MARCAS\n");
    printf("6.LISTAR TIPOS\n");
    printf("7.LISTAR SERVICIOS\n");
    printf("8.INGRESAR TRABAJOS\n");
    printf("9.MOSTRAR TRABAJOS\n");
    printf("10.SALIR\n");


    printf("eliga una opcion: ");
    scanf("%d",&opcion);

    return opcion;


}

int buscarLibreNotebook(eNotebook notebooks[] , int tamNotebook)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamNotebook; i++)
    {
        if(notebooks[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }

    return retorno;

}

void ingresoDatosNotebook(eNotebook notebooks[] , int tamNotebook)
{

    int i = 0;
    int indice;
    int id = generarIdNotebook();

    indice = buscarLibreNotebook(notebooks,tamNotebook);

    if(indice == -1)
    {
        printf("NO HAY MAS LUGAR.");
    }

    else
    {

       /* printf("%d.ingrese ID: ",i+1);
        scanf("%d",&emp[indice].id);
        fflush(stdin);*/



        printf("%d.ingrese modelo: ",i+1);
        fflush(stdin);
        gets(notebooks[indice].modelo);
        fflush(stdin);

        printf("%d.ingrese idMarca: ",i+1);
        scanf("%d",&notebooks[indice].idMarca);
        fflush(stdin);

        printf("%d.ingrese idTipo: ",i+1);
        scanf("%d",&notebooks[indice].idTipo);
        fflush(stdin);

        printf("%d.ingrese precio: ",i+1);
        scanf("%f",&notebooks[indice].precio);
        fflush(stdin);

        fflush(stdin);

        notebooks[indice].id = id;

        notebooks[indice].isEmpty = 0;


        printf("\n");
    }

}

int buscarNotebook(int id, eNotebook notebooks[], int tamNotebook)
{
    int i;
    int retorno = -1;

    for(i=0; i<tamNotebook; i++)
    {
        if(notebooks[i].id == id && notebooks[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }



    return retorno;

}



void printNotebook(eNotebook notebooks , eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{

    char descripcionMarca[20];
    char descripcionTipo[20];

    cargarDescripcionMarcas(descripcionMarca,marcas,notebooks.idMarca,tamMarca);
    cargarDescripcionTipos(descripcionTipo,tipos,notebooks.idTipo,tamTipo);

    printf("  %d  %10s %10s   %10s    %.2f   \n",notebooks.id,notebooks.modelo,descripcionMarca,descripcionTipo,notebooks.precio);



}


void mostrarNotebooks(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{
    int trigger = 0;
    int i;

    printf("**********************************************************************************\n");
    printf("  ID      MODELO        MARCA        TIPO     PRECIO\n");
    for(i=0; i<tamNotebook; i++)
    {

        if(notebooks[i].isEmpty == 0)
        {
            printNotebook(notebooks[i],marcas,tamMarca,tipos,tamTipo);
            trigger = 1;
        }


    }

    if(trigger==0)
    {
        printf("no hay notebooks.\n");
    }

}





void modificarNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{
    int numero = 0;
    int id = 0;
    float precio;
    float tipo;

    char respuesta;

    mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarca,tipos,tamTipo);

    printf("\ningrese el ID de la notebook a modificar: ");
    scanf("%d",&numero);
    limpiarBuffer();


    if((id = buscarNotebook(numero,notebooks,tamNotebook)) < 0)
    {
        printf("\nno se encontro empleado.\n");

    }

    else
    {
        printf("usuario encontrado.\n");
        pause();
        clean();

        printf("MODIFICAR:\n1.Precio\n2.Tipo\neliga una opcion: ");
        scanf("%d",&numero);

        switch(numero)
        {

        case 1:
            printf("ingrese nuevo precio: ");
            scanf("%f",&precio);

            printf("esta seguro?: ");
            limpiarBuffer();
            scanf("%c",&respuesta);
            limpiarBuffer();

            if(respuesta=='s' || respuesta=='S')
            {

                notebooks[id].precio = precio;
                printf("cambio realizado.\n");

            }

            else
            {
                printf("ningun cambio fue realizado.\n");
            }

            break;

        case 2:
            printf("ingrese nuevo idTipo: ");
            scanf("%f",&tipo);

            printf("esta seguro?: ");
            limpiarBuffer();
            scanf("%c",&respuesta);
            limpiarBuffer();

            if(respuesta=='s' || respuesta=='S')
            {

                notebooks[id].idTipo = tipo;
                printf("cambio realizado.\n");

            }

            else
            {
                printf("ningun cambio fue realizado.\n");
            }

            break;


        default:
            printf("no es una opcion valida.\n");
            break;

        }

    }


    printf("\n");


}


void removerNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{
    int numero = 0;
    int id = 0;
    char respuesta;

    mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarca,tipos,tamTipo);

    printf("ingrese ID de notebook a remover: ");
    scanf("%d",&numero);

    if((id = buscarNotebook(numero,notebooks,tamNotebook)<0))
    {
        printf("no se encontro el ID\n");
    }

    else
    {

        printf("seguro desea remover a la notebook? %s:",notebooks[id].modelo);
        limpiarBuffer();
        scanf("%c",&respuesta);
        limpiarBuffer();

        if(respuesta=='s' || respuesta=='S')
        {
            notebooks[id].isEmpty = 1;
            printf("empleado removido.\n");
        }
        else
        {
            printf("ningun cambio fue realizado.\n");
        }
    }

    printf("\n");

}


int cargarDescripcionNotebook(char descripcion[] , eNotebook notebooks[] , int id , int tamNotebook)
{

    int i , retorno;

    retorno = -1;

    for(i=0;i<tamNotebook;i++)
    {
        if(notebooks[i].id == id)
        {
            strcpy(descripcion,notebooks[i].modelo);
            retorno = 1;
        }

    }

    return retorno;

}
