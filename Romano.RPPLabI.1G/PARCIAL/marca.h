#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

int id;
char marca[20];

}eMarca;

void printMarcas(eMarca marcas[] , int tamMarcas);
int cargarDescripcionMarcas(char descripcion[] , eMarca marcas[] , int id , int tamMarcas);

#endif // MARCA_H_INCLUDED
