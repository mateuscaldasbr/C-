#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Seu programa deve ler vários conjuntos de teste. 
A primeira linha de um conjunto de teste contém um inteiro não negativo, N, que indica o número de processos a serem lidos e colocados na fila de prontos (o valor N = 0 indica o final da entrada).

Seguem-se N linhas, cada uma contendo um par de números inteiros não negativos X e Y que representam o tempo de ingresso do processo (X) e o tempo de duração do processo (Y). Os processos são numerados sequencialmente a partir de 1, na ordem em que aparecem na entrada.*/

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n = 0; /*n Número de processos a ser lidos // OBS: Inteiro não negativo  */
    printf("Insira o numero de processos 'N'\n");
    scanf("%d", &n);

    int x[n]; /* x = Tempo de ingresso do processo. */
    int y[n]; /* y = Tempo de duração do processo. */
    int i;    /* Declarado fora do for imcopatibilidade do copilador usado no VSCODE. */
    for (i = 0; i < n; i++)
    {
        printf("Insira o tempo de ingresso do processo 'X' [%d]\n", i + 1);
        scanf("%d", &x[i]);
        printf("Insira o tempo de duracao do processo 'Y' [%d]\n", i + 1);
        scanf("%d", &y[i]);
    }

    printf("SUCESSO\n", n);
    //system("pause");
    return 0;
}