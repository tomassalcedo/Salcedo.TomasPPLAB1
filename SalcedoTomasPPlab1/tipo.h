#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

int id;
char descripcion[21];


}eTipo;


#endif // TIPO_H_INCLUDED

void mostrarTipos(eTipo tipos[],int tamT);

int cargarDescripcionTipo(char descripcion[],int id,eTipo tipos[],int tamT);
