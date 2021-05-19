#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"







void mostrarServicios(eServicio servicios[],int tamS)
{
    printf("\n\n***** Listado de Servicios *****\n");
    printf(" Id     |   Servicio   |  Precio\n");
    printf("------------------------------------\n");


    for(int i=0 ; i < tamS ;i++)
    {

        printf("  %4d  |  %-10s   %f\n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);


    }

}


void cargarInformacionServicio(char descripcion[] ,int id,eServicio servicios[],int tamS)
{

     int todoOk= 0;

    for(int i=0; i<tamS; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion,servicios[i].descripcion);
            todoOk= 1;
        }
    }




    return todoOk;



}
