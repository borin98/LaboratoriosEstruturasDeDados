#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Pessoa
{

    char nomePessoas [ 1000 ] [ 50 ] ;

    int vetorConhecem [ 1000 ] ;
    int vetorCelebridade [ 1000 ] ;

    int quantPessoas ;

} Pessoa ;

typedef struct Pessoa *pNo ;

pNo inicializaVetor (  )
{

    pNo Pessoas = malloc ( sizeof ( Pessoa ) );

    Pessoas -> quantPessoas = 0 ;

    for ( int i = 0; i < 1000; i++ )
    {

        Pessoas -> vetorConhecem [ i ] = 0 ;
        Pessoas -> vetorCelebridade [ i ] = 0 ;

    }

    for ( int k = 0; k < 1000; k++ )
    {

        for ( int j = 0; j < 50; j++ )
        {

            Pessoas -> nomePessoas [ k ] [ j ] ='\0';

        }

    }

    return Pessoas ;

}

void informacaoNomes ( pNo Pessoas )
{

    for ( int i = 0 ; i < Pessoas -> quantPessoas; i++ )
    {

        printf("Nome : %s\n", Pessoas -> nomePessoas [ i ] ) ;
        printf("quantas pessoas conhece : %d\n", Pessoas -> vetorConhecem [ i ] ) ;
        printf("quantas pessoas conhecem ela : %d\n", Pessoas -> vetorCelebridade [ i ] ) ;

    }


}

void funcaoFamoso ( pNo Pessoas )
{


    for ( int i = 0; i < Pessoas -> quantPessoas && Pessoas ->quantPessoas > 0 ; i++ )
    {

        if ( Pessoas -> vetorConhecem [ i ] == 0 &&
             Pessoas -> vetorCelebridade [ i ] == ( Pessoas -> quantPessoas - 1 ) )
        {

            printf("%s e' celebridade.\n", Pessoas -> nomePessoas [ i ] ) ;

            return ;

        }

    }

    printf("Nao ha' celebridade.\n") ;

}

int verificaNomeMatriz ( pNo p, char* str)
{

    for (int k = 0; k < p->quantPessoas; k++)
    {


        if ( strcmp(p->nomePessoas [ k ], str) == 0 ) // ve se o nome1 apareceu já na matriz de nomes
        {

            return k ;

        }

    }

    return -1 ;

}

void realizaOperacoes (  )
{

    pNo Pessoas ;

    Pessoas = inicializaVetor ( ) ;

    char *nome = NULL ;
    size_t len = 0 ;
    char *nomePessoa1 = malloc ( 50 * sizeof ( char ) ) ;
    char *nomePessoa2 = malloc ( 50 * sizeof ( char ) ) ;
    int k ;
    int l ;
    int aux ;

    while ( getline ( &nome, &len, stdin ) != EOF  )
    {

        l = 0 ;
        aux = 0 ;

        for ( int i = 0;  i < len && nome[i] !='\n' && aux == 0; i++)
        {

            if ( nome [ i ] == 'c' && nome [ i + 1 ] == 'o' &&
                 nome [ i + 2 ] == 'n' && nome [ i + 3 ] == 'h' &&
                 nome [ i + 4 ] == 'e' && nome [ i + 5 ] == 'c' &&
                 nome [ i + 6 ] == 'e')
            {

                nomePessoa1 [ 0 ] = '\0' ;
                nomePessoa2 [ 0 ] = '\0' ;

                k = ( i + 8 ) ;
                aux = 1 ;

                for ( int j = 0; j < i-1; j++ )
                {

                    nomePessoa1 [ j ] =  nome [ j ] ;

                }

                nomePessoa1 [ i - 1 ] = '\0' ;

                while ( nome [ k ] !='\n' )
                {

                    nomePessoa2 [ l ] = nome [ k ] ;
                    l++ ;
                    k++ ;

                }

                nomePessoa2 [ l ] = '\0' ;

            }

        }

        if ( Pessoas -> quantPessoas == 0 && strcmp ( nomePessoa1, nomePessoa2 ) != 0 )
        {

            strcpy ( Pessoas -> nomePessoas [ 0 ], nomePessoa1 ) ;
            strcpy ( Pessoas -> nomePessoas [ 1 ], nomePessoa2 ) ;

            Pessoas -> vetorCelebridade [ 1 ] = 1 ;
            Pessoas -> vetorConhecem [ 0 ] = 1 ;

            Pessoas -> quantPessoas = 2 ;

        }

        else
        {

            if ( strcmp ( nomePessoa1, nomePessoa2 ) != 0 )
            {

                int verif ;

                verif = verificaNomeMatriz ( Pessoas, nomePessoa1 ) ;

                if ( verif >= 0 )
                {

                    Pessoas -> vetorConhecem [ verif ] += 1 ;

                }

                else
                {

                    strcpy ( Pessoas -> nomePessoas [ Pessoas -> quantPessoas ], nomePessoa1 ) ;
                    Pessoas -> quantPessoas += 1 ;

                }

                verif = verificaNomeMatriz ( Pessoas, nomePessoa2 ) ;

                if ( verif >= 0 )
                {

                    Pessoas -> vetorCelebridade [ verif ] += 1 ;

                }

                else
                {

                    strcpy ( Pessoas -> nomePessoas [ Pessoas -> quantPessoas ], nomePessoa2 ) ;

                    Pessoas -> vetorCelebridade [ Pessoas -> quantPessoas ] += 1 ;

                    Pessoas -> quantPessoas += 1 ;

                }

            }

        }

    }

    funcaoFamoso ( Pessoas ) ;

    free ( Pessoas ) ;
    free ( nomePessoa1 ) ;
    free ( nomePessoa2 ) ;

}

int main ( void )
{

    realizaOperacoes ( ) ;

    return 0 ;

}