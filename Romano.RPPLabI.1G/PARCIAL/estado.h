#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED

typedef struct{

int id;
char estado[20];

}eEstado;

void printEstado(eEstado estado[] , int tamEstado);
int cargarDescripcionEstado(char descripcion[] , eEstado estado[] , int id , int tamEstado);

#endif // ESTADO_H_INCLUDED
