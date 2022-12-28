#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void abc( );
void def( );
main ( )
{
	signal (SIGINT , abc);
	signal (SIGQUIT , def);
	while (1)
		printf("\n HELLO");
}
void abc (int signo)
{
	printf( "signal number of SIGINT: %d \n",signo) ;
	exit (0) ;
}
void def (int signo)
{
	printf( "signal number of SIGQUIT: %d \n",signo) ;
	exit (0) ;
}
