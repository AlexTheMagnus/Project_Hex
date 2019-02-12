//Debe ser ejecutado como admin "sudo ./Project_Hex.out"
//ruta = "/usr/share/applications/"
#include <unistd.h>
#include <limits.h>

#include <fstream>
using std::ofstream;
using std::ifstream;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

string getpath() {
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       string ruta_ejec(cwd);          //Paso de char* a string con el constructor de string
       return (ruta_ejec + "/icons/");   //ruta donde se esta ejecutando el programa
   }
   else {
       perror("getcwd() error");
       return "error";
   }
}

int main() {
    cout << endl;

    string app, icon;                          //nombre app, nombre del nuevo icono
    string ruta = "/usr/share/applications/";   //ruta a la carpeta de las apps
    //Formato del fichero de info:  nombre_archivo_app,nombre_icono_nuevo
    string filenameinfo = "info.txt";          //nombre del fichero con la info de las apps a cambiar el icono
    string linea;

    ifstream fileinfo(filenameinfo);
    if (!fileinfo){
        cout << "Error al abrir el archivo de la info" << endl;
        exit(-1);
    }

  //getline devuelve falso cuando no hay mas lineas por leer
  while(getline(fileinfo, app, ',')){
    getline(fileinfo, icon, '\n');
    cout << "Cambiando icono de " << app << "..." << endl;


    app = ruta + app;
    icon = getpath() + icon;
    ifstream fileapp(app);                         //abre el archivo de dicha app
    ofstream fileapptemp(ruta + "filetemp.txt");   //abre el archivo temporalde la app
    if(!(fileapp.is_open()) || !(fileapptemp.is_open())){                  //no se pudo abrir alguno de los 2
      cout << "Error al abrir el archivo de la app" << endl;
      cout << "Compruebe que haya asignado privilegios al programa" << endl;
      exit(-1);
    }


    //modificar línea a línea
    while(getline(fileapp, linea, '\n')){
      if((linea.compare(0,5,"Icon=")) == 0) {  //comprueba si se encuentra en la linea de "Icon="
        linea = "Icon=" + icon;                 //si entra cambia la ruta del icono
      }
      fileapptemp << linea <<endl;                         //escribe en el nuevo fichero
    }


    //reemplazar un archivo por otro
   fileapp.close();
   fileapptemp.close();
   remove(app.c_str());                                     // borrar el original
   rename((ruta + "filetemp.txt").c_str(), app.c_str());    // renombrar el temporal


    fileapp.close();
    cout << "\e[0;32m";     //Pone las letras en color verde
    cout << "OK" << endl;
    cout << "\e[0m";        //Reset de formato de letra (color, negrita,..)
  }
  fileinfo.close();
  cout << endl;
  cout << "\e[1;32m";       //Pone las letras en color verde
  cout << "--Iconos cambiados correctamente. DONE.--" << endl;
  //cout << "\e[0m";        //Reset de formato de letra (color, negrita,..)
  //cout << "\e[0;34m" << endl;   //Color azul
  //cout << "Pulse intro para terminar el programa" << endl;

}
