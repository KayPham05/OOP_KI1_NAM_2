#include "User.h"
#include "ThanSoHoc.h"
#include "CungHoangDao.h"
#include "Tarot.cpp"
#include <conio.h>
int main() {
    ThanSoHoc than;
    CungHoangDao cung;
    User user;
 srand(static_cast<unsigned>(time(0))); // Khởi tạo hạt giống cho random
    int selectedOption = 0;
    char key;
    do {
        system("cls");
        cout << "+-------------------------------+" << endl;
        cout << "|          MENU CHiNH           |" << endl;
        cout << "+-------------------------------+" << endl;
        cout << (selectedOption == 0 ? " -> " : "    ") << "Nhap thong tin nguoi xem boi\n"; // Thêm tùy chọn nhập thông tin
        cout << (selectedOption == 1 ? " -> " : "    ") << "Xem boi than so hoc\n";
        cout << (selectedOption == 2 ? " -> " : "    ") << "xem boi cung hoang dao\n";
        cout << (selectedOption == 3 ? " -> " : "    ") << "xem boi bai Tarot\n"; // Thêm tùy chọn thoát
        cout << (selectedOption == 4 ? " -> " : "    ") << "Thoat\n"; // Thêm tùy chọn thoát
        cout << "+-------------------------------+" << endl;

        key = _getch();
        if (key == 72) { // Mũi tên lên
            selectedOption = (selectedOption - 1 + 5) % 5;
        } else if (key == 80) { // Mũi tên xuống
            selectedOption = (selectedOption + 1) % 5;
        } else if (key == 13) { // Phím Enter
            system("cls");
            if (selectedOption == 0) {
                cin >> user; 
            } else if (selectedOption == 1) {
                cout<<"ket qua cua ban:\n";
                than.display(user);
            } else if (selectedOption == 2) {
                cout<<"ket qua cua ban:\n";
                cung.print(user);
            } else {
                break; // Thoát chương trình
            }
        }
    } while (true); 

    return 0;
}
