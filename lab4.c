#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// função que coloca o novo valor de z na matriz desejada
double** novaMatriz ( int linha, double dP , double media, double** matriz )
{

    int aux = 1 ;
    double z ;

    for ( int i = 0; i < linha; i++ )
    {

        for ( int j = 0; j < aux; j++ )
        {

            z = ( matriz [ i ] [ j ] - media )/dP ;

            matriz [ i ] [ j ] = z ;

        }

        aux++ ;

    }

    return matriz ;

}

double pegaDesvioPadrao ( int linha, int nElementos, double media, double** matriz )
{

    int aux = 1 ;
    double soma = 0 ;

    for ( int i = 0; i < linha; i++ )
    {

        for ( int j = 0; j < aux; j++ )
        {

            soma += pow ( ( matriz [ i ] [ j ] - media ), 2 ) ;

        }

        aux++ ;

    }

    soma /= nElementos ;

    return sqrt ( soma ) ;

}

double pegaMedia ( int linha , int qElementos, double** matriz )
{

    int aux = 1 ;
    double soma = 0 ;

    for ( int i = 0; i < linha; i++ )
    {

        for ( int j = 0; j < aux; j++ )
        {

            soma += matriz [ i ] [ j ] ;

        }

        aux++ ;

    }

    return soma/qElementos ;

}

// função que inicializa o jagged array
double** inicializaMatriz ( int linha )
{

    double **matriz = malloc ( linha*sizeof ( double* ) ) ;

    int aux = 1 ;
    double elemento = 0 ;

    for ( int i = 0; i < linha; i++ )
    {

        matriz [ i ] = malloc ( aux * sizeof ( double ) ) ;

        for ( int j = 0; j < aux; j++ )
        {

            scanf("%lf",&elemento) ;
            matriz [ i ] [ j ] = elemento ;

        }

        aux++ ;

    }

    return matriz ;

}

// função alfa que printa o valor dos elementos da matriz
void printaMatriz ( int lin, double media, double dP, double** matriz )
{

    int coluna = 1 ;

    for ( int i = 0; i < lin; i++ )
    {

        for ( int j = 0; j < coluna; j++ )
        {

            printf("%.12f ", matriz [ i ] [ j ] ) ;

        }

        printf("\n") ;

        coluna++ ;

    }

    printf("\n%.12f %.12f \n", media, dP ) ;

}

int main ( void )
{

    int lin ;
    double **matriz = NULL ;

    scanf ( "%d", &lin ) ;

    int quantElementos = ( ( lin*lin ) + lin ) / 2 ;

    matriz = inicializaMatriz ( lin ) ;

    double media = pegaMedia ( lin, quantElementos, matriz ) ;
    double dP = pegaDesvioPadrao ( lin, quantElementos, media, matriz ) ;

    matriz = novaMatriz ( lin, dP, media, matriz ) ;

    printaMatriz ( lin, media, dP, matriz ) ;

    free ( matriz ) ;

    return 0 ;

}

