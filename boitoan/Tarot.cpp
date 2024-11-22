#include "Tarot.h"
#include "User.h"
#include <algorithm> // random_shuffle
#include <ctime>     // time
#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
// ----------------- TarotCard Methods -----------------
TarotCard::TarotCard(string ten, string daiDien, string yNgia, string tinhHuong)
    : ten(ten), daiDien(daiDien), yNgia(yNgia), tinhHuong(tinhHuong) {
}
void setColor2(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
string TarotCard::getTen() const { return ten; }
string TarotCard::getDaiDien() const { return daiDien; }
string TarotCard::getYNgia() const { return yNgia; }
string TarotCard::getTinhHuong() const { return tinhHuong; }


void printWithLineBreaks(const string& text, int maxCharsPerLine, int x, int y) {
    int currentLineLength = 0; // Độ dài dòng hiện tại
    string currentWord;        // Từ hiện tại đang xử lý
    int currentY = y;          // Vị trí dòng y hiện tại

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (c == ' ' || i == text.length() - 1) {
            // Thêm ký tự cuối nếu là ký tự cuối cùng
            if (i == text.length() - 1 && c != ' ') {
                currentWord += c;
            }

            // Nếu từ hiện tại không vừa dòng, xuống dòng
            if (currentLineLength + currentWord.length() > maxCharsPerLine) {
                currentY++;                 // Tăng dòng
                currentLineLength = 0;      // Đặt lại độ dài dòng
                gotoXY(x, currentY);        // Di chuyển con trỏ đến đầu dòng mới
            }

            // In từ hiện tại
            if (currentLineLength > 0) {
                cout << " ";                // Thêm khoảng cách giữa các từ
                currentLineLength++;
            }
            cout << currentWord;            // In từ
            currentLineLength += currentWord.length();
            currentWord.clear();
        }
        else {
            // Ghép ký tự vào từ hiện tại
            currentWord += c;
        }
    }
}

void drawBox(int x, int y, int width, int height, int color) {
    setColor2(color); // Đặt màu cho khung
    gotoXY(x, y);
    cout << char(201); // Góc trên trái
    gotoXY(x + width, y);
    cout << char(187); // Góc trên phải
    gotoXY(x, y + height);
    cout << char(200); // Góc dưới trái
    gotoXY(x + width, y + height);
    cout << char(188); // Góc dưới phải

    // Vẽ cạnh trên và dưới
    for (int i = 1; i < width; i++) {
        gotoXY(x + i, y);
        cout << char(205); // Ký tự ngang
        gotoXY(x + i, y + height);
        cout << char(205); // Ký tự ngang
    }

    // Vẽ cạnh trái và phải
    for (int i = 1; i < height; i++) {
        gotoXY(x, y + i);
        cout << char(186); // Ký tự dọc
        gotoXY(x + width, y + i);
        cout << char(186); // Ký tự dọc
    }

    setColor2(7); // Trả về màu mặc định
}



void TarotCard::display() const {
    vector<int> colors = { 9, 10, 11, 12, 13, 14 }; // Mảng màu
    int colorIndex = 0; // Chỉ số màu hiện tại


    while (true) {
        // Xóa màn hình trước khi vẽ
        system("cls");

        // Lấy màu hiện tại
        int color1 = colors[colorIndex % colors.size()];
        int color2 = colors[(colorIndex + 1) % colors.size()];
        int color3 = colors[(colorIndex + 2) % colors.size()];
        int textColor = colors[(colorIndex + 3) % colors.size()];
        // Vẽ các khung
        drawBox(15, 2, 74, 30, color1); // Khung lớn
        drawBox(25, 4, 54, 2, color3);
        drawBox(20, 10, 20, 20, color2); // Khung nhỏ 1
        drawBox(42, 10, 20, 20, color3); // Khung nhỏ 2
        drawBox(64, 10, 20, 20, color1); // Khung nhỏ 3
        
        drawBox(20, 10, 20, 2, color2);
        drawBox(42, 10, 20, 2, color3);
        drawBox(64, 10, 20, 2, color1);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
        gotoXY(37, 5);
        cout << ten << endl;
        gotoXY(26, 11);
        cout << "DAI DIEN";
        gotoXY(22, 14);
        printWithLineBreaks(daiDien, 17, 22, 14); // Tùy chỉnh số ký tự tối đa mỗi dòng
        
        gotoXY(48, 11);
        cout << "Y NGHIA";
        gotoXY(44, 14);
        printWithLineBreaks(yNgia, 17, 44, 14);

        gotoXY(70, 11);
        cout << "TINH HUONG";
        gotoXY(66, 14);
        printWithLineBreaks(tinhHuong, 17, 66, 14);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        cout << endl;
        Sleep(800);
        colorIndex++;

        if (_kbhit()) { // Nếu có phím được nhấn
            char key = _getch(); // Lấy mã phím
            if (key == '\r') { // Nếu là phím Enter
                break; // Thoát vòng lặp
            }
        }
    }

}


// ----------------- TarotDeck Methods -----------------
TarotDeck::TarotDeck() {
    // Initialize the deck with some cards (example cards)
    deck.push_back(TarotCard("The Fool (Ke Kho Khon)", "Dai dien cho su khoi dau, su ngau hung, va su tu do. Thuong lien quan den hanh trinh moi ma khong biet truoc ket qua, su chinh phuc su khong biet truoc.", "Bat dau mot hanh trinh moi ma khong co su chuan bi day du. Tuong trung cho su ngay tho va tu do trong viec chap nhan nhung rui ro.", "Bat dau mot cong viec moi, thay doi noi o, hoac bat dau mot moi quan he ma khong chac chan ve tuong lai."));
    deck.push_back(TarotCard("The Magician (Nha Ao Thuat)", "Ky nang, kha nang dieu khien va tao ra thuc te bang suc manh y chi. Nhieu khi goi y su tap trung vao muc tieu va su tu tin. ", "Kha nang bien uoc mo thanh hien thuc thong qua su tap trung va y chi. Khuyen khich ban tan dung tai nang cua minh.", "Ban co the thanh cong bang cach su dung nhung ky nang va nguon luc da co."));
    deck.push_back(TarotCard("The High Priestess (Nu Tu Te Cao Cap)", "Su truc giac, bi mat va tri tue noi tam. Khuyen nen lang nghe tieng noi ben trong va tim kiem hieu biet chinh minh.", "Khuyen khich viec lang nghe truc giac va kham pha nhung bi mat. Nu Tu Te bieu trung cho su hieu biet sau sac ve ban than.", "Can tin vao cam giac truc giac khi doi mat voi mot quyet dinh quan trong."));
    // Add more cards as needed...
}

void TarotDeck::shuffleDeck() {
    srand(static_cast<unsigned>(time(0)));
    random_shuffle(deck.begin(), deck.end());
}

TarotCard TarotDeck::drawCard() {
    if (deck.empty()) {
        throw runtime_error("Bo bai da het!");
    }
    TarotCard drawnCard = deck.back();
    deck.pop_back();
    return drawnCard;
}
void SetColor(int color) {
    cout << "\033[" << color << "m";
}

void ReSetColor() {
    cout << "\033[0m";
}
void TarotDeck::displayDeck() const {
    for (const auto& card : deck) {
        card.display();
        cout << "--------------------------------" << endl;
    }
}

int TarotDeck::getRemainingCards() const {
    return deck.size();
}
// Hàm hiển thị menu
void displayMenu(int selected) {
    system("cls");
    SetColor(35);  // Màu tím cho chữ "Number God Study"
    cout << "                                  N U M B E R       G O D       S T U D Y   " << endl;
    cout << "\n";
    ReSetColor();
    SetColor(33);
    cout << "                                 +---------------------------------------+" << endl;
    SetColor(31);
    cout << "                                 |               BOI TAROT               |" << endl;
    SetColor(35);
    cout << "                                 +---------------------------------------+" << endl;
    ReSetColor();
    // Mục 1: Nhập thông tin người xem bói
    if (selected == 0) {
        SetColor(32);  // Màu xanh lá cây cho mục được chọn
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " -> Boi su nghiep                      |" << endl;
        cout << "                                 =========================================" << endl;
        ReSetColor();  // Trở lại màu bình thường
    }
    else {
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " Boi su nghiep                         |" << endl;
        cout << "                                 =========================================" << endl;
    }

    // Mục 2: Xem thần số học
    if (selected == 1) {
        SetColor(33);
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " -> Boi tinh yeu                       |" << endl;
        cout << "                                 =========================================" << endl;
        ReSetColor();
    }
    else {
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " Boi tinh yeu                          |" << endl;
        cout << "                                 =========================================" << endl;
    }

    // Mục 3: Xem cung hoàng đạo
    if (selected == 2) {
        SetColor(34);
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " -> Boi gia dinh                       |" << endl;
        cout << "                                 =========================================" << endl;
        ReSetColor();
    }
    else {
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " Boi gia dinh                          |" << endl;
        cout << "                                 =========================================" << endl;
    }

    // Mục 4: Xem bói bài Tarot
    if (selected == 3) {
        SetColor(31);
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " -> Boi hien tai                       |" << endl;
        cout << "                                 =========================================" << endl;
        ReSetColor();
    }
    else {
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " Boi hien tai                          |" << endl;
        cout << "                                 =========================================" << endl;
    }
    if (selected == 4) {
        SetColor(34);
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " -> Boi tuong lai                      |" << endl;
        cout << "                                 =========================================" << endl;
        ReSetColor();
    }
    else {
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " Boi tuong lai                         |" << endl;
        cout << "                                 =========================================" << endl;
    }
    if (selected == 5) {
        SetColor(33);
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " -> Boi qua khu                        |" << endl;
        cout << "                                 =========================================" << endl;
        ReSetColor();
    }
    else {
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " Boi qua khu                           |" << endl;
        cout << "                                 =========================================" << endl;
    }
    // Mục 6: Thoát
    if (selected == 6) {
        SetColor(35);
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " ->Quay lai                            |" << endl;
        cout << "                                 =========================================" << endl;
        ReSetColor();
    }
    else {
        cout << "                                 =========================================" << endl;
        cout << "                                 |" << " Quay lai                              |" << endl;
        cout << "                                 =========================================" << endl;
    }

    cout << "                                 +---------------------------------------+" << endl;
}

void boiTarot() {
    TarotDeck tarotDeck; // Khởi tạo bộ bài
    tarotDeck.shuffleDeck(); // Trộn bộ bài

    int selected = 0;
    char key;

    do {
        displayMenu(selected);

        key = _getch();
        if (key == 72) { // Mũi tên lên
            selected = (selected - 1 + 7) % 7;
        }
        else if (key == 80) { // Mũi tên xuống
            selected = (selected + 1) % 7;
        }
        else if (key == 13) { // Phím Enter
            system("cls");
            if (selected < 6) { // Các mục bói bài
                try {
                    TarotDeck tarotDeck;       // Tạo một bộ bài mới
                    tarotDeck.shuffleDeck();   // Trộn bộ bài
                    TarotCard card = tarotDeck.drawCard(); // Rút một lá bài
                    card.display();           // In thông tin lá bài
                    
                    gotoXY(25, 36);
                    cout << "ENTER DE QUAY LAI MENU BOI TAROT";
                    gotoXY(24, 19);
                    char tempKey = _getch();
                }
                catch (const exception& e) {
                    cerr << "Loi: " << e.what() << endl; // Xử lý lỗi nếu bộ bài trống
                }
            }
            else { // Quay lại
                break;
            }
        }
    } while (true);
}

