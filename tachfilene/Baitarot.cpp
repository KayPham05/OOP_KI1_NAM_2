#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct TarotCard {
    std::string name;
    std::string meaning;
};

// Ham de khoi tao bo bai Tarot
std::vector<TarotCard> createTarotDeck() {
    return {
        {"The Fool", "Khoi dau moi, su ngay tho, hanh trinh moi."},
        {"The Magician", "Su tap trung, kha nang sang tao, khai thac tiem nang."},
        {"The High Priestess", "Truc giac, bi mat, thau hieu ben trong."},
        {"The Empress", "Tinh yeu, su sinh soi, me thien nhien."},
        {"The Emperor", "Quyen luc, su kiem soat, trat tu va ky luat."},
        {"The Hierophant", "Truyen thong, giao duc, chi dan tam linh."},
        {"The Lovers", "Tinh yeu, moi quan he, su lua chon quan trong."},
        {"The Chariot", "Chien thang, y chi, dieu khien hoan canh."},
        {"Strength", "Suc manh noi tai, long dung cam, kien nhan."},
        {"The Hermit", "Su co doc, suy tu, tim kiem su that."},
        {"Wheel of Fortune", "Van may, chu ky, su thay doi."},
        {"Justice", "Cong ly, su can bang, trach nhiem."},
        {"The Hanged Man", "Su tam dung, goc nhin khac, hy sinh."},
        {"Death", "Su ket thuc, bien doi, su doi moi."},
        {"Temperance", "Can bang, dieu do, hoa hop."},
        {"The Devil", "Le thuoc, cam do, so hai."},
        {"The Tower", "Sup do, thay doi dot ngot, kham pha su that."},
        {"The Star", "Hy vong, cam hung, su huong dan."},
        {"The Moon", "Ao tuong, bi mat, su bat dinh."},
        {"The Sun", "Thanh cong, hanh phuc, su khai sang."},
        {"Judgement", "Su danh gia lai, thuc tinh, phan quyet."},
        {"The World", "Hoan thanh, thanh tuu, ket thuc chu ky."}
    };
}

// Ham de rut ngau nhien 1 la bai tu bo bai
TarotCard drawRandomCard(const std::vector<TarotCard>& deck) {
    int randomIndex = rand() % deck.size();
    return deck[randomIndex];
}

int main() {
    // Khoi tao bo bai Tarot
    std::vector<TarotCard> tarotDeck = createTarotDeck();

    // Khoi tao random seed
    srand(static_cast<unsigned>(time(0)));

    // Rut 3 la bai
    TarotCard past = drawRandomCard(tarotDeck);
    TarotCard present = drawRandomCard(tarotDeck);
    TarotCard future = drawRandomCard(tarotDeck);

    // Hien thi ket qua
    std::cout << "Ket qua trai bai Tarot 3 la:\n\n";

    std::cout << "Qua khu: " << past.name << " - " << past.meaning << "\n";
    std::cout << "Hien tai: " << present.name << " - " << present.meaning << "\n";
    std::cout << "Tuong lai: " << future.name << " - " << future.meaning << "\n";

    return 0;
}
