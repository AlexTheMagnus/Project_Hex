//Debe ser ejecutado como admin "sudo ./Project_Hex.out"
//appPath = "/usr/share/applications/"

#include "fileFunctions.cc"
#include "getters.cc"

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    printWelcomeMessage();

    string appName, iconName;                     //nombre app, nombre del nuevo icono
    string appPath = "/usr/share/applications/";  //ruta a la carpeta de las apps
    string iconFolderPath;                        //ruta de la carpeta icon
    //Formato del fichero de info:  nombre_archivo_app,nombre_icono_nuevo
    string fileInfoName = getFileInfoName(argc, argv);  //nombre del fichero con la info de las apps a cambiar el icono
    string fileLine;

    ifstream fileInfo = openFile("./" + fileInfoName);

    //getline devuelve falso cuando no hay mas lineas por leer
    while (getline(fileInfo, appName, ',')) {
        getline(fileInfo, iconName, '\n');
        printChangingIconMessage(appName);

        appName = getApp(appPath, appName);
        iconName = getIcon(iconFolderPath, iconName);

        //modificar fichero de la app
        updateAppFile(fileLine, iconName, appName, appPath);

        printOKMessage();
    }

    fileInfo.close();
    printEndMessage();
}
