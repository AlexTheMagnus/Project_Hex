#include "../domain/fileReaderMapper.cc"

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include <iostream>

#include "../colorMacros.cc"

class NativeFileReaderMapper : public FileReaderMapper {
   private:
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

   public:
    std::vector<App> mapFileToApps(string infoFilePath) {
        vector<App> apps;
        ifstream fileInfo = openFile(infoFilePath);
        string settingfileName, newIconName;

        while (getline(fileInfo, settingfileName, ',')) {
            getline(fileInfo, newIconName, '\n');

            App *auxiliaryApp = new App;
            auxiliaryApp->setSettingFileName(settingfileName);
            auxiliaryApp->setNewIconName(newIconName);

            apps.push_back(*auxiliaryApp);
        }

        return apps;
    }
};