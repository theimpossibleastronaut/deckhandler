[![Build Status](https://travis-ci.org/theimpossibleastronaut/deckhandler.svg?branch=master)](https://travis-ci.org/theimpossibleastronaut/deckhandler)

# deckhandler
Library to handle a deck of cards

This will create a deck of cards and shuffle it.

## Building

    gcc -Wall example-01.c deckhandler.c -o example-01

Deckhandler is such a small library that building it as a shared or
static library is not needed. If you wish to use the sources, see the
[example from
aa-poker-hands](https://github.com/theimpossibleastronaut/aa-pokerhands/blob/master/src/Makefile.am).

If you are here for educational purposes, read on...

## Building a shared library and testing

You can use cmake to build only the library.

    mkdir build
    cd build
    cmake .. -D TYPE_SHARED=(OFF/ON)

("Off" will create a "static" library)

If you wish to make the library manually, you can use the instructions
below, adapted from [Creating a shared and static library with the gnu
compiler
(gcc)](https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index)

```
#!/bin/sh
gcc -shared -fPIC -Wl,-soname,libdeckhandler.so.1 -o libdeckhandler.so.1.0.0 deckhandler.c
ln -s libdeckhandler.so.1.0.0 libdeckhandler.so.1
gcc example-01.c libdeckhandler.so.1.0.0 -o example-01
LD_LIBRARY_PATH=`pwd` ./example-01
```

## Creating a static library and linking

```
#!/bin/sh
gcc -c example-01.c -o example-01.o
gcc -c deckhandler.c -o deckhandler.o
ar rcs libdeckhandler.a deckhandler.o
gcc example-01.o -L'pwd' -ldeckhandler -o example-01
```

## Projects that use deckhandler

* [aa-pokerhands](https://github.com/theimpossibleastronaut/aa-pokerhands)
