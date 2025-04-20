/*
 * deckhandler.c
 * Library to handle a deck of cards
 * <https://github.com/theimpossibleastronaut/deckhandler>
 *
 * Copyright 2019 Andy <andy400-dev@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "deckhandler.h"

const char *suits[] = {
  "Hearts  ",
  "Diamonds",
  "Spades  ",
  "Clubs   "
};

const char *faces[] = {
  "Ace",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  "10",
  "Jack",
  "Queen",
  "King"
};

void
deck_init_dh (st_deck_dh *deck_dh)
{
  int card = 0;
  int suit = 0;
  int face = ACE;

  while (suit < NUM_OF_SUITS)
  {
    deck_dh->card[card].face_val = face++;
    deck_dh->card[card].suit = suit;

    if (face > KING)
    {
      face = ACE;
      suit++;
    }

    card++;
  }

  return;
}

void
swap (st_deck_dh *deck_dh, int i, int rnd)
{
      // swap
  int tmp_card_face = deck_dh->card[i].face_val;
  int tmp_card_suit = deck_dh->card[i].suit;
  deck_dh->card[i].face_val = deck_dh->card[rnd].face_val;
  deck_dh->card[i].suit = deck_dh->card[rnd].suit;
  deck_dh->card[rnd].face_val = tmp_card_face;
  deck_dh->card[rnd].suit = tmp_card_suit;

}

void
deck_shuffle_dh (st_deck_dh *deck_dh)
{

  int i = 0;
  while (i < CARDS_IN_DECK)
  {
    /* card will be a random number between 0 and 51 */
    int rnd = rand () % CARDS_IN_DECK;
    swap(deck_dh, i, rnd);

    i++;
  }

  const int split = CARDS_IN_DECK / 2;

  /* Shuffle the left side of the deck into the right side */
  i = 0;
  while (i < split)
  {
    int rnd = (rand () % split) + split;
    swap(deck_dh, i, rnd);
    i++;
  }

  /* Shuffle the right side of the deck into the left side */
  i = 0;
  while (i < split)
  {
    int rnd = (rand () % split);
    swap(deck_dh, i + split, rnd);
    i++;
  }
  return;
}

const char
*get_card_face(st_card_info_dh card) {
  return faces[card.face_val-1];
}

const char
*get_card_suit(st_card_info_dh card) {
  return suits[card.suit];
}

const char *
get_card_unicode_suit(st_card_info_dh card)
{
  switch (card.suit)
  {
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

const char *
get_card_face_str(int val)
{
  switch (val)
  {
  case 1:
    return "A";
  case 11:
    return "J";
  case 12:
    return "Q";
  case 13:
    return "K";
  default:
    {
      static char buf[3];
      snprintf(buf, sizeof(buf), "%d", val);
      return buf;
    }
  }
}
