#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void execute(int num) {
  pid_t pid = fork();

  if (pid == 0) { // Child process
    switch (num) {
      case 1: // Same program, same code
        cout << "Child process executing same code as parent." << endl;
        break;
      case 2: // Same program, different code
        cout << "Child process executing different code." << endl;
        sleep(2);
        cout << "Child process complete." << endl;
        break;
      default:
        cout << "Invalid case." << endl;
        break;
    }
  } else if (pid > 0) { // Parent process
    wait(NULL);
    cout << "Parent process waiting for child to complete." << endl;
    cout << "Child process completed." << endl;
  } else {
    cout << "Error creating child process." << endl;
  }
}

int main() {
  int num;
  cout << "Choose case(1-3): ";
  cin >> num;
  execute(num);

  return 0;
}