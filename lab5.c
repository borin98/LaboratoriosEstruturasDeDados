#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Adendos do programa
 * Precisa verificar se a insert-first estÃ¡ funcionando ( parece funcionar )
 * estÃ¡ esvaziando a cada interaÃ§Ã£o do programa
 * precisa realizar o caso em que o Ãºtimo Ã© a ponta
 * jÃ¡ implementandado a funÃ§Ã£o que remove o Ãºltimo tambÃ©m
 * jÃ¡ fiz o tratamento do caso em que ele adiciona os casos vazios
 */

typedef struct Vetor
{

    int *v ;
    int primeiro ;
    int ultimo ;
    int tam ;
    int nElementos ;
    int dobrou ;

} Vetor ;

typedef struct Vetor *pNo ;

pNo rediVetor ( pNo p )
{

    pNo aux = p;

    if ( p -> nElementos == 0 )
    {

        return aux ;

    }

    if ( p -> tam > 1 )
    {

        //printf("\nDiminuindo o tamanho !!!\n") ;
        int tamAux = p -> tam / 2 ;
        int *vetAux = malloc ( tamAux*sizeof ( int ) ) ;
        int j = 0 ;
        int prim = p -> primeiro ;
        int quanCopias = 0 ;

        for ( int i = 0; i < tamAux; i++ )
        {

            vetAux [ i ] = 0 ;

        }

        while ( p -> ultimo != prim && p -> nElementos > 0 )
        {

            vetAux [ j ] = p -> v [ prim ] ;
            j ++ ;
            prim ++ ;
            quanCopias ++ ;

        }

        vetAux [ j ] = p -> v [ prim ] ;

        aux -> tam = tamAux ;
        aux -> v = vetAux ;
        aux -> primeiro = 0 ;
        aux -> ultimo = quanCopias ;

    }

    return aux ;

}

pNo removeLast ( pNo p )
{

    if ( p -> ultimo + 1 == p -> tam )
    {

        p -> ultimo = 0 ;

    }

    else
    {

        p -> ultimo -- ;

    }

    if ( p -> nElementos > 0 )
    {

        p -> nElementos -- ;

    }

    return p ;

}

pNo removeFirst ( pNo p )
{

    if ( p -> primeiro + 1 == p -> tam )
    {

        p -> primeiro = 0 ;

    }

    else
    {

        p -> primeiro ++ ;

    }

    if ( p -> nElementos > 0 )
    {

        p -> nElementos -- ;

    }

    return p ;

}

void printFirst ( pNo p )
{

    if ( p -> nElementos > 0 )
    {

        if ( p -> tam == 1 )
        {

            p -> primeiro = p -> ultimo ;

        }

        printf("%d\n", p -> v [ p -> primeiro ] ) ;

    }

}

void printLast ( pNo p )
{

    if ( p -> nElementos > 0 )
    {

        if ( p -> tam == 1 )
        {

            p -> ultimo = p -> primeiro ;

        }

        printf("%d\n", p -> v [ p -> ultimo ] ) ;

    }

}

void printaVetor ( pNo p )
{

    if ( p -> tam == 1 )
    {

        p -> ultimo = p -> primeiro ;

    }

    for ( int i = 0; i < p -> tam; i++ )
    {

        printf("%d ", p -> v [ i ] ) ;

    }

    printf("\nPrimeiro elemento da fila : %d\n", p -> v [ p -> primeiro ] ) ;
    printf("ultimo elemento : %d", p -> v [ p -> ultimo ] ) ;
    printf("\n") ;

}

void isEmpty ( pNo p )
{

    if ( p -> nElementos == 0 )
    {

        printf("yes\n") ;

        return ;

    }

    printf("no\n") ;

}

pNo insertLast ( pNo p, int n )
{

    if ( p -> tam == 1 )
    {

        p -> ultimo = 0 ;
        p -> nElementos ++ ;
        p -> v [ p -> ultimo ] = n ;

        return p ;

    }

    p -> ultimo ++ ;
    p -> nElementos ++;
    p -> dobrou = 0 ;
    p -> v [ p -> ultimo ] = n ;

    return p ;

}

pNo dobraTamanho ( pNo p )
{

    pNo aux = p ;

    if ( aux -> nElementos == aux -> tam )
    {

        //printf("dobrou de tamaho\n") ;

        p -> dobrou = 1 ;

        int n = 2*aux -> tam ;

        //printf("tamanho atual : %d\n", n) ;

        int *vet = malloc ( ( n )*sizeof ( int ) ) ;
        int i = 0 ;

        do
        {

            vet [ i ] = p -> v [ ( p -> primeiro + i )%p->tam ] ;
            i++ ;

        } while (  i < p -> tam ) ;

        aux -> ultimo = p -> tam - 1 ;
        aux -> v = vet ;
        aux -> tam = n ;
        aux -> primeiro = 0 ;

    }

    return aux ;

}

// antes de inserir, tem que verificar se dÃ¡ pra colocar mais elementos nele
pNo insertFirst ( pNo p, int n )
{

    if ( p -> tam == 1 )
    {

        p -> primeiro = 0 ;
        p -> nElementos ++ ;
        p -> v [ p -> primeiro ] = n ;

        return p ;

    }

    p -> primeiro -- ;
    p -> nElementos ++;
    p -> dobrou = 0 ;

    if ( p -> primeiro  < 0 )
    {

        p -> primeiro = p -> tam - 1 ;

    }

    else if ( p -> primeiro == p -> tam )
    {

        p -> primeiro = p -> tam - 1 ;

    }

    p -> v [ p -> primeiro ] = n ;

    return p ;

}

pNo inicializaVetor (  )
{

    pNo vetor = malloc ( sizeof ( Vetor ) ) ;

    vetor -> primeiro = 0 ;
    vetor -> ultimo = 1 ;
    vetor -> tam = 1 ;
    vetor -> nElementos = 0 ;
    vetor -> dobrou = 1 ;

    vetor -> v = malloc ( sizeof ( int ) ) ;
    vetor -> v [0] = 0 ;

    return vetor ;

}

int main ( void )
{

    pNo vetor = inicializaVetor (  ) ;
    char teste[12] ;
    int num ;
    int conv = 0 ;

    while ( scanf ( "%s", teste ) != EOF )
    {
        //printf("%s\n", teste) ;

        if ( strcmp ( teste, "exit" ) != 0 ) // caso seja diferente da funÃ§Ã£o exit
        {

            if ( teste [ 0 ] == 'i' && teste [ 1 ] == 'n' && teste [ 2 ] == 's' &&
                 teste [ 3 ] == 'e' && teste [ 4 ] == 'r' && teste [ 5 ] == 't' &&
                 teste [ 7 ] == 'f' && teste [ 8 ] == 'i' && teste [ 9 ] == 'r' &&
                 teste [ 10 ] == 's' && teste [ 11 ] == 't' )
            {

                conv = scanf("%d", &num ) ;

                if ( conv != 0 )
                {

                    vetor = dobraTamanho ( vetor ) ;

                    vetor = insertFirst ( vetor, num ) ;

                }
            }

            else if ( strcmp ( teste, "is-empty" ) == 0 )
            {

                isEmpty ( vetor ) ;

            }

            else if ( strcmp ( teste, "insert-last" ) == 0 )
            {

                conv = scanf("%d", &num ) ;

                if ( conv != 0 )
                {

                    vetor = dobraTamanho ( vetor ) ;

                    vetor = insertLast ( vetor, num ) ;

                }


            }

            else if ( strcmp ( teste, "print-last" ) == 0 )
            {

                printLast ( vetor ) ;

            }

            else if ( strcmp ( teste, "print-first" ) == 0 )
            {

                printFirst ( vetor ) ;

            }

            else if (   teste [ 0 ] == 'r' && teste [ 1 ] == 'e' && teste [ 2 ] == 'm' &&
                        teste [ 3 ] == 'o' && teste [ 4 ] == 'v' && teste [ 5 ] == 'e' &&
                        teste [ 7 ] == 'f' && teste [ 8 ] == 'i' && teste [ 9 ] == 'r' &&
                        teste [ 10 ] == 's' && teste [ 11 ] == 't' )
            {

                vetor = removeFirst ( vetor ) ;

            }

            else if ( strcmp ( teste, "remove-last" ) == 0 )
            {

                vetor = removeLast ( vetor ) ;

            }

            if ( vetor -> tam - vetor -> nElementos >= 3 * vetor -> nElementos )
            {

                vetor = rediVetor ( vetor ) ;

            }

           // printaVetor ( vetor ) ;

           // printf("\n") ;

            for ( int i = 0; i < 13 && teste [ i ] != '\0'; i++ )
            {

                teste [ i ] = '\0' ;

            }

        }

        else if ( strcmp ( teste, "exit" ) == 0 )
        {

            free ( vetor ) ;
            return 0 ;

        }

    }

}