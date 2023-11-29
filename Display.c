#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
	
	char buffer[50];
    const char message[] = "Welcome to ENSEA Tiny Shell.\nType 'exit' to quit.\nenseash %";
    
	while(1){
			
		// STDOUT_FILENO is a standard file descriptor associated with console display 
		write(STDOUT_FILENO, message, sizeof(message) - 1);
		scanf("%s",buffer);
		// scanf : reading the keybord charcters
		if (strcmp("exit",buffer)==0)
		// strcmp : compare the memorize caracters
		{
			return 0;
		}
	}
    return 0;
}
