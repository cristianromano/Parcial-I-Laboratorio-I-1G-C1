#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

int id;
char tipo[20];

}eTipo;

void printTipo(eTipo tipos[] , int tamTipos);
int cargarDescripcionTipos(char descripcion[] , eTipo tipos[] , int id , int tamTipos);

#endif // TIPO_H_INCLUDED
