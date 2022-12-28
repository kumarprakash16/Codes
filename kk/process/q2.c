#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
	int n;
	printf("Enter number: ");
	scanf("%d",&n);
	int pid;
	pid = fork();
	if(pid<0){
		printf("error in creating child process");
		exit(-1);
	}
	else if(pid == 0){
		//child: check prime
		int i, c = 0;
		for(i=1; i<=n; i++)
			if(n%i == 0 )
				c++;
		if(c == 2)
			printf("\n%d is prime", n);
		else
			printf("\n%d is composite",n);
	}
	else{
		if(n%2==0)
			printf("\n%d is even", n);
		else
			printf("\n%d id odd", n);
	}
	return 0;
}
