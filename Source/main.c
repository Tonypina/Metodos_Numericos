#include "Metodos.h"

// Función a encontrar raíz
double f( double x ){
    // 3cos(2x) + 5x
    return (3*cos(2*x)+(5*x));
}

// Primera derivada de f
double g( double x ){
    // -6sen(2x) + 5
    return (-6*sin(2*x)+5);
}

// Segunda derivada de f
double h( double x ){
    // -12cos(2x)
    return (-12*cos(2*x));
}

// Driver program
int main(){
    // Inter intervalo;
    double inter[INTERVAL_TAM] = {0.0};

    double err;

    printf("Introduzca el error aceptable para la aproximacion: ");
    scanf("%lf", &err);

    printf("\nEncontrando raiz de 3cos(2x) + 5x...\n\n");

    printf("\tTabulando...\n");
    printf("\t x || f(x) \n");
    
    // Recorre e imprime los valores de f(xi) desde el -4 al 4
    for( int i = -4; i < 5; i++ ){
        
        if( f(i)*f(i+1) < 0 ){

            inter[a] = (double)i;
            inter[b] = (double)i + 1;
        }
        printf("\t%d || %lf\n", i, f(i));
    }

    printf("El intervalo donde se encuentra la solucion es: [%0.0lf, %0.0lf]\n", inter[a], inter[b]);

    // Bisección
    printf( "\nBISECCION\nLa solucion con %lf de error es: %0.4lf\n", err, biseccion( f, inter, 0, err ));

    // Regla Falsa
    printf("\nREGLA FALSA\nLa solucion con %lf de error es: %0.4lf\n", err, regla_falsa( f, inter, 0, err ));

    // Newton-Raphson
    printf("\nNEWTON-RAPHSON\nLa solución con %lf de error es: %0.4lf\n", err, newton_raphson( f, g, h, inter, 0, err ));
}