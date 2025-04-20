/*
 * deckhandler.h
 *
 * This file is part of the deckhandler library
 * <https://github.com/theimpossibleastronaut/deckhandler>
 *
 * Copyright 2019-2020 Andy <andy400-dev@yahoo.com>
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

#ifndef __DECK_HANDLER
#define __DECK_HANDLER

#define NUM_OF_FACES 13
#define NUM_OF_SUITS 4

extern const char *faces[NUM_OF_FACES];
extern const char *suits[NUM_OF_SUITS];

#define CARDS_IN_DECK 52
#define ACE 1
#define KING 13

enum
{ HEARTS, DIAMONDS, SPADES, CLUBS };

typedef struct{
    int face_val;
    int suit;
}st_card_info_dh;

typedef struct {
  st_card_info_dh card[CARDS_IN_DECK];
}st_deck_dh;

void
deck_init_dh (st_deck_dh *deck_dh);

void
deck_shuffle_dh (st_deck_dh *deck_dh);

const char
*get_card_face(st_card_info_dh card);

const char
*get_card_suit(st_card_info_dh card);

const char *get_card_unicode_suit(st_card_info_dh card);

const char *get_card_face_str(int val);

#endif
