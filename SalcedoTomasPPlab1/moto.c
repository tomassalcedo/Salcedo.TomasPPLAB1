#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "tipo.h"





void inicializarM(eMoto vec[], int tamM)
{

     for(int i=0; i < tamM ; i++)
    {

        vec[i].isEmpty=1;




    }



}


int buscarLibreM(eMoto motos[],int tamM)
{

     int indice = -1;

    for(int i=0; i < tamM ; i++)
    {

        if(motos[i].isEmpty==1)
        {
            indice= i;
            break;

        }


    }

    return indice;

}





int altaMoto(int idx,eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{
    int todoOk=0;
    int idTipo;
    int idColor;
    char marca[21];
    int cilindrada;

    int indice;

    eMoto auxMoto;

    indice = buscarLibreM(motos,tamM);

    printf("****Alta moto****\n\n");


    if(indice == 1)
    {
        printf("Sistema Completo\n");
    }
    else{
         auxMoto.id = idx;
         mostrarTipos(tipos,tamT);

         printf("Ingrese el id del tipo: ");
         scanf("%d",&idTipo);

         while(idTipo < 1000 || idTipo > 1003)
         {
             printf("Id invalido.Reingrese ID: ");
             scanf("%d",&idTipo);

         }

         auxMoto.id = idTipo;

         mostrarColores(colores,tamC);

         printf("Ingrese ID del color: ");
         scanf("%d",&idColor);

         while(!validarIdColor(idColor,colores,tamC))

         {
             printf("ID invalido.Reingrese ID: ");
             scanf("%d",&idColor);
         }


         auxMoto.idColor = idColor;

         printf("Ingrese marca: ");
         fflush(stdin);
         gets(marca);


         strcpy(auxMoto.marca,marca);

         printf("Ingrese cilindrada: ");
         scanf("%d",&cilindrada);

         auxMoto.cilindrada = cilindrada;

         auxMoto.isEmpty=0;

         motos[indice] = auxMoto;


         todoOk=1;






    }




return todoOk;
}


void mostrarMoto(eMoto moto,eTipo tipos[],int tamT,eColor colores[],int tamC)
{

    char descripcionTipo[20];
    char descripcionColor[20];

    cargarDescripcionTipo(descripcionTipo,moto.idTipo,tipos,tamT);
    cargarDescripcionColor(descripcionColor,moto.idColor,colores,tamC);

    printf("%d %s  %s  %s %d\n\n",moto.id,descripcionTipo,moto.marca,descripcionColor,moto.cilindrada);


}


void mostrarMotos(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{


    int flag=0;
    printf("*****Listado de Motos*****\n\n");
    printf(" id  Tipo  Marca  Color  cilindrada\n\n");

    for(int i=0; i < tamM; i++)
    {


        if(motos[i].isEmpty==0)
        {
            mostrarMoto(motos[i],tipos,tamT,colores,tamC);
            flag=1;

        }

    }

    if(flag==0)
    {
        printf("\nNo hay motos que mostrar\n\n");
    }

}



int buscarMoto(int id , eMoto motos[],int tamM)
{

    int indice= -1;

    for(int i=0; i < tamM; i++)
    {
        if(motos[i].id == id && motos[i].isEmpty==0)
        {
            indice=i;
            break;

        }

    }
    return indice;
}


void bajaMoto(eMoto motos[], int tamM,eTipo tipos[], int tamT,eColor colores[],int tamC)
{


    int indice;
    int id;
    char confirma;

    system("cls");
    printf("*****Baja Moto*****\n\n");

    mostrarMotos(motos,tamM,tipos,tamT,colores,tamC);
    printf("Ingrese ID:  ");
    scanf("%d",&id);

    indice = buscarMoto(id,motos,tamM);

    if(indice== -1)
    {
        printf("No hay registro de una moto con el id: %d\n",id);

    }
    else
    {   printf(" id  Tipo   Color  cilindrada\n\n");
        mostrarMoto(motos[indice],tipos,tamT,colores,tamC);
        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);
        if(confirma=='s')
        {
            motos[indice].isEmpty=1;
            printf("Se ha realizado la baja exitosamente\n\n");

        }

        else
        {
            printf("Se ha cancelado la operacion\n\n");

        }


    }




}

int menuMod()
{
   char opcion;

    system("cls");
    printf("*****Modificar Moto*****\n\n");
    printf("a_Modificar color\n");
    printf("b_Modificar cilindrada\n");
    printf("c_Salir\n\n");

    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);


    return opcion;
}






void modificarMoto(eMoto motos[],int tamM,eTipo tipos[], int tamT,eColor colores[],int tamC)
{

    int indice;
    int id;
    int nuevoColor;
    int nuevaCilindrada;
    int seguir='s';
    char confirma;


    do
    {

        switch(menuMod())
        {

        case 'a':

            mostrarMotos(motos,tamM,tipos,tamT,colores,tamC);

            printf("Ingrese id: ");
            scanf("%d",&id);


            indice = buscarMoto(id,motos,tamM);

            if(indice == -1)
            {
                printf("No hay registro de una moto con el id: %d",id);



            }



            else
            {    printf(" id  Tipo   Color  cilindrada\n\n");

                  mostrarMoto(motos[indice],tipos,tamT,colores,tamC);
                 mostrarColores(colores,tamC);

                printf("Ingrese id del color: ");
                scanf("%d",&nuevoColor);
                motos[indice].idColor=nuevoColor;
                printf("\nColor actualizado con exito\n\n");
                system("pause");
                break;
            }




        case 'b':
            printf("Ingrese id: ");
            scanf("%d",&id);

            indice = buscarMoto(id,motos,tamM);



            if(indice== -1){

                printf("No hay registro de una moto id: %d\n",id);
            }
            else{

            printf(" id  Tipo   Color  cilindrada\n\n");

                   mostrarMoto(motos[indice],tipos,tamT,colores,tamC);
                printf("Ingrese nueva cilindrada: ");
                scanf("%d",&nuevaCilindrada);

                motos[indice].cilindrada = nuevaCilindrada;
                printf("\nCilindrada actualizada con exito\n\n");
                system("pause");
                break;


            }

        case 'c':
            printf("Confirma salida?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            seguir='n';
        }


 break;




        }




    }
    while(seguir=='s');






}
