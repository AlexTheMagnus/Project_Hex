#include <iostream>

#include "../colorMacros.cc"
#include "fileReaderMapper.cc"
#include "iconChanger.cc"

class changeIconsFromFileController {
   private:
    void printWelcomeMessage() {
        std::cout << CLEAR;  //hace un clear pero mas bonito
        std::cout << std::endl;
        std::cout << UBLUE;  //Color azul
        std::cout << "\t"
                  << "Project_Hex" << std::endl;
        std::cout << RESET;  //Reset de formato de letra (color, negrita,..)
        std::cout << std::endl;
    }

    void printChangingIconMessage(string settingFileName) {
        std::cout << "Cambiando icono de " << settingFileName << "..." << std::endl;
    }

    void printOKMessage() {
        std::cout << GREEN;  //Pone las letras en color verde
        std::cout << "   OK" << std::endl;
        std::cout << RESET;  //Reset de formato de letra (color, negrita,..)
    }

   public:
    void changeIconsFromFile(string infoFileName) {
        printWelcomeMessage();

        NativeFileReaderMapper fileReaderMapper;
        vector<App> apps = (fileReaderMapper.mapFileToApps(infoFileName));

        NativeIconChanger iconChanger;

        for (std::vector<App>::iterator iterator = apps.begin(); iterator != apps.end(); ++iterator) {
            printChangingIconMessage(iterator->getSettingFileName());

            iconChanger.changeIconOf(iterator->getSettingFileName(), iterator->getNewIconName());
            printOKMessage();
        }
    }
};