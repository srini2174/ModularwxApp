ModularwxApp

ModularwxApp
============

Cross-Platform Modular Application (Main app + plugins) example for C++/wxWidgets

Organization of project
=======================

The project is organized in a modular way as per the guidelines given https://cmake-basis.github.io/standard/modules.html

ToplevelWS
|
|
|=== Application
|=== Doc
|=== Modules
|=== Frameworks
		|
		|
		|====ApplicationFW
		|		|
		|		|===modules
		|				|
		|				|=== module-1
		|				|=== module-2
		|=====PluginItf
				|
				|===modules
						|
						|=== GuiPluginItf
						|=== NonGuiPluginItf
						
Requirements
------------
* Compiled shared (DLL Debug/DLL Release) version of wxWidgets. [Git Master](https://github.com/wxWidgets/wxWidgets) or official [3.1.x](http://wxwidgets.org/downloads/) release should work fine.
* [CMake](http://www.cmake.org/) - required on all platforms. It is used for creating 
  * Visual Studio code along with Visual studio build tools 2017 under Windows
  * Makefiles under Linux
  * XCode projects under OS X
* Under each modules/config folder a settings.cmake file is located.  This file has to be changed to provide the installation details for wxwidgets
* Ensure that you have only `vc_dll` subfolder in `%WXWIN%/libs`. If you have `vc_lib*` folders (contain static build of wxWidgets) then rename them temporary.

wxWidgets Build Commands for Linux and OS X
-------------------------------------------
<strong>Debug:</strong>

`configure --enable-shared --disable-static --enable-unicode --disable-compat28 --disable-final --enable-debug`

<strong>Release:</strong>

`configure --enable-shared --disable-static --enable-unicode --disable-compat28 --enable-final --disable-debug`

Compilation under Windows
-------------------------
* Open Visual Studio code
* Install Cmake Tools and make the necessary setup
* Set the correct compiler toolkit option from the status bar
* Execute `build from the status bar




