#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void abc( );
main ( )
{
	
	signal (SIGCHLD , abc);
	int pid = fork();
	if(pid == 0){
		printf("\nchild process");
	}
	else{
		
		printf("\nparent process\n");
		wait();
		
	}
}
void abc (int signo)
{
	printf( "\nChild process signal number of SIGCHLD: %d \n",signo) ;
	exit (0) ;
}

