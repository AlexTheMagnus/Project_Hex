#include <fstream>
using std::ifstream;
using std::ofstream;

#ifndef PRINTMESSAGEFUNCTIONS_H
#define PRINTMESSAGEFUNCTIONS_H
#include "printMessageFunctions.cc"
#endif

ifstream openFile(string fileNameInfo)
{
  ifstream fileInfo(fileNameInfo);
  if (!fileInfo)
  {
    printErrorOpeningInfoFileMessage();
    exit(-1);
  }

  return fileInfo;
}

void createNewAppFile(ifstream &fileApp, ofstream &fileAppTemp, string fileLine, string iconName)
{
  while (getline(fileApp, fileLine, '\n'))
  {
    if ((fileLine.compare(0, 5, "Icon=")) == 0)
    {                                //comprueba si se encuentra en la linea de "Icon="
      fileLine = "Icon=" + iconName; //si entra cambia la ruta del icono
    }
    fileAppTemp << fileLine << endl; //escribe en el nuevo fichero
  }
}

void replaceAppFile(ifstream &fileApp, ofstream &fileAppTemp, string appName, string appPath)
{
  fileApp.close();
  fileAppTemp.close();
  remove(appName.c_str());                                     // borrar el original
  rename((appPath + "filetemp.txt").c_str(), appName.c_str()); // renombrar el temporal
}

void updateAppFile(string fileLine, string iconName, string appName, string appPath)
{

  ifstream fileApp(appName);                      //abre el archivo de dicha app
  ofstream fileAppTemp(appPath + "filetemp.txt"); //abre el archivo temporal de la app

  if (!(fileApp.is_open()) || !(fileAppTemp.is_open()))
  { //no se pudo abrir alguno de los 2
    printErrorOpeningAppFileMessage();
    exit(-1);
  }

  //crear nuevo fichero de la app a raíz del original
  createNewAppFile(fileApp, fileAppTemp, fileLine, iconName);

  //reemplazar un archivo por otro
  replaceAppFile(fileApp, fileAppTemp, appName, appPath);

  fileApp.close();
}
