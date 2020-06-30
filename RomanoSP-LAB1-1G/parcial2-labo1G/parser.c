#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entidad.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_BicicletaFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    char id[100],nombre[100],tipo[100],tiempo[100];
    eBicicletas* this;
    int retorno = 1;
    int r;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {

        fscanf(pFile,"%[^,] ,%[^,],%[^,],%[^\n]\n",id,nombre,tipo,tiempo );

        do
        {

            r = fscanf(pFile,"%[^,] ,%[^,],%[^,],%[^\n]\n",id,nombre,tipo,tiempo );

            if(r==4)
            {

                this = entity_newParametros(id,nombre,tipo,tiempo);

                ll_add(pArrayListEmployee,this);

                retorno = 0;


            }

        }while(!feof(pFile));

        fclose(pFile);

    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
   // Employee* this;
    int retorno = 1;
    int read = 0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do{

            Employee* this = employee_new();
            if(this!=NULL)
            {
                read = fread(this,sizeof(Employee),1,pFile);
            }

            if(read == 1)
            {
                ll_add(pArrayListEmployee,this);

            }

            retorno = 0;

        }while(!feof(pFile));

        fclose(pFile);
    }



    return retorno;
}
*/
