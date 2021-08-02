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
#include "stdlib.h"
#include "math.h"

// Define una enumeración para hacer más intuitivo los extremos del intervalo.
enum {a, b};
#define INTERVAL_TAM 2      // Define el tamaño del arreglo para hacer una tupla.

double biseccion( double (*f)(double), double* inter, double antSol, double err );
double regla_falsa( double (*f)(double), double* inter, double antSol, double err );
double newton_raphson( double (*f)(double), double (*g)(double), double (*h)(double), double* inter, double antSol, double err );


#endif   /* ----- #ifndef METODOS_INC  ----- */