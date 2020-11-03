#include "../domain/iconChanger.cc"

#include <fstream>
using std::ifstream;

#include <iostream>

#include "../colorMacros.cc"

class NativeIconChanger : public IconChanger {
   private:
    string aptAppsPath = "/usr/share/applications/";

    void printErrorOpeningInfoFileMessage() {
        std::cout << RED;  //Color rojo
        std::cout << "Error al abrir el archivo" << std::endl;
        std::cout << RESET;  //Reset de formato de letra (color, negrita,..)
    }

    ifstream openFile(string fileNameInfo) {
        ifstream fileInfo(fileNameInfo);
        if (!fileInfo) {
            printErrorOpeningInfoFileMessage();
            exit(-1);
        }

        return fileInfo;
    }

    string getAptAppsPath() { return aptAppsPath; }

    string settingFileFullPath(string settingFileName) {
        return aptAppsPath + settingFileName;
    }

    void createNewAppFile(ifstream &fileApp, string iconName) {
        string fileLine;
        ofstream fileAppTemp(appPath + "filetemp.txt");  //abre el archivo temporal de la app

        while (getline(fileApp, fileLine, '\n')) {
            if ((fileLine.compare(0, 5, "Icon=")) == 0) {  //comprueba si se encuentra en la linea de "Icon="
                fileLine = "Icon=" + iconName;             //si entra cambia la ruta del icono
            }
            fileAppTemp << fileLine << std::endl;  //escribe en el nuevo fichero
        }
    }

   public:
    void changeIconOf(string settingFileName, string newIconName) {
        ifstream settingFile = openFile(settingFileFullPath(settingFileName));

        createNewAppFile(settingFile, newIconName);

        replaceAppFile(settingFile, fileAppTemp, settingFileName, appPath);
    }
};