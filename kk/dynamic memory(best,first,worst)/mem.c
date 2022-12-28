#include<stdio.h>
#include<stdlib.h>

int part[]={100,500,200,300,400};
int proc[]={212,417,112,426};
int n=5,m=4;

void bestfit()
{
	int visit[5]={0,0,0,0,0};
	int rem[5]={100,500,200,300,400};
	int i=0,j=0,k=-1;
	for(i=0;i<4;i++)
	{
		k=-1;
		for(j=0;j<5;j++)
		{
			if(part[j]>=proc[i] && visit[j]==0 && k==-1)
			{
				k=j;
			}
			else if(part[j]>=proc[i] && visit[j]==0 && part[j]<part[k])
			{
				k=j;
			}
		}
		if(k==-1)
		{
			printf("No contiguos memory available for proces P%d\n",i+1);
		}
		else
		{
			visit[k]=1;
			rem[k]=part[k]-proc[i];
			printf("P%d size %dK fits in partition %d size %dK\n",i+1,proc[i],k+1,part[k]);
		}
	}
	printf("\nINTERNAL FRAGMENTATION \n\n");
	for(i=0;i<5;i++)
	{
		printf("Original Partition %d = %dK , Remaining memory = %dK\n",i+1,part[i],rem[i]);
	}
}

void firstfit()
{
	int visit[5]={0,0,0,0,0};
	int rem[5]={100,500,200,300,400};
	int i=0,j=0,k=-1;
	for(i=0;i<4;i++)
	{
		k=-1;
		for(j=0;j<5;j++)
		{
			if(part[j]>=proc[i] && visit[j]==0 && k==-1)
			{
				k=j;
				break;
			}
		}
		if(k==-1)
		{
			printf("No contiguos memory available for proces P%d\n",i+1);
		}
		else
		{
			visit[k]=1;
			rem[k]=part[k]-proc[i];
			printf("P%d size %dK fits in partition %d size %dK\n",i+1,proc[i],k+1,part[k]);
		}
	}
	printf("\nINTERNAL FRAGMENTATION \n\n");
	for(i=0;i<5;i++)
	{
		printf("Original Partition %d = %dK , Remaining memory = %dK\n",i+1,part[i],rem[i]);
	}
}

void worstfit()
{
	int visit[5]={0,0,0,0,0};
	int rem[5]={100,500,200,300,400};
	int i=0,j=0,k=-1;
	for(i=0;i<4;i++)
	{
		k=-1;
		for(j=0;j<5;j++)
		{
			if(part[j]>=proc[i] && visit[j]==0 && k==-1)
			{
				k=j;
			}
			else if(part[j]>proc[i] && visit[j]==0 && part[j]>part[k])
			{
				k=j;
			}
		}
		if(k==-1)
		{
			printf("No contiguos memory available for proces P%d\n",i+1);
		}
		else
		{
			visit[k]=1;
			rem[k]=part[k]-proc[i];
			printf("P%d size %dK fits in partition %d size %dK\n",i+1,proc[i],k+1,part[k]);
		}
	}
	printf("\nINTERNAL FRAGMENTATION \n\n");
	for(i=0;i<5;i++)
	{
		printf("Original Partition %d = %dK , Remaining memory = %dK\n",i+1,part[i],rem[i]);
	}
}

int main()
{
	int ch;
	while(1)
	{
	printf("\n**************************Dynamic Storage Allocation Problem **************************************\n");
	printf("1)Best-Fit\n");
	printf("2)First-Fit\n");
	printf("3)Worst-Fit\n");
	printf("4)Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:bestfit();
		       break;
		case 2:firstfit();
		       break;
		case 3:worstfit();
		       break;
		case 4:exit(0);
	}
	}
}
