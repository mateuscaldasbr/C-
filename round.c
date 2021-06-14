/*Paulo Mateus de Lima Caldas && Sérgio*/
/*ALGORITMO DE ROUND ROBIN*/

#include <stdio.h>
#include <conio.h>

int main(){
	int n, i, qt,
	contador = 0,
	temp,
	sq = 0,
	bt[10],
	wt[10],
	tat[10],
	rem_bt[10];;
	
	float awt = 0, atat = 0;
	
	printf("Insira o número de processos a serem lidos e colocados na fila de prontos:\n ");
	scanf ("%i", &n);
	
	for(i=0; i<n; i++){
		printf("Tempo de Execucao do processo: ");
		scanf ("%i", &bt[i]);
		rem_bt[i] = bt[i];
	}
	
	printf("Insira o valor de Quantum: ");
	scanf ("%i", &qt);
	
	while(1){
		for(i=0; contador=0; i++){
			temp = qt;
			if(rem_bt[i] == 0){
				contador++;
				continue;
			}
			if(rem_bt[i] > qt){
				rem_bt[i] = rem_bt[i] - qt;
			}else{
				if(rem_bt[i] >= 0){
					temp = rem_bt[i];
					rem_bt[i] = 0;
				}
				
				sq = sq + temp;
				tat[i] = sq;
			}
				
		}
		if(n==contador)
			break;
		
	}
	printf("\nProcessos\tTempo de Execução\tTurnaround\tTempo_Espera\n");
	
	for(i=0; i<n; i++){
		wt[i] = tat[i] - bt[i];
		awt = awt + wt[i];
		atat = atat + tat[i];
		
		printf("\n%i\t%i\t\t%i\t\t%i", i+1, bt[i], tat[i], wt[i]);
	}
	
	awt = awt/n;
	atat = atat/n;
	
	printf("Media de Tempo de Espera: %f", awt);
	printf("Media Turnaround: %f", atat);	
}