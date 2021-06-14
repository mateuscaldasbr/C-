/*Paulo Mateus de Lima Caldas && Sérgio*/
/*ALGORITMO DE SJF*/

#include <stdio.h>
#define max 50
int main()
{
    int x[max], y[max], temp[max];
    int i, menor, count = 0, time, n;
    double tempEspera = 0, tempResposta = 0, end;
    float tempMedioEspera, tempMedioExecucao;
    printf("Insira o numero de processos a serem lidos e colocados na fila de prontos\n");
    scanf("%i", &n);
    printf("Insira os dados dos %i processos\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Insira o tempo de ingresso %i: \n",x[i]);
        scanf("%i", &x[i]);
        printf("Insira o tempo de duracao do processo %i:\n",y[i]);
        scanf("%i", &y[i]);
        temp[i] = y[i];
    }
    y[9] = 9999;
    for (time = 0; count != n; time++)
    {
        menor = 9;
        for (i = 0; i < n; i++)
        {
            if (x[i] <= time && y[i] < y[menor] && y[i] > 0)
            {
                menor = i;
            }
        }
        y[menor]--;
        if (y[menor] == 0)
        {
            count++;
            end = time + 1;
            tempEspera = tempEspera + end - x[menor] - temp[menor];
            tempResposta = tempResposta + end - x[menor];
        }
    }
    tempMedioEspera = tempEspera / n;
    tempMedioExecucao = tempResposta / n;

    printf("Tempo medio de execucao: %fn \n", tempMedioExecucao);
    printf("Tempo medio de espera: %f \n", tempMedioEspera);
    
    return 0;
}