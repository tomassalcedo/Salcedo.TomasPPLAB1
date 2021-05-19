#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "color.h"
#include "moto.h"
#include "servicio.h"
#include "moto.h"
#include "trabajo.h"
#include "tipo.h"



#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMM 20
#define TAMTRA 20

int menu();






int main()
{

    char confirma='n';


    eTipo tipos[TAMT] = {{1000,"Enduro"}, {1001,"Chopera"}, {1002,"Scooter"}, {1003,"Ciclomotor"}};
    eColor colores[TAMC] = { {10000,"Gris"},{10001,"Negro"}, {10002,"Blanco"}, {10003,"Azul"},{10004,"Rojo"}};
    eServicio servicios[TAMS] = {  {20000,"Limpieza",250},{20001,"Ajuste",300},{20002,"Balanceo",170},{20003,"Cadena",190}};



    eMoto listaM[TAMM];
    eTrabajo listaT[TAMTRA];


    int proximoIdMoto=1000;
    int proximoIdTrabajo=1000;



    inicializarM(listaM,TAMM);
    inicializarT(listaT,TAMTRA);

 do{

    system("cls");
    switch(menu())
    {

  case 'a':

  if(altaMoto(proximoIdMoto,listaM,TAMM,tipos,TAMT,colores,TAMC))
  {
      proximoIdMoto++;
      printf("Alta exitosa\n");
  }
system("pause");
      break;

  case 'b':
    modificarMoto(listaM,TAMM,tipos,TAMT,colores,TAMC);
    system("pause");
    break;


  case 'c':
      bajaMoto(listaM,TAMM,tipos,TAMT,colores,TAMC);
     system("pause");
    break;

  case 'd':
    mostrarMotos(listaM,TAMM,tipos,TAMT,colores,TAMC);
    system("pause");
    break;


  case 'e':
    mostrarTipos(tipos,TAMT);
    system("pause");
    break;

  case 'f':
     mostrarColores(colores,TAMC);
     system("pause");
     break;

  case 'g':
    mostrarServicios(servicios,TAMS);
    system("pause");
    break;

  case 'h':
      altaTrabajo(proximoIdTrabajo,listaT,TAMT,listaM,TAMM,servicios,TAMS);
      system("pause");
      break;

  case 'i':
    mostrarTrabajos(listaT,TAMT,listaM,TAMM,servicios,TAMS);
    system("pause");
    break;














    }













 }while(confirma == 'n');








    return 0;
}




int menu()
{

    char opcion;


    system("cls");
    printf("*****Service de motos*****\n\n");

    printf("A. Alta Moto\n");
    printf("B. Modificar moto\n");
    printf("C. Baja moto\n");
    printf("D. Listar motos\n");
    printf("E. Listar tipos\n");
    printf("F. Listar Colores\n");
    printf("G. Listar Servicios\n");
    printf("H. Alta Trabajo\n");
    printf("I. Listar Trabajos\n");
    printf("J. Salir\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;

}
