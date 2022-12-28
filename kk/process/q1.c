#include<stdio.h>
#include<stdlib.h>
int main(){
	//printf("parent process id: %d",getpid());
	int pid = fork();
	if(pid == 0)
		printf("\nchild process id: %d",0);
	else
		printf("\nparent process id: %d",getpid());
	return 0;
}
