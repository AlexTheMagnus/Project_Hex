#include "../domain/fileReaderMapper.cc"

#include <vector>

#include "../domain/app.cc"

class NativeFileReaderMapper : public FileReaderMapper {
   public:
    std::vector<App> mapFileToApps(string infoFilePath) {
    }
};