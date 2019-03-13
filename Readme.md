# Project_Hex

Could a program that change ubuntu app icons be a good idea? I think it's.

## Getting Started

Follow the easy next steps to have your custom ubuntu icons.

## Prerequisites
None, just know the name of the configuration file of the program you would like to change the icon and have an icon to put instead of the original icon.

> **Note:** *Configuration files are saved in /usr/share/applications. If you don't know the name of any of the programs you want to change the icon, you can check it there.*

### Installing
Download the github [Project_Hex repository](https://github.com/AlexTheMagnus/Project_Hex) and compile it with:
```
make
```
Then an executable *Project_Hex.out* will have apeared.  
Put inside the *icon* folder the icon u would like to have.  
Open with any text editor the file *info.txt* and type inside the name of the configuration file followed by the name of the icon you put inside the *icon* folder. See the next example:
```
atom.desktop,atom_icon.png
```
It is possible to change several icons at the same time. Just type an *enter* and write the next icon line:
```
atom.desktop,atomNewIcon.png
firefox.desktop,firefoxNewIcon.png
spotify.desktop,spotifyNewIcon.png
```
Finally, execute it typing:
```
./Project_Hex
```
Now, enjoy your brand new ubuntu icons :) .

## Configuration File Index
In this section you can check some names of configuration files.

* Atom -> atom.desktop
* Evince -> evince.desktop
* Filezilla -> filezilla.desktop
* Firefox -> firefox.desktop
* Nautilus -> org.gnome.Nautilus.desktop
* Spotify -> spotify.desktop
* Steam -> steam.desktop
* Telegram -> telegramdesktop.desktop

## Authors

* **Manuel Alejandro Luque León** - Initial idea and programming - [AlexMagnus](https://github.com/AlexTheMagnus)

See also contributors who help to improve this project:  
**Pablo Rodríguez Guillén** - [Pablorg99](https://github.com/Pablorg99)


## License

The project owner is [AlexMagnus](https://github.com/AlexTheMagnus). This code can be free edited, but the original developer must be mentioned and please contact the owner so that he could check it and learn from it.
