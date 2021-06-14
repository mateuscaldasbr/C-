/*Paulo Mateus de Lima Caldas && Sérgio*/
/*ALGORITMO DE ROUND ROBIN*/

    #include<stdio.h>  
    #include<conio.h>  
      
    void main()  
    {    
        int i, n, sum=0,count=0, y, m, wt=0, tat=0, at[10], bt[10], temp[10];  
        float avg_wt, avg_tat;  
        printf("O valor do quantum a ser utilizado no escalonamento dos processos\n");  
    scanf("%d", &m); 
        printf("O numero de processos a serem lidos e colocados na fila de prontos\n");  
        scanf("%d", &n);  
        y = n;  
       
    for(i=0; i<n; i++)  
    {  
    printf("Tempo de ingresso do processo: %i \n",i+1);  
    scanf("%d", &at[i]);  
    printf("Tempo de duracao do processo \n");
    scanf("%d", &bt[i]);  
    temp[i] = bt[i]; /*Guardar a duracao do processo em um array*/
    } 
    // Display the process No, burst time, Turn Around Time and the waiting time  
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
    for(sum=0, i = 0; y!=0; )  
    {  
    if(temp[i] <= m && temp[i] > 0) // define the conditions   
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
            y--; //decrement the process no.  
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            wt = wt+sum-at[i]-bt[i];  
            tat = tat+sum-at[i];  
            count =0;     
        }  
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=sum)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
    // represents the average waiting time and Turn Around time  
    avg_wt = wt * 1.0/n;  
    avg_tat = tat * 1.0/n;  
    printf("\n Average Turn Around Time: \t%f", avg_wt);  
    printf("\n Average Waiting Time: \t%f", avg_tat);  
    getch();  
    }  