/**
 * @file metodos.c
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
double biseccion( double (*f)(double), inter intervalo, double antSol, double err ){

    double f1 = f(intervalo.a);
    double f2 = f(intervalo.b);

    // Criterio de convergencia
    if( (f1*f2) < 0 ){

        // Se realiza bisección
        double sol = (intervalo.a + intervalo.b) / 2;
        double tmp = f( sol );

        if( tmp < 0 && f1 < f2 ){
            intervalo.a = sol;
        } else if( tmp > 0 && f1 > f2 ){
            intervalo.a = sol;
        } else {
            intervalo.b = sol;
        }

        if( fabs(sol - antSol) > err ){
            sol = biseccion( f, intervalo, sol, err );
        }
        return sol;

    } else {
        return -1;
    }
}
