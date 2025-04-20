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
deck_init_dh(st_deck_dh *deck_dh)
{
  int card = 0;
  int suit = 0;
  int face = ACE;

  while (suit < MAX_SUITS)
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

static void
swap(st_deck_dh *deck_dh, int i, int j)
{
  st_card_info_dh tmp = deck_dh->card[i];
  deck_dh->card[i] = deck_dh->card[j];
  deck_dh->card[j] = tmp;
}

void
deck_shuffle_dh(st_deck_dh *deck_dh)
{
  for (int i = CARDS_IN_DECK - 1; i > 0; --i)
  {
    int j = rand() % (i + 1);
    swap(deck_dh, i, j);
  }
}

const char *
get_card_face(st_card_info_dh card)
{
  return faces[card.face_val - 1];
}

const char *
get_card_suit(st_card_info_dh card)
{
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
