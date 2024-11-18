#ifndef TAROT_H
#define TAROT_H

#include <vector>
#include <string>
#include "User.h"

struct TarotCard {
    std::string ten;
};

// Hàm rút ngẫu nhiên một lá bài từ bộ bài
TarotCard RutBai(const std::vector<TarotCard>& deck);

// Hàm tạo bộ bài Tarot
std::vector<TarotCard> createTarotDeck();

class FortuneTelling {
public:
    virtual void boiToan(User& user) = 0;
    virtual std::string Soduongdoi(int Sochudao) = 0;
};

// Lớp kế thừa từ FortuneTelling để thực hiện bói toán Tarot
class TarotReading : public FortuneTelling {
public:
    void boiToan(User& user) override; // Thực hiện bói toán
    std::string Soduongdoi(int Sochudao) override; // Tính số đường đời
};

#endif // TAROT_H
