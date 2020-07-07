#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{

char servicios[25];
float precios;
int id;



}eServicio;

void printServicios(eServicio servicios[] , int tamServicios);
int cargarDescripcionServicios(char descripcion[] , eServicio servicios[] , int id , int tamServicios);

#endif // SERVICIOS_H_INCLUDED
