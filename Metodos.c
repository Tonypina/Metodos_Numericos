/**
 * @file Metodos.c
 * @author Piña Rossette Marco Antonio
 * @brief Definiciones de los métodos numéricos
 * @version 0.1
 * @date 2021-06-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Metodos.h"

// Método de bisección
double biseccion( double (*f)(double), double* inter, double antSol, double err ){

    double f1 = f(inter[a]);
    double f2 = f(inter[b]);

    // Criterio de convergencia
    if( (f1*f2) < 0 ){

        // Se realiza bisección
        double sol = (inter[a] + inter[b]) / 2;
        double tmp = f( sol );

        if( tmp < 0 && f1 < f2 ){
            inter[a] = sol;
        } else if( tmp > 0 && f1 > f2 ){
            inter[a] = sol;
        } else {
            inter[b] = sol;
        }

        if( fabs(sol - antSol) > err ){
            sol = biseccion( f, inter, sol, err );
        }
        return sol;

    } else {
        return -1;
    }
}

// Método de regla falsa
double regla_falsa( double (*f)(double), double* inter, double antSol, double err ){
    
    double f1 = f(inter[a]);
    double f2 = f(inter[b]);

    // Criterio de convergencia
    if( (f1*f2) < 0 ){

        // Se realiza bisección
        double sol = inter[a] + ((f1*(inter[a] - inter[b])) / (f2 - f1));
        double tmp = f( sol );

        if( tmp < 0 && f1 < f2 ){
            inter[a] = sol;
        } else if( tmp > 0 && f1 > f2 ){
            inter[a] = sol;
        } else {
            inter[b] = sol;
        }

        if( fabs(sol - antSol) > err ){
            sol = regla_falsa( f, inter, sol, err );
        }
        return sol;

    } else {
        return -1;
    }
}
