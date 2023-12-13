#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

string execCommand(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");

    if (!pipe) {
        cerr << "Error executing command." << endl;
        return "";
    }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }

    pclose(pipe);
    return result;
}

int main() {
    // Get memory information using the free command
    string memoryInfo = execCommand("free -h");
    if (!memoryInfo.empty()) {
        cout << "Memory Information:\n" << memoryInfo;
    }

    return 0;
}
