/*ALGORITMO POR PRIORIDADES*/

#include <stdio.h>
#define max 30

main(){
    //wt - tempo de espera
    //bt - tempo de execução
    //tat - tournaround

	int i, n, j, t, bt[max], wt[max], pr[max], tat[max], pos;
	float awt = 0, atat = 0;

	printf("Quantidade de Processos: ");
	scanf("%d", &n);

	printf("Tempo de Execução: ");
	for(i=0; i<n; i++){
		scanf("%d", &bt[i]);
	}

	printf("Insira a Prioridade dos Processos: ");
	for(i=0; i<n; i++){
		scanf("%d", &pr[i]);
	}

	for(i=0; i<n; i++){
		pos = i;
		for(j=i+1; j<n; j++){
			if(pr[j] < pr[pos]){
				pos = j;
			}
		}
		t = pr[i];
		pr[i] = pr[pos];
		pr[pos] = t;

		t = bt[i];
		bt[i] = bt[pos];
		bt[pos] = t;

	}

	wt[0] = 0;
	printf("Processos\tTempo_Execucaio\tPrioridade\tTempo_Espera\tTurnaround\n");

	for(i=0; i<n; i++){
		wt[i] = 0;
		tat[i] = 0;
		for(j=0; j<i; j++){
			wt[i] = wt[i] + bt[j];
		}

		tat[i] = wt[i] + bt[i];
		awt = awt + wt[i];
		atat = atat + tat[i];

		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
	}
	awt = awt/n;
	atat = atat/n;

	printf("Media Tempo de Espera: %f", awt);
	printf("Media de Turnaround: %f", atat);
}