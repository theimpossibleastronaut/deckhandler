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

int
main(int argc, char *argv[])
{
  (void) argc;
  (void) argv;
  /* declare a deck using type "struct dh_deck" (defined in deckhandler.h) */
  struct dh_deck deck_a;

  /* initialize the deck */
  dh_init_deck(&deck_a);

  int deals_num = 0;
  int deals_max = 3;

  dh_pcg_srand(1, 1);

  do
  {
    /* shuffle the deck */
    puts("\n\n\t]=[ Shuffling ]=[\n");
    dh_shuffle_deck(&deck_a);

    /* show each card in the deck */
    int deal;
    for (deal = 0; deal < CARDS_IN_DECK; deal++)
    {
      /* The "faces" and "suits" arrays are initialized in deckhandler.c */
      // fprintf (stderr, "%s of %s\n", get_card_face(deck_a.card[deal]), get_card_suit(deck_a.card[deal]));
      struct dh_card card = dh_deal_top_card(&deck_a);
      fprintf (stderr, "%i\n", card.face_val);
      if (deal < 4 && deals_num == 0)
      {
        switch (deal)
        {
        case 0:
          assert(card.face_val == TWO);
          break;
        case 1:
          assert(card.face_val == FIVE);
          break;
        case 2:
          assert(card.face_val == FIVE);
          break;
        case 3:
          assert(card.face_val == FIVE);
          break;
        case 4:
          assert(card.face_val == QUEEN);
          break;
        case 5:
          assert(card.face_val == JACK);
          break;
        case 6:
          assert(card.face_val == KING);
          break;
        case 7:
          assert(card.face_val == SIX);
          break;
        case 8:
          assert(card.face_val == NINE);
          break;
        case 9:
          assert(card.face_val == THREE);
          break;
        }
      }
    }
  }
  while (deals_num++ < deals_max);

  puts
    ("\n\n\t]=[ Create 4 decks, shuffle each one, and deal them all out ]=[\n");
  int total_decks = 4;
  struct dh_deck deck_num[total_decks];

  int which_deck;
  for (which_deck = 0; which_deck < total_decks; which_deck++)
  {
    dh_init_deck(&deck_num[which_deck]);
    dh_shuffle_deck(&deck_num[which_deck]);
  }

  /* There's no function in the library (yet) that shuffles multiple decks
   * together, but using the method below will provide a close simulation */
  for (int i = 0; i < CARDS_IN_DECK; i++)
  {
    for (which_deck = 0; which_deck < total_decks; which_deck++)
    {
      struct dh_card card = dh_deal_top_card(&deck_num[which_deck]);
      printf("%s of %s\n",
             get_card_face(card),
             get_card_suit(card));
             if (i == CARDS_IN_DECK - 1) {
              switch (which_deck) {
                case 0:
                  assert(card.face_val == TEN);
                  break;
                case 1:
                  assert(card.face_val == TWO);
                  break;
                case 2:
                  assert(card.face_val == THREE);
                  break;
                case 3:
                  assert(card.face_val == ACE);
                  break;
                }
              }
    }
  }

  return 0;
}
