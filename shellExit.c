#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	
	char buffer[50];
    const char message[] = "enseash ";
    const char bye[]="Bye bye...\n";
    pid_t pid;
    int status;
	
	while(1){ 
		write(STDOUT_FILENO, message, sizeof(message) - 1);
		int n=read(STDIN_FILENO,buffer,50);
		//reading of the number of enter caracters 
		buffer[n-1]=0;
		if (strcmp("exit",buffer)==0 | n==0){
			// <ctr> + d mean n==0
			write(STDOUT_FILENO, bye, sizeof(bye) - 1);
			exit(1);
		}
		// test before fork to exit 
		pid=fork();
		// formating the buffer
		if (pid != 0) {
			// father code
			wait(&status);
			//waiting for the child
		} 
		else {
			// child code
			if(n==1){
				// enter case
				const char *date="date";
				execlp(date, date, (char *)NULL);
			}
			else if (n>1){
				execlp(buffer, buffer, (char *)NULL);
			}
		}
	}
    return 0;
}
