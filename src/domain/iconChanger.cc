#ifndef STRING_H
#define STRING_H
#include <string>
using std::string;
#endif

class IconChanger {
   public:
    virtual void changeIconOf(string settingFileName, string newIconName) {}
};