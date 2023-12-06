#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

void fonction_exemple() {
	for (int i = 0; i < 1000000; ++i) {
}

int main() {
	// Enregistrement du temps de début
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    
    fonction_exemple();
    
    // Enregistrement du temps de fin
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calcul de la durée en nanosecondes
    long long delta_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
	
	// Conversion de la durée en millisecondes
    double delta_ms = (double)delta_ns / 1000000.0;
    
	return 0;
}

