/**
 * @file Metodos.h
 * @author Piña Rossette Marco Antonio
 * @brief Declaraciones de los métodos numéricos
 * @version 0.1
 * @date 2021-06-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef  METODOS_INC
#define  METODOS_INC

#include "stdio.h"
#include "math.h"

// Estructura para manejar intervalos
typedef struct inter{
    double a;
    double b;
}inter;

double biseccion( double (*f)(double), inter intervalo, double antSol, double err );

#endif   /* ----- #ifndef METODOS_INC  ----- */