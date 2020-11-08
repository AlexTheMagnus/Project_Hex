#include <string.h>

string getFileInfoName(int argc, char* argv[]) {
    if (argc > 2) {
        printUnexpectedArgumentsMessage();
        exit(-1);
    }
    if (argc = 2) {
        return argv[1];
    }
    return "info.txt";
}

int main(int argc, char* argv[]) {
    string fileInfoName = getFileInfoName(argc, argv);
}