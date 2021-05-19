#include "fecha.h"
#include "moto.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED


typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;

#endif // TRABAJO_H_INCLUDED


void inicializarT(eTrabajo vec[], int tam);

int buscarLibreTrabajo(eTrabajo trabajo[], int tamT);

int altaTrabajo(int idx,eTrabajo vecT[],int tamT,eMoto motos[],int tamA,eServicio vecS[],int tamS);
