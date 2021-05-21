#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;        /*n Número de processos a ser lidos // OBS: Inteiro não negativo  */
    int x = 0, y = 0; /* x = Tempo de ingresso do processo // y = Tempo de duração do processo // */

    printf("Por favor, insira o numero de processos a ser lido \n");
    scanf("%d", &n);
    
    printf("%i\n",n);
    system("pause");
    return 0;
}