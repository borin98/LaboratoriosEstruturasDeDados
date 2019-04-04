#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero;
    int frequencia ;
    char simb ;

    while ( scanf("(%d,%d,%c) ", &numero, &frequencia, &simb) != EOF )
    {

        printf("%3d |",numero) ;

        for ( int j = 0; j < frequencia ; j++ )
        {

            printf("%c", simb) ;

        }

        printf(" %d\n",frequencia) ;

    }

    return 0 ;

}