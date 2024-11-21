#include "Tarot.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <vector>

using namespace std;
void SetColor(int color) {
    cout << "\033[" << color << "m";
}

void ReSetColor() {
    cout << "\033[0m";
}
void OpenWebsite() {
    // URL of the website
    string url = "https://tarot.vn/giai-y-nghia-78-la-bai-tarot/";
    // Open the URL in the default web browser
    string command = "start " + url;
    system(command.c_str());
}
TarotCard RutBai(const vector<TarotCard>& deck) {
    int randomIndex = rand() % deck.size();
    return deck[randomIndex];
}

// Triển khai hàm tạo bộ bài Tarot
vector<TarotCard> createTarotDeck() {
    return {
       {"The Fool(Ke Kho Khon)\n"
        "+============================================================================================================================================================+\n"
        "|Dai dien cho su khoi dau, su ngau hung, va su tu do. Thuong lien quan den hanh trinh moi ma khong biet truoc ket qua, su chinh phuc su khong biet truoc.    |\n"
        "|Y nghia sau sac: Bat dau mot hanh trinh moi ma khong co su chuan bi day du. Tuong trung cho su ngay tho va tu do trong viec chap nhan nhung rui ro.         |\n"
        "|Tinh huong: Bat dau mot cong viec moi, thay doi noi o, hoac bat dau mot moi quan he ma khong chac chan ve tuong lai.                                        |\n"
        "+============================================================================================================================================================+"},

    {"The Magician (Nha Ao Thuat)\n"
     "+======================================================================================================================================+\n"
     "|Ky nang, kha nang dieu khien va tao ra thuc te bang suc manh y chi. Nhieu khi goi y su tap trung vao muc tieu va su tu tin.           |\n"
     "|Y nghia sau sac: Kha nang bien uoc mo thanh hien thuc thong qua su tap trung va y chi. Khuyen khich ban tan dung tai nang cua minh.   |\n"
     "|Tinh huong: Ban co the thanh cong bang cach su dung nhung ky nang va nguon luc da co.                                                 |\n"
     "+======================================================================================================================================+"},

    {"The High Priestess (Nu Tu Te Cao Cap)\n"
     "+===========================================================================================================================================+\n"
     "|Su truc giac, bi mat va tri tue noi tam. Khuyen nen lang nghe tieng noi ben trong va tim kiem hieu biet chinh minh.                        |\n"
     "|Y nghia sau sac: Khuyen khich viec lang nghe truc giac va kham pha nhung bi mat. Nu Tu Te bieu trung cho su hieu biet sau sac ve ban than. |\n"
     "|Tinh huong: Can tin vao cam giac truc giac khi doi mat voi mot quyet dinh quan trong.                                                      |\n"
     "+===========================================================================================================================================+"},

    {"The Empress (Hoang Hau)\n"
     "+====================================================================================================================+\n"
     "|Dai dien cho su phong thinh, tinh yeu, me thien nhien, va su cham soc. La bieu tuong cua tinh thuong va nu tinh.    |\n"
     "|Y nghia sau sac: Su nuoi duong va kha nang sinh san. Bieu tuong cho su phong phu, cham soc va tinh yeu.             |\n"
     "|Tinh huong: Phat trien mot du an moi, nuoi duong cac moi quan he ca nhan, tim kiem su binh yen.                     |\n"
     "+====================================================================================================================+"},

    {"The Emperor (Hoang De)\n"
     "+======================================================================================================================+"
     "|Su kiem soat, quyen luc va cau truc. La bieu tuong cua ke lanh dao, nguyen tac nam tinh va trat tu xa hoi.            |\n"
     "|Y nghia sau sac: Quyen luc va su kiem soat. Khuyen khich su lanh dao va xay dung nen tang vung chac cho tuong lai.    |\n"
     "|Tinh huong: Can co su quyet doan trong viec ra quyet dinh lon.                                                        |\n"
     "+======================================================================================================================+"},

    {"The Hierophant (Thay Tu Cao Cap)\n"
     "+=============================================================================================================+"
     "|Dai dien cho truyen thong, giao duc, va dao ly tam linh. Goi y su can bang giua thuc hanh va hoc thuyet.     |\n"
     "|Y nghia sau sac: Bieu trung cho truyen thong va giao duc. Khuyen khich tim kiem su chi dan va hoc hoi.       |\n"
     "|Tinh huong: Tham gia mot khoa hoc, tim su tu van tu nguoi co kinh nghiem.                                    |\n"
    },

    {"The Lovers (Nguoi Yeu Nhau): Su lua chon, moi quan he, va tinh yeu. Goi y tinh than doan ket, quyet dinh quan trong va tinh cam.\n"
     "Y nghia sau sac: Tinh yeu, su ket noi va su lua chon. Bieu tuong cho su gan ket sau sac giua hai nguoi.\n"
     "Tinh huong: Can ra quyet dinh ve mot moi quan he quan trong."},

    {"The Chariot (Xe Ngua): Chien thang bang y chi va su kiem soat. Goi y su tien bo, dat duoc thanh cong sau khi khac phuc kho khan.\n"
     "Y nghia sau sac: Su quyet tam va kha nang kiem soat. Khuyen khich ban giu vung quyet tam.\n"
     "Tinh huong: Doi mat voi mot thu thach lon trong cuoc song."},

    {"Strength (Suc Manh): Su manh me noi tai, su kien nhan va long dung cam. Khuyen nen dung cam doi mat voi kho khan.\n"
     "Y nghia sau sac: Su kiên nhẫn, long dung cam. Khuyen khich ban doi mat voi kho khan.\n"
     "Tinh huong: Can phai doi mat voi mot noi so hoac thu thach."},

    {"The Hermit (Nha An Si): Su suy tu, co doc va tim kiem su that. Goi y su can thiet cua viec nghi lai, tu van va hieu biet noi tam.\n"
     "Y nghia sau sac: Tim kiem su tinh lang va hieu biet. Khuyen khich ban danh thoi gian de tu phan tich.\n"
     "Tinh huong: Can thoi gian rieng tu de hieu ro hon ve ban than."},

    {"Wheel of Fortune (Banh Xe Van Menh): Su thay doi, chu ky moi va van may. La nhac nho rang cuoc song la mot vong xoay khong ngung nghi.\n"
     "Y nghia sau sac: Chu ky va su thay doi. Khuyen khich ban chuan bi cho nhung thay doi bat ngo.\n"
     "Tinh huong: Doi mat voi nhung thang tram trong cuoc song."},

    {"Justice (Cong Ly): Su cong bang, can bang va trach nhiem. Goi y nhung quyet dinh cong minh va hau qua cua hanh dong.\n"
     "Y nghia sau sac: Su cong bang va trach nhiem. Khuyen khich ban ra quyet dinh cong bang.\n"
     "Tinh huong: Can can nhac ve quyet dinh cua ban."},

    {"The Hanged Man (Nguoi Bi TreoNguoc): Su hy sinh, goc nhin moi va tam dung. Khuyen nen nhin su viec tu goc do khac de tim ra giai phap.\n"
     "Y nghia sau sac: Su hy sinh va goc nhin moi. Khuyen khich ban nghi lai ve goc do khac.\n"
     "Tinh huong: Can tim kiem giai phap cho mot tinh huong khong the tien len."},

    {"Death (Cai Chet): Su ket thuc, bien doi va su doi moi. Dai dien cho su ket thuc cua mot chu ky va su khoi dau moi.\n"
     "Y nghia sau sac: Su ket thuc va bien doi. Khuyen khich ban chap nhan su thay doi trong cuoc song.\n"
     "Tinh huong: Ket thuc mot chu ky de mo ra chu ky moi."},

    {"The Devil (Quy Du): Su le thuoc, cam do va so hai. Goi y su can thiet cua viec giai phong khoi nhung rang buoc tinh than.\n"
     "Y nghia sau sac: Su le thuoc va cam do. Khuyen khich ban giai phong khoi nhung rang buoc.\n"
     "Tinh huong: Can thoat khoi nhung thoi quen xau."},

    {"The Tower (Toa Thap): Su tan vo, thay doi dot ngot va khung hoang. La bieu tuong cua su do vo de thanh lap lai.\n"
     "Y nghia sau sac: Su tan vo va khung hoang. Khuyen khich ban chuan bi cho nhung thay doi manh me.\n"
     "Tinh huong: Doi mat voi khung hoang trong cuoc song."},

    {"The Star (Ngoi Sao): Hy vong, chua lanh va cam hung. Dai dien cho su lac quan va niem tin vao tuong lai.\n"
     "Y nghia sau sac: Hy vong va cam hung. Khuyen khich ban tin tuong vao tuong lai.\n"
     "Tinh huong: Tim thay a sang hy vong trong luc kho khan."},

    {"The Moon (Mat Trang): Ao tuong, bi an va su khong chac chan. Goi y su hieu lam, lo so va nhung dieu an giau.\n"
     "Y nghia sau sac: Ao tuong va bi an. Khuyen khich ban tim kiem su ro rang trong cam xuc.\n"
     "Tinh huong: Can lam ro hon ve cac lo lang va nghi ngo."},

    {"The Sun (Mat Troi): Thanh cong, hanh phuc va su soi sang. Dai dien cho su thanh cong, hanh phuc va su khai sang.\n"
     "Y nghia sau sac: Thanh cong va hanh phuc. Bieu trung cho su toa sang va hanh phuc.\n"
     "Tinh huong: Thoi ky thinh vuong va nen tan huong."},

    {"Judgement (Phan Quyet): Su danh gia, tai sinh va loi nhan. Goi y su xem xet hanh dong va nhung quyet dinh ve tuong lai.\n"
     "Y nghia sau sac: Su danh gia va tai sinh. Khuyen khich ban xem xet hanh dong cua minh.\n"
     "Tinh huong: Can doi mat voi hau qua tu cac quyet dinh truoc do."},

    {"The World (The Gioi): Su hoan thanh, thanh tuu va su trọn ven. Dai dien cho su vien man va thanh cong trong cuoc song.\n"
     "Y nghia sau sac: Su hoan thanh va thanh tuu. Bieu trung cho su hoan thanh va ket thuc thanh cong.\n"
     "Tinh huong: Hoan thanh mot chu ky lon trong cuoc song."}
    };
}

void TarotReading::boiToan(User& user) {
    vector<TarotCard> deck = createTarotDeck();  // Tạo bộ bài Tarot
    int selected = 0;
    char key;
    srand(static_cast<unsigned>(time(0)));

    do {
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

        key = _getch();
        if (key == 72) { // Mũi tên lên
            selected = (selected - 1 + 7) % 7;
        } else if (key == 80) { // Mũi tên xuống
            selected = (selected + 1) % 7;
        } else if (key == 13) { // Phím Enter
            system("cls");
            if (selected < 5) {
                TarotCard drawnCard = RutBai(deck);  // Rút một lá bài ngẫu nhiên
                cout << "Ban da rut duoc la bai: " << drawnCard.ten << endl;
                cout << "Neu ban can tim hieu them hay nhap vao duong link duoi day: " << endl;
                cout << "+=======================================================+" << endl;
                cout << "|    https://tarot.vn/giai-y-nghia-78-la-bai-tarot/     |" << endl;
                cout << "+=======================================================+" << endl;
                cin.get();
                system("pause");
            } else {
                break;
            }
        }
    } while (true);
}

string TarotReading::Soduongdoi(int Sochudao) {
    return "So duong doi cua ban la " + to_string(Sochudao);
}
