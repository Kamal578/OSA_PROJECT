#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <pid>\n", argv[0]);
        exit(1);
    }

    pid_t pid = atoi(argv[1]);

    srand(time(NULL)); // Initialize the random number generator

    for (int i = 0; i < 100; i++)
    {
        int signal = rand() % 3 + 2; // Generate a random signal number (2, 3, or 15)
        if(signal == 2 || signal == 3){
            printf("Sending signal %d to process %d\n", signal, pid);
            kill(pid, signal);
            sleep(1); // Wait for 1 second before sending the next signal
        }
        else{
            signal = 15;
            printf("Sending signal %d to process %d\n", signal, pid);
            kill(pid, signal);
            sleep(1); // Wait for 1 second before sending the next signal
        }
    }

    return 0;
}
