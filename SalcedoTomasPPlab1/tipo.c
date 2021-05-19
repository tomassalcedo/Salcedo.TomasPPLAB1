#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"




int cargarDescripcionTipo(char descripcion[],int id,eTipo tipos[],int tamT)
{

     int todoOk=0;

for(int i=0; i < tamT ; i++){

    if(tipos[i].id == id){

        strcpy(descripcion,tipos[i].descripcion);
        todoOk=1;

    }

}

return todoOk;

}


void mostrarTipos(eTipo tipos[],int tamT)
{


    printf("\n\n***** Listado de Tipos *****\n");
    printf(" Id   | Tipo\n");
    printf("------------------\n");


    for(int i=0 ; i < tamT ;i++)
    {

        printf("  %4d  |  %-10s \n",tipos[i].id ,tipos[i].descripcion);


    }


}
