#include "thansohoc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
    hideCursor();  // Ẩn con trỏ chuột

    int selected = 0;  // Lựa chọn hiện tại (chỉ số)
    char key;

    do {
        displayMenu(selected);  // Hiển thị menu với lựa chọn hiện tại
        key = _getch();         // Đọc phím người dùng (không cần Enter)

        if (key == 72) {  // Phím mũi tên lên (key code 72)
            selected = (selected - 1 + 3) % 3;  // Di chuyển lên, nếu vượt quá thì quay lại cuối
        } else if (key == 80) {  // Phím mũi tên xuống (key code 80)
            selected = (selected + 1) % 3;  // Di chuyển xuống, nếu vượt quá thì quay lại đầu
        } else if (key == 13) {  // Phím Enter (key code 13)
            system("cls");
            if (selected == 0) {
                cout << "Ban da chon: Than So Hoc" << endl;
                // Gọi hàm thần số học ở đây
            } else if (selected == 1) {
                cout << "Ban da chon: Boi tarot" << endl;
                // Gọi hàm bói tarot ở đây
            } else if (selected == 2) {
                cout << "EXIT" << endl;
                break;
            }
            system("pause");  // Dừng màn hình để người dùng thấy kết quả trước khi trở lại menu
        }
    } while (true);
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

