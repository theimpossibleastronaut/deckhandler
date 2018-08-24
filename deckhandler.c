/*
 * deckhandler.c
 * Library to handle a deck of cards
 * <https://github.com/theimpossibleastronaut/deckhandler>
 *
 * Copyright 2018 Andy <andy400-dev@yahoo.com>
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

void deck_init_dh (st_deck_dh *deck_dh)
{
  int card = 0;
  int suit = HEARTS;
  int face = ACE;

  while (suit < CLUBS + 1)
  {
    deck_dh->card[card].face_val_dh = face++;
    deck_dh->card[card].suit_dh = suit;

    if (face > KING)
    {
      face = ACE;
      suit++;
    }

    card++;
  }
}

void
deck_shuffle_dh (st_deck_dh *deck_dh)
{
  int j = 0;
  bool status[CARDS_IN_DECK];

  do
  {
    status[j] = 1;
  }while (j++ < CARDS_IN_DECK);

  j = 0;

  int card = 0;

  st_deck_dh temp_deck;

  while (j < CARDS_IN_DECK)
  {
    /* card will a random number between 0 and 51 */
    card = rand () % CARDS_IN_DECK;

    if (status[card])
    {
      temp_deck.card[j].face_val_dh = deck_dh->card[card].face_val_dh;
      temp_deck.card[j].suit_dh = deck_dh->card[card].suit_dh;

      /* switch status[card] to 0 so it won't get used again */
      status[card] = 0;
      j++;
    }
  }

  /* The temp_deck is now shuffled. Let's swap the values with the original
   * deck now */

  for (j = 0; j < CARDS_IN_DECK; j++)
  {
    deck_dh->card[j].face_val_dh = temp_deck.card[j].face_val_dh;
    deck_dh->card[j].suit_dh = temp_deck.card[j].suit_dh;
  }
}
