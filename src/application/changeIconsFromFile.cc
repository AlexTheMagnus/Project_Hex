#include "../domain/app.cc"
#include "../domain/fileReaderMapper.cc"
#include "../domain/iconChanger.cc"

class ChangeIconsFromFile {
   private:
    FileReaderMapper _fileReaderMapper;
    IconChanger _iconChanger;

   public:
    ChangeIconsFromFile(FileReaderMapper fileReaderMapper, IconChanger iconChanger) {
        _fileReaderMapper = fileReaderMapper;
        _iconChanger = iconChanger;
    };

    void run(string infoFilePath) {
        std::vector<App> apps = _fileReaderMapper.mapFileToApps(infoFilePath);
        for (int iterator = 0; iterator < apps.size(); iterator++) {
            _iconChanger.changeIconOf(apps[iterator].getSettingFileName(), apps[iterator].getNewIconName());
        }
    }
};