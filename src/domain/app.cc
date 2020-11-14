#ifndef STRING_H
#define STRING_H
#include <string>
using std::string;
#endif

class App {
   private:
    string _settingFileName;
    string _newIconName;

   public:
    inline void setSettingFileName(string settingFileName) { _settingFileName = settingFileName; }
    inline void setNewIconName(string newIconName) { _newIconName = newIconName; }

    inline string getSettingFileName() { return _settingFileName; }
    inline string getNewIconName() { return _newIconName; }
};