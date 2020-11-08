#include "infraestructure/changeIconsFromFileController.cc"

void printUnexpectedArgumentsMessage() {
    std::cout << RED;  //Color rojo
    std::cout << "Error, demasiados argumetos." << std::endl;
    std::cout << "El uso adecuado es: \"sudo ./Project_Hex.out <infoFile.txt>\"" << std::endl;
    std::cout << RESET;  //Reset de formato de letra (color, negrita,..)
}

string getFileInfoName(int argc, char* argv[]) {
    if (argc > 2) {
        printUnexpectedArgumentsMessage();
        exit(-1);
    }
    if (argc == 2) {
        std::cerr << "info" << std::endl;

        return argv[1];
    }
    std::cerr << "info" << std::endl;

    return "info.txt";
}

int main(int argc, char* argv[]) {
    string infoFileName = getFileInfoName(argc, argv);
    std::cout << infoFileName << std::endl;

    changeIconsFromFileController changeIconsFromFileController;
    changeIconsFromFileController.changeIconsFromFile(infoFileName);
}