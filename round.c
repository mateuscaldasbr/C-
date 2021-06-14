/*Paulo Mateus de Lima Caldas && Sérgio*/
/*ALGORITMO DE ROUND ROBIN*/

    #include<stdio.h>  
    #include<conio.h>  
      
    void main()  
    {    
        int i, n, sum=0,count=0, y, m, wt=0, tat=0, vetX[10], vetY[10], temp[10];  
        float tempMedioEspera, tempMedioExecucao;  
        printf("O valor do quantum a ser utilizado no escalonamento dos processos\n");  
    scanf("%d", &m); 
        printf("O numero de processos a serem lidos e colocados na fila de prontos\n");  
        scanf("%d", &n);  
        y = n;  
       
    for(i=0; i<n; i++)  
    {  
    printf("Tempo de ingresso do processo: %i \n",i+1);  
    scanf("%d", &vetX[i]);  /*Vetor 'X'*/
    printf("Tempo de duracao do processo \n");
    scanf("%d", &vetY[i]);  /*Vetor 'Y'*/
    temp[i] = vetY[i]; /*Guardar a duracao do processo em um array*/
    }   
    printf("\n Processo \t\t Duracao Processo \t\t TAT \t\t Tempo de espera ");  
    for(sum=0, i = 0; y!=0; )  
    {  
    if(temp[i] <= m && temp[i] > 0)
    {  
        sum = sum + temp[i];  
        temp[i] = 0;  
        count=1;  
        }   
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - m;  
            sum = sum + m;    
        }  
        if(temp[i]==0 && count==1)  
        {  
            y--;  
            printf("\nProcesso Numero[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, vetY[i], sum-vetX[i], sum-vetX[i]-vetY[i]);  
            wt = wt+sum-vetX[i]-vetY[i];  
            tat = tat+sum-vetX[i];  
            count =0;     
        }  
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(vetX[i+1]<=sum)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }    
    tempMedioEspera = wt * 1.0/n;  
    tempMedioExecucao = tat * 1.0/n;  
    printf("\n Tempo medio de execucao:\t%fs", tempMedioExecucao);  
    printf("\n Tempo medio de espera:\t%fs", tempMedioEspera);  
    getch();  
    }  