#include <iostream>
#include <conio.h>     // Sử dụng thư viện getch() cho Windows
#include <windows.h>   // Sử dụng thư viện windows.h để làm việc với console

using namespace std;

// Hàm ẩn con trỏ chuột
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE; // Ẩn con trỏ
    info.dwSize = 100;     // Kích thước của con trỏ
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Hàm hiển thị menu với lựa chọn đang được chọn
void displayMenu(int selected) {
    string options[] = {"Chon than so hoc", "Chon boi tarot", "exit"};
    system("cls"); // Xóa màn hình
    cout << "+------------------------------------------+" << endl;
    cout << "|                 MENU                     |" << endl;
    cout << "+------------------------------------------+" << endl;
    for (int i = 0; i < 3; i++) {
        if (i == selected) {
            cout << " -> ";  // Mũi tên chỉ vào lựa chọn hiện tại
        } else {
            cout << "    ";  // Khoảng trống cho các lựa chọn còn lại
        }
        cout << options[i] << endl;
    }
    cout << "+------------------------------------------+" << endl;
}

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

    return 0;
}
