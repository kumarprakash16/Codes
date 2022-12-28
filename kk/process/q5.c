#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
        int pid;
	printf("parent starts\n");
        pid = fork();
        if(pid<0){
              printf("error in creating child process");
              exit(-1);
      }
       else if(pid == 0){
               //child
	      // sleep(10);
               printf("child starts\n");
	       int i;
	       for(i =1;i<=10;i++)
		       printf("%d ",i);
	       printf("\nchild ends\n");
      }
      else{
//	      printf("parent starts\n");
	      int i;
	      for(i =1;i<=10;i++)
		      printf("%d ",i);
	      printf("\nparent ends\n");
	      sleep(1);
       }
     return 0;
}

