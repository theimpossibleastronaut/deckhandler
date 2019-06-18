[![Build Status](https://travis-ci.org/theimpossibleastronaut/deckhandler.svg?branch=master)](https://travis-ci.org/theimpossibleastronaut/deckhandler)

# deckhandler
Library that will create a deck of cards and shuffle it.

Two functions are included:

    deck_init_dh: initialize a deck
    deck_shuffle_dh: shuffle the deck

## Example

If you want to use more than one deck, use:

    st_deck_dh *deck_a, *deck_b, *deck_c;

Detailed example usage can be seen in
[example-01.c](https://github.com/theimpossibleastronaut/deckhandler/blob/master/example-01.c)
and
[aa-pokerhands](https://github.com/theimpossibleastronaut/aa-pokerhands)

## Dependencies

* [meson](http://mesonbuild.com/Quick-guide.html) (for the build system)

## Building

    meson builddir
    cd builddir
    ninja

That will build the library, create the `example-01` executable and
then link to the library.

## Projects that use deckhandler

* [aa-pokerhands](https://github.com/theimpossibleastronaut/aa-pokerhands)
