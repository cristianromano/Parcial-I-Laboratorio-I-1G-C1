#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entidad.h"
#include "parser.h"

/*
static int generarId()
{
    static int contadorId=1002;
    contadorId++;
    return contadorId;
}

* \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    pFile = fopen(path,"r+");

    int retorno = 1;

    if(pFile!=NULL)
    {
        parser_BicicletaFromText(pFile,pArrayListEmployee);
        printf("exito al cargar datos por texto.\n");
        retorno = 0;
    }
    else
    {
        printf("error al cargar datos por texto.\n");
    }


    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    pFile = fopen(path,"rb");

    int retorno = 1;

    if(pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        printf("exito al cargar datos por binario.\n");
        retorno = 0;
    }
    else
    {
        printf("error al cargar datos por binario.\n");
    }


    fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* this;
    char nombre[20], sueldo[20], horasTrabajadas[20], id[20];
    int idAux;
    char rta;

    if(pArrayListEmployee!=NULL)
    {
        printf("ingrese nombre: ");
        fflush(stdin);

        gets(nombre);

        printf("ingrese sueldo: ");
        fflush(stdin);

        scanf("%s",sueldo);

        printf("ingrese horas trabajadas: ");
        fflush(stdin);

        scanf("%s",horasTrabajadas);

        fflush(stdin);

        idAux = generarId();

        fflush(stdin);

        sprintf(id,"%d",idAux);

        fflush(stdin);

        printf("seguro que desea cargar empleado? s/n\n");
        scanf("%c",&rta);

        if(rta=='s' || rta=='S')
        {
            this = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            ll_add(pArrayListEmployee,this);

            printf("empleado cargado con exito.\n");
            pause();
            clean();
        }

        else
        {
            printf("no se a cargado empleado.\n");
            pause();
            clean();
        }

    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int numero, opcion = 0;
    Employee* this;
    char rta;
    float sueldo;
    int horas;

    if(mostrarEmpleados(pArrayListEmployee)==0)
    {
        printf("ingrese ID de empleado que desea modificar: \n");
        scanf("%d",&numero);
        clean();

        if(pArrayListEmployee!=NULL)
        {
            this = buscarEmpleado(pArrayListEmployee,numero);

            if(this!=NULL)
            {
                printf("ID             NOMBRE      HORAS         SUELDO\n");
                printf("--------------------------------------------------\n");
                mostrarEmpleado(this);
                printf("\neste es el empleado que desea modificar? s/n\n");
                fflush(stdin);
                scanf("%c",&rta);

                if(rta=='s' || rta=='S')
                {
                    clean();
                    printf("que dato desea modificar?\n1.Sueldo\n2.Horas\n");
                    scanf("%d",&opcion);

                    switch(opcion)
                    {
                    case 1:
                        printf("ingrese nuevo sueldo: ");
                        scanf("%f",&sueldo);
                        employee_setSueldo(this,sueldo);
                        printf("nuevo sueldo cargado con exito\n");
                        break;

                    case 2:
                        printf("ingrese nuevo horario: ");
                        scanf("%d",&horas);
                        employee_setHorasTrabajadas(this,horas);
                        printf("nuevas horas cargadas con exito\n");
                        break;

                    default:
                        printf("no es una opcion\n");
                        break;
                    }
                }


            }

        }
    }





    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int numero;
    Employee* this;
    int index;
    char rta;

    if(mostrarEmpleados(pArrayListEmployee)==0)
    {
        printf("ingrese ID de empleado que desea remover: \n");
        scanf("%d",&numero);
        clean();

        if(pArrayListEmployee!=NULL)
        {
            this = buscarEmpleado(pArrayListEmployee,numero);

            if(this!=NULL)
            {
                printf("ID             NOMBRE      HORAS         SUELDO\n");
                printf("--------------------------------------------------\n");
                mostrarEmpleado(this);
                printf("\neste es el empleado que desea remover? s/n\n");
                fflush(stdin);
                scanf("%c",&rta);

                if(rta=='s' || rta=='S')
                {
                    clean();

                    index = ll_indexOf(pArrayListEmployee,this);
                    ll_remove(pArrayListEmployee,index);
                    printf("empleado removido con exito.\n");

                }
            }


        }

    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int mostrarEmpleados(LinkedList* arrayEmpleados)
{
    int i;
    int retorno = 0;
    int flag = 0;

    Employee* this;

    if(arrayEmpleados!=NULL)
    {
        printf("ID             NOMBRE      HORAS         SUELDO\n");
        printf("--------------------------------------------------\n");
        for(i=0; i<ll_len(arrayEmpleados); i++)
        {
            this = (Employee*) ll_get(arrayEmpleados,i);

            if(this!=NULL)
            {
                mostrarEmpleado(this);
                flag = 1;

            }

            printf("--------------------------------------------------\n");
        }

        if(flag==0)
        {
            printf("no hay empleados.\n");

            retorno = 1;
        }

    }



    return retorno;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortBici(LinkedList* pArrayListEmployee)
{


    if(pArrayListEmployee!=NULL)
    {

            ll_sort(pArrayListEmployee,sortTiempo,1);
            printf("ordenado con exito.\n");

    }



    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pFile;

    int i;

    pFile = fopen(path,"w+");

    eBicicletas* this;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {

        fprintf(pFile,"Id,Nombre,Tipo,Tiempo\n");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (eBicicletas*)ll_get(pArrayListEmployee,i);

            fprintf(pFile,"%d,%s,%s,%d\n",this->id,this->nombre,this->tipo,this->tiempo);


        }


        printf("guardado con exito.\n");
    }

    fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    int i;

    pFile = fopen(path,"wb");

    Employee* this;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {


        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee,i);

            fwrite(this,sizeof(Employee),1,pFile);

        }

        fclose(pFile);
        printf("guardado con exito.\n");

    }


    return 1;
}
*/
int controller_filterEntity(LinkedList* pArrayListEntity)
{
    int retorno = -1;
    int option;
    LinkedList* filterList;
    char rta;
    printf("Seleeccionar filtro por: \n1.BMX\n2.PLAYERA\n3.MTB\n4.PASEO\nOPCION:");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
            filterList = ll_filter(pArrayListEntity, funcionFilterBMX);
        printf("desea guardar la lista filtrada?");
        limpiarBuffer();
        scanf("%c",&rta);
        if(rta == 's' || rta == 'S')
        {
            controller_saveAsText("filteredDataBMX.csv", filterList);
            printf("Filtrado con exito.\n");
            pause();
            retorno = 0;
        }
        break;

    case 2:
      filterList = ll_filter(pArrayListEntity, funcionFilterPlayera);
        printf("desea guardar la lista filtrada?");
        limpiarBuffer();
        scanf("%c",&rta);
        if(rta == 's' || rta == 'S')
        {
            controller_saveAsText("filteredDataPlayera.csv", filterList);
            printf("Filtrado con exito.\n");
            pause();
            retorno = 0;
        }
        break;

    case 3:
           filterList = ll_filter(pArrayListEntity, funcionFilterMTB);
        printf("desea guardar la lista filtrada?");
        limpiarBuffer();
        scanf("%c",&rta);
        if(rta == 's' || rta == 'S')
        {
            controller_saveAsText("filteredMTB.csv", filterList);
            printf("Filtrado con exito.\n");
            retorno = 0;
        }
        break;

    case 4:
           filterList = ll_filter(pArrayListEntity, funcionFilterPaseo);
        printf("desea guardar la lista filtrada?");
        limpiarBuffer();
        scanf("%c",&rta);
        if(rta == 's' || rta == 'S')
        {
            controller_saveAsText("filteredPaseo.csv", filterList);
            printf("Filtrado con exito.\n");
            retorno = 0;
        }
        break;

    default:
        printf("Opcion no valida\n");
        break;


    }

    return retorno;
}




int controller_mapEntity(LinkedList* pArrayListEntity)
{
    int retorno = -1;

    if(ll_map(pArrayListEntity,entityMapTiempo) )
    {
        printf("exito.\n");
        pause();
        retorno = 1;
    }

    return retorno;
}
