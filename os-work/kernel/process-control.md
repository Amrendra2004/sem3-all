Certainly! Below are separate code snippets for each of the functionalities: `fork()`, `getpid()`, `ps`, `kill`, and `sleep`. Each code demonstrates one specific functionality.

### `fork()`:

```cpp
#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
    pid_t childPid = fork();

    if (childPid == -1) {
        cerr << "Error forking the process\n";
        return 1;
    } else if (childPid == 0) {
        // Child process
        cout << "Child process ID: " << getpid() << endl;
    } else {
        // Parent process
        cout << "Parent process ID: " << getpid() << endl;
    }

    return 0;
}
```

### `getpid()`:

```cpp
#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
    pid_t processId = getpid();

    cout << "Current process ID: " << processId << endl;

    return 0;
}
```

### `ps`:

```cpp
#include <cstdlib>
using namespace std;
int main() {
    // Display process information using 'ps'
    system("ps -p $(echo $$)");

    return 0;
}
```

### `kill`:

```cpp
#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;
int main() {
    pid_t processId; // Specify the process ID to terminate

    cout << "Enter the process ID to terminate: ";
    cin >> processId;

    // Send SIGTERM signal to the specified process
    int result = kill(processId, SIGTERM);

    if (result == 0) {
        cout << "SIGTERM signal sent to process " << processId << endl;
    } else {
        cerr << "Error sending SIGTERM signal to process " << processId << endl;
        perror("Error details");
    }

    return 0;
}
```

### `sleep`:

```cpp
#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
    cout << "Sleeping for 3 seconds...\n";
    sleep(3);
    cout << "Woke up after sleeping\n";

    return 0;
}
```

You can compile and run each code separately to observe its individual functionality.