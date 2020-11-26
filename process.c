#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
  
int status;
pid_t pidFather, pidChild;

int process_child();
int process_father();
void printPIDStatus( pid_t pid);
int main() {
  pidFather = getpid();

  printf("I am the father my ID is  %d\n", pidFather);
  switch (pidChild=fork()) {
  case -1:
    perror("fork problem !!!");
    exit(2);
    break;
  case 0:
    process_child();
    break;
  default:
    process_father();
    break;
  }
  return 0;
}

int process_child() {
	for (int i=0;i<3;i++)
	{
	printf("Im the Child myfather status is  ");
	printPIDStatus(pidFather);
	sleep(1);
}
	

}

int process_father() {
	printf("I am the father my Child staus is  ");
	printPIDStatus(pidChild);
	printf("I am the father my Child staus is  ");
	printPIDStatus(pidChild);
	printf("I am the father my Child staus is  ");
	printPIDStatus(pidChild);
	waitpid(pidChild,&status,0);
	




}
void printPIDStatus( pid_t pid)
{
	FILE *fp;
	char StatPath[20];
	char StatMsg[20];

	sprintf(StatPath, "/proc/%ld/status",(long)pid);
	if((fp=fopen(StatPath,"r"))==NULL)
		return;
	while(fgets(StatMsg,20,fp)!=NULL)
		if (strncmp(StatMsg,"State",5)==0){
			printf("%s \n",&StatMsg[7]);
		break;}
		fclose(fp);
	
	
}


