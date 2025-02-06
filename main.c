
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture4.h"

int main(int argc, char *argv[])
{
	// basics of threads
	// windows version
	// basics_main();

	// basics of processes
	// windows version
	// basics_processes();

	// using _spawn to create a new process
	// main_spawn();

	// semaphores, example from Visual studio
	// main_sem();	

	// semaphores example - extended example from the previous lectures
	// basics_sem_main();

	// pthread example
	// main_pthread();

	// processes example - POSIX version
	// main_processes_posix();

	// sempahores example - POSIX version
	// main_semaphores_posix();

	// dining philosophers example - POSIX version
	main_philosophers(argc, argv);

	return 0;
}