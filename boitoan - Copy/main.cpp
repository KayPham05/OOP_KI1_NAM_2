#include "User.h"
#include "ThanSoHoc.h"
#include "CungHoangDao.h"
#include "Tarot.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hàm để thay đổi màu chữ
void setColor(int color) {
    cout << "\033[" << color << "m";
}

void resetColor() {
    cout << "\033[0m";
}

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

        // Mục 1: Nhập thông tin người xem bói
        if (selectedOption == 0) {
            setColor(32);  // Màu xanh lá cây cho mục được chọn
            cout << " -> Nhap thong tin nguoi xem boi\n";
            resetColor();  // Trở lại màu bình thường
        } else {
            cout << "    Nhap thong tin nguoi xem boi\n";
        }

        // Mục 2: Xem thần số học
        if (selectedOption == 1) {
            setColor(33);
            cout << " -> Xem than so hoc\n";
            resetColor();
        } else {
            cout << "    Xem than so hoc\n";
        }

        // Mục 3: Xem cung hoàng đạo
        if (selectedOption == 2) {
            setColor(34);
            cout << " -> Xem cung hoang dao\n";
            resetColor();
        } else {
            cout << "    Xem cung hoang dao\n";
        }

        // Mục 4: Xem bói bài Tarot
        if (selectedOption == 3) {
            setColor(31);
            cout << " -> Xem boi bai Tarot\n";
            resetColor();
        } else {
            cout << "    Xem boi bai Tarot\n";
        }
        if (selectedOption == 4) {
            setColor(26);
            cout << " -> Sua thong tin \n";
            resetColor();
        } else {
            cout << "    Sua thong tin \n";
        }
        // Mục 5: Thoát

        if (selectedOption == 5) {
            setColor(35);
            cout << " -> Thoat\n";
            resetColor();
        } else {
            cout << "    Thoat\n";
        }

        cout << "+-------------------------------+" << endl;

        key = _getch();
        if (key == 72) { // Mũi tên lên
            selectedOption = (selectedOption - 1 + 6) % 6;
        } else if (key == 80) { // Mũi tên xuống
            selectedOption = (selectedOption + 1) % 6;
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

    // Mục 1: Xem Số Đường Đời
    if (thanSoOption == 0) {
        setColor(32);  // Màu xanh lá cây cho mục được chọn
        cout << " -> Xem So Duong Doi\n";
        resetColor();
    } else {
        cout << "    Xem So Duong Doi\n";
    }

    // Mục 2: Xem Số Linh Hồn
    if (thanSoOption == 1) {
        setColor(33);  // Màu vàng cho mục được chọn
        cout << " -> Xem So Linh Hon\n";
        resetColor();
    } else {
        cout << "    Xem So Linh Hon\n";
    }

    // Mục 3: Xem Số Biểu Đạt
    if (thanSoOption == 2) {
        setColor(34);  // Màu xanh dương cho mục được chọn
        cout << " -> Xem So Bieu Dat\n";
        resetColor();
    } else {
        cout << "    Xem So Bieu Dat\n";
    }

    // Mục 4: Xem Số Nhân Cách
    if (thanSoOption == 3) {
        setColor(35);  // Màu tím cho mục được chọn
        cout << " -> Xem So Nhan Cach\n";
        resetColor();
    } else {
        cout << "    Xem So Nhan Cach\n";
    }

    // Mục 5: Quay lại
    if (thanSoOption == 4) {
        setColor(31);  // Màu đỏ cho mục được chọn
        cout << " -> Quay lai\n";
        resetColor();
    } else {
        cout << "    Quay lai\n";
    }

    cout << "+-------------------------------+" << endl;

    key = _getch();
    if (key == 72) { // Mũi tên lên
        thanSoOption = (thanSoOption - 1 + 5) % 5;
    } else if (key == 80) { // Mũi tên xuống
        thanSoOption = (thanSoOption + 1) % 5;
    } else if (key == 13) { // Phím Enter
        // Xử lý hành động khi chọn các mục
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
            }
            else if (selectedOption == 4)
            {
                 int thanSoOption = 0;
do {
    system("cls");
    cout << "+-------------------------------+" << endl;
    cout << "|       SUA THONG TIN           |" << endl;
    cout << "+-------------------------------+" << endl;

    // Mục 1: Xem Số Đường Đời
    if (thanSoOption == 0) {
        setColor(32);  // Màu xanh lá cây cho mục được chọn
        cout << " -> SUA TEN \n";
        resetColor();
    } else {
        cout << "    SUA TEN\n";
    }

    // Mục 2: Xem Số Linh Hồn
    if (thanSoOption == 1) {
        setColor(33);  // Màu vàng cho mục được chọn
        cout << " -> SUA NGAY THANG NAM SINH\n";
        resetColor();
    } else {
        cout << "   SUA NGAY THANG NAM SINH\n";
    }

    // Mục 3: Xem Số Biểu Đạt
    if (thanSoOption == 2) {
        setColor(34);  // Màu xanh dương cho mục được chọn
        cout << " ->SUA GIOI TINH\n";
        resetColor();
    } else {
        cout << "    SUA GIOI TINH\n";
    }

    // Mục 5: Quay lại
    if (thanSoOption == 4) {
        setColor(31);  // Màu đỏ cho mục được chọn
        cout << " -> Quay lai\n";
        resetColor();
    } else {
        cout << "    Quay lai\n";
    }

    cout << "+-------------------------------+" << endl;

    key = _getch();
    if (key == 72) { // Mũi tên lên
        thanSoOption = (thanSoOption - 1 + 5) % 5;
    } else if (key == 80) { // Mũi tên xuống
        thanSoOption = (thanSoOption + 1) % 5;
    } else if (key == 13) { // Phím Enter
        // Xử lý hành động khi chọn các mục
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



            }
            
             else {
                break; // Thoát chương trình
            }
        }
    } while (true);

    return 0;
}
