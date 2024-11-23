#include "User.h"
#include "Tarot.h"
#include "ThanSoHoc.h"
#include "CungHoangDao.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
using namespace std;

// Hàm để thay đổi màu chữ
void setColor(int color) {
    cout << "\033[" << color << "m";
}

void resetColor() {
    cout << "\033[0m";
}
void openWebsite() {
    // URL of the website
    string url = "https://tracuuthansohoc.com/than-so-hoc-so-1/";
    // Open the URL in the default web browser
    string command = "start " + url;
    system(command.c_str());
}

int main() {
    TarotDeck tarotDeck;
    CungHoangDao cung;
    User user;
    SoDuongDoi soDuongDoi;
    LinhHon linhHon;
    BieuDat bieuDat;
    NhanCach nhanCach;
    srand(static_cast<unsigned>(time(0))); // Khởi tạo hạt giống cho random
    bool exitProgram = false;  // Biến điều kiện thoát chương trình
    bool returnToMainMenu = false; // Biến quay lại menu chính
    int selectedRoleOption = 0;
    int selectedFortuneOption = 0;
    char key;


    do {
        system("cls");
        setColor(35);  // Màu tím cho chữ "Number God Study"
        cout << endl;
        cout << "                                  N U M B E R       G O D       S T U D Y   " << endl;
        cout << "\n";
        resetColor();
        setColor(33);
        cout << "                                 +---------------------------------------+" << endl;
        setColor(31);
        cout << "                                 |              CHON VAI TRO             |" << endl;
        setColor(35);
        cout << "                                 +---------------------------------------+" << endl;
        resetColor();

        // Menu lựa chọn vai trò: Admin hay Người dùng
        if (selectedRoleOption == 0) {
            setColor(32);  // Màu xanh lá cây cho mục được chọn
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Admin                              |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();  // Trở lại màu bình thường
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Admin                                 |" << endl;
            cout << "                                 =========================================" << endl;
        }

        if (selectedRoleOption == 1) {
            setColor(33);
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Nguoi dung                         |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Nguoi dung                            |" << endl;
            cout << "                                 =========================================" << endl;
        }

        if (selectedRoleOption == 2) {
            setColor(33);
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Thoat                              |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Thoat                                 |" << endl;
            cout << "                                 =========================================" << endl;
        }

        cout << "                                 +---------------------------------------+" << endl;
        key = _getch();
        if (key == 72) { // Mũi tên lên
            selectedRoleOption = (selectedRoleOption - 1 + 3) % 3;
        }
        else if (key == 80) { // Mũi tên xuống
            selectedRoleOption = (selectedRoleOption + 1) % 3;
        }
        else if (key == 13) { // Enter
            if (selectedRoleOption == 0) {
                cout << "Chức năng Admin đang được phát triển...\n";
                cin.get();
            }
            else if (selectedRoleOption == 2) {
                exitProgram = true; // Đặt biến thoát chương trình
                break; // Thoát khỏi vòng lặp
            }
            else if (selectedRoleOption == 1) {
                break; // Thoát khỏi vòng lặp
            }
        }
    } while (!exitProgram && !returnToMainMenu);  // Kiểm tra biến điều kiện thoát

    if (exitProgram) {
        cout << "Nhan enter de thoat .\n";
        return 0;  // Thoát chương trình
    }


    do {
        system("cls");
        setColor(35);  // Màu tím cho chữ "Number God Study"
        cout << endl;
        cout << "                                  N U M B E R       G O D       S T U D Y   " << endl;
        cout << "\n";
        resetColor();
        setColor(33);
        cout << "                                 +---------------------------------------+" << endl;
        setColor(31);
        cout << "                                 |               BOI TOAN                |" << endl;
        setColor(35);
        cout << "                                 +---------------------------------------+" << endl;
        resetColor();

        // Mục 1: Nhập thông tin người xem bói
        if (selectedFortuneOption == 0) {
            setColor(32);  // Màu xanh lá cây cho mục được chọn
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Nhap thong tin nguoi xem boi       |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();  // Trở lại màu bình thường
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Nhap thong tin nguoi xem boi          |" << endl;
            cout << "                                 =========================================" << endl;
        }

        // Mục 2: Xem thần số học
        if (selectedFortuneOption == 1) {
            setColor(33);
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Xem than so hoc                    |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Xem than so hoc                       |" << endl;
            cout << "                                 =========================================" << endl;
        }

        // Mục 3: Xem cung hoàng đạo
        if (selectedFortuneOption == 2) {
            setColor(34);
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Xem cung hoang dao                 |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Xem cung hoang dao                    |" << endl;
            cout << "                                 =========================================" << endl;
        }

        // Mục 4: Xem bói bài Tarot
        if (selectedFortuneOption == 3) {
            setColor(31);
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Xem boi bai Tarot                  |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Xem boi bai Tarot                     |" << endl;
            cout << "                                 =========================================" << endl;
        }

        // Mục 5: Quay lại (Exit)
        if (selectedFortuneOption == 4) {
            setColor(35);
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " -> Quay Lai                           |" << endl;
            cout << "                                 =========================================" << endl;
            resetColor();
        }
        else {
            cout << "                                 =========================================" << endl;
            cout << "                                 |" << " Quay Lai                              |" << endl;
            cout << "                                 =========================================" << endl;
        }

        cout << "                                 +---------------------------------------+" << endl;

        key = _getch();  // Đọc phím người dùng nhấn
        if (key == 72) { // Mũi tên lên
            selectedFortuneOption = (selectedFortuneOption - 1 + 5) % 5;
        }
        else if (key == 80) { // Mũi tên xuống
            selectedFortuneOption = (selectedFortuneOption + 1) % 5;
        }
        else if (key == 13) { // Phím Enter

            if (selectedFortuneOption == 0) {
                system("cls");
                cin >> user;
                cin.ignore();
                //cout << "Nhan Enter de tiep tuc...\n";
                cin.get();
            }

            else if (selectedFortuneOption == 4) {
                returnToMainMenu = true; // Quay lại menu chính
            }
            else if (selectedFortuneOption == 1) {
                int thanSoOption = 0;
                do {
                    system("cls");
                    setColor(35);  // Màu tím cho chữ "Number God Study"
                    cout << "                                  N U M B E R       G O D       S T U D Y   " << endl;
                    cout << "\n";
                    resetColor();
                    setColor(33);
                    cout << "                                 +---------------------------------------+" << endl;
                    setColor(31);
                    cout << "                                 |           BOI THAN SO HOC             |" << endl;
                    setColor(35);
                    cout << "                                 +---------------------------------------+" << endl;
                    resetColor();
                    // Mục 1: Nhập thông tin người xem bói
                    if (thanSoOption == 0) {
                        setColor(32);  // Màu xanh lá cây cho mục được chọn
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " -> Xem So Duong Doi                   |" << endl;
                        cout << "                                 =========================================" << endl;
                        resetColor();  // Trở lại màu bình thường
                    }
                    else {
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " Xem So Duong Doi                      |" << endl;
                        cout << "                                 =========================================" << endl;
                    }

                    // Mục 2: Xem thần số học
                    if (thanSoOption == 1) {
                        setColor(33);
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " -> Xem So Linh Hon                    |" << endl;
                        cout << "                                 =========================================" << endl;
                        resetColor();
                    }
                    else {
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " Xem So Linh Hon                       |" << endl;
                        cout << "                                 =========================================" << endl;
                    }


                    if (thanSoOption == 2) {
                        setColor(34);
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " -> Xem So Bieu Dat                    |" << endl;
                        cout << "                                 =========================================" << endl;
                        resetColor();
                    }
                    else {
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " Xem So Bieu Dat                       |" << endl;
                        cout << "                                 =========================================" << endl;
                    }

                    // Mục 4: Xem bói bài Tarot
                    if (thanSoOption == 3) {
                        setColor(31);
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " -> Xem So Nhan Cach                   |" << endl;
                        cout << "                                 =========================================" << endl;
                        resetColor();
                    }
                    else {
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " Xem So Nhan Cach                      |" << endl;
                        cout << "                                 =========================================" << endl;
                    }

                    // Mục 5: Thoát
                    if (thanSoOption == 4) {
                        setColor(35);
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " ->Quay lai                            |" << endl;
                        cout << "                                 =========================================" << endl;
                        resetColor();
                    }
                    else {
                        cout << "                                 =========================================" << endl;
                        cout << "                                 |" << " Quay lai                              |" << endl;
                        cout << "                                 =========================================" << endl;
                    }

                    cout << "                                 +---------------------------------------+" << endl;

                    key = _getch();
                    if (key == 72) { // Mũi tên lên
                        thanSoOption = (thanSoOption - 1 + 5) % 5;
                    }
                    else if (key == 80) { // Mũi tên xuống
                        thanSoOption = (thanSoOption + 1) % 5;
                    }
                    else if (key == 13) { // Phím Enter
                        // Xử lý hành động khi chọn các mục
                        if (thanSoOption == 0) {
                            system("cls");
                            cout << "Ket qua So Duong Doi:\n";
                            soDuongDoi.thongTin(user);

                            cout << "Neu ban can tim hieu them hay nhap vao duong link duoi day: " << endl;
                            cout << "+=======================================================+" << endl;
                            cout << "|     https://tracuuthansohoc.com/than-so-hoc-so-1/     |" << endl;
                            cout << "+=======================================================+" << endl;
                            cin.get();
                        }
                        else if (thanSoOption == 1) {
                            system("cls");
                            cout << "Ket qua So Linh Hon:\n";
                            linhHon.thongTin(user);
                            cout << "Neu ban can tim hieu them hay nhap vao duong link duoi day: " << endl;
                            cout << "+=======================================================+" << endl;
                            cout << "|     https://tracuuthansohoc.com/than-so-hoc-so-1/     |" << endl;
                            cout << "+=======================================================+" << endl;
                            cin.get();
                        }
                        else if (thanSoOption == 2) {
                            system("cls");
                            cout << "Ket qua So Bieu Dat:\n";
                            bieuDat.thongTin(user);
                            cout << "Neu ban can tim hieu them hay nhap vao duong link duoi day: " << endl;
                            cout << "+=======================================================+" << endl;
                            cout << "|     https://tracuuthansohoc.com/than-so-hoc-so-1/     |" << endl;
                            cout << "+=======================================================+" << endl;
                            cin.get();
                        }
                        else if (thanSoOption == 3) {
                            system("cls");
                            cout << "Ket qua So Nhan Cach:\n";
                            nhanCach.thongTin(user);
                            cout << "Neu ban can tim hieu them hay nhap vao duong link duoi day: " << endl;
                            cout << "+=======================================================+" << endl;
                            cout << "|     https://tracuuthansohoc.com/than-so-hoc-so-1/     |" << endl;
                            cout << "+=======================================================+" << endl;
                            cin.get();
                        }
                        else {
                            break;
                        }
                    }
                } while (true);

            }
            else if (selectedFortuneOption == 2) {
                system("cls");
                cout << "Ket qua cua ban:\n";
                cung.Display(user);


                cout << "Nhan Enter de quay lai...\n";
                cin.get();
            }
            else if (selectedFortuneOption == 3) {
                system("cls");
                try {
                    boiTarot();
                }
                catch (const std::exception& e) {
                    cerr << "Loi: " << e.what() << endl; // Thông báo lỗi nếu bộ bài hết lá
                }
            }

            else {
                break; // Thoát chương trình
            }

        }

    } while (true);

    return 0;
}