#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int n;
int at[100];
int bt[100];
int ct[100];
int pr[100];
char proc [100];
int twt;
int tat;
void waiting()
{
	twt=0;
	int i;
	for(i=0;i<n;i++)
	{
		twt+=ct[i]-bt[i];	
	}
}

void completion()
{
	int i,prev=0;
	for(i=0;i<n;i++)
	{
		ct[i]=bt[i]+prev;
		prev=ct[i];
	}
}
void turnaround()
{
	tat=0;
	int i;
	for(i=0;i<n;i++)
	{
		tat+=ct[i];
	}
}
void output()
{
	int i;
	printf("Process\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\t%d\n",proc[i],bt[i],ct[i]-bt[i],ct[i]);
	}
}

void display()
{

	int i;
	printf("The process is as follows: \n");
	for(i=0;i<n;i++)
	{
		printf("%c\t",proc[i]);
	}
	printf("\n");
}

void input()
{
	int i;
	printf("Enter the no of process : ");
	scanf("%d",&n);
	printf("Enter the Process and  burst time : ");
	for(i=0;i<n;i++)
	{
		scanf(" %c %d",&proc[i],&bt[i]);
	}
}

void priorinput()
{
	int i;
	printf("Enter the no of process : ");
	scanf("%d",&n);
	printf("Enter the process and burst time and priority : ");
	for(i=0;i<n;i++)
	{
		scanf(" %c %d %d",&proc[i],&bt[i],&pr[i]);
	}
}

void sort()
{
	int i,j,tmp;
	char t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[i])
			{
				tmp=bt[i];
				bt[i]=bt[j];
				bt[j]=tmp;
				t=proc[i];
				proc[i]=proc[j];
				proc[j]=t;
			}
		}
	}
}

void priorsort()
{
	int i,j,tmp,tmp2;
	char t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[i])
			{
				tmp=pr[i];
				pr[i]=pr[j];
				pr[j]=tmp;

				tmp2=bt[i];
				bt[i]=bt[j];
				bt[j]=tmp2;

				t=proc[i];
				proc[i]=proc[j];
				proc[j]=t;
			}
		}
	}
}


void fcfs()
{
	input();
	completion();
	waiting();
	turnaround();
	output();
	display();
	printf("Average waiting time = %f\n",twt/(n*(1.0)));
	printf("Average TurnAround time = %f\n",tat/(n*(1.0)));

}

void sjf()
{
	input();
	sort();
	completion();
	waiting();
	turnaround();
	output();
	display();
	printf("Average waiting time = %f\n",twt/(n*(1.0)));
	printf("Average turnaAround time = %f\n",tat/(n*(1.0)));
}

void prior()
{
	priorinput();
	priorsort();
	completion();
	waiting();
	turnaround();
	output();
	display();
	printf("Average waiting time = %f\n",twt/(n*(1.0)));
	printf("Average turnaround time = %f\n",tat/(n*(1.0)));
}

void rr()
{
	int i=0;
	int x=3;
	input();
	printf("Enter time slot");
	scanf("%d",&x);
	int c=0;
	int tmp[n];
	for(i=0;i<n;i++)
	{
		tmp[i]=bt[i];
	}
	int t=0;
	printf("Process : \n");
	while(c!=n)
	{
		c=0;
		for(i=0;i<n;i++)
		{
			if(tmp[i]>x)
			{
				tmp[i]-=x;
				t+=x;
				printf("%c\t",proc[i]);	
			}
			else if(tmp[i]>0)
			{
				printf("%c\t",proc[i]);
				t+=tmp[i];
				ct[i]=t;
				tmp[i]=0;
				
			}
			else
			{
				c++;
			}
		}
	}
	printf("\n\n");
	waiting();
	turnaround();
	output();
	printf("Average waiting time = %f\n",twt/(n*(1.0)));
	printf("Average Turnaround time = %f\n",tat/(n*(1.0)));
}

void srtf()
{
	int i;
	printf("Enter the no of process : ");
	scanf("%d",&n);
	printf("Enter the Process name,arrival time and burst time : ");
	for(i=0;i<n;i++)
	{
		scanf(" %c %d %d",&proc[i],&at[i],&bt[i]);
	}
	int comp=0;
	int c=0;
	int tmp[n];
	for(i=0;i<n;i++)
	{
		tmp[i]=bt[i];
	}
	while(c<n)
	{
		int ind=-1;
		int mn=1000;
		for(i=0;i<n;i++)
		{
			if(at[i]<=comp && tmp[i]!=0)
			{
				if(tmp[i]<mn)
				{
					mn=tmp[i];
					ind=i;
				}
				else if(tmp[i]==mn && at[i]<at[ind])
				{
					ind=i;
				}
			}
		}
		if(ind!=-1)
		{
			printf("%c  ",proc[ind]);
			tmp[ind]=tmp[ind]-1;
			if(tmp[ind]==0)
			{
				c++;
				ct[ind]=comp+1;
			}
		}
		comp+=1;
	}
	waiting();
	turnaround();
	printf("\nProcess\tAT\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t%d\t%d\t%d\t%d\n",proc[i],at[i],bt[i],ct[i]-bt[i]-at[i],ct[i]-at[i]);
		twt=twt-at[i];
		tat=tat-at[i];
	}
	printf("Average waiting time :  %f\n",twt/(n*(1.0)));
	printf("AVerage turn around time : %f\n",tat/(n*(1.0)));
}


int main()
{
	int op;
	char ch='y';
	while(ch=='y')
	{
		printf("\tCPU Scheduling ALgorithm\n");
		printf("1)FCFS\n");
		printf("2)SJF\n");
		printf("3)Priority\n");
		printf("4)Round Robin\n");
		printf("5)SRTF\n");
		printf("6)EXIT\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) 
		{
			case 1:fcfs();
			      break;
			case 2:sjf();
			       break;
			case 3:prior();
			       break;
			case 4:rr();
			       break;
			case 5:srtf();
			       break;
			case 6:exit(0);
			       break;
			default:break;
		}
		printf("DO u want Continue ? ");
		scanf(" %c",&ch);
	}
}
