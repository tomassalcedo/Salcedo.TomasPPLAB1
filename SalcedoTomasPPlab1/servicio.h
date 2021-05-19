#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    float precio;


}eServicio;


#endif // SERVICIO_H_INCLUDED


void mostrarServicios(eServicio servicios[],int tamS);

void cargarInformacionServicio(char descripcion[] ,int id,eServicio servicios[],int tamS);
