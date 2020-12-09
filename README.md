# IndiaEngine
[Tiled documentatie](docs/Tiled.md)

# Project setup Windows 10 64 bit

## [vcpkg](https://github.com/Microsoft/vcpkg#getting-Enemyted) (package manager) installatie ❗
#### Git Clone de volgende repository naar 'C:\dev'
     cd C:\dev
     git clone https://github.com/microsoft/vcpkg
     .\vcpkg\bootstrap-vcpkg.bat
###### Test met het commando 
      C:\dev\vcpkg\vcpkg.exe search sdl2

### Visual studio integratie ❗
#### commando om vcpkg met Visual Studio te gebruiken
    C:\dev\vcpkg\vcpkg.exe integrate install


### Packages om te installeren ❗
##### Voer het bestand install_dependencies.bat uit in de project root.
##### _Controleer voor Google Test dat je via Visual Studio Installer het component 'Test Adapter for Google Test' hebt geïnstalleerd voor jouw installatie van Visual Studio_

### Validatie
##### Controleer of alle dependencies zijn geïnstalleerd met het volgende commando
    C:\dev\vcpkg\vcpkg.exe list

## Finishing setup
Nadat vcpkg en alle packages goed zijn ingesteld, kun je in Visual Studio de map openen. Indien er errors komen gerelateerd aan CMake, kan het zijn dat een package niet is geïnstalleerd of dat vcpkg  op de verkeerde plek staat.

###### Unit tests
Unit tests zijn te runnen door `UnitTests.exe` te builden in Visual Studio. Als je dit doet met de Test Explorer open, dan zal deze automatisch gevuld worden met de Unit Tests uit het project.

## [Doxygen](https://www.doxygen.nl)

### Doxygen diagrammen met [Graphviz](https://www2.graphviz.org/Packages/stable/windows/10/cmake/Release/x64/)
Om uitgebreide diagrammen te genereren gebruikt Doxygen Dot van Graphviz. 
Voer het setup bestand uit. 
- __Let op:__ installeer Graphviz naar `C:\Graphviz\` anders zal Doxygen Dot niet kunnen vinden.
- __Let op:__ Voordat Dot zal werken, zul je nog eerst met een opdrachtprompt met administratieve rechten het commando `dot -c` vanuit `C:\Graphviz\bin` moeten uitvoeren.

Indien je deze stappen hebt gevolgd, zal het project builden en zal de Doxygen documentatie uitgebreide grafieken bevatten.

### Doxygen lezen
Bij iedere release build en installatie is een docs map met daarin een `Doxygen.html` bestand te vinden. Deze opent de bijgeleverde Doxygen documentatie van de IndiaEngine.

### Doxygen genereren
Indien je Doxygen hebt geïnstalleerd op je machine, dan zal er tijdens het builden en installeren van de release versie de Doxygen documentatie gegenereerd worden in de doelmap.

# IndiaEngine builden & installeren 
## Windows 10 64 bit
### Builden
Vanuit Visual Studio kun je de IndiaEngine builden of installeren. Indien je de IndiaEngine build, dan komt het resultaat in de `out` map in de projectmap terecht.

### Installeren
Indien je de IndiaEngine installeert, dan komt de IndiaEngine in de `${INSTALL_DIR}` variabele uit `CMakeLists.txt`. `${INSTALL_DIR}` is standaard `C:/dev/IndiaEngine`

