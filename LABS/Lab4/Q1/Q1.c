#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  

    if (pid == -1) {
        perror("fork failed");  
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
