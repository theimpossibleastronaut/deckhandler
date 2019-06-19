Building an Interface for the Deckhandler
=========================================

The interface is written in [SWIG](http://swig.org/index.php). Although these instructions are for building in python, SWIG supports building interfaces for many other languages.

To build the interface for python:

```bash
swig -python deckhandler.i
gcc -fpic -c deckhandler.c  deckhandler_wrap.c -I/usr/local/include/python2.7
ld -shared deckhandler.o deckhandler_wrap.o -o _deckhandler.so
```
Note that here, the path of `python.h` is assumed to be `/usr/local/include/python2.7`. This may not be true on your system. For example, if python 3 is installed on your Linux OS, then the path would be `/usr/local/include/python3.7`. If you want to build using anaconda 3 python headers, then the path needs to be set to `/path/to/anaconda3/include/python3.7m/`.

After creating the interface, you can run it as so in python (note: make sure you launch your python console in the same directory as you built the interface into, or modify your [sys.path](https://docs.python.org/3/library/sys.html#sys.path) to point to the interface's directory):

```py
import deckhandler

# Create a deck.
deck = deckhandler.st_deck_dh()

# Initialise the deck.
deckhandler.deck_init_dh(deck)

# Shuffle the deck.
deckhandler.deck_shuffle_dh(deck)

# get the 11th card in the deck.
card = deckhandler.deck_dh_get(deck, 10)

# Print the face value and suit value of this card.
print("face val: {}, suit value: {}".format(card.face_val, card.suit))
```
