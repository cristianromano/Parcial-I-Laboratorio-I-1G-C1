#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

int id;
char nombre[25];
char sexo;

}eCliente;

void hardcodeoCliente(eCliente clientes[]);
int cargarDescripcionCliente(char descripcion[] , eCliente clientes[] , int id , int tamCliente);

#endif // CLIENTE_H_INCLUDED
