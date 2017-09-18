FallingCode
=======================

### Introduction ###
It simuates the scene of falling code coming from the film Matrix.

### Dependent library ###
ncurses<br>
If you want to use another library, you just need to change `SysTool.cpp` and `makefile`.

### Installation ###
Download and execute `make`.

### Execution ###
Go to the directory `bin` and execute one of the commands as below:
* `./matrix.out colorValue`. E.g. `./matrix.out 23`.
* `./matrix.out string colorValue`. E.g. `./matrix.out "hello world!" 122`.
<br>Besides, the `colorValue` is optional and its range is [0, 255].
