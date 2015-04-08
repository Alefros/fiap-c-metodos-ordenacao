#include <stdio.h>
#include <stdlib.h>

 /**------------------------------------------------------------
 '       NopsStraps - 3 SIS                                     '
 '                                                              '
 '       Alef Santos                                            '
 '       Viviane Barros                                         '
 '       Lucas Vitoreti                                         '
 '       Marcos JR.                                             '
 '                                                              '
 '   Email da Professora: profadriane.colossetti@fiap.com.br    '
 '                                                              '
 /**----------------Variáveis Globais-------------------------**/

            int vetorDesordenado[]={5,9,14,2,8,1};
            int tamanhoDoVetorDesordenado=6;
            int vetor[6];
            int ordenado = 0;

/**------------------Escopo das Funções-----------------------**/

            void implementaMenu();
            void direta(int v[6]);
            void shellSort(int vetor[tamanhoDoVetorDesordenado], int tamanhoDoVetorDesordenado);
            void bubbleSort(int vetor[tamanhoDoVetorDesordenado]);
            void quickSort(int vetorDesordenado[tamanhoDoVetorDesordenado], int inicio, int fim);
            void heapsort(int a[], int n);
            void selectionSort( int vetorDesordenado[], int tamanhoVetor );
            void trocarPosicaoValores( int *posicaoA, int *posicaoB );
            void imprimir(int a[6]);
            void menuOrdenarBuscar();
            void menuBuscar();
            void buscaSequencial(int vetorRecebido[6], int elementoRecebido);
            void buscaBinaria(int vetorRecebido[6], int elementoRecebido);

/**---------------------------------------------------------------------------------------------------------**/

    int main() /**As funções utilizadas, foram separadas, o main só está sendo utilizado para exibir o menu =D **/
    {
        printf("\n          Bem Vindo Ao Programa !! ");
        menuOrdenarBuscar();
        return 0;
    }

    void menuOrdenarBuscar()
    {
        int escolha=0;
        do
        {
            printf("\n\n- - - - - Escolha Entre Ordenar ou Buscar - - - - - \n");
            printf("\n");
            printf("\n          1 - Ordenar");
            printf("\n          2 - Buscar");
            printf("\n          3 - Limpar Tela\n\n");
            scanf("%d",& escolha);
            switch(escolha)
            {
                case 1:
                {
                    implementaMenu();
                    break;
                }
                case 2:
                {
                    menuBuscar();
                    break;
                }
                case 3:
                {
                    system("cls");
                    break;
                }
            }
        }while(escolha!=0);
    }
     void menuBuscar()
    {
        int escolhaBusca=0, elemento=-1;
        do
        {
            printf("\n\nQual Elemento Sera Procurado ?\n");
            scanf("%d",& elemento);
            printf("\nQual Modo Ira Ser Usado Para Busca ?\n");
            printf("\n           0 - Sair");
            printf("\n           1 - Sequencial");
            printf("\n           2 - Binaria");
            printf("\n           3 - Hashing");
            printf("\n           4 - Limpar Tela\n\n ");
            scanf("%d",& escolhaBusca);
            switch(escolhaBusca)
            {
                case 1:
                {
                    if (ordenado==0)
                    {
                        buscaSequencial(vetorDesordenado, elemento);
                    }
                    if (ordenado==1)
                    {
                        buscaSequencial(vetor, elemento);
                    }
                    break;
                }
                case 2:
                {
                     if (ordenado==0)
                    {
                        printf("Favor Ordenar o Vetor");
                        implementaMenu();
                    }
                    else
                    if (ordenado==1)
                    {
                        printf("Modo de Busca Binaria");
                        buscaBinaria(vetor, elemento);
                    }
                }
                case 3:
                {

                }
                case 4:
                {
                    system("cls");
                    break;
                }
            }
        }while(escolhaBusca!=0);
    }
    void implementaMenu()
    {
        int escolha=0;
        do
        {
            printf("\n");
            printf("\n           0 - Sair ");
            printf("\n           1 - Direta ");
            printf("\n           2 - BubbleSort ");
            printf("\n           3 - ShellSort ");
            printf("\n           4 - QuickSort ");
            printf("\n           5 - SelectionSort ");
            printf("\n           6 - HeapSort ");
            printf("\n           7 - Imprimir Lista ");
            printf("\n           8 - Limpar Tela ");
            printf("\n\n           Escolha Um Metodo: ");
            scanf("%d",&escolha);
                if(escolha<0||escolha>8)
                {
                    printf("\n Invalido !!\n");
                    escolha=8;
                }
            switch(escolha)
            {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    printf("\nModo de Ordem Direta \n");
                    direta(vetorDesordenado);
                    ordenado = 1;
                    break;
                }

                case 2:
                {
                    printf("\n Modem de Ordem bubbleSort \n");
                    bubbleSort(vetorDesordenado);
                    ordenado = 1;
                    break;
                }
                case 3:
                {
                    printf("\n Modo de Ordem ShellSort \n");
                    shellSort(vetorDesordenado, tamanhoDoVetorDesordenado);
                    ordenado = 1;
                    break;
                }
                case 4:
                {

                    /** Por tratar-se de uma expressão recursiva, toda impressão é feita fora
                        da função, para não ser feita repetidamente
                        Além disso, o vetor  'a' é passado como parâmetro e é impresso após a
                        execução da função 'quickSort'
                    */
                    printf("\n QuickSort \n");
                    int n=tamanhoDoVetorDesordenado;
                    printf("\nVetor Desordenado...\n\n");
                    int aux;
                    for(aux=0;aux<tamanhoDoVetorDesordenado;aux++)
                    {
                    vetor[aux]=vetorDesordenado[aux];
                    printf("%d ", vetor[aux]);
                    }
                    quickSort(vetor, 0, (n-1));
                    printf("\n\nVetor Ordenado \n\n");
                    imprimir(vetor);
                    ordenado = 1;
                    break;
                }
                case 5:
                {
                    printf("\n SelectionSort \n");
                    selectionSort(vetorDesordenado, tamanhoDoVetorDesordenado);
                    ordenado = 1;
                    break;
                }
                case 6:
                {
                    printf("\n HeapSort \n");
                    int aux;
                    int n=tamanhoDoVetorDesordenado;
                    printf("\nVetor Desordenado...\n\n");
                    for(aux=0;aux<tamanhoDoVetorDesordenado;aux++)
                    {
                        vetor[aux]=vetorDesordenado[aux];
                        printf("%d ", vetor[aux]);
                    }
                    heapsort(vetor, n);
                    printf("\n\nVetor Ordenado \n\n");
                    imprimir(vetor);
                    ordenado = 1;
                    break;
                }
                case 7:
                {
                    printf("\nVetor Desordenado...\n\n");
                    imprimir(vetorDesordenado);
                    ordenado = 0;
                    break;
                }
                case 8:
                {
                    system("cls");
                    break;
                }
            }

        }while(escolha !=0);
}
void direta(int vetorDesordenado[6])
{
        int i, j, tamanho, chave;
        tamanho=6;
        printf("\nVetor Desordenado...\n\n");
        for(i=0;i<tamanho;i++)
        {
            vetor[i]=vetorDesordenado[i];
            printf(" %d", vetor[i]);
        }
        for (j=1;j<tamanho;j++)
        {
            chave = vetor[j];
            i = j - 1;
            while((i>=0) && (vetor[i]>chave))
            {
                vetor[i+1] = vetor[i];
                i = i - 1;
            }
            vetor[i+1] = chave;
        }
        printf("\n");
        printf("\nVetor Ordenado...\n\n");
        imprimir(vetor);
        return 0;
}
void bubbleSort(int vetorDesordenado[tamanhoDoVetorDesordenado])
{
        int i, d, swap;
        for(i=0;i<tamanhoDoVetorDesordenado;i++)
        {
            vetor[i]=vetorDesordenado[i];
            printf(" %d", vetor[i]);
        }
        for (i=0; i<(tamanhoDoVetorDesordenado-1); i++)
        {
            for (d=0; d <tamanhoDoVetorDesordenado-i-1; d++)
            {
                if (vetor[d] > vetor[d+1])
                {
                    swap= vetor[d];
                    vetor[d]=vetor[d+1];
                    vetor[d+1]=swap;
                }
            }
        }
        printf("\n");
        printf("\nVetor Ordenado...\n\n");
        imprimir(vetor);
        return 0;
}
void shellSort(int vetorDesordenado[], int tamanhoDoVetor)
{
        int i, j, incremento, temp, auxiliar;
        incremento = 3;
        printf("\nVetor Desordenado...\n\n");
        for(i=0;i<tamanhoDoVetor;i++)
        {
            vetor[i]=vetorDesordenado[i];
            printf("%d ", vetor[i]);
        }
        while (incremento > 0)
        {
            for (i=0; i < tamanhoDoVetor; i++)
            {
                j = i;
                temp = vetor[i];
                while ((j >= incremento) && (vetor[j-incremento] > temp))
                {
                    vetor[j] = vetor[j - incremento];
                    j = j - incremento;
                }
                vetor[j] = temp;
            }
        if (incremento/2 != 0)
            incremento = incremento/2;
		else if (incremento == 1)
            incremento = 0;
        else
        incremento = 1;
        }
        printf("\n\nVetor Ordenado \n\n");
        imprimir(vetor);
}
void quickSort(int a[], int esquerda, int direita)
{
        int i, j, x, y;
        i = esquerda;
        j = direita;
        x = a[(esquerda + direita) / 2];

        while(i <= j)
        {
            while(a[i] < x && i < direita)
            {
                i++;
            }
            while(a[j] > x && j > esquerda)
            {
                j--;
            }
            if(i <= j)
            {
                y = a[i];
                a[i] = a[j];
                a[j] = y;
                i++;
                j--;
            }
        }
        if(j > esquerda)
        {
            quickSort(a, esquerda, j);
        }
        if(i < direita)
        {
            quickSort(a,  i, direita);
        }
}
 void heapsort(int a[], int n)
{
       int i = n/2, pai, filho, t;
       for (;;)
       {
          if (i > 0)
          {
              i--;
              t = a[i];
          }
          else
          {
              n--;
              if (n == 0)
                 return;
              t = a[n];
              a[n] = a[0];
          }
          pai = i;
          filho = i*2;     /*** Primeiro será feita a comparação com o filho da esquerda.*/
          while (filho < n)
          {
              if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
                  {                 /**Se o filho da esquerda for menor do que o filho da direita,*/
                    filho++;        /**então será feita a troca do filho que será comparado.*/
                  }
              if (a[filho] > t)
              {
                 a[pai] = a[filho];

                 pai = filho;
                 filho = pai*2 + 1;
              }
              else
                 break;
          }
          a[pai] = t;
       }
}
void selectionSort( int vetorDesordenado[], int tamanhoVetor )
{
        int aux;
        int n=tamanhoDoVetorDesordenado;
        printf("\nVetor Desordenado...\n\n");
        for(aux=0;aux<tamanhoDoVetorDesordenado;aux++)
        {
            vetor[aux]=vetorDesordenado[aux];
            printf("%d ", vetor[aux]);
        }

        int i, j, posicaoValorMinimo;
        for (i = 0; i < ( tamanhoVetor - 1 ); i++)
        {
            posicaoValorMinimo = i;
            for (j = ( i + 1 ); j < tamanhoVetor; j++)
            {
                if( vetor[j] < vetor[posicaoValorMinimo] )
                {
                    posicaoValorMinimo = j;
                 }
            }
            if ( i != posicaoValorMinimo )
            {
                trocarPosicaoValores( &vetor[i], &vetor[posicaoValorMinimo] );
            }
        }
        printf("\n\nVetor Ordenado \n\n");
            imprimir(vetor);

}

void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;
}
void imprimir(int a[6])
{
            int auxiliar;
            for(auxiliar=0; auxiliar<6; auxiliar++)
            {
                printf("%d ", a[auxiliar]);
            }
}
void buscaSequencial(int vetorRecebido[6], int elementoRecebido)
{
            int auxiliar, encontrado = 0;
            for(auxiliar=0; auxiliar<tamanhoDoVetorDesordenado; auxiliar++)
            {
                if (vetorRecebido[auxiliar]==elementoRecebido)
                {
                    printf("Elemento %d Encontrado Na Posicao: %d \n",elementoRecebido, auxiliar);
                    encontrado=1;
                }
            }
            if (encontrado==0)
            {
                printf("Elemento %d Nao Localizado !! \n", elementoRecebido);
            }
}
void buscaBinaria(int vetorRecebido[6], int elementoRecebido)
{
            int i; /* Variavel de controle dos loops */
            int valor; /* Variavel que ira conter o valor temporario da posicao do vetor */
            int controle = 1; /* Controla se o elemento foi encontrado */
            int esquerda=0, meio, direita =tamanhoDoVetorDesordenado-1;  /* percorrem na busca binaria */

            while (esquerda <= direita)               /* Loop que ira realizar a pesquisa binaria */
            {
                meio = (esquerda + direita) / 2;
                if (elementoRecebido == vetorRecebido[meio])
                {
                    controle=0;
                    break;
                }
                else if (elementoRecebido < vetorRecebido[meio])
                {
                    direita = meio - 1;
                    continue;
                }

              /**Se a pesquisa for maior que o meio do vetor, entao a pesquisa comecara a partir do meio atual atual do vetor*/

              else if(elementoRecebido > vetorRecebido[meio])
              {
                 esquerda = meio + 1;
                 continue;
              }

              /**
              * Caso nada seja encontrado, define o controle = 1
              */
              else
              {
                 controle = 1;
                 break;
              }

        }

        if (controle == 0){
           printf("Elemento %d encontrado! Posicao: %d - Valor: %d", elementoRecebido, meio, vetorRecebido[meio]);
        } else {
           printf("Elemento %d nao encontrado!", elementoRecebido);
        }
}
