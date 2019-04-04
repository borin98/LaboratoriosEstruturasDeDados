#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("      +0 +1 +2 +3 +4 +5 +6 +7 \n") ;
    printf("    +------------------------ \n") ;

    // int soma = 0 ;

    for ( int i = 32; i < 127; i++ )
    {

        printf ( "%3d | ",i );

        for ( int j = 0; j < 8; j++ )
        {


            if ( ( i + j ) != 127 )
            {

                printf(" %c ", ( i + j ) ) ;

            }

            else if ( ( i + j  ) == 127 )
            {

                printf("   ") ;

            }

            if ( j == 7 )
            {

                i += j ;

                //printf("    ") ;

            }

        }

        printf("\n");

    }

}