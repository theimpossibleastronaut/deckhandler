/*
 * deckhandler.c
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

#include <pcg_basic.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "deckhandler.h"

static pcg32_random_t rng;

static const char *dh_suits[] = {"Hearts  ", "Diamonds", "Spades  ", "Clubs   "};

static const char *dh_faces[] = {"Ace", "2", "3",  "4",    "5",     "6",   "7",
                                 "8",   "9", "10", "Jack", "Queen", "King"};

const struct dh_card dh_card_back = {
    .face_val = -1,
    .suit = -1,
};

const struct dh_card dh_card_null = {
    .face_val = -2,
    .suit = -2,
};

void dh_pcg_srand(uint64_t initstate, uint64_t initseq) {
  pcg32_srandom_r(&rng, initstate, initseq);
  return;
}

void dh_pcg_srand_auto(void) {
  uint64_t initstate = time(NULL) ^ (intptr_t)&printf;
  uint64_t initseq = (intptr_t)&dh_faces;
  pcg32_srandom_r(&rng, initstate, initseq);
}

static void dh_init_deck(struct dh_deck *deck) {
  deck->top_card = 0;

  int card = 0;
  int suit = 0;
  int face = ACE;

  while (suit < MAX_SUITS) {
    deck->card[card].face_val = face++;
    deck->card[card].suit = suit;

    if (face > KING) {
      face = ACE;
      suit++;
    }

    card++;
  }
  return;
}

struct dh_deck dh_get_new_deck(void) {
  struct dh_deck deck;
  dh_init_deck(&deck);
  return deck;
}

struct dh_card dh_deal_top_card(struct dh_deck *deck) {
  if (deck->top_card == CARDS_IN_DECK) {
    deck->top_card = 0;
    puts("deckhandler: deck wrapped");
  }
  struct dh_card card = deck->card[deck->top_card];
  deck->top_card++;
  return card;
}

static void swap(struct dh_deck *deck_dh, int i, int j) {
  struct dh_card tmp = deck_dh->card[i];
  deck_dh->card[i] = deck_dh->card[j];
  deck_dh->card[j] = tmp;
}

void dh_shuffle_deck(struct dh_deck *deck) {
  for (int i = CARDS_IN_DECK - 1; i > 0; --i) {
    int j = pcg32_boundedrand_r(&rng, i + 1);
    swap(deck, i, j);
  }
  deck->top_card = 0;
}

const char *get_card_face(struct dh_card card) { return dh_faces[card.face_val - 1]; }

const char *get_card_suit(struct dh_card card) { return dh_suits[card.suit]; }

const char *get_card_unicode_suit(struct dh_card card) {
  switch (card.suit) {
  case DIAMONDS:
    return "\u2666";
  case HEARTS:
    return "\u2665";
  case SPADES:
    return "\u2660";
  case CLUBS:
    return "\u2663";
  default:
    return "?";
  }
}

const char *get_card_face_str(int val) {
  switch (val) {
  case 1:
    return "A";
  case 11:
    return "J";
  case 12:
    return "Q";
  case 13:
    return "K";
  default: {
    static char buf[3];
    snprintf(buf, sizeof(buf), "%d", val);
    return buf;
  }
  }
}
