#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#define Conversion 1000000

int main() {
	
	char buffer[50];
	char text[100];
	char * commandToken[100];
    const char message[] = "enseash % ";
    const char bye[]="Bye bye...\n";
    pid_t pid;
    struct timespec tim_start, tim_stop;//time counting variables
    
    int status;
    const char * separator = " "; // space is the separator
    int i=0;
	
	while(1){ 
		
		write(STDOUT_FILENO, message, sizeof(message) - 1);
		
		int n=read(STDIN_FILENO,buffer,50);//reading of the number of enter caracters 
		buffer[n-1]=0;
		
		clock_gettime(CLOCK_REALTIME, &tim_start);//starting time value
		
		if (strcmp("exit",buffer)==0 | n==0){
			// <ctr> + d mean n==0
			write(STDOUT_FILENO, bye, sizeof(bye) - 1);
			exit(1);
		}
		// test before fork to exit 
		pid=fork();
		// formating the buffer
		if (pid > 0) {
			// father code
			wait(&status);
			//waiting for the child
			
			clock_gettime(CLOCK_REALTIME, &tim_stop);//end time value
			double duration = (tim_stop.tv_sec-tim_start.tv_sec)*1000+(tim_stop.tv_nsec - tim_start.tv_nsec)/Conversion;

			if (WIFEXITED(status)){
				sprintf(text,"ensea [exit : %d | %.01f ms] %% ", WEXITSTATUS(status),duration);
				write(STDOUT_FILENO, text, strlen(text)); 
			}
			//signal	
			else if (WIFSIGNALED(status)) {
				sprintf(text,"ensea [sign : %d | %.01f ms] %% ", WTERMSIG(status),duration);
				write(STDOUT_FILENO,text, strlen(text)); 
			}
		} 
		else {
			// child code
			if(n==1){
				// enter case
				const char *date="date";
				execlp(date, date, (char *)NULL);
			}
			else if (n>1){
				i=0;
				char * strToken = strtok(buffer,separator);
				while(strToken !=NULL){ //entire buffer parcourt
					commandToken[i]=strToken;
					strToken = strtok(NULL,separator); // next token
					i++;
				}
				commandToken[i] = NULL;
				execvp(commandToken[0],commandToken);
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
	}
    return 0;
}
