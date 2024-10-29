#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <conio.h>     // Su dung thu vien getch() cho Windows
#include <windows.h>   // Su dung thu vien windows.h de lam viec voi console
#include <fstream>     // Thu vien de lam viec voi file
#include <ctime>       // Thu vien de su dung time

using namespace std;

struct TarotCard {
    string name;
    string meaning;
};

vector<TarotCard> createTarotDeck() {
    return {
        {"The Fool (Ke Kho Khon): Dai dien cho su khoi dau, su ngau hung, va su tu do. Thuong lien quan den hanh trinh moi ma khong biet truoc ket qua, su chinh phuc su khong biet truoc."},

		{"The Magician (Nha ao thuat): Ky nang, kha nang dieu khien va tao ra thuc te bang suc manh y chi. Nhieu khi goi y su tap trung vao muc tieu va su tu tin."},

		{"The High Priestess (Nu tu te cao cap): Su truc giac, bi mat va tri tue noi tam. Khuyen nen lang nghe tieng noi ben trong va tim kiem hieu biet chinh minh."},

		{"The Empress (Hoang hau): Dai dien cho su phong thinh, tinh yeu, me thien nhien, va su cham soc. La bieu tuong cua tinh thuong va nu tinh."},
		
		{"The Emperor (Hoang de): Su kiem soat, quyen luc va cau truc. La bieu tuong cua ke lanh dao, nguyen tac nam tinh va trat tu xa hoi."},
		
		{"The Hierophant (Thay tu cao cap): Dai dien cho truyen thong, giao duc, va dao ly tam linh. Goi y su can bang giua thuc hanh va hoc thuyet."},

		{"The Love   (Nguoi yeu nhau): Su lua chon, moi quan he, va tinh yeu. Goi y tinh than doan ket, quyet dinh quan trong va tinh cam."},
		
		{"The Chariot (Xe ngua): Chien thang bang y chi va su kiem soat. Goi y su tien bo, dat duoc thanh cong sau khi khac phuc kho khan."},

		{"Strength (Suc manh): Su manh me noi tai, su kien nhan va long dung cam. Khuyen nen dung cam doi mat voi kho khan."},

		{"The Hermit (Nha an si): Su suy tu, co doc va tim kiem su that. Goi y su can thiet cua viec nghi lai, tu van va hieu biet noi tam."},

		{"Wheel of Fortune (Banh xe van menh): Su thay doi, chu ky moi va van may. La nhac nho rang cuoc song la mot vong xoay khong ngung nghi."},

		{"Justice  Cong ly): Su cong bang, can bang va trach nhiem. Goi y nhung quyet dinh cong minh va hau qua cua hanh dong."},

		{"The Hanged Man (Nguoi bi treo nguoc): Su hy sinh, goc nhin moi va tam dung. Khuyen nen nhin su viec tu goc do khac de tim ra giai phap."},

		{"Death (Cai chet): Su ket thuc, bien doi va su doi moi. Dai dien cho su ket thuc cua mot chu ky va su khoi dau moi."},

		{"The Devil (Quy du): Su le thuoc, cam do va so hai. Goi y su can thiet cua viec giai phong khoi nhung rang buoc tinh than."},

		{"The Tower (Toa thap): Su tan vo, thay doi dot ngot va khung hoang. La bieu tuong cua su do vo de thanh lap lai."},

		{"The Star (Ngoi sao): Hy vong, chua lanh va cam hung. Dai dien cho su lac quan va niem tin vao tuong lai."},

		{"The Moon (Mat trang): Ao tuong, bi an va su khong chac chan. Goi y su hieu lam, lo so va nhung dieu an giau."},

		{"The Sun (Mat troi): Thanh cong, hanh phuc va su soi sang. Dai dien cho su thanh cong, hanh phuc va su khai sang."},

		{"Judgement (Phan quyet): Su thuc tinh, danh gia lai va su tai sinh. Khuyen nen suy nghi ky truoc khi dua ra quyet dinh lon."},
		
		{"The World (The gioi): Su hoan thanh, thanh tuu va ket thuc chu ky. La bieu tuong cua su vien man va ket thuc thanh cong."},
	    };
}

TarotCard drawRandomCard(const vector<TarotCard>& deck) {
    int randomIndex = rand() % deck.size();
    return deck[randomIndex];
}

int reduceToSingleDigit(int num) {
    while (num > 9 && num != 11 && num != 22) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int calculateLifePathNumber(int day, int month, int year) {
    int sum = day + month + year;
    return reduceToSingleDigit(sum);
}

int calculateExpressionNumber(const string& name) {
    int sum = 0;
    for (char c : name) {
        if (isalpha(c)) {
            sum += toupper(c) - 'A' + 1;
        }
    }
    return reduceToSingleDigit(sum);
}

class User {
private:
    string ten;
    string ngaySinh;
    string gioiTinh;

public:
    User() {}

    User(string ten, string ngaySinh, string gioiTinh) : ten(ten), ngaySinh(ngaySinh), gioiTinh(gioiTinh) {}

    string layTen() const {
        return ten;
    }

    string layNgaySinh() const {
        return ngaySinh;
    }

    string layGioiTinh() const {
        return gioiTinh;
    }

    void nhapThongTinNguoiDung() {
        cout << "Nhap ten cua ban: ";
        getline(cin >> ws, ten);
        cout << "Nhap ngay sinh (dd-mm-yyyy): ";
        getline(cin, ngaySinh);
        cout << "Nhap gioi tinh (Nam/Nu): ";
        getline(cin, gioiTinh);

        // Luu thong tin vao file
        ofstream outFile("user_info.txt", ios::trunc);
        if (outFile.is_open()) {
            outFile << "Ten: " << ten << ", Ngay Sinh: " << ngaySinh << ", Gioi Tinh: " << gioiTinh << endl;
            outFile.close();
            cout << "Thong tin da duoc luu vao file user_info.txt!" << endl;
        } else {
            cout << "Khong the mo file!" << endl;
        }
    }

    void inThongTinNguoiDung() {
        cout << "Ten: " << ten << ", Ngay Sinh: " << ngaySinh << ", Gioi Tinh: " << gioiTinh << endl;
    }

    // Ham de lay ngay sinh tu chuoi nhap vao
    void layNgaySinhTuBanPhim(int& day, int& month, int& year) {
        sscanf(ngaySinh.c_str(), "%d-%d-%d", &day, &month, &year);
    }

    friend class FortuneApp;
};

class FortuneTelling {
public:
    virtual void boiToan(User& user) = 0;
};

class NumerologyReading : public FortuneTelling {
public:
    void boiToan(User& user) override {
        int day, month, year;
        user.layNgaySinhTuBanPhim(day, month, year); // Lay ngay sinh tu nguoi dung

        int lifePathNumber = calculateLifePathNumber(day, month, year);
        int expressionNumber = calculateExpressionNumber(user.layTen());

        // Menu con cho boi than so hoc
        int selected = 0;
        char key;
        do {
            system("cls");
            cout << "+-------------------------------+" << endl;
            cout << "|      MENU THAN SO HOC         |" << endl;
            cout << "+-------------------------------+" << endl;
            cout << (selected == 0 ? " -> " : "    ") << "Xem so duong doi (Life Path Number)\n";
            cout << (selected == 1 ? " -> " : "    ") << "Xem so ten (Expression Number)\n";
            cout << (selected == 2 ? " -> " : "    ") << "Xem ca hai\n"; // Xem ca hai
            cout << (selected == 3 ? " -> " : "    ") << "Quay lai menu chinh\n"; // Cap nhat so luong menu
            cout << "+-------------------------------+" << endl;

            key = _getch();
            if (key == 72) { // Mui ten len
                selected = (selected - 1 + 4) % 4; // Cap nhat chi so
            } else if (key == 80) { // Mui ten xuong
                selected = (selected + 1) % 4; // Cap nhat chi so
            } else if (key == 13) { // Phim Enter
                system("cls");
                if (selected == 0) {
                    cout << "So duong doi (Life Path Number): " << lifePathNumber << endl;
                    displayMeaning(lifePathNumber); // Hien thi y nghia
                    system("pause");
                } else if (selected == 1) {
                    cout << "So ten (Expression Number): " << expressionNumber << endl;
                    displayMeaning(expressionNumber); // Hien thi y nghia
                    system("pause");
                } else if (selected == 2) { // Hien thi ca hai
                    cout << "So duong doi (Life Path Number): " << lifePathNumber << endl;
                    displayMeaning(lifePathNumber); // Hien thi y nghia cho so duong doi
                    cout << "So ten (Expression Number): " << expressionNumber << endl;
                    displayMeaning(expressionNumber); // Hien thi y nghia cho so ten
                    system("pause");
                } else if (selected == 3) {
                    break; // Quay lai menu chinh
                }
            }
        } while (true);
    }

    void displayMeaning(int number) {
        switch (number) {
            case 1:
                cout << "So 10:Đai dien cho su tao bao, doi moi, chap nhan rui ro, kha nang phuc hoi va di theo tieng noi ben trong, co to chat lanh dao." << endl;
                break;
            case 2:
                cout << "So 2: Dai dien cho su kien nhan, cong bang, kha nang ngoai giao va tam long yeu thuong, nhan ai." << endl;
                break;
            case 3:
                cout << "So 3: Dai dien cho su nang dong, tu tin, vui tuoi, kha nang can bang cam xuc, bieu cam tu nhien va truyen duoc nhieu nguon cam hung." << endl;
                break;
            case 4:
                cout << "So 4: Dai dien cho dinh huong thuc te, su chia se thuc te, lam viec de thiet lap cam giac an toan, dong thoi hieu va thuc hien duoc suc manh cua qua trinh san xuat." << endl;
                break;
            case 5:
                cout << "So 5: Dai dien cho su mao hiem, thich phieu luu, khong so hai, luon ky luat ban than va muon chi cho moi nguoi dat duoc cach song tu do." << endl;
                break;
            case 6:
                cout << "So 6: Dai dien cho su trach nhiem, khong phan xet, khong chi trich nhung hanh dong va lua chon cua nguoi khac, ban co tam nhin xa, nhin thay toan canh truoc mat. San long giup do nguoi khac mot cach chan thanh." << endl;
                break;
            case 7:
                cout << "So 7: Dai dien cho truc giac, tri tue, luon tim kiem ban chat cua van de, su vat, hien tuong." << endl;
                break;
            case 8:
                cout << "So 8: Dai dien cho su thoai mai, du da ve tai chinh, su dung quyen luc mot cach khon ngoan vi loi ich cua nguoi khac." << endl;
                break;
            case 9:
                cout << "So 9: Dai dien cho tinh than nhan dao, thuong nghi cho nguoi khac, cho cong dong. Dong thoi, day la nguoi co nghi luc va y chi manh me, dung cam." << endl;
                break;
            case 11:
                cout << "So 11: Dai dien cho su tinh te, so huu mot truc giac vo cung tot, co kha nang thau hieu nhung nguoi xung quanh." << endl;
                break;
            case 22:
                cout << "So  22: Dai dien cho su kien cuong, thong minh va quyet doan. Ngoai ra, day la con so co trach nhiem, nguyen tac va ky luat trong cong viec va cuoc song." << endl;
                break;
            default:
                cout << "Khong co y nghia cho so nay." << endl;
                break;
        }
    }
};

class TarotReading : public FortuneTelling {
public:
    void boiToan(User& user) override {
        // Menu con cho boi tarot
        int selected = 0;
        char key;
        do {
            system("cls");
            cout << "+-------------------------------+" << endl;
            cout << "|        MENU BOI TAROT         |" << endl;
            cout << "+-------------------------------+" << endl;
            cout << (selected == 0 ? " -> " : "    ") << "Boi su nghiep\n";
            cout << (selected == 1 ? " -> " : "    ") << "Boi tinh yeu\n";
            cout << (selected == 2 ? " -> " : "    ") << "Boi gia dinh\n";
            cout << (selected == 3 ? " -> " : "    ") << "Boi qua khu\n";
            cout << (selected == 4 ? " -> " : "    ") << "Boi hien tai\n";
            cout << (selected == 5 ? " -> " : "    ") << "Boi tuong lai\n";
            cout << (selected == 6 ? " -> " : "    ") << "Quay lai menu chinh\n"; // Quay lai menu chinh
            cout << "+-------------------------------+" << endl;

            key = _getch();
            if (key == 72) { // Mui ten len
                selected = (selected - 1 + 7) % 7; // Cap nhat chi so
            } else if (key == 80) { // Mui ten xuong
                selected = (selected + 1) % 7; // Cap nhat chi so
            } else if (key == 13) { // Phim Enter
                system("cls");
                if (selected >= 0 && selected <= 5) {
                    vector<TarotCard> deck = createTarotDeck();
                    TarotCard drawnCard = drawRandomCard(deck);
                    
                    switch (selected) {
                        case 0:
                            cout << "Boi su nghiep: " << endl;
                            break;
                        case 1:
                            cout << "Boi tinh yeu: " << endl;
                            break;
                        case 2:
                            cout << "Boi gia dinh: " << endl;
                            break;
                        case 3:
                            cout << "Boi qua khu: " << endl;
                            break;
                        case 4:
                            cout << "Boi hien tai: " << endl;
                            break;
                        case 5:
                            cout << "Boi tuong lai: " << endl;
                            break;
                    }
                    cout << "Ban da rut duoc: " << drawnCard.name << endl;
                    system("pause");
                } else if (selected == 6) {
                    break; // Quay lai menu chinh
                }
            }
        } while (true);
    }
};

class FortuneApp {
private:
    User user;

public:
    void start() {
        int selected = 0;
        char key;
        do {
            system("cls");
            cout << "+-------------------------------+" << endl;
            cout << "|        MENU BOI TOAN          |" << endl;
            cout << "+-------------------------------+" << endl;
            cout << (selected == 0 ? " -> " : "    ") << "Nhap thong tin nguoi dung\n";
            cout << (selected == 1 ? " -> " : "    ") << "Boi than so hoc\n";
            cout << (selected == 2 ? " -> " : "    ") << "Boi tarot\n";
            cout << (selected == 3 ? " -> " : "    ") << "Thoat\n"; // Thoát chương trình
            cout << "+-------------------------------+" << endl;

            key = _getch();
            if (key == 72) { // Mui ten len
                selected = (selected - 1 + 4) % 4; // Cap nhat chi so
            } else if (key == 80) { // Mui ten xuong
                selected = (selected + 1) % 4; // Cap nhat chi so
            } else if (key == 13) { // Phim Enter
                system("cls");
                FortuneTelling* fortune = nullptr;
                if (selected == 0) {
                    user.nhapThongTinNguoiDung(); // Nhap thong tin nguoi dung
                    user.inThongTinNguoiDung();   // In thong tin vua nhap
                    system("pause");               // Doi nguoi dung nhan phim
                } else if (selected == 1) {
                    fortune = new NumerologyReading();
                } else if (selected == 2) {
                    fortune = new TarotReading();
                } else if (selected == 3) {
                    break; // Thoat chuong trinh
                }
                if (fortune) {
                    fortune->boiToan(user);
                    delete fortune;
                }
            }
        } while (true);
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Khoi tao hat giong cho ngau nhien
    FortuneApp app;
    app.start();
    return 0;
}
// moi push