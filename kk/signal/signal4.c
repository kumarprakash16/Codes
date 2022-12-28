#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void abc( );

main ( )
{
	signal (SIGALRM , abc);
	int left = alarm(2);
	while (1)
		printf("\n HELLO");
}
void abc (int signo)
{
	printf( "signal number of SIGALRM: %d \n",signo) ;
	exit (0) ;
}
