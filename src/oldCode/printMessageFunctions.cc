#ifndef STRING_H
#include <string>
using std::string;
#endif

#include <iostream>
using std::cout;
using std::endl;

#include "../colorMacros.cc"

void printWelcomeMessage() {
    cout << CLEAR;  //hace un clear pero mas bonito
    cout << endl;
    cout << UBLUE;  //Color azul
    cout << "\t"
         << "Project_Hex" << endl;
    cout << RESET;  //Reset de formato de letra (color, negrita,..)
    cout << endl;
}

void printUnexpectedArgumentsMessage() {
    cout << RED;  //Color rojo
    cout << "Error, demasiados argumetos." << endl;
    cout << "El uso adecuado es: \"sudo ./Project_Hex.out <infoFile.txt>\"" << endl;
    cout << RESET;  //Reset de formato de letra (color, negrita,..)
}

void printOKMessage() {
    cout << GREEN;  //Pone las letras en color verde
    cout << "   OK" << endl;
    cout << RESET;  //Reset de formato de letra (color, negrita,..)
}

void printEndMessage() {
    cout << endl;
    cout << BGREEN;
    cout << "--Iconos cambiados correctamente. DONE.--" << endl;
    cout << RESET;         //Reset de formato de letra (color, negrita,..)
    cout << BLUE << endl;  //Color azul
    cout << "Pulse intro para terminar el programa" << endl;
    getchar();
    system("reset");
}

void printIconFolderNotFoundMessage() {
    cout << RED;  //Color rojo
    cout << "Error al encontrar el path de la carpeta icon";
    cout << RESET;  //Reset de formato de letra (color, negrita,..)
}

void printErrorGettingExecutionPathMessage() {
    cout << RED;  //Color rojo
    perror("getcwd() error");
    cout << RESET;  //Reset de formato de letra (color, negrita,..)
}

void printErrorOpeningInfoFileMessage() {
    cout << RED;  //Color rojo
    cout << "Error al abrir el archivo" << endl;
    cout << RESET;  //Reset de formato de letra (color, negrita,..)
}

void printErrorOpeningAppFileMessage() {
    cout << RED;  //Color rojo
    cout << "Error al abrir el archivo de la app" << endl;
    cout << "Compruebe que haya asignado privilegios al programa" << endl;
    cout << RESET;
}

void printChangingIconMessage(string appName) {
    cout << "Cambiando icono de " << appName << "..." << endl;
}