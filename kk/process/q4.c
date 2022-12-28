#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
        int pid;
        pid = fork();
        if(pid<0){
              printf("error in creating child process");
              exit(-1);
      }
       else if(pid == 0){
               //child
               printf("child starts\n");
	       int i;
	       for(i =1;i<=10;i++)
		       printf("%d ",i);
	       printf("\nchild ends\n");
      }
      else{
	      wait();
	      printf("parent ends\n");
       }
     return 0;
}

