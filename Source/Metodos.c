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

/**
 * @brief Método de bisección
 * 
 * @param f función f(x) a resolver
 * @param inter Referencia del intervalo a trabajar
 * @param antSol Aproximación de la iteración anterior
 * @param err Porcentaje de error en forma decimal
 * @return Aproximación de la raíz de f(x)
 */
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

/**
 * @brief Método de Regla Falsa
 * 
 * @param f Función f(x) a resolver
 * @param inter Referencia del intervalo a trabajar
 * @param antSol Aproximación de la iteración anterior
 * @param err Porcetaje de error en forma decimal
 * @return Aproximación de la raíz de f(x)
 */
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

/**
 * @brief Método de Newton - Raphson
 * 
 * @param f Función f(x) a resolver
 * @param g Primera derivada de f(x)
 * @param h Segunda derivada de f(x)
 * @param inter Referncia del intervalo a trabajar
 * @param antSol Aproximación de la iteración anterior
 * @param err Porcentaje de error en forma decimal
 * @return Aproximación de la raíz de f(x)
 */
double newton_raphson( double (*f)(double), double (*g)(double), double(*h)(double), double* inter, double antSol, double err ){

    if( !antSol ){
        antSol = (inter[a] + inter[b])/2;
    }

    double fi = f(antSol); // Valor de la función
    double gi = g(antSol); // Valor de la primera derivada
    double hi = h(antSol); // Valor de la segunda derivada

    // Criterio de convergencia
    if( fabs( (fi*hi)/pow(gi, 2) ) < 1 ){

        double sol = antSol - ( fi/gi );

        if( fabs(sol - antSol) > err ){
            sol = newton_raphson( f, g, h, inter, sol, err );
        }
        return sol;
    
    } else {
        return -1;
    }
}