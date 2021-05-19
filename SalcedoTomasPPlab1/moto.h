#include "tipo.h"
#include "color.h"

#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED


typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;

}eMoto;


#endif // MOTO_H_INCLUDED




void inicializarM(eMoto vec[], int tamM);


int buscarLibreM(eMoto motos[],int tamM);

int altaMoto(int idx,eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);

void mostrarMoto(eMoto moto,eTipo tipos[],int tamT,eColor colores[],int tamC);

void mostrarMotos(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);

void bajaMoto(eMoto motos[], int tamM,eTipo tipos[], int tamT,eColor colores[],int tamC);

void modificarMoto(eMoto motos[],int tamM,eTipo tipos[], int tamT,eColor colores[],int tamC);

int menuMod();
