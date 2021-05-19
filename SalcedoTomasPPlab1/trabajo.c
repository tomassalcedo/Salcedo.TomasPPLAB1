#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "fecha.h"
#include "moto.h"
#include "servicio.h"




void inicializarT(eTrabajo vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {

        vec[i].isEmpty=1;



    }

}



int buscarLibreTrabajo(eTrabajo trabajo[], int tamT)
{
    int indice = -1;

    for(int i=0; i<tamT; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void mostrarTrabajo(eTrabajo trabajo, eMoto moto,eServicio servicios[],int tamS)
{


    char nombreServicio[20];


    cargarInformacionServicio(nombreServicio,trabajo.idServicio,servicios,tamS);

    printf("  %d|        %s         |      %-10s\n",trabajo.id,moto.marca,nombreServicio);






}



void mostrarTrabajos(eTrabajo trabajos[],int tamT,eMoto motos[],int tamM, eServicio servicios[],int tamS)
{

     int flag=0;
    system("cls");


    system("cls");
    printf("\n     ***** Listado de Trabajos *****\n");
    printf("  Id   | Marca |   Servicio   |\n");
    printf("---------------------------------------------------\n");
    for(int i=0; i<tamT; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i],motos[i],servicios,tamS);
            flag=1;

        }
    }
    if(flag==0)
    {
        printf("\n   No hay trabajo que mostrar\n\n");
    }


}



int altaTrabajo(int idx,eTrabajo vecT[],int tamT,eMoto motos[],int tamM,eServicio vecS[],int tamS)
{

    int todoOk=0;
    int patente;
    int buscar;
    int id;
    int idServicio;



    int indice = buscarLibreTrabajo(vecT,tamT);
    eTrabajo auxTrabajo;

    system("cls");
    printf("*****Alta Trabajo*****\n\n");

    if(indice== -1)
    {
        printf("Sistema Completo\n\n");
    }
    else
    {
        auxTrabajo.id= idx;




        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d",&id);

       buscar= buscarMoto(id,motos,tamM);


        if(buscar == -1)
        {
            printf("No hay registro de una moto con el id: %d\n\n",id);
            system("pause");


        }
        else{


             mostrarServicios(vecS,tamS);

             printf("Ingrese id de servicio: ");
             scanf("%d",&idServicio);
             auxTrabajo.idServicio = idServicio;








        auxTrabajo.isEmpty=0;

        vecT[indice]=auxTrabajo;
        todoOk=1;

        printf("\nAlta Exitosa\n\n");
        system("pause");





        }


    }











    return todoOk;

}
