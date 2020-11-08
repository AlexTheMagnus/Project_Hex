#include "../domain/iconChanger.cc"

#include <fstream>
using std::ifstream;

#include <limits.h>
#include <unistd.h>

#include <iostream>

#include "../colorMacros.cc"

class NativeIconChanger : public IconChanger {
   private:
    string aptAppsPath = "/usr/share/applications/";

    string tempFileName = "tempFile.txt";

    // Methods -------------------------------------

    string getAptAppsPath() { return aptAppsPath; }

    string getTempFileName() { return "tempFile.txt"; }

    string getSettingFileFullPath(string settingFileName) {
        return getAptAppsPath() + settingFileName;
    }

    void printChangingIconMessage(string appName) {
        std::cout << "Cambiando icono de " << appName << "..." << std::endl;
    }

    void printErrorOpeningInfoFileMessage() {
        std::cout << RED;  //Color rojo
        std::cout << "Error al abrir el archivo" << std::endl;
        std::cout << RESET;  //Reset de formato de letra (color, negrita,..)
    }

    void printErrorGettingExecutionPathMessage() {
        std::cout << RED;  //Color rojo
        perror("getcwd() error");
        std::cout << RESET;  //Reset de formato de letra (color, negrita,..)
    }

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

    string getIconFullPath(string iconName) {
        return getIconFolderPath() + iconName;
    }

    ifstream openFile(string fileNameInfo) {
        ifstream fileInfo(fileNameInfo);
        if (!fileInfo) {
            printErrorOpeningInfoFileMessage();
            exit(-1);
        }

        return fileInfo;
    }

    void createNewAppFile(string settingFileName, string iconName) {
        string fileLine;
        std::ifstream settingFile = openFile(getSettingFileFullPath(settingFileName));
        std::ofstream tempSettingFile(getAptAppsPath() + getTempFileName());

        while (getline(settingFile, fileLine, '\n')) {
            if ((fileLine.compare(0, 5, "Icon=")) == 0) {
                fileLine = "Icon=" + getIconFullPath(iconName);
            }
            tempSettingFile << fileLine << std::endl;
        }

        settingFile.close();
        tempSettingFile.close();
    }

    void replaceAppFile(string settingFileName) {
        remove(getSettingFileFullPath(settingFileName).c_str());
        rename((getAptAppsPath() + getTempFileName()).c_str(), getSettingFileFullPath(settingFileName).c_str());
    }

   public:
    void changeIconOf(string settingFileName, string newIconName) {
        printChangingIconMessage(settingFileName);

        createNewAppFile(settingFileName, newIconName);
        replaceAppFile(settingFileName);
    }
};