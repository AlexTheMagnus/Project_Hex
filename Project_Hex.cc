//Debe ser ejecutado como admin "sudo ./Project_Hex.out"
//appPath = "/usr/share/applications/"
#include <unistd.h>
#include <limits.h>

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

//Macros de colores
#define BLUE "\e[0;34m"   //POne el texto en color azul
#define UBLUE "\e[4;34m"  //Color azul con subrayado
#define RED "\e[0;31m"    //Color rojo
#define GREEN "\e[0;32m"  //Color verde
#define BGREEN "\e[1;32m" //Color verde con negrita
#define RESET "\e[0m"     //Reset de formato de letra (color, negrita,..)
#define CLEAR "\33[2J"    //Hace un clear pero mas bonito

////////////////////////////////////////////////////////////////////////////////

//Devuelve el path de la carpeta donde estan los iconos
string getpath()
{
  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL)
  {
    string executionPath(cwd);          //Paso de char* a string con el constructor de string
    return (executionPath + "/icons/"); //ruta donde se esta ejecutando el programa
  }
  else
  {
    cout << RED; //Color rojo
    perror("getcwd() error");
    cout << RESET; //Reset de formato de letra (color, negrita,..)
    return "error";
  }
}

void printWelcomeMessage()
{
  cout << CLEAR; //hace un clear pero mas bonito
  cout << endl;
  cout << UBLUE; //Color azul
  cout << "\t"
       << "Project_Hex" << endl;
  cout << RESET; //Reset de formato de letra (color, negrita,..)
  cout << endl;
}

void printOKMessage()
{
  cout << GREEN; //Pone las letras en color verde
  cout << "   OK" << endl;
  cout << RESET; //Reset de formato de letra (color, negrita,..)
}

void printEndMessage()
{
  cout << endl;
  cout << BGREEN;
  cout << "--Iconos cambiados correctamente. DONE.--" << endl;
  cout << RESET;        //Reset de formato de letra (color, negrita,..)
  cout << BLUE << endl; //Color azul
  cout << "Pulse intro para terminar el programa" << endl;
  getchar();
  system("reset");
}

void printIconFolderNotFoundMessage()
{
  cout << RED; //Color rojo
  cout << "Error al encontrar el path de la carpeta icon";
  cout << RESET; //Reset de formato de letra (color, negrita,..)
}

ifstream openFile(string fileNameInfo)
{
  ifstream fileInfo(fileNameInfo);
  if (!fileInfo)
  {
    cout << RED; //Color rojo
    cout << "Error al abrir el archivo" << endl;
    cout << RESET; //Reset de formato de letra (color, negrita,..)
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
  {              //no se pudo abrir alguno de los 2
    cout << RED; //Color rojo
    cout << "Error al abrir el archivo de la app" << endl;
    cout << "Compruebe que haya asignado privilegios al programa" << endl;
    cout << RESET;
    exit(-1);
  }

  //crear nuevo fichero de la app a raíz del original
  createNewAppFile(fileApp, fileAppTemp, fileLine, iconName);

  //reemplazar un archivo por otro
  replaceAppFile(fileApp, fileAppTemp, appName, appPath);

  fileApp.close();
}

void setApp(string appPath, string &appName)
{
  appName = appPath + appName;
}

void setIcon(string iconFolderPath, string &iconName)
{
  if ((iconFolderPath = getpath()) == "error")
  {
    printIconFolderNotFoundMessage();
  }
  iconName = getpath() + iconName;
}

int main()
{
  printWelcomeMessage();

  string appName, iconName;                    //nombre app, nombre del nuevo icono
  string appPath = "/usr/share/applications/"; //ruta a la carpeta de las apps
  string iconFolderPath;                       //ruta de la carpeta icon
  //Formato del fichero de info:  nombre_archivo_app,nombre_icono_nuevo
  string fileNameInfo = "info.txt"; //nombre del fichero con la info de las apps a cambiar el icono
  string fileLine;

  ifstream fileInfo = openFile(fileNameInfo);

  //getline devuelve falso cuando no hay mas lineas por leer
  while (getline(fileInfo, appName, ','))
  {
    getline(fileInfo, iconName, '\n');
    cout << "Cambiando icono de " << appName << "..." << endl;

    setApp(appPath, appName);
    setIcon(iconFolderPath, iconName);

    //modificar fichero de la app
    updateAppFile(fileLine, iconName, appName, appPath);

    printOKMessage();
  }

  fileInfo.close();
  printEndMessage();
}
