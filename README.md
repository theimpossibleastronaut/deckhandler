[![Build Status](https://travis-ci.org/theimpossibleastronaut/deckhandler.svg?branch=master)](https://travis-ci.org/theimpossibleastronaut/deckhandler)

# deckhandler
Library that will create a deck of cards and shuffle it.

Two functions are included:

    deck_init_dh: initialize a deck
    deck_shuffle_dh: shuffle the deck

## Example

Create a deck:

    st_deck_dh deck_a;

Initialize and shuffle it:

    deck_init_dh (&deck_a);
    deck_shuffle_dh (&deck_a);

If you want to use more than one deck, use:

    st_deck_dh deck_a, deck_b, deck_c;

Detailed example usage can be seen in
[example-01.c](https://github.com/theimpossibleastronaut/deckhandler/blob/master/example-01.c)

## Building

To build the example program:

    mkdir build
    cd build
    cmake ..
    make

That will build the library, create the `example-01` executable and
then link to the libary.

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
    make deckhandler

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
