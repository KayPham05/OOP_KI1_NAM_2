#ifdef Tarot_H
#define Tarot_H
#include <vector>
#include <string>
struct TarotCard {
};
TarotCard drawRandomCard(const vector<TarotCard>& deck);
vector<TarotCard> createTarotDeck();
  
#endif 