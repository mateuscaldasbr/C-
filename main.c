#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*#include <fcfs.h>*/

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
    int z[n]; /* z = Numero do processo */

    int i; /* Declarado fora do for por incopatibilidade do copilador usado no VSCODE. */
    for (i = 0; i < n; i++)
    {
        printf("Insira o tempo de ingresso do processo 'X' [%d]\n", i + 1);
        scanf("%d", &x[i]);
        printf("Insira o tempo de duracao do processo 'Y' [%d]\n", i + 1);
        scanf("%d", &y[i]);
        z[i] = i + 1;
    }

    /* ORGANIZAR POR TEMPO DE CHEGADA*/

    int tempA;
    int tempB;

    for (tempA = 0; tempA < n; tempA++)
    {
        for (i = 0; i < n; i++)
        {

            for (tempB = 0; i < n - 1; i++)
            {
                if (x[i] > x[i + 1])
                {
                    int temp;
                    temp = x[i];
                    x[i] = x[i + 1]; /* Ordenando pela posição de chegada */
                    x[i + 1] = temp;

                    temp = y[i];
                    y[i] = y[i + 1]; /* Tempo de duração do processo*/
                    y[i + 1] = temp;

                    temp = z[i];
                    z[i] = z[i + 1]; /* Numero do processo*/
                    z[i + 1] = temp;
                }
            }
        }
    }

    printf("Escolha o algoritmo de escalonamento \n");
    printf("||  01 - FCFS ||\n");
    printf("||  02 - SJF  ||\n");

    int resposta; /* variável para a respsota */
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
    {
        void fcfs(int vetorA[], int vetorB[], int vetorC[], int n);
        fcfs(x, y, z, n);
        break;
    }
    case 2:
        break;
    default:
        printf("Opcao invalida\n");
    }

    printf("\n||  SUCESSO  ||\n");
    /*system("pause");*/
    return 0;
}

/*fcfs.h ----- código */

void fcfs(int vetorA[], int vetorB[], int vetorC[], int n)
{
    /*Teste Organização*/
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Ingresso[%d] - Duracao[%d] - Processo[%d] \n", vetorA[i], vetorB[i], vetorC[i]);
    }
    ////////////////////////////////////////////////////
    float turnaround = 0; /*tempMedioExecucao*/
    float somaTurn = 0;
    for (i = 0; i < n; i++)
    {
        somaTurn = vetorB[i] + somaTurn;
        turnaround = turnaround + somaTurn - vetorA[i];
    }
    turnaround = (turnaround / n);
    if (turnaround < 0)
        turnaround = 0;
    printf("\n Turnaround: %f\n", turnaround);
    ////////////////////////////////////////////////////
    float somaEspera = 0;
    float resultoEspera = 0;
    for (i = 0; i < n; i++)
    {
        somaEspera = vetorB[i] + somaEspera;
        resultoEspera = resultoEspera + somaEspera - vetorA[i];
    }

    resultoEspera = ((resultoEspera - somaEspera) / n);
    if (resultoEspera < 0)
        resultoEspera = 0;
    printf("\n Tempo medio de espera %f\n", resultoEspera);

    ////////////////////////////////////////////////////
    printf("\nOrdem de Execucao\n\n");

    for (i = 0; i < n; i++)
    {
        printf("\tP[%d]", vetorC[i]);
    }
    ////////////////////////////////////////////////////
}