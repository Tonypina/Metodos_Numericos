#include "Metodos.h"

// Función a encontrar raíz
double f( double x ){
    // 3cos(2x) + 5x
    return (3*cos(2*x)+(5*x));
}

// Driver program
int main(){
    inter intervalo;
    
    // El error se puede pedir al usuario
    double err = 0.00008;

    printf("Encontrando raiz de 3cos(2x) + 5x...\n\n");

    printf("\tTabulando...\n");
    printf("\t x || f(x) \n");
    
    // Recorre e imprime los valores de f(xi) desde el -4 al 4
    for( int i = -4; i < 5; i++ ){
        
        if( f(i)*f(i+1) < 0 ){

            intervalo.a = (double)i;
            intervalo.b = (double)i+1;
        }
        printf("\t%d || %lf\n", i, f(i));
    }

    // Realizamos bisección
    printf( "\nLa solucion con %lf de error es: %0.4lf", err, biseccion( f, intervalo, 0, err ));

}