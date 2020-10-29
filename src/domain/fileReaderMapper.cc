#include <vector>

#include "app.cc"

class FileReaderMapper {
   public:
    virtual std::vector<App> mapFileToApps(string infoFilePath) {}
};