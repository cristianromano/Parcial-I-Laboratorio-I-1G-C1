#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "informes.h"
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"
#include "trabajo.h"
#include "cliente.h"



#define TAMMARCA 4
#define TAMTIPOS 4
#define TAMSERVICIOS 4
#define TAMNOTEBOOKS 100
#define TAMCLIENTES 5

#define TAMTRABAJOS 100

void menuParaInformes()
{

//   printf("1.INFORMAR PRECIO DE NOTEBOOK X MARCA\n");
    printf("1.INFORMAR NOTEBOOK X TIPO\n");
    printf("2.INFORMAR NOTEBOOK MAS BARATA X MARCA\n");
    printf("3.INFORMAR NOTEBOOK X MARCA\n");
    printf("4.INFORMAR SELECCIONANDO TIPO Y MARCA NOTEBOOK\n");
    printf("5.INFORMAR LISTADO SEPARADO NOTEBOOK X MARCA\n");
    printf("6.INFORMAR MARCA MAS ELEGIDA\n");

    /* printf("6.REALIZAR UN AUMENTO DE PRECIO A LA MARCA\n");
     printf("7.INFORMAR MARCA MAS COSTOSA\n");
     printf("8.INFORMAR TOTAL PRECIOS X MARCA\n");
     printf("9.INFORMAR NOTEBOOKS X MARCA\n");*/

    printf("7.INFORMAR TRABAJO X FECHA\n");
    printf("8.INFORMAR TRABAJOS X SERVICIO\n");
    printf("9.INFORMAR TRABAJOS X NOTEBOOK\n");
    printf("10.INFORMAR COSTO TOTAL DE TRABAJOS X NOTEBOOK\n");
    printf("11.SALIR A MENU PRINCIPAL\n");

}

void menuDeInformes(eTrabajo trabajos[], int tamTrabajos,eNotebook notebooks[],int tamNotebook, eServicio servicios[], int tamServicios, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente)
{
    int numero = 0;
    char seguir = 's';



    do
    {

        menuParaInformes();
        printf("ingrese opcion: ");
        scanf("%d",&numero);

        switch(numero)
        {
        case 1:
            clean();
            informeNotebookXTipo(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            break;

        case 2:
            clean();
            informeNotebookMasBaratas(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS);
            break;

        case 3:
            clean();
            informeNotebooKListadoXMarca(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            break;

        case 4:
            clean();
            informarTipoYMarcaNotebook(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            break;

        case 5:
            clean();
            informeNotebooKListado(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            break;

         case 6:
            clean();
            informeMarcaMasElegida(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS);
            break;

        case 7:
            clean();
            informarTrabajoXFecha(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,notebooks,TAMNOTEBOOKS);
            break;

        case 8:
            clean();
            informarTrabajosXServicios(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,notebooks,TAMNOTEBOOKS);
            break;

        case 9:
            clean();
            informarTrabajosXNotebook(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            break;


        case 10:
            clean();
            informarTrabajosXCostos(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            break;

        case 11:
            seguir = 'n';
            break;

        default:
            printf("no es una opcion.\n");
            break;

        }

        pause();
        clean();

    }
    while(seguir=='s');


}


void informarPrecioXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{

    int marca;
    int i;
    int trigger = 0;
    char descripcion[20];

    printMarcas(marcas,tamMarca);
    printf("ingrese marca de la notebook: ");
    scanf("%d",&marca);

    cargarDescripcionMarcas(descripcion,marcas,marca,tamMarca);

    clean();

    printf("**********************************************************************************\n");
    printf(" NOMBRE         ID      MODELO        MARCA        TIPO     PRECIO\n");



    for(i=0; i<tamNotebook; i++)
    {
        if(notebooks[i].idMarca == marca && notebooks[i].isEmpty == 0)
        {
            // printNotebook(notebooks[i],marcas,tamMarca,tipos,tamTipo);
            printf("**********************************************************************************\n");
            trigger = 1;
        }

    }


    if(trigger == 0)
    {
        printf("no hay notebooks registrado a esa marca %s\n",descripcion);
    }


}

void informarTipoYMarcaNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo,eCliente clientes[], int tamCliente)
{

    int marca;
    int tipo;
    int i;
    int trigger = 0;
    char descripcion[20];
    char descripcionTipo[20];
    int contador = 0;

    printMarcas(marcas,tamMarca);
    printf("ingrese marca de la notebook: ");
    scanf("%d",&marca);

    printTipo(tipos,tamTipo);
    printf("ingrese tipo de la notebook: ");
    scanf("%d",&tipo);


    cargarDescripcionMarcas(descripcion,marcas,marca,tamMarca);
    cargarDescripcionTipos(descripcionTipo,tipos,tipo,tamTipo);

    clean();

    printf("**********************************************************************************\n");


    for(i=0; i<tamNotebook; i++)
    {
        if(notebooks[i].idMarca == marca && notebooks[i].idTipo == tipo && notebooks[i].isEmpty == 0)
        {
            contador++;
            // printf("**********************************************************************************\n");
            trigger = 1;
        }

    }

    if(trigger == 1)
    {
        printf("en total son: %d de la marca %s con el tipo %s\n",contador,descripcion,descripcionTipo);
        printf("**********************************************************************************\n");
    }

    if(trigger == 0)
    {
        printf("no hay notebooks registrado a esa marca %s con el tipo %s\n",descripcion,descripcionTipo);
    }


}


void informeNotebookXTipo(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente)
{
    int  j;
    int trigger = 0;
    int tipo;

    printTipo(tipos,tamTipo);
    printf("ingrese tipo de la notebook: ");
    scanf("%d",&tipo);


    clean();
    printf("*************************************************************************************************\n");
    printf(" NOMBRE         ID      MODELO        MARCA        TIPO     PRECIO\n");

    for(j=0; j<tamNotebook; j++)
    {
        if(notebooks[j].idTipo == tipo && notebooks[j].isEmpty == 0)
        {
            printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente);
            trigger = 1;
        }
    }


    if(trigger == 0)
    {
        printf("no hay notebooks de ese tipo.\n");
    }

    printf("*************************************************************************************************\n");


}


void informeNotebookMasBaratas(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{

    int j;
    int trigger = 0;
    float menor;
    char nombre[20];


    for(j=0; j<tamNotebook; j++)
    {
        if(notebooks[j].isEmpty == 0)
        {
            if(notebooks[j].precio < menor || trigger == 0)
            {

                menor = notebooks[j].precio;
                trigger = 1;

            }

        }

    }


    if(trigger == 1)
    {
        printf("*************************************************************************************************\n");

        for(j=0; j<tamNotebook; j++)
        {
            if(notebooks[j].precio == menor && notebooks[j].isEmpty == 0)
            {
                cargarDescripcionMarcas(nombre,marcas,notebooks[j].idMarca,tamMarca);
                printf("La notebook mas baratas de la marca %s , vale: %.2f\n",nombre,menor);
            }

        }

    }


    if(trigger == 0)
    {
        printf("no hay notebooks de ese tipo.\n");
    }

    printf("*************************************************************************************************\n");



}


void informeMarcaMasElegida(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{

float cantidadNotebooks[tamMarca];
float mayor;
int trigger = 0;
char descripcion[20];
int i;


for(i=0;i<tamMarca;i++)
{
    cantidadNotebooks[i] = cargarTotalNotebooks(notebooks,tamNotebook,marcas[i].id);


}

for(i=0;i<tamMarca;i++)
{
    if(cantidadNotebooks[i] > mayor || trigger == 0)
    {
        mayor = cantidadNotebooks[i];
        trigger = 1;

    }

}

if(trigger == 1)
{
     printf("las marcas mas elegidas son: \n");

    for(i=0;i<tamMarca;i++)
    {
        if(cantidadNotebooks[i] == mayor && notebooks[i].isEmpty == 0)
        {
            cargarDescripcionMarcas(descripcion,marcas,marcas[i].id,tamMarca);
            printf("%d.%s\n",marcas[i].id,descripcion);
        }
    }
}




}




void informeNotebooKListado(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente)
{

    int i, j;
    int trigger;

    for(i=0; i<tamMarca; i++)
    {

        // printf("**********************************************************************************\n");

        printf("MARCA %s\n",marcas[i].marca);

        printf("**********************************************************************************\n");
        printf(" NOMBRE         ID      MODELO        MARCA        TIPO     PRECIO\n");

        trigger = 0;
        for(j=0; j<tamNotebook; j++)
        {
            if(notebooks[j].idMarca == marcas[i].id && notebooks[j].isEmpty == 0)
            {

                printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente);
                trigger = 1;
                //  printf("**********************************************************************************\n");

            }
        }

        if(trigger == 0)
        {
            printf("no hay notebooks de ese tipo.\n");
        }

        printf("**********************************************************************************\n");
    }


}

void informeNotebooKListadoXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente)
{

    int  j;
    int trigger;
    int marca;

    printMarcas(marcas,tamMarca);
    printf("ingrese marca de la notebook: ");
    scanf("%d",&marca);


    printf("**********************************************************************************\n");
    printf(" NOMBRE         ID      MODELO        MARCA        TIPO     PRECIO\n");

    trigger = 0;
    for(j=0; j<tamNotebook; j++)
    {
        if(notebooks[j].idMarca == marca && notebooks[j].isEmpty == 0)
        {

            printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente);
            trigger = 1;
            //  printf("**********************************************************************************\n");

        }
    }

    if(trigger == 0)
    {
        printf("no hay notebooks de ese tipo.\n");
    }

    printf("**********************************************************************************\n");


}


void informeNotebooGamer(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{

    int j;
    int trigger;


    // printf("**********************************************************************************\n");

    printf("NOTEBOOK GAMERS\n");

    printf("**********************************************************************************\n");
    printf("  ID      MODELO        MARCA        TIPO     PRECIO\n");

    trigger = 0;
    for(j=0; j<tamNotebook; j++)
    {
        if(notebooks[j].idTipo == 5000 && notebooks[j].isEmpty == 0)
        {

            //      printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo);
            trigger = 1;
            //  printf("**********************************************************************************\n");

        }
    }

    if(trigger == 0)
    {
        printf("no hay notebooks de ese tipo.\n");
    }

    printf("**********************************************************************************\n");


}

void aumentoPrecioMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{

    int i;
    char descripcion[20];
    float aumento;
    int porcentaje;
    int numero;
    int trigger = 0;

    printMarcas(marcas,tamMarca);
    printf("Ingrese ID de la marca: ");
    scanf("%d",&numero);
    printf("Ingrese el aumento a la marca: ");
    scanf("%d",&porcentaje);

    cargarDescripcionMarcas(descripcion,marcas,numero,tamMarca);

    for(i=0; i<tamNotebook; i++)
    {

        if(notebooks[i].idMarca == numero)
        {

            aumento = (notebooks[i].precio * porcentaje)/100;

            notebooks[i].precio += aumento;

            trigger = 1;


        }


    }

    if(trigger==1)
    {
        printf("realizado con exito.\n");
    }

    if(trigger==0)
    {
        printf("\nlamentablemente no hay notebooks de la marca %s\n",descripcion);
    }


}



void informarMarcaMasBarata(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{


    float marcaMasBarata[tamMarca];
    float menor;
    int trigger = 0;
    char descripcion[20];
    int i;


    for(i=0; i<tamMarca; i++)
    {
        marcaMasBarata[i] = cargarPrecioMarca(tamNotebook,notebooks,marcas[i].id);

    }

    for(i=0; i<tamMarca; i++)
    {
        if(marcaMasBarata[i] < menor || trigger == 0)
        {
            menor = marcaMasBarata[i];
            trigger = 1;

        }

    }

    if(trigger == 1)
    {
        printf("la marca mas barata son: \n");

        for(i=0; i<tamMarca; i++)
        {
            if(marcaMasBarata[i] == menor && notebooks[i].isEmpty == 0)
            {
                cargarDescripcionMarcas(descripcion,marcas,marcas[i].id,tamMarca);
                printf("%d.%s con %.2f total\n",marcas[i].id,descripcion,menor);
            }
        }
    }



}


void informarTotalPreciosXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{

    float totalPrecio[tamMarca];
    int trigger = 0;
    int i, j;


    for(i=0; i<tamMarca; i++)
    {
        totalPrecio[i] = cargarPrecioMarca(tamNotebook,notebooks,marcas[i].id);

    }


    for(i=0; i<tamMarca; i++)
    {

        // printf("**********************************************************************************\n");

        printf("**********************************************************************************\n");
        printf("PRECIO TOTAL DE LA MARCA %s: ",marcas[i].marca);

        trigger = 0;
        for(j=0; j<tamNotebook; j++)
        {
            if(notebooks[j].idMarca == marcas[i].id && notebooks[j].isEmpty == 0)
            {

                printf("%.2f\n",totalPrecio[i]);
                trigger = 1;
                break;
                //  printf("**********************************************************************************\n");

            }
        }

        if(trigger == 0)
        {
            printf("no hay notebooks de ese tipo.\n");
        }

        printf("**********************************************************************************\n");
    }


}


void informarTotalNotebooksXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{
    int i, j;
    int trigger;
    int acumulador = 0;

    for(i=0; i<tamMarca; i++)
    {

        printf("MARCA %s\n",marcas[i].marca);

        acumulador = 0;
        trigger = 0;
        for(j=0; j<tamNotebook; j++)
        {
            if(notebooks[j].idMarca == marcas[i].id && notebooks[j].isEmpty == 0)
            {
                acumulador++;
                trigger = 1;
            }
        }


        if(trigger==1)
        {
            printf("el total de notebooks de la marca %s es de: %d\n",marcas[i].marca,acumulador);
        }


        if(trigger == 0)
        {
            printf("no hay empleados en ese sector.\n");
        }

        printf("*************************************************************************************************\n");




    }



}

void informarTrabajoXFecha(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook)
{
    int i;
    int anio;
    int trigger = 0;



    printf("ingrese anio para ver los servicios del mismo: ");
    scanf("%d",&anio);


    printf("**********************************************************************************\n");
    printf("  ID  TRABAJO   ID NOTEBOOK       MODELO       SERVICIO     FECHA    \n");
    for(i=0; i<tamTrabajos; i++)
    {

        if(trabajos[i].fecha.anio == anio && trabajos[i].isEmpty == 0)
        {
            printTrabajos(trabajos[i],notebooks,tamNotebook,servicios,tamServicios);
            trigger = 1;
        }


    }

    if(trigger == 0)
    {
        printf("no hay trabajos registrados del anio %d\n",anio);
    }



}


void informarTrabajosXServicios(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook)
{
    int i;
    int servicio;
    int trigger = 0;


    printServicios(servicios,tamServicios);
    printf("ingrese ID de servicio: ");
    scanf("%d",&servicio);


    printf("**********************************************************************************\n");
    printf("  ID  TRABAJO   ID NOTEBOOK       MODELO       SERVICIO     FECHA    \n");
    for(i=0; i<tamTrabajos; i++)
    {

        if(trabajos[i].idServicio == servicio && trabajos[i].isEmpty == 0)
        {
            printTrabajos(trabajos[i],notebooks,tamNotebook,servicios,tamServicios);
            trigger = 1;
        }


    }

    if(trigger == 0)
    {
        printf("no hay servicios de ese tipo registrados\n");
    }
}

void informarTrabajosXNotebook(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipos , eCliente clientes[] , int tamCliente)
{
    int i;
    int notebook;
    int trigger = 0;


   mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarcas,tipos,tamTipos,clientes,tamCliente);
    printf("ingrese ID de notebook: ");
    scanf("%d",&notebook);


    printf("**********************************************************************************\n");
    printf("  ID  TRABAJO   ID NOTEBOOK       MODELO       SERVICIO     FECHA    \n");
    for(i=0; i<tamTrabajos; i++)
    {

        if(trabajos[i].idNotebook == notebook && trabajos[i].isEmpty == 0)
        {
            printTrabajos(trabajos[i],notebooks,tamNotebook,servicios,tamServicios);
            trigger = 1;
        }


    }

    if(trigger == 0)
    {
        printf("no hay servicios realizados a esta notebook\n");
    }
}

void informarTrabajosXCostos(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipos , eCliente clientes[] , int tamCliente)
{
    int i, j;
    int notebook;
    int trigger = 0;
    float acumulador = 0;


    mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarcas,tipos,tamTipos,clientes,tamCliente);
    printf("ingrese ID de notebook: ");
    scanf("%d",&notebook);


    printf("**********************************************************************************\n");
    for(i=0; i<tamTrabajos; i++)
    {

        if(trabajos[i].idNotebook == notebook && trabajos[i].isEmpty == 0)
        {

            for(j=0; j<tamServicios; j++)
            {
                if(trabajos[i].idServicio == servicios[j].id)
                {
                    acumulador += servicios[j].precios;
                    trigger = 1;
                }

            }

        }
    }

    if(trigger == 1)
    {
        printf("total acumulado de los servicios de la notebook ID: %d son: %.2f\n",notebook,acumulador);
    }

    if(trigger == 0)
    {
        printf("no hay servicios realizados a esta notebook\n");
    }
}

float cargarPrecioMarca(int tamNotebooks, eNotebook notebooks[], int id)
{

    int i;
    float acumulador = 0;


    for(i=0; i<tamNotebooks; i++)
    {
        if(notebooks[i].idMarca == id && notebooks[i].isEmpty == 0)
        {
            acumulador += notebooks[i].precio;
        }
    }


    return acumulador;

}



int cargarTotalNotebooks(eNotebook notebooks[], int tamNotebooks , int idMarca)
{

    int i;
    int contador = 0;

        for(i=0;i<tamNotebooks;i++)
        {
            if(notebooks[i].idMarca == idMarca && notebooks[i].isEmpty ==0)
            {
                contador++;
            }
        }


    return contador;


}

