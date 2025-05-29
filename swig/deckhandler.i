 %module deckhandler
 %{
 /* Includes the header in the wrapper code */
 #include "deckhandler.h"
 %}

 /* Parse the header file to generate wrappers */
 %include "deckhandler.h"

 %inline %{
void
deck_dh_set(DH_Deck deck, DH_Card card, int i) {
  deck.card[i] = card;
}

DH_Card
deck_dh_get(DH_Deck deck, int i) {
  return deck.card[i];
}

void
seed(void) {
  dh_pcg_srand_auto();
}
%}
