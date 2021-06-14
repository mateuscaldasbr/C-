/* Paulo Mateus de Lima Caldas && Sérgio do Carmo*/

#include <stdio.h>
#define max 50 /*Basicamente usado para determinar o tamanho do vetor*/

main()
{
    int i,      /*Contador*/
        n,      /*Número de processos*/
        x[max], /*Tempo de ingresso do processo*/
        y[max], /*Tempo de duração do processo*/
        temp_espera[max],
        turna_round[max],
        temp[max];

    float tempMedioEspera = 0,
          tempMedioTurnaround = 0;

    printf("Insira o numero de processos a serem lidos e colocados na fila de prontos: \n");
    scanf("%i", &n);

    for (i = 0; i < n; i++)
    {
        printf("Tempo de ingresso do processo %i: \n", i + 1);
        scanf("%i", &x[i]);
        printf("Tempo de duracao do processo %i: \n", i + 1);
        scanf("%i", &y[i]);
    }

    temp[0] = 0;
    printf("Processo\tTempo_Execucao\tTempo_Chegada\tTempo_Espera\tTurnaround\t\n");
    for (i = 0; i < n; i++)
    {
        temp_espera[i] = 0;
        turna_round[i] = 0;
        temp[i + 1] = temp[i] + y[i];
        temp_espera[i] = temp[i] - x[i];
        if (temp_espera[i] < 0) /*Tempo de espera não pode ser negativo*/
        {
            temp_espera[i] = 0;
        }
        turna_round[i] = temp_espera[i] + y[i];
        tempMedioEspera = tempMedioEspera + temp_espera[i];
        tempMedioTurnaround = tempMedioTurnaround + turna_round[i];

        printf("P:%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, y[i], x[i], temp_espera[i], turna_round[i]);
    }
    tempMedioEspera = tempMedioEspera / n;
    tempMedioTurnaround = tempMedioTurnaround / n;

    printf("Tempo Medio de Execucao: %fs\n", tempMedioTurnaround);
    printf("Tempo Medio de Espera: %fs\n", tempMedioEspera);
    system("pause");
    return 0;

    /*FIM*/
}