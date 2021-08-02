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

void tabular_funcion( double* inter ){
    
    printf("\n\t\t\tTabulando...\n\n");
    printf("\t\t\t x || f(x) \n");
    
    // Recorre e imprime los valores de f(xi) desde el -4 al 4
    for( int i = -4; i < 5; i++ ){
        
        if( f(i)*f(i+1) < 0 ){

            inter[a] = (double)i;
            inter[b] = (double)i + 1;
        }
        printf("\t\t\t%d || %lf\n", i, f(i));
    }

    printf("\n\t\tIntervalo a trabajar: [%0.0lf, %0.0lf]\n", inter[a], inter[b]);
}

int menu(){

    printf("\t\tELIJA UN METODO PARA RESOLVER LA FUNCION\n\n");
    printf("\t\t\t1. Biseccion\n");
    printf("\t\t\t2. Regla Falsa\n");
    printf("\t\t\t3. Newton - Raphson\n\n");
    printf("\t\t\t4. Salir\n\n");
    printf("\t\t\t--> ");

    int resp;
    scanf("%d", &resp);
    return resp;
}


// Driver program
int main(){
    // Inter intervalo;
    double inter[INTERVAL_TAM] = {0.0};
    double err;

    printf("\n\tIntroduzca el error aceptable para la aproximacion: ");
    scanf("%lf", &err);

    while(1){
        switch(menu()){
            case 1:    
                tabular_funcion( inter );
                printf("\n\t\tEncontrando raiz de 3cos(2x) + 5x...\n\n");        
                printf( "\n\t\t\tBISECCION\n\tLa solucion con %lf de error es: %0.4lf\n\n", err, biseccion( f, inter, 0, err ));
                break;
            case 2:
                tabular_funcion( inter );
                printf("\n\t\tEncontrando raiz de 3cos(2x) + 5x...\n\n");        
                printf("\n\t\t\tREGLA FALSA\n\tLa solucion con %lf de error es: %0.4lf\n\n", err, regla_falsa( f, inter, 0, err ));
                break;
            case 3:
                tabular_funcion( inter );
                printf("\n\t\tEncontrando raiz de 3cos(2x) + 5x...\n\n");     
                printf("\n\t\t\tNEWTON-RAPHSON\n\tLa solución con %lf de error es: %0.4lf\n\n", err, newton_raphson( f, g, h, inter, 0, err ));
                break;
            case 4:
                exit(1);
            default:
                printf("Opcion invalida.");
        }
    }
}