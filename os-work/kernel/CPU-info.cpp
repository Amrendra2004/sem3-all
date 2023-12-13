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
    string kernelVersion = execCommand("uname -r");
    if (!kernelVersion.empty()) {
        cout << "Linux Kernel Version: " << kernelVersion;
    }

    string cpuType = execCommand("uname -m");
    if (!cpuType.empty()) {
        cout << "CPU Type: " << cpuType;
    }

    string cpuInfo = execCommand("lscpu");
    if (!cpuInfo.empty()) {
        cout << "CPU Information:\n" << cpuInfo;
    }

    return 0;
}
