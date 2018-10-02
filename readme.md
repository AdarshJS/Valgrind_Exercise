# C++ Boilerplate
[![Build Status](https://travis-ci.org/AdarshJS/Valgrind_Exercise.svg?branch=valgrind_exercise)](https://travis-ci.org/AdarshJS/Valgrind_Exercise)
[![Coverage Status](https://coveralls.io/repos/github/AdarshJS/Valgrind_Exercise/badge.svg?branch=valgrind_exercise)](https://coveralls.io/github/AdarshJS/Valgrind_Exercise?branch=valgrind_exercise)
---

## Overview

Exercise to use Valgrind tools.

## Prerequisites

Install valgrind:
```
sudo apt install valgrind
```
Valgrind is an undefined behavior checking tool, a function and memory profiler, data race detection tool, and a leak checking tool. A useful resource can be found here: http://maintainablecode.logdown.com/posts/245425-valgrind-is-not-a-leak-checker

Install KCachegrind for visualization:
```
sudo apt install kcachegrind
```
This tool is used to provide a GUI visualization of flow of your program, what functions are eating up your runtime, and generally, a better understanding of where to focus your efforts.


## Standard install via command-line
```
git clone --recursive https://github.com/AdarshJS/Valgrind_Exercise.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Using Valgrind

Identifying errors (without any special arguments):
```
valgrind ./myProgram myProgramsFirstArg myProgramsSecondArg
```

In our case, to identify memory leaks and other errors use:
```
cd <path to repository>
valgrind --tool=memcheck --leak-check=full ./build/app/shell-app 

```

Running the function and memory profiler:
```
cd <path to repository>
valgrind --tool=callgrind ./build/app/shell-app
valgrind --tool=massif ./build/app/shell-app
```

callgrind provides insights into what functions are taking up a lot of runtime. This produces a file like callgrind.out.<ID>. See an example in the results folder. This file can be viewed in Kcachegrind.

massif provides insights into where most memory is allocated. This produces an output file like massif.out.<ID>. To view this file, run the following command:
```
ms_print massif.out.<ID>
```
This will display the output on the terminal. See an example output in results/massif_output. A useful link for reference: http://valgrind.org/docs/manual/ms-manual.html



