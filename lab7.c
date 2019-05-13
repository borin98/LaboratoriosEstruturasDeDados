#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista
{

    char* str ;
    int* dadoInt ;
    float* dadofloat ;
    char* c ;

    struct Lista *prox ;

} Lista ;

typedef struct Lista *pNo ;

// função genérica que adiciona um elemento pelo tail da lista
void adicionaTail ( char comando, pNo *lista )
{

    pNo aux = malloc ( sizeof ( Lista ) ) ;

    pNo ultimo = *lista ;

    if ( comando == 's' )
    {

        char* str = malloc ( 128 * sizeof ( char ) ) ;
        char c ; // para pegar o espaço

        scanf("%c", &c ) ;

        fgets ( str, 128, stdin ) ;

        int tam = strlen ( str ) ;

        str [ tam - 1 ] = 0 ;

        aux -> str = malloc ( 128 * sizeof ( char ) ) ;
        aux -> str = str ;

    }

    else if ( comando == 'd' )
    {

        int* dadoInt = malloc ( sizeof ( int ) ) ;
        scanf("%d", dadoInt ) ;

        aux -> dadoInt = malloc ( sizeof ( int ) ) ;
        aux -> dadoInt = dadoInt ;

    }

    else if ( comando == 'f' )
    {

        float* dadoFloat = malloc ( sizeof ( float ) ) ;
        scanf("%f", dadoFloat ) ;

        aux -> dadofloat = malloc ( sizeof ( float ) ) ;
        aux -> dadofloat = dadoFloat ;

    }

    else
    {

        char* c = malloc ( sizeof ( char ) ) ;

        scanf(" %c", c ) ;

        aux -> c = malloc ( sizeof ( char ) ) ;
        aux -> c = c ;

    }

    if ( *lista == NULL )
    {

        *lista = aux ;

        return ;

    }

    while ( ultimo -> prox != NULL )
    {

        ultimo = ultimo -> prox ;

    }

    ultimo -> prox = aux ;

}

void criaNos ( pNo *lista, int n )
{

    char op ;

    pNo percorre = malloc ( sizeof ( Lista ) ) ;
    percorre = (*lista) ;

    for ( int i = 0; i < n; i++ )
    {

        scanf(" %c", &op ) ;

        adicionaTail ( op , &percorre ) ;

    }

    (*lista) = percorre ;

}

void imprimeLista ( pNo p )
{

    pNo percorre ;

    for ( percorre = p; percorre != NULL; percorre = percorre -> prox )
    {

        if ( percorre -> str != NULL )
        {

            printf("%s ", percorre -> str ) ;

        }

        else if ( percorre -> dadoInt != NULL )
        {

            printf("%d ",  *percorre -> dadoInt ) ;

        }

        else if ( percorre -> dadofloat != NULL )
        {

            printf("%0.4f ", *percorre -> dadofloat ) ;

        }

        else
        {

            printf("%c ", *percorre -> c ) ;

        }

    }

}

void reverse ( pNo *lista )
{

    pNo copia ;

    pNo final ;
    pNo troca ;
    pNo post ;

    pNo percorre ;
    percorre = *lista ;

    pNo prev = *lista ;

    pNo target ;

    int n1 ;
    int n2 ;
    int aux ;

    int i = 0 ;
    int k = 0 ;

    scanf("%d %d", &n1, &n2) ;

    if ( n1 != n2 )
    {

        if ( n1 > n2 ) // ajustando para sempre deixar o segundo o maior valor
        {

            aux = n2 ;
            n2 = n1 ;
            n1 = aux ;

        }

        while ( percorre != NULL )
        {

            if ( ( i + 1 ) == n1 || n1 == 0 )
            {

                for ( k = i ; k < n2 - 1; k++ )
                {

                    percorre = percorre -> prox ;

                }

                target = percorre -> prox ;

                post = target -> prox ;

                int auxN2 = n2 ;

                auxN2 -= 2 ;

                final = target ;

                target -> prox = percorre ;

                if ( n1 == 0 )
                {

                    target = target -> prox ;

                    while ( auxN2 != - 1 )
                    {

                        copia = *lista ;

                        for ( int i = 0; i < auxN2; i++ )
                        {

                            copia = copia -> prox ;

                        }

                        target -> prox = copia ;
                        target = target -> prox ;

                        auxN2 -- ;
                    }

                    target -> prox = post ;

                    (*lista) = final ;

                    return ;

                }

                pNo perTarget = target ;

                perTarget = perTarget -> prox ;

                if ( n1 + 1 == n2 )
                {

                    pNo perTar = target ;

                    perTar -> prox = percorre ;
                    percorre -> prox = post ;

                    prev -> prox = perTar ;

                    return ;

                }

                while ( n2 != n1 )
                {

                    copia = *lista ;

                    for ( int i = 0; i < n2; i++ )
                    {

                        copia = copia -> prox ;

                    }

                    perTarget -> prox = copia ;
                    perTarget = perTarget -> prox ;

                    n2 -- ;

                }


                troca = prev -> prox ;
                troca -> prox = post ;

                perTarget -> prox = troca ;

                prev -> prox = target ;

                return ;

            }

            i++ ;
            percorre = percorre -> prox ;
            prev = prev -> prox ;

        }

    }

}

void transpose ( pNo *lista, int n )
{

    pNo percorre = *lista ;

    pNo noTroca = *lista ;

    pNo ant = *lista ;

    pNo percorreAux = *lista ;

    pNo target ;
    pNo post ;
    pNo noN2 ;

    int n1 ;
    int n2 ;
    int n3 ;

    int aux ;

    int i = 0 ;
    int k;
    int j ;

    scanf("%d %d %d", &n1, &n2, &n3) ;

    if ( n1 == 0 && n3 == -1 )
    {

        return ;

    }

    if ( n1 != n2 || n2 != n3 || n3 != n1 )
    {

        // colocar a função de troca de valores

        while ( percorre != NULL )
        {

            if ( n3 == -1 )
            {

                if ( n1 == n2 )
                {

                    pNo headAux = *lista ;

                    for ( int m = 0; m < n2 - 1; m++ )
                    {

                        percorre = percorre -> prox ;

                    }

                    target = percorre -> prox ;
                    post = target -> prox ;

                    percorre -> prox = post ;

                    target -> prox = headAux ;

                    (*lista) = target ;

                    return ;

                }

                int l = 0 ;

                for ( int k = 0; k < n2 - 1; k++ )
                {

                    percorre = percorre -> prox ;

                    if ( l < n1 - 1 )
                    {

                        percorreAux = percorreAux -> prox ;

                        l ++ ;

                    }

                }

                pNo headAux = percorreAux -> prox ;

                target = percorre -> prox ;
                post = target -> prox ;

                target -> prox = percorreAux ;
                percorreAux -> prox = post ;

                headAux -> prox = target ;

                (*lista) = headAux ;

                return ;

            }

            if ( ( i + 1 ) == n3 || n3 == 0 )
            {

                if ( n1 > n2 ) // ajustando para sempre deixar o segundo o maior valor
                {

                    aux = n2 ;
                    n2 = n1 ;
                    n1 = aux ;

                }

                int l = 0;

                for ( k = i; k < n3 - 1; k++ )
                {

                    percorre = percorre -> prox ;

                    if ( l < n1 - 1 )
                    {

                        percorreAux = percorreAux -> prox ;

                        l ++ ;

                    }

                }

                if ( n3 == n - 1 )
                {

                    target = percorre -> prox ;
                    post = target -> prox ;

                    if ( n1 == 0 )
                    {

                        if ( n2 == 0 )
                        {

                            pNo headLista = percorreAux -> prox ;
                            percorreAux -> prox = post ;

                            target -> prox = percorreAux ;

                            (*lista) = headLista ;

                            return ;

                        }

                    }

                    pNo headAux = percorreAux -> prox ;
                    target -> prox = headAux ;

                    percorre -> prox = post ;

                    percorreAux -> prox = target ;

                    return ;

                }

                if ( n3 == 0 )
                {

                    if ( n1  == 1 )
                    {

                        return ;

                    }

                    if ( n1 == n2 )
                    {

                        pNo copia = *lista ;
                        pNo noAux = percorre -> prox ;
                        pNo headAux = noAux -> prox ;

                        for ( k = 0; k < n2 - 1; k ++ )
                        {

                            percorre = percorre -> prox ;

                        }

                        target = percorre -> prox ;
                        post = target -> prox ;

                        target -> prox = headAux ;

                        percorre -> prox = noAux ;
                        noAux -> prox = post ;

                        copia -> prox = target ;

                        return ;

                    }

                    int l = 0 ;

                    pNo auxLista = *lista ;

                    for ( int m = 0; m < n2 - 1; m++ )
                    {

                        if ( l < n1 - 1 )
                        {

                            noTroca = noTroca -> prox ;

                            if ( l < n1 - 2 )
                            {

                                auxLista = auxLista -> prox ;

                            }

                            l++ ;

                        }

                        percorre = percorre -> prox ;

                    }

                    pNo headAux = noTroca -> prox ;

                    target = percorre -> prox ;
                    post = target -> prox ;

                    noTroca -> prox = post ;

                    target -> prox = noTroca ;
                    percorre -> prox = target ;

                    auxLista -> prox = headAux ;

                    (*lista) = auxLista ;

                    return ;

                }

                target = percorre -> prox ;
                post = target -> prox ;

                if ( n1 == 0 )
                {

                    target -> prox = ant ;

                    for ( int k = 0; k < n2; k++ )
                    {

                        ant = ant -> prox ;

                    }

                    ant -> prox = post ;
                    percorre -> prox = target ;

                    (*lista) = percorre ;

                    return ;

                }

                for ( j = 0; j < n1 - 1; j++ )
                {

                    ant = ant -> prox ;

                }

                noN2 = ant -> prox ;

                if ( n1 == n2 )
                {

                    ant -> prox = noN2 -> prox ;

                    percorre -> prox = target ;

                    target -> prox = noN2 ;
                    noN2 -> prox = post ;

                    (*lista) = ant ;

                    return ;

                }

                percorre -> prox = post ;

                target -> prox = noN2 ;

                ant -> prox = target ;

                (*lista) = ant ;

                return;

            }

            percorre = percorre -> prox ;
            i ++ ;

        }

    }


}

// função que realiza a lógica das operações de reverse e transpose
void operacoesRT ( pNo *lista, int n, int tam )
{

    char c ;

    // primeiro print sem a lista modificada
    imprimeLista ( *lista ) ;

    printf("\n") ;

    for ( int i = 0; i < n; i++ )
    {

        scanf(" %c", &c) ;

        if ( c == 'r' )
        {

            reverse ( lista ) ;

        }

        else if ( c == 't' )
        {

            transpose ( lista, tam ) ;

        }

        imprimeLista ( *lista ) ;
        printf("\n") ;

    }

}

void liberaMemoria ( pNo* p )
{

    pNo aux ;

    for ( aux = *p; aux != NULL; aux = aux -> prox )
    {

        free ( aux ) ;

    }

    *p = aux ;

}

int main ( void )
{

    pNo lista = NULL ;

    int n ;
    int numOp ;

    char c ; // variável para pegar o \n após o scanf

    scanf ("%d", &n ) ;
    c = getchar (  ) ;

    criaNos ( &lista, n ) ;

    scanf("%d", &numOp ) ;
    c = getchar (  ) ;

    operacoesRT ( &lista, numOp, n ) ;

    liberaMemoria ( &lista ) ;

    return 0 ;

}