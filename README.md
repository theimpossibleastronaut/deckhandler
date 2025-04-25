[![Linux](https://github.com/theimpossibleastronaut/deckhandler/actions/workflows/linux.yml/badge.svg)](https://github.com/theimpossibleastronaut/deckhandler/actions/workflows/linux.yml)
[![Windows](https://github.com/theimpossibleastronaut/deckhandler/actions/workflows/windows.yml/badge.svg)](https://github.com/theimpossibleastronaut/deckhandler/actions/workflows/windows.yml)

# deckhandler
Library that will create a deck of cards and shuffle it.

Two functions are included:

    dh_init_deck: initialize a deck
    dh_shuffle_deck: shuffle the deck
    get_card_face: get the "face" of a card
    get_card_suit: get the suit of a card

Detailed example usage can be seen in
[example-01.c](https://github.com/theimpossibleastronaut/deckhandler/blob/master/test/test_01.c)
and
[aa-pokerhands](https://github.com/theimpossibleastronaut/aa-pokerhands)

## Dependencies

* [meson](http://mesonbuild.com/Quick-guide.html) (for the build system)

## Building

    meson setup builddir
    cd builddir
    ninja

That will build the library, create the `example-01` executable and
then link to the library.

## Tests

    ninja test

## Installation

To specify the installation directory (defaults to /usr/local) and
install the program:

    From *builddir*: `meson configure --prefix=
    ninja install

To uninstall:

    ninja uninstall

## Projects that use deckhandler

* [aa-pokerhands](https://github.com/theimpossibleastronaut/aa-pokerhands)

## Using the library with other languages

See [SWIG_INTERFACE.md](https://github.com/theimpossibleastronaut/deckhandler/blob/master/SWIG_INTERFACE.md)
