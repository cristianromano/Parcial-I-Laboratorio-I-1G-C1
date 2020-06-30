#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char tipo[128];
    int tiempo;


}eBicicletas;

eBicicletas* entity_new();
eBicicletas* entity_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr);
//void employee_delete();

int entity_setId(eBicicletas* this,int id);
int entity_getId(eBicicletas* this,int* id);

int entity_setNombre(eBicicletas* this,char* nombre);
int entity_getNombre(eBicicletas* this,char* nombre);

int entity_setTipo(eBicicletas* this,char* tipo);
int entity_getTipo(eBicicletas* this,char* tipo);

int entity_setTiempo(eBicicletas* this,int tiempo);
int entity_getTiempo(eBicicletas* this,int* tiempo);


int mostrarBici(eBicicletas* this);

int mostrarBicis(LinkedList* arrayEmpleados);

int sortTiempo(void* datoUno, void* datoDos);

/*Employee* buscarEmpleado(LinkedList* arrayEmpleados, int id);
int ultimoID(LinkedList* arrayEmpleados);*/

int funcionFilterBMX(void* pElement);
int funcionFilterPaseo(void* pElement);
int funcionFilterMTB(void* pElement);
int funcionFilterPlayera(void* pElement);

int random();
void clean();
void pause();
void limpiarBuffer();

//int sortNombre(void* datoUno , void* datoDos);
int sortTipo(void* datoUno, void* datoDos);

void menu(int* opcion);

int filterID(void* id);
int filterNombre(void* nombre);
int entityMapTiempo(void* p);
int contadorEmpleados(void* empleado);

#endif // employee_H_INCLUDED
