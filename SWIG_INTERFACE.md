Building an Interface for the Deckhandler
=========================================

The interface is written in [SWIG](http://swig.org/index.php). Although
these instructions are for building a python wrapper, SWIG supports
building interfaces for many other languages.

To build the wrapper for python, from 'builddir':

```bash
meson configure -Dswig_lang=python
ninja
```

The resulting files will be in 'swig'.

After creating the wrapper, you can run it as so in python (note: make
sure you launch your python console in the same directory as you built
the wrapper into, or modify your
[sys.path](https://docs.python.org/3/library/sys.html#sys.path) to
point to the wrapper's directory):

```py
import deckhandler

# Set a seed.
deckhandler.seed()

# Create a deck.
deck = deckhandler.get_new_deck()

# Shuffle the deck.
deckhandler.DH_shuffle_deck(deck)

# Print out the whole deck.
for i in range(deckhandler.DH_CARDS_IN_DECK):
    card = deckhandler.deck_dh_get(deck, i)
    print("face: {}, suit: {}".format(deckhandler.DH_get_card_face(card), deckhandler.DH_get_card_suit(card)))
```
