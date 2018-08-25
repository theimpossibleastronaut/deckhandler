[![Build Status](https://travis-ci.org/theimpossibleastronaut/deckhandler.svg?branch=master)](https://travis-ci.org/theimpossibleastronaut/deckhandler)

# deckhandler
Library to handle a deck of cards

This will create a deck of cards and shuffle it.

# Building

    gcc -Wall example-01.c deckhandler.c -o example-01

# Building a shared library and testing

```
#!/bin/sh
gcc -shared -fPIC -Wl,-soname,libdeckhandler.so.1 -o libdeckhandler.so.1.0.0 deckhandler.c
ln -s libdeckhandler.so.1.0.0 libdeckhandler.so.1
gcc example-01.c libdeckhandler.so.1.0.0 -o example-01
LD_LIBRARY_PATH=`pwd` ./example-01
```

# Creating a static library and linking

```
#!/bin/sh
gcc -c example-01.c -o example-01.o
gcc -c deckhandler.c -o deckhandler.o
ar rcs libdeckhandler.a deckhandler.o
gcc example-01.o -L'pwd' -ldeckhandler -o example-01
```
