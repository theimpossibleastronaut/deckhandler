/*
 * deckhandler.h
 * Library to handle a deck of cards
 * <https://github.com/theimpossibleastronaut/deckhandler>
 *

 MIT License

 Copyright (c) 2019-2025 Andy Alt

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*/

#ifndef __DECK_HANDLER
#define __DECK_HANDLER

#define NUM_OF_FACES 13

enum
{ HEARTS, DIAMONDS, SPADES, CLUBS, MAX_SUITS };

enum card_face
{
  ACE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE_HIGH,
};

#define CARDS_IN_DECK 52

struct dh_card
{
  int face_val;
  int suit;
};

struct dh_deck
{
  struct dh_card card[CARDS_IN_DECK];
};

void dh_init_deck(struct dh_deck *deck_dh);

void dh_shuffle_deck(struct dh_deck *deck_dh);

const char *get_card_face(struct dh_card card);

const char *get_card_suit(struct dh_card card);

const char *get_card_unicode_suit(struct dh_card card);

const char *get_card_face_str(int val);

#endif
