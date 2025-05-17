/**
 * @file deckhandler.h
 * @brief Library to handle a standard deck of playing cards.
 *
 * Provides functions to initialize, shuffle, and query cards in a deck.
 * Includes support for custom PCG-based randomization.
 *
 * @author Andy Alt
 * @copyright MIT License
 * @see https://github.com/theimpossibleastronaut/deckhandler
 */

#ifndef __DECK_HANDLER
#define __DECK_HANDLER

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/// Number of face values in a standard card deck (Ace to King).
#define NUM_OF_FACES 13

/// Enumeration of the four standard card suits.
enum
{
  HEARTS,      ///< Hearts suit
  DIAMONDS,    ///< Diamonds suit
  SPADES,      ///< Spades suit
  CLUBS,       ///< Clubs suit
  MAX_SUITS    ///< Number of suits
};

/// Enumeration of card face values (Ace can be high or low).
enum card_face
{
  ACE = 1,     ///< Ace (low)
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
  ACE_HIGH     ///< Ace (high) for straight evaluation, not dealt
};

/// Total number of cards in a standard deck.
#define CARDS_IN_DECK 52

/**
 * @struct dh_card
 * @brief Represents a single playing card with a face value and suit.
 */
struct dh_card
{
  int face_val; ///< Value of the card face (1–13)
  int suit;     ///< Suit of the card (see enum)
};

extern struct dh_card dh_card_back;

/**
 * @struct dh_deck
 * @brief Represents a full deck of 52 playing cards.
 */
struct dh_deck
{
  struct dh_card card[CARDS_IN_DECK]; ///< Array of all cards in the deck
  int top_card;
};

/**
 * @brief Seed the PCG random number generator with user-supplied values.
 *
 * @param initstate Initialization state value.
 * @param initseq   Initialization sequence value.
 */
void dh_pcg_srand(uint64_t initstate, uint64_t initseq);

/**
 * @brief Automatically seed the PCG random number generator with internal defaults.
 *
 * Uses `time(NULL)` and pointer values for entropy.
 */
void dh_pcg_srand_auto(void);

/**
 * @brief Initialize a deck in a sorted order (no shuffling).
 *
 * @param deck_dh Pointer to the deck to initialize.
 */
void dh_init_deck(struct dh_deck *deck);

struct dh_card dh_deal_top_card(struct dh_deck *deck);

/**
 * @brief Shuffle a deck of cards using the PCG random number generator.
 *
 * @param deck_dh Pointer to the deck to shuffle.
 */
void dh_shuffle_deck(struct dh_deck *deck_dh);

/**
 * @brief Get the string name of a card's face value (e.g., "Ace", "10", "King").
 *
 * @param card The card to query.
 * @return Pointer to a constant string.
 */
const char *get_card_face(struct dh_card card);

/**
 * @brief Get the string name of a card's suit (e.g., "Hearts", "Spades").
 *
 * @param card The card to query.
 * @return Pointer to a constant string.
 */
const char *get_card_suit(struct dh_card card);

/**
 * @brief Get the Unicode symbol representing the card's suit.
 *
 * ♥ ♠ ♦ ♣ depending on the suit.
 *
 * @param card The card to query.
 * @return Pointer to a UTF-8 encoded Unicode string.
 */
const char *get_card_unicode_suit(struct dh_card card);

/**
 * @brief Get the string name of a face value given its integer representation.
 *
 * @param val Integer value representing a face (1–13).
 * @return Pointer to a constant string.
 */
const char *get_card_face_str(int val);

#ifdef __cplusplus
}
#endif
#endif // __DECK_HANDLER
