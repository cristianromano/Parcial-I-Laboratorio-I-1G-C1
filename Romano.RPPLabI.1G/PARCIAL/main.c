#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"
#include "trabajo.h"
#include "informes.h"
#include "cliente.h"
#include "estado.h"


#define TAMMARCA 4
#define TAMTIPOS 4
#define TAMSERVICIOS 4
#define TAMNOTEBOOKS 100
#define TAMTRABAJOS 100
#define TAMCLIENTES 5
#define TAMESTADO 2

int main()
{

    char seguir = 's';
    int opcion;
    int trigger = 1;
    eFecha fechas[TAMTRABAJOS];
    eMarca marca[TAMMARCA] = { {1000,"COMPAQ"},{1001,"ASUS"},{1002,"ACER"},{1003,"HP"} };
    eTipo tipos[TAMTIPOS] = { {5000,"GAMER"},{5001,"DISENIO"},{5002,"ULTRABOOK"},{5003,"NORMALITA"} };
    eServicio servicios[TAMSERVICIOS] = { {"BATERIA",250,20000},{"ANTIVIRUS",300,20001},{"ACTUALIZACION",400,20002},{"FUENTE",600,20003} };
    eEstado estados[TAMESTADO] = { {1,"NUEVO"} , {2,"USADO"}   };

        eCliente clientes[TAMCLIENTES];

        hardcodeoCliente(clientes);

        eNotebook notebooks[TAMNOTEBOOKS];

        initNotebook(notebooks,TAMNOTEBOOKS);

        hardcodeoDatosNotebook(notebooks);

        eTrabajo trabajos[TAMTRABAJOS];

        initTrabajos(trabajos,TAMTRABAJOS);

        hardcodeoDatosTrabajo(trabajos);

    do{


        opcion = menu();

        switch(opcion)
        {
        case 1:
        clean();
        ingresoDatosNotebook(notebooks,TAMNOTEBOOKS);

        trigger = 1;
        break;

        case 2:

        if(trigger==1){
            clean();
          modificarNotebook(notebooks,TAMNOTEBOOKS,marca,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estados,TAMESTADO);
        }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;

        case 3:
         if(trigger==1){
            clean();
            mostrarNotebooks(notebooks,TAMNOTEBOOKS,marca,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estados,TAMESTADO);
        }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;

        case 4:
         if(trigger==1){
            clean();
            removerNotebook(notebooks,TAMNOTEBOOKS,marca,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estados,TAMESTADO);
        }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;

        case 5:
         if(trigger==1){
            clean();
          printMarcas(marca,TAMMARCA);
        }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;

        case 6:
         if(trigger==1){
            clean();
          printTipo(tipos,TAMTIPOS);
        }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;

        case 7:
         if(trigger==1){
            clean();
            printServicios(servicios,TAMSERVICIOS);
        }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;

        case 8:
         if(trigger==1){
            clean();
            ingresoDatosTrabajo(trabajos,TAMTRABAJOS,fechas,notebooks,TAMNOTEBOOKS,tipos,TAMTIPOS,marca,TAMMARCA,servicios,TAMSERVICIOS,clientes,TAMCLIENTES,estados,TAMESTADO);
        }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;


        case 9:
         if(trigger==1){
            clean();
            mostrarTrabajos(trabajos,TAMTRABAJOS,notebooks,TAMNOTEBOOKS,servicios,TAMSERVICIOS);
            }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
        break;

        case 10:
         if(trigger==1){
            clean();
            menuDeInformes(trabajos,TAMTRABAJOS,notebooks,TAMNOTEBOOKS,servicios,TAMSERVICIOS,marca,TAMMARCA,tipos,TAMTIPOS,clientes,TAMCLIENTES,estados,TAMESTADO);
            }
        else
        {
            printf("no hay notebooks ingresados.\n");
        }
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

    }while(seguir=='s');


    return 0;



















}
