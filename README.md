# deckhandler
Library to handle a deck of cards

A work-in-progress

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


