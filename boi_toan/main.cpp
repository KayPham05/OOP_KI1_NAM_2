#include "User.h"
#include "ThanSoHoc.h"
#include "CungHoangDao.h"
#include "Tarot.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    TarotReading tarot;
    CungHoangDao cung;
    User user;
    SoDuongDoi soDuongDoi;
    LinhHon linhHon;
    BieuDat bieuDat;
    NhanCach nhanCach;
    srand(static_cast<unsigned>(time(0))); // Khởi tạo hạt giống cho random
    int selectedOption = 0;
    char key;

    do {
        system("cls");
        cout << "+-------------------------------+" << endl;
        cout << "|          MENU CHiNH           |" << endl;
        cout << "+-------------------------------+" << endl;
        cout << (selectedOption == 0 ? " -> " : "    ") << "Nhap thong tin nguoi xem boi\n";
        cout << (selectedOption == 1 ? " -> " : "    ") << "Xem than so hoc\n";
        cout << (selectedOption == 2 ? " -> " : "    ") << "Xem cung hoang dao\n";
        cout << (selectedOption == 3 ? " -> " : "    ") << "Xem boi bai Tarot\n";
        cout << (selectedOption == 4 ? " -> " : "    ") << "Thoat\n";
        cout << "+-------------------------------+" << endl;

        key = _getch();
        if (key == 72) { // Mũi tên lên
            selectedOption = (selectedOption - 1 + 5) % 5;
        } else if (key == 80) { // Mũi tên xuống
            selectedOption = (selectedOption + 1) % 5;
        } else if (key == 13) { // Phím Enter
            if (selectedOption == 0) {
                system("cls");
                cin >> user;
                cin.ignore(); 
                cout << "Nhan Enter de tiep tuc...\n";
                cin.get();
            } else if (selectedOption == 1) {
                int thanSoOption = 0;
                do {
                    system("cls");
                    cout << "+-------------------------------+" << endl;
                    cout << "|       XEM THAN SO HOC         |" << endl;
                    cout << "+-------------------------------+" << endl;
                    cout << (thanSoOption == 0 ? " -> " : "    ") << "Xem So Duong Doi\n";
                    cout << (thanSoOption == 1 ? " -> " : "    ") << "Xem So Linh Hon\n";
                    cout << (thanSoOption == 2 ? " -> " : "    ") << "Xem So Bieu Dat\n";
                    cout << (thanSoOption == 3 ? " -> " : "    ") << "Xem So Nhan Cach\n";
                    cout << (thanSoOption == 4 ? " -> " : "    ") << "Quay lai\n";
                    cout << "+-------------------------------+" << endl;

                    key = _getch();
                    if (key == 72) { // Mũi tên lên
                        thanSoOption = (thanSoOption - 1 + 5) % 5;
                    } else if (key == 80) { // Mũi tên xuống
                        thanSoOption = (thanSoOption + 1) % 5;
                    } else if (key == 13) { // Phím Enter
                        if (thanSoOption == 0) {
                            system("cls");
                            cout << "Ket qua So Duong Doi:\n";
                            soDuongDoi.thongTin(user);
                            cout << "Nhan Enter de quay lai...\n";
                            cin.get(); 
                        } else if (thanSoOption == 1) {
                            system("cls");
                            cout << "Ket qua So Linh Hon:\n";
                            linhHon.thongTin(user);
                            cin.get();
                        } else if (thanSoOption == 2) {
                            system("cls");
                            cout << "Ket qua So Bieu Dat:\n";
                            bieuDat.thongTin(user);
                            cin.get();
                        } else if (thanSoOption == 3) {
                            system("cls");
                            cout << "Ket qua So Nhan Cach:\n";
                            nhanCach.thongTin(user);
                            cin.get();
                        } else {
                            break; 
                        }
                    }
                } while (true);
            } else if (selectedOption == 2) {
                system("cls");
                cout << "Ket qua cua ban:\n";
                cung.print(user);
                cout << "Nhan Enter de quay lai...\n";
                cin.get();
            } else if (selectedOption == 3) {
                system("cls");
                tarot.boiToan(user);
                cout << "Nhan Enter de quay lai...\n";
                cin.get();
            } else {
                break; // Thoát chương trình
            }
        }
    } while (true);

    return 0;
}
