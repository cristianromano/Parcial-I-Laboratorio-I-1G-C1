#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entidad.h"

eBicicletas* entity_new()
{

eBicicletas* this;

this = (eBicicletas*)malloc(sizeof(eBicicletas));
	if(this!=NULL)
	{
		this->id = 0;
		strcpy(this->nombre,"");
		this->tiempo=0;
		strcpy(this->tipo,"");



	}

	else
	{
		printf("no hay lugar libre");
	}


	return this;

}


eBicicletas* entity_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{

eBicicletas* this = entity_new();
int id;
int tiempo;


	if(this!=NULL)
	{

		id = atoi(idStr);
		tiempo = atoi(tiempoStr);
		entity_setId(this,id);
		entity_setNombre(this, nombreStr);
		entity_setTipo(this, tipoStr);
		entity_setTiempo(this, tiempo);


	}

	return this;
}

/*void employee_delete(Employee* this)
{
    free(this);
}*/




int entity_setId(eBicicletas* this,int id)
{

int retorno = -1;

	if(this!=NULL)
	{

		this->id = id;
		retorno = 1;
	}



return retorno;

}

int entity_getId(eBicicletas* this,int* id)
{

int retorno = -1;

if(this!=NULL)
{

	*id = this->id;
	retorno = 1;
}

return retorno;

}




int entity_setTiempo(eBicicletas* this,int tiempo)
{

int retorno = -1;

	if(this!=NULL)
	{

		this->tiempo = tiempo;
		retorno = 1;
	}



return retorno;

}

int entity_getTiempo(eBicicletas* this,int* tiempo)
{

int retorno = -1;

if(this!=NULL)
{

	*tiempo = this->tiempo;
	retorno = 1;
}

return retorno;

}



int entity_setNombre(eBicicletas* this,char* nombre)
{

int retorno = -1;

	if(this!=NULL)
	{

		strcpy(this->nombre , nombre);
		fflush(stdout);
		retorno = 1;
	}



return retorno;

}

int entity_getNombre(eBicicletas* this,char* nombre)
{

int retorno = -1;

if(this!=NULL)
{

	strcpy(nombre, this->nombre);
	fflush(stdout);
	retorno = 1;
}

return retorno;

}

int entity_setTipo(eBicicletas* this,char* tipo)
{

int retorno = -1;

	if(this!=NULL)
	{

		strcpy(this->tipo, tipo);
		fflush(stdout);
		retorno = 1;
	}



return retorno;

}

int entity_getTipo(eBicicletas* this,char* tipo)
{

int retorno = -1;

if(this!=NULL)
{

	strcpy(tipo, this->tipo);
	fflush(stdout);
	retorno = 1;
}

return retorno;

}



int mostrarBici(eBicicletas* this)
{
    int retorno = 1;

    if(this!=NULL)
    {
        printf("%04d  %15s       %4s         %4d\n",this->id,this->nombre,this->tipo,this->tiempo);
        retorno = 0;
    }

    return retorno;

}

int mostrarBicis(LinkedList* arrayEmpleados)
{
    int i;
    int retorno = 1;
    int flag = 0;

    eBicicletas* this;

    if(arrayEmpleados!=NULL)
    {
        printf("ID             NOMBRE      TIPO         TIEMPO\n");
        printf("--------------------------------------------------\n");
        for(i=0; i<ll_len(arrayEmpleados); i++)
        {
            this = (eBicicletas*) ll_get(arrayEmpleados,i);

            if(this!=NULL)
            {
                mostrarBici(this);
                flag = 1;
            }

            printf("--------------------------------------------------\n");

        }

        if(flag==0)
        {
            printf("no hay empleados.\n");
        }


    }



    return retorno;

}

/*Employee* buscarEmpleado(LinkedList* arrayEmpleados, int id)
{

    int i;
    Employee* this = NULL;

    if(arrayEmpleados!=NULL)
    {
        for(i=0; i<ll_len(arrayEmpleados); i++)
        {

            this = (Employee*)ll_get(arrayEmpleados,i);

            if(this->id == id)
            {
                return this;
            }


        }
    }


    return this;

}




int ultimoID(LinkedList* arrayEmpleados)
{
    int retorno = -1;
    int mayor = 0;
    int flag = 0;
    Employee* this;
    int i;

    if(arrayEmpleados!=NULL)
    {
        for(i=0; i<ll_len(arrayEmpleados); i++)
        {
            this = (Employee*)ll_get(arrayEmpleados,i);

            if(this!=NULL)
            {
                if(this->id > mayor || flag == 0)
                {
                    mayor = this->id;
                    flag = 1;
                }
            }
        }

        retorno = mayor;


    }

    return retorno;
}
*/


int sortTipo(void* datoUno, void* datoDos)
{

    int retorno = -1;
    eBicicletas* x ;
    eBicicletas* y ;


    if(datoUno!=NULL && datoDos!=NULL)
    {
        x = (eBicicletas*) datoUno;
        y = (eBicicletas*) datoDos;


        if( strcmp(x->tipo , y->tipo) > 0)
        {
            retorno = 1;
        }

        else if( strcmp(x->tipo , y->tipo) < 0)
        {
            retorno = 0;
        }


    }

    return retorno;
}


int sortTiempo(void* datoUno, void* datoDos)
{

    int retorno = -1;
    eBicicletas* x ;
    eBicicletas* y ;


    if(datoUno!=NULL && datoDos!=NULL)
    {
        x = (eBicicletas*) datoUno;
        y = (eBicicletas*) datoDos;

        if(x->tiempo > y->tiempo)
        {

            retorno = 1;
        }


    }

    return retorno;
}

/*int sortNombre(void* datoUno, void* datoDos)
{

    int retorno;
    Employee* nombreUno = (Employee*) datoUno;
    Employee* nombreDos = (Employee*) datoDos;

    if(strcmp(nombreUno->nombre, nombreDos->nombre)>0)
    {
        retorno =  1;
    }

    else if(strcmp(nombreUno->nombre, nombreDos->nombre)<0)
    {
        retorno =  0;
    }


    return retorno;
}*/

void menu(int* opcion)
{

    printf("1.CARGAR BICIS\n2.MOSTRAR BICIS\n3.MAPEAR TIEMPOS\n4.FILTRAR LISTAS\n5.ORDENAR POR TIEMPO ASCENDENTE\n6.GUARDAR\n7.SALIR\nOPCION: ");
    scanf("%d",&*opcion);

}

/*int filterID(void* id)
{
    int retorno = 0;
    Employee* x;

    if(id!=NULL)
    {
        x = (Employee*) id;

        if(x->id > 500 && x->id < 600)
        {
            retorno = 1;
        }

    }

    return retorno;
}

int filterNombre(void* nombre)
{
    int retorno = 0;
    Employee* x;

    if(nombre!=NULL)
    {
        x = (Employee*) nombre;

        if(strcmp(x->nombre,"Cristian")==0)
        {
            retorno = 1;
        }

    }

    return retorno;
}

*/

int entityMapTiempo(void* p)
{
    int retorno = -1;

    eBicicletas* bici;

    if(p != NULL)
    {

        bici = (eBicicletas*) p;

        entity_setTiempo(bici,random());


        retorno = 1;
    }
    return retorno;
}


/*int contadorEmpleados(void* empleado)
{
    int retorno = -1;
    Employee* x;
    if(empleado!=NULL)
    {
        x = (Employee*) empleado;

        retorno = 1;
    }

    return retorno;
}

*/

int funcionFilterBMX(void* pElement)
{
	int retorno = 0;

	eBicicletas* this;

	char tipo[128];

	this = (eBicicletas*) pElement;

	entity_getTipo(this,tipo);

	if(pElement!=NULL)
	{
		if(strcmp(tipo , "BMX")==0)
		{
			retorno = 1;

		}


	}


	return retorno;
}

int funcionFilterPaseo(void* pElement)
{
	int retorno = 0;

	eBicicletas* this;

	this = (eBicicletas*) pElement;

	if(pElement!=NULL)
	{
		if(strcmp(this->tipo , "PASEO")==0)
		{
			retorno = 1;

		}
	}


	return retorno;
}

int funcionFilterMTB(void* pElement)
{
	int retorno = 0;

	eBicicletas* this;

	this = (eBicicletas*) pElement;

	if(pElement!=NULL)
	{
		if(strcmp(this->tipo, "MTB")==0)
		{
			retorno = 1;

		}
	}


	return retorno;
}

int funcionFilterPlayera(void* pElement)
{
	int retorno = 0;

	eBicicletas* this;

	this = (eBicicletas*) pElement;

	if(pElement!=NULL)
	{
		if(strcmp(this->tipo, "PLAYERA")==0)
		{
			retorno = 1;

		}
	}


	return retorno;
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


int random()
{
    int aleatorio;

    aleatorio = rand()%(71)+50;

    return aleatorio;
}
