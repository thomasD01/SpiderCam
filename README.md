# SpiderCam

## Entwicklungsumgebung

- Programmiersprache : C++
- Standard           : C++17
- Compiler           : msvc
- Architektur        : x86-64

## Benutzung

Nehmen sie die Datei SpiderCam.exe und legen sie in einem Verzeichnis ihrer wahl ab. Erstellen sie in diesem Verzeichnis den Ordner **data**. In diesem kann die datei **input.dat** abgelegt werden, welche die Kamerabewegung gemäß Aufgabenstellung angibt. Das programm kann durch doppelklicken der Exe Datei Ausgeführt werden, woraufhin die Dateien **out1.csv** und **out2.csv** im data Ordner erstellt werden.

## Kompilieren

Im Verzeichnis Code befindet sich eine **CMakeLists.txt**, mithilfe von CMake kann das Programm Komppiliert werden. Hierzu wird mindestens CMake version 3.21 benötigt. 
1. Makefile erzeugen
   ```bash
    cmake .
   ```
2. Ausführbare Datei erstellen
   ```bash
    cd build && make
   ```
3. Programm ausführen
   ```bash
    cd ../bin && main.*
   ```

**je nach Compiler hat die ausgegebene Datei eine andere Endung**

- MacOS:   keine Endung
- Windows: .exe
- linux:   .o oder keine Endung