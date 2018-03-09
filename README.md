# Cross platform development example.  

CMake generates the appropriate compiler and linker options and ide project for different platforms from the same source files.

The same program builds and runs on numerous different platforms and integrated development environments without any change, relying on CMake to generate the specifics required to build on a particular environment, and libraries to provide the specifics required to execute in a particular environment.

See [Brian's rules for writing cross platform code](https://www.backblaze.com/blog/10-rules-for-how-to-write-cross-platform-code/):
> Rule #1: Simultaneously develop – don’t “port” it later, and _**do not outsource**_ the effort!

So you need to start off with something like this, that builds and runs on many platforms and many ides

## Windows Visual Studio ide
Using Visual Studio (which includes compiler, Git, and CMake functionality, hence no need to install half a dozen separate products and get them talking to each other): Launch the Visual Studio developer command prompt.
```
    git clone https://github.com/studi-c/cross-platform-hello.git
```

This will create the folder cross-platform-hello.  Launch Visual Studio and open that folder.  Visual Studio will automatically create a Visual Studio project in the `.vs` subdirectory from CMakeLists.txt in the main directory.

## Linux command line
Install git, g++, make, and cmake:  
```
    git clone https://github.com/studi-c/cross-platform-hello.git
    cd cross-platform-hello/build
    cmake ..
    make
    ./cross-platform-hello
```

`Cmake` creates the gnu makefile in the `build` subdirectory from CMakeLists.txt in the main directory.  `Make` then interprets that makefile as a script to call g++ to compile your program.

	
## Code::Blocks ide on linux
Install git, g++, make, cmake and codeblocks:
```
    git clone https://github.com/studi-c/cross-platform-hello.git
    cd cross-platform-hello/build
    cmake -G "CodeBlocks - Unix Makefiles" ..
```

Cmake creates a codeblocks project file (.cdb) in the `build` subdirectory from CMakeLists.txt in the main directory.  Launch CodeBlocks and open the project file.

## Windows command line using MingGW.
Install MingGW, Git, and Cmake.  Launch a command line with the path including Git, CMake and MingGW/bin.  
```
    git clone https://github.com/studi-c/cross-platform-hello.git
    cd cross-platform-hello/build
    cmake -G "MinGW Makefiles" ..
    mingw32-make
    cross-platform-hello
```

CMake will generate a makefile for mingw-make in the `build` subdirectory from CMakeLists.txt in the main directory.

## Code::Blocks ide using MinGW on windows
Install MingGW, Git, Cmake, and Code::Blocks.  Launch a command line with the path including Git, CMake and MingGW/bin.  
```
    git clone https://github.com/studi-c/cross-platform-hello.git
    cd cross-platform-hello/build
    cmake -G "CodeBlocks - MinGW Makefiles" ..
```

Cmake will create a codeblocks project file (.cdb) in the `build` subdirectory from CMakeLists.txt in the main directory.  Launch CodeBlocks and open the project file.

##Developers need all target environments at their fingertips

Each developer needs to install Oracle Virtual Box, and have several different platforms living on his computer in virtual machines.  It is easier to do cross platform development on Oracle Virtual Box machines than real machines because you can cut and paste between different environments, and move between different environments with a mouse click.

Developing this way from the beginning means that the developer will not design in features that depend on things idiosyncratic to a particular ide or a particular operating system, but instead will use things provided by libraries, and anything you might need is available in some form in an operating system independent and ide independent library.  So for example he should not use the registry on windows, but will instead use a configuration file in yaml, because windows registry only exists on windows, but libraries for reading and writing yaml are available that work in any ide and operating system.

Most ide specific and operating system dependent libraries are reinventing the wheel, and reinventing it badly, though you pretty much have to use operating system dependent designs to write installers, have to have a separate installer written specifically for a target operating system, using tools characteristic of that operating system

Visual Studio's facilities for creating the graphical user interface are very good, and will only work on windows.  WxWidgets, on the other hand, runs on all machines, and Code::Blocks, an IDE that supports wxWidgets, runs on all machines.  Brian argues for creating a separate GUI module that is not operating system  independent, but is built specifically for a particular platform using the best tools available for that platform. 

But, on the other hand wxWidgets is catching up.  Visual Studio is very good, but has not improved significantly for a long time.  WxWidgets has improved significantly, so it is not altogether obvious that his advice is up to date maybe you should use wxWidgets and Code::Blocks for a UI that will work on all machines, while looking as much as possible like the UI that most people will use - Windows 10.