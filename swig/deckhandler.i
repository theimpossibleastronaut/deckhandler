 %module deckhandler
 %{
 /* Includes the header in the wrapper code */
 #include "deckhandler.h"
 %}

 /* Parse the header file to generate wrappers */
 %include "deckhandler.h"

 %inline %{
void
deck_dh_set(struct dh_deck deck, struct dh_card card, int i) {
  deck.card[i] = card;
}

struct dh_card
deck_dh_get(struct dh_deck deck, int i) {
  return deck.card[i];
}

void
seed(void) {
  dh_pcg_srand_auto();
}
%}
