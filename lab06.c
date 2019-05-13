#include <stdlib.h>
#include <stdio.h>

/* Adendos do programa
 * Primeira função implementada
 * Segunda função implementada
 * Falta implementar a terceira função
 * Tá somando as funções
 */

typedef struct No
{

    int dado ;
    struct No *prox ;

}No;

typedef struct No *pNo ;

pNo iniciaLista (  )
{

    return NULL ;

}

void imprimeListaRecursivamente ( pNo p )
{

    if ( p != NULL )
    {

        printf("%d ", p -> dado ) ; // declaração que imprime do head ao tail
        imprimeListaRecursivamente ( p -> prox ) ;

    }

}

void destroiListaIterativa ( pNo p )
{

    while ( p != NULL )
    {

        free ( p ) ;
        p = p -> prox ;

    }

}

// adiciona no tail da lista
pNo adicionaElemento ( pNo p, int e )
{

    pNo aux = malloc ( sizeof ( No ) ) ;
    pNo copia = malloc ( sizeof ( No ) ) ;

    if ( p == NULL )
    {

        aux -> dado = e ;
        aux -> prox = 0 ;

        return aux ;

    }

    aux -> dado = e ;
    aux -> prox = NULL ;

    copia = p ; // varíavel que serve apenas para percorrer até o fim da lista

    // isto não altera o valor verdadeiro de p
    while ( copia -> prox != NULL )
    {

        copia = copia -> prox ;

    }

    copia -> prox = aux ;

    return p ;

}

void destroiListaRecursiva ( pNo p )
{

    if ( p != NULL )
    {

        destroiListaRecursiva ( p -> prox ) ;

        free ( p ) ;

    }

}

pNo copiaListaRecursivamente ( pNo l1 )
{

    pNo aux = malloc ( sizeof ( No ) ) ;

    if ( l1 == NULL )
    {

        return NULL ;

    }

    aux -> dado = l1 -> dado ;
    aux -> prox = copiaListaRecursivamente ( l1 -> prox ) ;

    return aux ;

}

// adiciona um elemento no tail de uma lista recursivamente
pNo adicionaElementoTail  ( pNo p, int x )
{

    if ( p == NULL )
    {

        p = adicionaElemento ( p, x ) ;

        return p ;

    }

    p -> prox = adicionaElementoTail ( p -> prox, x ) ;

    return p ;

}

pNo criaLista ( int nReq )
{
    pNo p = iniciaLista (  ) ;

    for ( int i = 1; i <= nReq; i++ )
    {

        p = adicionaElemento ( p, i ) ;

    }

    return p ;

}

pNo criaListaReq ( int nReq )
{

    pNo p = iniciaLista ( ) ;
    int elem ;

    for ( int i = 0; i < nReq; i++ )
    {

        scanf("%d", &elem) ;
        p = adicionaElemento ( p, elem ) ;

    }

    return p ;

}

pNo criaChave ( int nChaves )
{

    pNo aux = iniciaLista (  ) ;

    for ( int i = 0; i < nChaves; i++ )
    {

        aux = adicionaElementoTail ( aux, 0 ) ;

    }

    return aux ;

}

pNo concatenaLista ( pNo l1, pNo l2)
{

    if ( l1 == NULL )
    {

        return l2 ;

    }

    l1 -> prox = concatenaLista ( l1 -> prox, l2 ) ;

    return l1 ;

}

// função que retorna a lista após uma operação de MTF
pNo MoveToFront ( pNo lista, pNo listaReq, int* soma, int nChaves )
{

    int elem = listaReq -> dado ;

    if ( elem > nChaves )
    {

        *soma = 0 ;

        return lista ;

    }

    if ( elem == lista -> dado ) // caso em que ele já está no começo da lista
    {

        *soma += 1 ;

        return lista ;

    }

    pNo copia = malloc ( sizeof ( No ) ) ;
    copia = copiaListaRecursivamente ( lista ) ;

    for ( int i = 0; i < nChaves; i++ )
    {

        *soma += 1 ;

        if ( elem == lista -> dado )
        {

            pNo percorre = copia ; // cópia para percorrer o vetor
            pNo novoVetor = iniciaLista (  ) ;

            novoVetor = adicionaElemento ( novoVetor, elem ) ; // copia apenas o primeiro valor na ponta

            for ( int j = i; j >= 0; j-- )
            {

                int valor2 = percorre -> dado ;
                percorre = percorre -> prox ;

                if ( j - 1 != -1 )
                {

                    novoVetor = adicionaElemento(novoVetor, valor2);

                }

            }

            // usar uma função pra concatenar dois vetores pelo tail aqui
            novoVetor = concatenaLista ( novoVetor, percorre ) ;

            return novoVetor ;

        }

        lista = lista -> prox ;

    }

    return copia ;

}

pNo tranpose ( pNo lista, pNo listaReq, int *soma, int nChaves )
{

    int elem = listaReq -> dado ;

    if ( elem > nChaves )
    {

        *soma = 0 ;

        return lista ;

    }

    if ( elem == lista -> dado ) // caso em que ele já está no começo da lista
    {

        *soma += 1 ;

        return lista ;

    }

    pNo copia = malloc ( sizeof ( No ) ) ;
    copia = copiaListaRecursivamente ( lista ) ;

    for ( int i = 0; i < nChaves; i++ )
    {

        *soma += 1 ;

        if ( elem == lista -> prox -> dado )
        {

            *soma += 1 ;

            pNo percorre = copia ; // cópia para percorrer o vetor
            pNo novoVetor = iniciaLista (  ) ;

            for ( int j = 0; j < nChaves; j++ )
            {

                if ( j == i )
                {

                    int valor1 = lista -> dado ;
                    lista = lista -> prox ;

                    int valor2 = lista -> dado ;
                    lista = lista -> prox ;

                    novoVetor = adicionaElementoTail ( novoVetor, valor2 ) ;

                    novoVetor = adicionaElementoTail ( novoVetor, valor1 ) ;

                    novoVetor = concatenaLista ( novoVetor, lista ) ;

                    return novoVetor ;

                }

                novoVetor = adicionaElementoTail ( novoVetor, copia -> dado ) ;
                copia = copia -> prox ;

            }

        }

        lista = lista -> prox ;

    }

    return copia ;

}

// função que devolve a lista da chave com o valor somado
pNo somaChave ( pNo lista, pNo *c, int elem, int *elemChave, int *posicao, int *valorPosicao )
{

    pNo percorreChave = (*c) ;

    pNo novoVetorChave = iniciaLista (  ) ;

    int soma = 1 ;

    while ( percorreChave != NULL && lista != NULL )
    {

        if ( elem == lista -> dado )
        {

            percorreChave -> dado += 1 ;

            *valorPosicao = percorreChave -> dado ;
            *elemChave = percorreChave -> dado ;

            soma = 0 ;

        }

        if ( soma  == 1 )
        {

            *posicao += 1 ;

        }

        novoVetorChave = adicionaElementoTail ( novoVetorChave, percorreChave -> dado ) ;
        percorreChave = percorreChave -> prox ;
        lista = lista -> prox ;

    }

    return novoVetorChave ;

}

// função que troca os valores da chave
pNo trocaChave ( pNo *c, pNo *lista, int elemChave, int *posicao )
{

    pNo copiaChave = malloc ( sizeof ( No ) ) ;
    copiaChave = copiaListaRecursivamente ( (*c) ) ;

    pNo listaNormal = malloc ( sizeof ( No ) ) ;
    listaNormal = copiaListaRecursivamente ( *lista ) ;

    pNo percorre = malloc ( sizeof ( No ) ) ;
    percorre = copiaListaRecursivamente ( *lista ) ;

    pNo percorreChave = copiaChave ;
    pNo novoVetorChave = iniciaLista (  ) ;

    pNo novoVetorLista = iniciaLista (  ) ;

    int valor = 0 ;
    int valorLista = 0 ;
    int adicionar = 0 ;
    int k = 0 ;
    int posFinal = 0 ;

    for ( int i = 0; i <= *posicao && percorre != NULL; i++ )
    {

        valorLista = percorre -> dado ;
        percorre = percorre -> prox ;

    }

    while ( percorreChave != NULL )
    {

        if ( elemChave >= percorreChave -> dado && adicionar == 0 )
        {

            novoVetorChave = adicionaElementoTail ( novoVetorChave, elemChave ) ;
            novoVetorLista = adicionaElementoTail ( novoVetorLista, valorLista ) ;

            valor = percorreChave -> dado ;
            valorLista = listaNormal -> dado ;

            for ( int i = 0; i < *posicao && (*lista) != NULL; i++ )
            {

                if ( elemChave >= copiaChave -> dado )
                novoVetorLista = adicionaElementoTail ( novoVetorLista, (*lista) -> dado ) ;

                (*lista) = (*lista) -> prox ;
                copiaChave = copiaChave -> prox ;

            }

            novoVetorLista = concatenaLista ( novoVetorLista, percorre ) ;

            adicionar = 1 ;

        }

        else if ( k == *posicao )
        {

            novoVetorChave = adicionaElementoTail ( novoVetorChave, valor ) ;

            posFinal = k ;

        }

        else
        {

            novoVetorChave = adicionaElementoTail ( novoVetorChave, percorreChave -> dado ) ;

            if ( adicionar == 0 )
            novoVetorLista = adicionaElementoTail ( novoVetorLista, listaNormal -> dado ) ;

        }

        k++ ;
        percorreChave = percorreChave -> prox ;
        listaNormal = listaNormal -> prox ;

    }

    *posicao = posFinal ;
    *lista = novoVetorLista ;

    return novoVetorChave ;

}

pNo montaChave ( pNo *c, int posicao )
{

    pNo percorre = malloc ( sizeof ( No ) ) ;
    percorre = copiaListaRecursivamente ( *c ) ;

    pNo novaLista = iniciaLista (  ) ;

    pNo listaTroca = malloc ( sizeof ( No ) ) ;
    listaTroca = copiaListaRecursivamente ( (*c) ) ;

    pNo novoVetor  = iniciaLista (  ) ;

    int valor = (*c) -> dado ; // maior valor da lista
    int k = 0 ;

    percorre = percorre -> prox ;

    if ( percorre == NULL )
    {

        return *c ;

    }

    valor = percorre -> dado ;

    while ( percorre != NULL )
    {

        if ( listaTroca -> dado < percorre -> dado )
        {

            novoVetor = adicionaElementoTail ( novoVetor, percorre -> dado ) ;
            novoVetor = adicionaElementoTail ( novoVetor, listaTroca -> dado ) ;

            listaTroca = listaTroca -> prox ;
            percorre = percorre -> prox ;

        }

        else
        {

            novoVetor = adicionaElementoTail ( novoVetor, listaTroca -> dado ) ;

        }


        if ( listaTroca != NULL )
        {

            listaTroca = listaTroca -> prox ;

        }

        if ( percorre != NULL )
        {

            percorre = percorre -> prox ;

        }

    }

    if ( listaTroca != NULL )
    {

        novoVetor = adicionaElementoTail ( novoVetor, listaTroca -> dado ) ;

    }

    return novoVetor ;

}

pNo count ( pNo lista, pNo listaReq, pNo *c, int *soma, int nChaves )
{

    int elem = listaReq -> dado ;
    int elemChave ;
    int posicao = 0 ; // posição do elemento que foi acrescentado
    int valorSoma = 0 ; // valor do elemento acrescentado
    int sair = 0 ;

    if ( elem > nChaves )
    {

        return lista ;

    }

    if ( elem == lista -> dado ) // caso em que ele já está no começo da lista
    {

        (*c)->dado += 1 ;

        *soma += 1 ;

        return lista ;

    }

    pNo copiaLista = malloc ( sizeof ( No ) ) ;
    pNo novaChave = malloc ( sizeof ( No ) ) ;

    (*c) = somaChave ( lista, c, elem, &elemChave, &posicao, &valorSoma ) ;

    for ( copiaLista = lista; sair == 0 && copiaLista != NULL ; copiaLista = copiaLista -> prox )
    {

        *soma += 1 ;

        if ( copiaLista -> dado == elem )
        {

            sair = 1 ;

        }

    }

    (*c) = trocaChave ( c, &lista, elemChave, &posicao ) ;
    (*c) = montaChave ( c, elemChave ) ;

    return lista ;

}

int opMTF ( pNo lista, pNo listaReq, int nChave, int nReq )
{

    int soma = 0 ;

    for ( int i = 0; i < nReq && listaReq != NULL; i++ )
    {

        int somaParc = 0 ;

        lista = MoveToFront ( lista, listaReq, &somaParc, nChave ) ;

        listaReq = listaReq -> prox ;

        soma += somaParc ;

        if ( listaReq == NULL )
        {

            return soma ;

        }

    }

    return soma ;

}

int oPTR ( pNo lista, pNo listaReq, int nChave, int nReq )
{

    int soma = 0 ;

    for ( int i = 0; i < nReq && listaReq != NULL; i++ )
    {

        int somaParc = 0 ;

        lista = tranpose ( lista, listaReq, &somaParc, nChave ) ;

        listaReq = listaReq -> prox ;
        soma += somaParc ;

        if ( listaReq == NULL )
        {

            return soma ;

        }

    }

    return soma ;

}

int opCont ( pNo lista, pNo listaReq, pNo *c, int nChave, int nReq )
{

    int soma = 0 ;

    for ( int i = 0; i < nReq; i++ )
    {

        int somaParc = 0 ;

        lista = count ( lista, listaReq, c, &somaParc, nChave ) ;

        /*printf("\ncaso : %d ", i) ;
        printf(" Contador : ") ;
        imprimeListaRecursivamente ( *c ) ;

        printf(" Vetor : ") ;
        imprimeListaRecursivamente ( lista ) ;*/

        listaReq = listaReq -> prox ;
        soma += somaParc ;

        if ( listaReq == NULL )
        {

            return soma ;

        }

    }

    return soma ;

}

// funçao principal de exemplo do programa
int main ( void )
{

    pNo listaReq = iniciaLista ( ) ;
    pNo chave = iniciaLista ( ) ;
    pNo lista = iniciaLista ( ) ;

    int nChaves ;
    int nReq ;
    int soma ;

    scanf("%d", &nChaves) ;
    scanf("%d", &nReq) ;

    listaReq = criaListaReq ( nReq ) ;
    chave = criaChave ( nChaves ) ;
    lista = criaLista ( nChaves ) ;

    soma = opMTF ( lista, listaReq, nChaves, nReq ) ;

    printf("%d ", soma) ;

    soma = 0 ;

    soma = oPTR ( lista, listaReq, nChaves, nReq ) ;

    printf("%d ", soma) ;

    soma = 0 ;

    soma = opCont ( lista, listaReq, &chave, nChaves, nReq ) ;

    printf("%d", soma) ;
    printf("\n") ;

    destroiListaIterativa ( lista ) ;
    destroiListaIterativa ( chave ) ;
    destroiListaIterativa ( listaReq ) ;

    return 0 ;

}