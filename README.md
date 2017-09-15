FallingCode
=======================

Introduction
-----------------------
It simuates the scene of falling code coming from the film Matrix.

Dependent library
-----------------------
ncurses<br>
If you want to use another library, you just need to change `SysTool.cpp` and `makefile`.

Installation
-----------------------
Download and execute `make`.

Execution
-----------------------
Go to the directory `bin` and execute one of the commands as below:
* `./matrix.out`
* `./matrix.out colorValue`. E.g. `./matrix.out 23`. `colorValue`: [0, 255]
* `./matrix.out string colorValue`. E.g. `./matrix.out "hello world!" 122`
