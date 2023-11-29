#include <unistd.h>

int main() {
    const char message[] = "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";
    
    // STDOUT_FILENO is a standard file descriptor associated with console display 
    write(STDOUT_FILENO, message, sizeof(message) - 1);

    return 0;
}
