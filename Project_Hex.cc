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

//Macros de colores
#define BLUE "\e[0;34m"         //POne el texto en color azul
#define UBLUE "\e[4;34m"        //Color azul con subrayado
#define RED "\e[0;31m"          //Color rojo
#define GREEN "\e[0;32m"        //Color verde
#define BGREEN "\e[1;32m"       //Color verde con negrita
#define RESET "\e[0m"           //Reset de formato de letra (color, negrita,..)
#define CLEAR "\33[2J"          //Hace un clear pero mas bonito

////////////////////////////////////////////////////////////////////////////////

//Devuelve el path de la carpeta donde estan los iconos
string getpath() {
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       string ruta_ejec(cwd);            //Paso de char* a string con el constructor de string
       return (ruta_ejec + "/icons/");   //ruta donde se esta ejecutando el programa
   }
   else {
       cout << RED;      //Color rojo
       perror("getcwd() error");
       cout << RESET;         //Reset de formato de letra (color, negrita,..)
       return "error";
   }
}

int main() {
    //system("clear");
    cout << CLEAR;       //hace un clear pero mas bonito
    cout << endl;
    cout << UBLUE;     //Color azul
    cout << "\t" << "Project_Hex" << endl;
    cout << RESET;        //Reset de formato de letra (color, negrita,..)
    cout << endl;

    string app, icon;                           //nombre app, nombre del nuevo icono
    string ruta = "/usr/share/applications/";   //ruta a la carpeta de las apps
    string path;                                //ruta de la carpeta icon
    //Formato del fichero de info:  nombre_archivo_app,nombre_icono_nuevo
    string filenameinfo = "info.txt";           //nombre del fichero con la info de las apps a cambiar el icono
    string linea;

    ifstream fileinfo(filenameinfo);
    if (!fileinfo){
        cout << RED;     //Color rojo
        cout << "Error al abrir el archivo de la info" << endl;
        cout << RESET;        //Reset de formato de letra (color, negrita,..)
        exit(-1);
    }

    //getline devuelve falso cuando no hay mas lineas por leer
    while(getline(fileinfo, app, ',')){
        getline(fileinfo, icon, '\n');
        cout << "Cambiando icono de " << app << "..." << endl;


        app = ruta + app;
        if((path = getpath()) == "error"){
            cout << RED;      //Color rojo
            cout << "Error al encontrar el path de la carpeta icon";
            cout << RESET;         //Reset de formato de letra (color, negrita,..)
        }
        icon = getpath() + icon;
        ifstream fileapp(app);                         //abre el archivo de dicha app
        ofstream fileapptemp(ruta + "filetemp.txt");   //abre el archivo temporalde la app
        if(!(fileapp.is_open()) || !(fileapptemp.is_open())){                  //no se pudo abrir alguno de los 2
            cout << RED;     //Color rojo
            cout << "Error al abrir el archivo de la app" << endl;
            cout << "Compruebe que haya asignado privilegios al programa" << endl;
            cout << RESET;
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
            cout << GREEN;          //Pone las letras en color verde
            cout << "   OK" << endl;
            cout << RESET;          //Reset de formato de letra (color, negrita,..)
    }
    fileinfo.close();
    cout << endl;
    cout << BGREEN;
    cout << "--Iconos cambiados correctamente. DONE.--" << endl;
    cout << RESET;               //Reset de formato de letra (color, negrita,..)
    cout << BLUE << endl;        //Color azul
    cout << "Pulse intro para terminar el programa" << endl;
    getchar();
    system("reset");
}
