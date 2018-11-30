//Debe ser ejecutado como admin "sudo ./a.out"
//ruta = "/usr/share/applications/"
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

int main() {
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
    icon = "/home/alex/Pictures/Project_Hex/icons/" + icon;
    ifstream fileapp(app);                         //abre el archivo de dicha app
    ofstream fileapptemp(ruta + "filetemp.txt");   //abre el archivo temporalde la app
    if(!(fileapp.is_open()) || !(fileapptemp.is_open())){                  //no se pudo abrir alguno de los 2
      cout << "Error al abrir el archivo de la app" << endl;
      exit(-1);
    }


    //modificar línea a línea
    while(getline(fileapp, linea, '\n')){
      if((linea.compare(0,6,"Icon=/")) == 0) {  //comprueba si se encuentra en la linea de "Icon=/"
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
    cout << "OK" << endl;
  }
  fileinfo.close();
  cout << endl;
  cout << "--Iconos cambiados correctamente. DONE.--" << endl;
}
