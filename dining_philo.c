/*
* The solution to the dining philosophers problem using threads in C
* source: rosettacode.org
* modifications - Github CoPilot (mostly comments)
*/

#include <stdio.h>
#include <threads.h>
#include <stdlib.h>

// the number of philosophers
#define NUM_THREADS 5

struct timespec time1;

// mutex for each fork == each philosopher
mtx_t forks[NUM_THREADS];

// Philosopher struct
// links each philosopher to their left and right fork
typedef struct {
	char *name;
	int left;
	int right;
} Philosopher;

// create a philosopher
// takes in the name of the philosopher and the index of the left and right fork
Philosopher *create(char *nam, int lef, int righ) {
	// Allocate memory for a new Philosopher struct
    Philosopher *x = malloc(sizeof(Philosopher));

    // Set the name of the philosopher
    x->name = nam;

    // Set the index of the left fork
    x->left = lef;

    // Set the index of the right fork
    x->right = righ;
	return x; 
}

// Function for a philosopher to eat
int eat(void *data) {
    // Set the sleep time to 1 second
    time1.tv_sec = 1;

    // Cast the data to a Philosopher struct
    Philosopher *foo = (Philosopher *) data;

    // Lock the left fork
    mtx_lock(&forks[foo->left]);

    // Lock the right fork
    mtx_lock(&forks[foo->right]);

    // Print that the philosopher is eating
    printf("%s is eating\n", foo->name);

    // Sleep for the specified time
    thrd_sleep(&time1, NULL);

    // Print that the philosopher is done eating
    printf("%s is done eating\n", foo->name);

    // Unlock the left fork
    mtx_unlock(&forks[foo->left]);

    // Unlock the right fork
    mtx_unlock(&forks[foo->right]);

    // Return 0 to indicate success
    return 0;
}

int main_philosophers(int argc, char *argv[]) {
    // Array to hold thread IDs for each philosopher
    thrd_t threadId[NUM_THREADS];

    // Array to hold all philosopher structs
    Philosopher *all[NUM_THREADS] = {
        create("Teral", 0, 1), 
        create("Billy", 1, 2), 
        create("Daniel", 2, 3), 
        create("Philip", 3, 4),
        create("Bennet", 0, 4)
    };

    // Initialize mutexes for each fork
    for (int i = 0; i < NUM_THREADS; i++) {
        if (mtx_init(&forks[i], mtx_plain) != thrd_success) {
            puts("FAILED IN MUTEX INIT!");
            return 0;
        }
    }

    // Create threads for each philosopher
    for (int i = 0; i < NUM_THREADS; ++i) {
        if (thrd_create(threadId + i, eat, all[i]) != thrd_success) {
            printf("%d-th thread create error\n", i);
            return 0;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; ++i)
        thrd_join(threadId[i], NULL);

    return 0;
}