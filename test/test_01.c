/*
 * test_01.c
 *
 * This file is part of the deckhandler library
 * <https://github.com/theimpossibleastronaut/deckhandler>
 *
 * Copyright 2019-2021 Andy Alt <andy400-dev@yahoo.com>
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

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "deckhandler.h"

int main (int argc, char *argv[])
{
  (void)argc;
  (void)argv;
  /* declare a deck using type "st_deck_dh" (defined in deckhandler.h) */
  st_deck_dh deck_a;

  /* initialize the deck */
  deck_init_dh (&deck_a);

  int deals_num = 0;
  int deals_max = 3;

  /* random generator used by deck_shuffle_dh() */
  // srand (time (NULL));
  srand (5);

  do
  {
    /* shuffle the deck */
    puts ("\n\n\t]=[ Shuffling ]=[\n");
    deck_shuffle_dh (&deck_a);

    /* show each card in the deck */
    int deal;
    for (deal = 0; deal < CARDS_IN_DECK; deal++)
    {
      /* The "faces" and "suits" arrays are initialized in deckhandler.c */
      printf ("%s of %s\n",
              get_card_face(deck_a.card[deal]),
              get_card_suit(deck_a.card[deal]));
      // qqprintf ("%i\n", deck_a.card[deal].face_val);
      if (deal < 4 && deals_num == 0)
      {
        switch (deal) {
          case 0: assert (deck_a.card[deal].face_val == 13); break;
          case 1: assert (deck_a.card[deal].face_val == 7); break;
          case 2: assert (deck_a.card[deal].face_val == 10); break;
          case 3: assert (deck_a.card[deal].face_val == 12); break;
          case 4: assert (deck_a.card[deal].face_val == 1); break;
          case 5: assert (deck_a.card[deal].face_val == 13); break;
          case 6: assert (deck_a.card[deal].face_val == 8); break;
          case 7: assert (deck_a.card[deal].face_val == 8); break;
          case 8: assert (deck_a.card[deal].face_val == 2); break;
          case 9: assert (deck_a.card[deal].face_val == 9); break;
        }
      }
    }
  }while (deals_num++ < deals_max);

  srand (time (NULL));

  puts ("\n\n\t]=[ Create 4 decks, shuffle each one, and deal them all out ]=[\n");
  int total_decks = 4;
  st_deck_dh deck_num[total_decks];

  int which_deck;
  for (which_deck = 0; which_deck < total_decks; which_deck++)
  {
    deck_init_dh (&deck_num[which_deck]);
    deck_shuffle_dh (&deck_num[which_deck]);
  }

  int card;

  /* There's no function in the library (yet) that shuffles multiple decks
   * together, but using the method below will provide a close simulation */
  for (card = 0; card < CARDS_IN_DECK; card++)
  {
    for (which_deck = 0; which_deck < total_decks; which_deck++)
    {
      printf ("%s of %s\n",
              get_card_face(deck_num[which_deck].card[card]),
              get_card_suit(deck_num[which_deck].card[card]));
    }
  }

  return 0;
}
