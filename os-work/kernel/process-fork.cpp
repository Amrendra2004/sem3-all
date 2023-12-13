/*Ques-2 Write a program to demonstrate fork where parent and child run same codes and child
process should run first. */
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    cout << "Parent process ID: " << getpid() << endl;

    pid_t child = fork();

    if (child == 0) {
        // Child process
        cout << "Child process ID: " << getpid() << endl;
        cout << "Child process running first\n";
    } else if (child > 0) {
        // Parent process
        waitpid(child, nullptr, 0);  // Wait for the child process to finish
        cout << "Parent process continues after the child\n";
    } else {
        cerr << "Error forking child\n";
        return 1;
    }

    return 0;
}
