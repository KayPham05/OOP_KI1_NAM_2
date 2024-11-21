#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    string input;
    char ch;

    cout << "Nhap du lieu (toi da 26 ky tu): ";
    while (true) {
        ch = _getch(); // Bắt ký tự người dùng nhập

        // Kiểm tra nếu nhấn Enter
        if (ch == 13) {
            break;
        }

        // Kiểm tra nếu nhấn Backspace
        if (ch == 8 && !input.empty()) {
            cout << "\b \b"; // Xóa ký tự khỏi màn hình
            input.pop_back();
            continue;
        }

        // Chỉ cho phép thêm nếu chưa vượt quá giới hạn
        if (input.length() < 26) {
            input += ch;
            cout << ch; // Hiển thị ký tự trên màn hình
        }
    }

    cout << "\nDu lieu vua nhap: " << input << endl;
    return 0;
}
