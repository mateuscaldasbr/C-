#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int y[20],x[10],n,i,j,temp,z[10],st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float tempMedioEspera,tempMedioExecucao;
    char pn[10][10],t[10];
    //clrscr();
    printf("Insira numero de processos a serem lidos e colocados na fila de prontos:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Nome do processo, tempo de ingresso,tempo de execucao & prioridade");
        //flushall();
        scanf("%s%d%d%d",pn[i],&x[i],&y[i],&z[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(z[i]<z[j])
            {
                temp=z[i];
                z[i]=z[j];
                z[j]=temp;
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
                temp=y[i];
                y[i]=y[j];
                y[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=x[i];
            wt[i]=st[i]-x[i];
            ft[i]=st[i]+y[i];
            ta[i]=ft[i]-x[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-x[i];
            ft[i]=st[i]+y[i];
            ta[i]=ft[i]-x[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    tempMedioEspera=(float)totwt/n;
    tempMedioExecucao=(float)totta/n;
    printf("\nPname\tTempo de ingresso\tTempo de execucao\tprioridade\ttempo de espera\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],x[i],y[i],z[i],wt[i],ta[i]);
    printf("\nTempo medio de execucao:%fs",tempMedioExecucao);
    printf("\nTempo medio de espera:%fs",tempMedioEspera);
    getch();
}