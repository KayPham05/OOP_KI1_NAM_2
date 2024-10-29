#ifndef THANSOHOC_H
#define THANSOHOC_H

#include <string>
#include <vector>

struct TarotCard {
    std::string name;
    std::string meaning;
};

// Khai báo các hàm (chỉ khai báo, không định nghĩa)
std::vector<TarotCard> createTarotDeck();
std::vector<TarotCard> createTarotDeck1();
TarotCard drawRandomCard(const std::vector<TarotCard>& deck);
void hideCursor();
void displayMenu(int selected);
int reduceToSingleDigit(int num);
int calculateLifePathNumber(int day, int month, int year);
int calculateExpressionNumber(const std::string& name);

#endif
