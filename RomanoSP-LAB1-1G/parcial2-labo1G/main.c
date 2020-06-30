#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entidad.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

    srand (time(NULL));
    char rta = 's';
    int opcion = 0;
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    char archivoTxt[50] = " ";

    char extension[10] = ".csv";


    do
    {

        menu(&opcion);

        switch(opcion)
        {
        case 1:
            printf("Que archivo desea cargar? Ingrese el nombre: \n");
            limpiarBuffer();
            gets(archivoTxt);
            strcat(archivoTxt,extension);

            if(archivoTxt!=NULL)
            {
                controller_loadFromText(archivoTxt,listaEmpleados);
                flag = 1;
            }

            else
            {
                printf("no existe.\n");
            }
            break;

        case 2:
            clean();
            mostrarBicis(listaEmpleados);
            break;

        case 3:
            clean();
            if(flag==1)
            {
              controller_mapEntity(listaEmpleados);
              printf("mapeo exitoso.\n");
            }
            else
            {
                printf("ingrese primero el .csv");
            }


            break;
        case 4:
            clean();
             if(flag==1)
            {
              controller_filterEntity(listaEmpleados);
            }
            else
            {
                printf("ingrese primero el .csv");
            }

            break;


        case 5:
            clean();
             if(flag==1)
            {
              controller_sortBici(listaEmpleados);
            }
            else
            {
                printf("ingrese primero el .csv");
            }
            break;

        case 6:
            clean();
             if(flag==1)
            {
              controller_saveAsText(archivoTxt,listaEmpleados);
            }
            else
            {
                printf("ingrese primero el .csv");
            }
            break;

        case 7:
            rta = 'n';

            break;

        default:
            printf("no es una opcion.\n");
            break;
        }

        printf("\n");
        pause();
        clean();
    }
    while(rta=='s');

    return 0;
}
