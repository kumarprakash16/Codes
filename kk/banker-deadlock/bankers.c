#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int n=5;
	char pr[5]={'A','B','C','D','E'};
	int mn1[5]={7,3,9,2,4};
	int mn2[5]={5,2,0,2,3};
	int mn3[5]={3,2,2,2,3};
	int ch1[5]={0,2,3,2,0};
	int ch2[5]={1,0,0,1,0};
	int ch3[5]={0,0,2,1,2};
	int req1[5],req2[5],req3[5];
	int av1=10,av2=5,av3=7;
	int cu1=0,cu2=0,cu3=0,ex1=0,ex2=0,ex3=0;
	int c=0;
	for(i=0;i<5;i++)
	{
		cu1+=ch1[i];
		cu2+=ch2[i];
		cu3+=ch3[i];
		req1[i]=mn1[i]-ch1[i];
		req2[i]=mn2[i]-ch2[i];
		req3[i]=mn3[i]-ch3[i];
	}
	ex1=av1-cu1;
	ex2=av2-cu2;
	ex3=av3-cu3;
	printf("Process\tMax_Need Holding Required\n");
	for(i=0;i<5;i++)
	{
		printf("%c\t%d %d %d\t%d %d %d\t%d %d %d\n",pr[i],mn1[i],mn2[i],mn3[i],ch1[i],ch2[i],ch3[i],req1[i],req2[i],req3[i]);
	}
	int fl=0;
	printf("\nsafety Sequence :  \n");
	while(1){
	for(i=0;i<n;i++)
	{
		if(req1[i]!=-1 && req2[i]!=-1 && req3[i]!=-1 &&  req1[i]<=ex1 && req2[i]<=ex2 && req3[i]<=ex3)
		{
			fl=1;
			c++;
			req1[i]=-1;
			req2[i]=-1;
			req3[i]=-1;
			printf("%c\t",pr[i]);
			ex1+=ch1[i];
			ex2+=ch2[i];
			ex3+=ch3[i];
		}
	}
	if(fl==0){
		printf("NO Sequence\n");
		printf("Deadlock\n");
		break;
	}
	fl=0;
	if(c==5)
	{
		break;
	}
	}
	printf("\n");


}
