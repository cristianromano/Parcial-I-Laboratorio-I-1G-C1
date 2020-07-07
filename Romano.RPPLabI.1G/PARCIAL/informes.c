#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
#define TAMESTADO 2

#define TAMTRABAJOS 100

void menuParaInformes()
{


    printf("1.INFORMAR NOTEBOOK X TIPO\n");
    printf("2.INFORMAR NOTEBOOK MAS BARATA\n");
    printf("3.MOSTRAR NOTEBOOK ELEGIDA X MARCA\n");
    printf("4.INFORMAR TOTAL DE NOTEBOOKS SELECCIONANDO TIPO Y MARCA NOTEBOOK\n");
    printf("5.INFORMAR LISTADO SEPARADO NOTEBOOK X MARCA\n");
    printf("6.INFORMAR MARCA MAS ELEGIDA\n");



    printf("7.INFORMAR TRABAJO X FECHA\n");
    printf("8.INFORMAR TRABAJOS X SERVICIO\n");
    printf("9.INFORMAR TRABAJOS X NOTEBOOK\n");
    printf("10.INFORMAR COSTO TOTAL DE TRABAJOS X NOTEBOOK\n");
  //  printf("11.SALIR A MENU PRINCIPAL\n");

    printf("**********************************************\n");
    printf("NUEVAS FUNCIONES RECUPERATORIO PARCIAL 1 / 1G\n");
    printf("**********************************************\n");
        printf("11.INFORMAR PRECIO DE NOTEBOOK X MARCA ELEGIDA\n");
        printf("12.REALIZAR UN AUMENTO DE PRECIO A LA MARCA\n");
        printf("13.INFORMAR MARCA MAS COSTOSA\n");
        printf("14.INFORMAR NETBOOKS GAMERS\n");
        printf("15.INFORMAR TOTAL PRECIOS X MARCA\n");
        printf("16.INFORMAR TOTAL NOTEBOOKS X MARCA\n");
        printf("17.INFORMAR NOTEBOOK X MODELO\n");
        printf("18.INFORMAR TRABAJOS X SERVICIO Y FECHA\n");
        printf("19.SALIR A MENU PRINCIPAL\n");

}


/** \brief es un switch que contiene los informes
 *
 * \param notebooks , tipos , clientes , estados , trabajos
 * \return void
 *
 */

void menuDeInformes(eTrabajo trabajos[], int tamTrabajos,eNotebook notebooks[],int tamNotebook, eServicio servicios[], int tamServicios, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente
                     ,eEstado estado[] , int tamEstado)
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
            informeNotebookXTipo(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);
            break;

        case 2:
            clean();
            informeNotebookMasBaratas(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS);
            break;

        case 3:
            clean();
            informeNotebooKListadoXMarca(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);
            break;

        case 4:
            clean();
            informarTipoYMarcaNotebook(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            break;

        case 5:
            clean();
            informeNotebooKListado(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);
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
            informarTrabajosXNotebook(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);
            break;


        case 10:
            clean();
            informarTrabajosXCostos(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);
            break;

         case 11:
            clean();
            informarPrecioXMarca(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);
            break;

        case 12:
            clean();
            aumentoPrecioMarca(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS);
            break;

        case 13:
            clean();
            informarMarcaMasCostosa(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS);

            break;

        case 14:
            clean();
            informeNotebooGamer(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);

            break;

        case 15:
            clean();
            informarTotalPreciosXMarca(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS);
            break;

         case 16:
            clean();
            informarTotalNotebooksXMarca(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS);
            break;

        case 17:
            clean();
            informeNotebookXModelo(notebooks,TAMNOTEBOOKS,marcas,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estado,TAMESTADO);
            break;

        case 18:
            clean();
            informarTrabajosXServiciosYFecha(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,notebooks,TAMNOTEBOOKS);
            break;

        case 19:
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

/** \brief informa el precio de una notebook seleccionada por marca
 *
 * \param notebooks , tipos , clientes , estados
 * \return void
 *
 */

void informarPrecioXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[] , int tamCliente,eEstado estado[],int tamEstado)
{

    int marca;
    int i;
    int trigger = 0;
    char descripcion[20];
    char desctipo[20];

    printMarcas(marcas,tamMarca);
    printf("ingrese marca de la notebook: ");
    scanf("%d",&marca);

    cargarDescripcionMarcas(descripcion,marcas,marca,tamMarca);

    clean();

    printf("********************************************************\n");
    printf("  MODELO        MARCA        TIPO     PRECIO\n");



    for(i=0; i<tamNotebook; i++)
    {
        if(notebooks[i].idMarca == marca && notebooks[i].isEmpty == 0)
        {
                cargarDescripcionTipos(desctipo,tipos,notebooks[i].idTipo,tamTipo);

                printf("%6s         %5s    %10s    %.2f\n",notebooks[i].modelo,descripcion,desctipo,notebooks[i].precio);

          //   printNotebook(notebooks[i],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente,estado,tamEstado);
             printf("********************************************************\n");
            trigger = 1;
        }

    }


    if(trigger == 0)
    {
        printf("no hay notebooks registrado a esa marca %s\n",descripcion);
    }


}

/** \brief se muestra las notebooks con la marca y el tipo seleccionado
 *
 * \param notebooks , tipos , clientes
 * \return void
 *
 */

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

/** \brief se informa notebook segun el tipo seleccionado
 *
 * \param notebooks , tipos , clientes , estados
 * \return void
 *
 */

void informeNotebookXTipo(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente,eEstado estados[] , int tamEstado)
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
            printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente,estados,tamEstado);
            trigger = 1;
        }
    }


    if(trigger == 0)
    {
        printf("no hay notebooks de ese tipo.\n");
    }

    printf("*************************************************************************************************\n");


}

/** \brief informa notebooks x modelo seleccionado
 *
 * \param notebooks , tipos , clientes , estados
 * \return void
 *
 */

void informeNotebookXModelo(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente,eEstado estados[] , int tamEstado)
{
    int  j;
    int trigger = 0;
    char modelo[20];

    printf("MODELOS:\n1.ROJO\n2.AZUL\n3.VERDE\n4.AMARILLO\n");
    printf("ingrese modelo de la notebook: ");
    limpiarBuffer();
    gets(modelo);


    clean();
    printf("*************************************************************************************************\n");
    printf(" NOMBRE         ID      MODELO        MARCA        TIPO     PRECIO    ESTADO\n");

    for(j=0; j<tamNotebook; j++)
    {
        if( (strcmp(notebooks[j].modelo , modelo)==0) && notebooks[j].isEmpty == 0)
        {
            printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente,estados,tamEstado);
            trigger = 1;
        }
    }


    if(trigger == 0)
    {
        printf("no hay notebooks de ese modelo.\n");
    }

    printf("*************************************************************************************************\n");


}

/** \brief informa la notebook mas barata
 *
 * \param notebooks , tipos , marca
 * \return void
 */


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
                printf("La notebook mas baratas es de la marca %s , vale: %.2f\n",nombre,menor);
            }

        }

    }


    if(trigger == 0)
    {
        printf("no hay notebooks de ese tipo.\n");
    }

    printf("*************************************************************************************************\n");



}

/** \brief informa la marca mas elegida
 *
 * \param notebooks , tipos , marca
 * \return void
 *
 */


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



/** \brief lista notebooks por marca
 *
 * \param notebooks , tipos , clientes , estados
 * \return void
 */

void informeNotebooKListado(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo
                            , eCliente clientes[], int tamCliente,eEstado estado[],int tamEstado)
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

                printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente,estado,tamEstado);
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

/** \brief lista una marca seleccionada de notebooks
 *
 * \param notebooks , tipos , clientes , estados
 * \return void
 *
 */


void informeNotebooKListadoXMarca(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamCliente,eEstado estado[] , int tamEstado)
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

            printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente,estado,tamEstado);
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

/** \brief lista notebooks gamers unicamente
 *
 * \param notebooks , tipos , clientes , estados
 * \return void
 *
 */

void informeNotebooGamer(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[] , int tamCliente,eEstado estado[],int tamEstado)
{

    int j;
    int trigger;


    // printf("**********************************************************************************\n");

    printf("NOTEBOOK GAMERS\n");

    printf("**********************************************************************************\n");
    printf(" NOMBRE         ID      MODELO        MARCA        TIPO     PRECIO    ESTADO\n");

    trigger = 0;
    for(j=0; j<tamNotebook; j++)
    {
        if(notebooks[j].idTipo == 5000 && notebooks[j].isEmpty == 0)
        {

                  printNotebook(notebooks[j],marcas,tamMarca,tipos,tamTipo,clientes,tamCliente,estado,tamEstado);
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

/** \brief realiza un aumento de precio a la marca seleccionada
 *
 * \param notebooks , tipos , marca
 * \return void
 *
 */

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


/** \brief informa la marca mas barata
 *
 * \param notebooks , tipos , marca
 * \return void
 *
 */

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

/** \brief informa marca mas costosa
 * \param notebooks , tipos , marca
 * \return void
 *
 */


void informarMarcaMasCostosa(eNotebook notebooks[],int tamNotebook,eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo)
{


    float marcaMasCostosa[tamMarca];
    float mayor;
    int trigger = 0;
    char descripcion[20];
    int i;


    for(i=0; i<tamMarca; i++)
    {
        marcaMasCostosa[i] = cargarPrecioMarca(tamNotebook,notebooks,marcas[i].id);

    }

    for(i=0; i<tamMarca; i++)
    {
        if(marcaMasCostosa[i] > mayor || trigger == 0)
        {
            mayor = marcaMasCostosa[i];
            trigger = 1;

        }

    }

    if(trigger == 1)
    {
        printf("la marca mas costosa es/son: \n");

        for(i=0; i<tamMarca; i++)
        {
            if(marcaMasCostosa[i] == mayor && notebooks[i].isEmpty == 0)
            {
                cargarDescripcionMarcas(descripcion,marcas,marcas[i].id,tamMarca);
                printf("%d.%s acumulando un total de %.2f \n",marcas[i].id,descripcion,mayor);
            }
        }
    }



}



/** \brief informa el total de precios de las marcas
 *
 * \param notebooks , tipos , marca
 * \return void
 *
 */

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

/** \brief informa el total de notebook x marca
 *
 * \param notebooks , tipos , clientes , estados
 * \return void
 *
 */

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
            printf("no hay notebooks de esta marca.\n");
        }

        printf("*************************************************************************************************\n");




    }



}

/** \brief informa trabajo x fecha
 *
 * \param trabajos , servicios , notebook
 * \return void
 *
 */

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

/** \brief informa trabajo x servicio seleccionado
 *
 * \param trabajos , servicios , notebook
 * \return void
 */

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

/** \brief informa trabajo x servicio y fecha seleccionados
 *
 * \param trabajos , servicios , notebook
 * \return void
 *
 */

void informarTrabajosXServiciosYFecha(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook)
{
     int servicio;
     int anio;
     int trigger = 0;
     int i;
     char servicioDes[20];

    printServicios(servicios,tamServicios);
    printf("ingrese ID de servicio: ");
    scanf("%d",&servicio);

    printf("ingrese anio para ver los servicios del mismo: ");
    scanf("%d",&anio);

    printf("**********************************************************************************\n");
    printf("  ID  TRABAJO   ID NOTEBOOK       MODELO       SERVICIO     FECHA    \n");
    for(i=0; i<tamTrabajos; i++)
    {

        if(trabajos[i].idServicio == servicio && trabajos[i].fecha.anio == anio && trabajos[i].isEmpty == 0)
        {
            printTrabajos(trabajos[i],notebooks,tamNotebook,servicios,tamServicios);
            trigger = 1;
        }


    }

    if(trigger == 0)
    {
        cargarDescripcionServicios(servicioDes,servicios,servicio,tamServicios);
        printf("no hubo servicio de: %s en el anio %d registrados\n",servicioDes,anio);
    }

    printf("**********************************************************************************\n");
}






/** \brief informar trabajos x ID notebook seleccionada
 *
 * \param trabajos , servicios , notebook , marca , tipo , cliente , estado
 * \return void
 */


void informarTrabajosXNotebook(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[] , int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipos , eCliente clientes[] , int tamCliente,eEstado estado[] , int tamEstado)
{
    int i;
    int notebook;
    int trigger = 0;


   mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarcas,tipos,tamTipos,clientes,tamCliente,estado,tamEstado);
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

/** \brief informa costo total del trabajo de una ID notebook seleccionada
 *
 * \param trabajos , servicios , notebook , marca , tipo , cliente , estado
 * \return void
 *
 */

void informarTrabajosXCostos(eTrabajo trabajos[],int tamTrabajos,eServicio servicios[], int tamServicios, eNotebook notebooks[], int tamNotebook, eMarca marcas[], int tamMarcas, eTipo tipos[], int tamTipos , eCliente clientes[] , int tamCliente,eEstado estado[] , int tamEstado)
{
    int i, j;
    int notebook;
    int trigger = 0;
    float acumulador = 0;


    mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarcas,tipos,tamTipos,clientes,tamCliente,estado,tamEstado);
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

