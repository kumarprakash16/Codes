#include<stdio.h>
#include<stdlib.h>

int seq[8]={98,183,37,122,14,124,65,67};
int ih=53;
int n=8;
void fcfs()
{
	int i;
	int ch=ih;
	int seek=0;
	printf("\nSeek sequence : ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",seq[i]);
		if(seq[i]>ch)
		{
			seek+=seq[i]-ch;
		}
		else
		{
			seek+=ch-seq[i];
		}
		ch=seq[i];
	}
	printf("\nTotal seek operations : %d\n\n",seek);
}

void sstf()
{
	int i,j;
	int ch=ih;
	int seek=0;
	int visit[8]={0,0,0,0,0,0,0,0};
	printf("\nSeek Sequence : ");
	for(i=0;i<n;i++)
	{
		int k;
		int mn=9999999;
		int x;
		for(j=0;j<n;j++)
		{
			if(seq[j]>=ch && visit[j]==0)
			{
				x=seq[j]-ch;
			}
			else if(ch>seq[j] && visit[j]==0)
			{
				x=ch-seq[j];
			}
			if(visit[j]==0 && x<mn)
			{
				k=j;
				mn=x;
			}
		}
		visit[k]=1;
		printf("%d\t",seq[k]);
		seek+=mn;
		ch=seq[k];
	}
	printf("\nTotal seek operations : %d\n\n",seek);
}

void scan()
{
	int ch=ih;
	int i,j,k;
	int seek=0;
	int tmp;
	int seq1[8]={98,183,37,122,14,124,65,67};
	for(i=0;i<8;i++)
	{
		for(j=i+1;j<8;j++)
		{
			if(seq1[i] >seq1[j])
			{
				tmp=seq1[i];
				seq1[i]=seq1[j];
				seq1[j]=tmp;
			}
		}
	}
	for(i=0;i<8;i++)
	{
		if(seq1[i]>ih)
		{
			break;
		}
	}
	k=i;
	printf("\nSeek Sequence(taking left) : ");
	for(j=k-1;j>=0;j--)
	{
		printf("%d\t",seq1[j]);
		seek+=ch-seq1[j];
		ch=seq1[j];
	}
	seek+=ch;
	printf("0\t");
	ch=0;
	for(j=k;j<n;j++)
	{
		printf("%d\t",seq1[j]);
		seek+=seq1[j]-ch;
		ch=seq1[j];
	}
	printf("\nTotal Seek Operation : %d\n\n",seek);

}

void cscan()
{
	int ch=ih;
	int i,j,k;
	int seek=0;
	int tmp;
	int seq1[8]={98,183,37,122,14,124,65,67};
	for(i=0;i<8;i++)
	{
		for(j=i+1;j<8;j++)
		{
			if(seq1[i] >seq1[j])
			{
				tmp=seq1[i];
				seq1[i]=seq1[j];
				seq1[j]=tmp;
			}
		}
	}
	for(i=0;i<8;i++)
	{
		if(seq1[i]>ih)
		{
			break;
		}
	}
	k=i;
	printf("\nSeek Sequence(taking left) : ");
	for(j=k-1;j>=0;j--)
	{
		printf("%d\t",seq1[j]);
		seek+=ch-seq1[j];
		ch=seq1[j];
	}
	seek+=ch;
	printf("0\t");
	ch=0;
	for(j=k;j<n;j++)
	{
		printf("%d\t",seq1[j]);
		seek+=seq1[j]-ch;
		ch=seq1[j];
	}
	seek+=199-ch;
	printf("199\t");
	printf("\nTotal Seek Operation : %d\n\n",seek);

}


int main()
{
	int ch;
	while(1)
	{
		printf("Disk Scheduling Algorithm\n");
		printf("1)FCFS\n");
		printf("2)SSTF\n");
		printf("3)SCAN\n");
		printf("4)CSCAN\n");
		printf("5)EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:fcfs();
			       break;
			case 2:sstf();
			       break;
			case 3:scan();
			       break;
			case 4:cscan();
			       break;
			case 5:exit(0);
		}
	}
}
