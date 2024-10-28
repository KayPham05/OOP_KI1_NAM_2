#include "thansohoc.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

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
std::vector<TarotCard> createTarotDeck1() {
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
TarotCard drawRandomCard(const std::vector<TarotCard>& deck) {
    int randomIndex = rand() % deck.size();
    return deck[randomIndex];
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 100;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void displayMenu(int selected) {
    string options[] = {"Chon than so hoc", "Chon boi tarot", "exit"};
    system("cls");
    cout << "+------------------------------------------+" << endl;
    cout << "|                 MENU                     |" << endl;
    cout << "+------------------------------------------+" << endl;
    for (int i = 0; i < 3; i++) {
        cout << (i == selected ? " -> " : "    ") << options[i] << endl;
    }
    cout << "+------------------------------------------+" << endl;
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

int calculateExpressionNumber(const std::string& name) {
    int sum = 0;
    for (char c : name) {
        if (std::isalpha(c)) {
            sum += std::toupper(c) - 'A' + 1;
        }
    }
    return reduceToSingleDigit(sum);
}
