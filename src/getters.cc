#include <limits.h>
#include <unistd.h>

#ifndef PRINTMESSAGEFUNCTIONS_H
#define PRINTMESSAGEFUNCTIONS_H
#include "infraestructure/printMessageFunctions.cc"
#endif

string getFileInfoName(int argc, char *argv[]) {
    if (argc > 2) {
        printUnexpectedArgumentsMessage();
        exit(-1);
    }
    if (argc = 2) {
        return argv[1];
    }
    return "info.txt";
}

//Devuelve la ruta de la carpeta donde estan los iconos
string getIconFolderPath() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        string executionPath(cwd);           //Paso de char* a string con el constructor de string
        return (executionPath + "/icons/");  //ruta donde se esta ejecutando el programa
    } else {
        printErrorGettingExecutionPathMessage();
        return "error";
    }
}

string getApp(string appPath, string appName) {
    return appPath + appName;
}

string getIcon(string iconFolderPath, string iconName) {
    if ((iconFolderPath = getIconFolderPath()) == "error") {
        printIconFolderNotFoundMessage();
    }
    return getIconFolderPath() + iconName;
}
