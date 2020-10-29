#ifndef STRING_H
#define STRING_H
#include <string>
using std::string;
#endif

#include "../domain/app.cc"

class ChangeIconsFromFile {
   private:
   public:
    ChangeIconsFromFile(/* recibe colaboradores: fileReader, iconChanger */);

    void run(string infoFilePath) {
        app apps[] = fileReader();
        for (int iterator = 0; iterator < apps.size(); iterator++) {
            iconChanger(apps[iterator].getSettingFileName(), apps[iterator].getNewIconName());
        }
    }
};

ChangeIconsFromFile::ChangeIconsFromFile(/* recibe colaboradores: fileReader, iconChanger */) {
}
