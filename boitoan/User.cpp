#include "User.h"
#include "CungHoangDao.h"
#include "ThanSoHoc.h"
#include <fstream>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <limits>
bool isLeapYear(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

bool isValidDate(int ngay, int thang, int nam) {
    if (thang < 1 || thang > 12) return false;
    
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (thang == 2 && isLeapYear(nam)) {
        daysInMonth[1] = 29;    
    }
    
    return (ngay >= 1 && ngay <= daysInMonth[thang - 1]);
}

bool isPastOrPresentDate(int ngay, int thang, int nam) {
    time_t t = time(0); // Lấy thời gian hiện tại
    struct tm now;
    localtime_s(&now, &t); // Sử dụng phiên bản an toàn

    int currentYear = now.tm_year + 1900;  // Năm hiện tại
    int currentMonth = now.tm_mon + 1;    // Tháng hiện tại
    int currentDay = now.tm_mday;         // Ngày hiện tại

    // Kiểm tra ngày nhập có hợp lệ không
    if (!isValidDate(ngay, thang, nam)) {
        return false;
    }

    // So sánh năm, tháng, ngày

    if (nam > currentYear || nam <= 1924)return false;
        if (nam == currentYear) {
        if (thang > currentMonth) return false;
        if (thang == currentMonth) {
            if (ngay > currentDay) return false;
        }
    }

    return true; // Ngày hợp lệ và không vượt quá ngày hiện tại
}

User::User() : Ten(""), GioiTinh(""), day{0, 0, 0}, BietDanh("") {}


void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// H�m v? m?t khung (rectangle)
void drawBox(int x, int y, int width, int height) {
    // V? g�c
    gotoXY(x, y);
    cout << char(218); // G�c tr�n tr�i
    gotoXY(x + width, y);
    cout << char(191); // G�c tr�n ph?i
    gotoXY(x, y + height);
    cout << char(192); // G�c d�?i tr�i
    gotoXY(x + width, y + height);
    cout << char(217); // G�c d�?i ph?i

    // V? c?nh tr�n v� c?nh d�?i
    for (int i = 1; i < width; i++) {
        gotoXY(x + i, y);
        cout << char(196); // K? t? ngang
        gotoXY(x + i, y + height);
        cout << char(196); // K? t? ngang
    }

    // V? c?nh tr�i v� c?nh ph?i
    for (int i = 1; i < height; i++) {
        gotoXY(x, y + i);
        cout << char(179); // K? t? d?c
        gotoXY(x + width, y + i);
        cout << char(179); // K? t? d?c
    }
}

void drawInputForm() {
    // Ti�u �? form
    gotoXY(20, 1);
    cout << "Nhap thong tin ca nhan";
    // V? khung v� ti�u �? cho t?ng ph?n nh?p
    gotoXY(10, 2);
    cout << "Ho ten khai sinh:";
    drawBox(10, 3, 86, 2); // Khung nh?p h? t�n khai sinh
    gotoXY(12, 4);
    cout << "Nhap ho ten: ";
    gotoXY(24, 4);
    cout << string(40, ' '); // V�ng nh?p li?u
    gotoXY(10, 6);
    cout << "Ten thuong dung neu co (VD: Louis Pham)";
    drawBox(10, 7, 50, 2); // Khung nh?p t�n th�?ng d�ng
    gotoXY(12, 8);
    cout << "Nhap ten thuong dung: ";
    gotoXY(33, 8);
    cout << string(20, ' '); // V�ng nh?p li?u
    drawBox(61, 7, 35, 2); // Khung nh?p t�n th�?ng d�ng
    gotoXY(63, 8);
    cout << "Gioi tinh: ";
    gotoXY(82, 8);
    cout << "(Nam/Nu/Khac)";
    gotoXY(73, 8);
    cout << string(4, ' '); // V�ng nh?p li?u
    gotoXY(10, 10);
    cout << "Ngay/thang/nam sinh duong lich:";
    drawBox(10, 11, 28, 2);
    gotoXY(12, 12);
    cout << "Ngay:";
    gotoXY(17, 12);
    cout << string(2, ' ');
    drawBox(39, 11, 28, 2);
    gotoXY(41, 12);
    cout << "Thang:";
    gotoXY(47, 12);
    cout << string(2, ' ');
    drawBox(68, 11, 28, 2);
    gotoXY(70, 12);
    cout << "Nam:";
    gotoXY(74, 12);
    cout << string(4, ' ');

}

void drawButtons(int selected) {
    // Vị trí các nút
    int x1 = 30, x2 = 50, y = 16;

    // Vẽ nút "Lưu thông tin"
    gotoXY(x1, y);
    if (selected == 1) {
        cout << "[ Luu thong tin ]"; // Nút đang được chọn
    }
    else {
        cout << "  Luu thong tin   ";
    }

    // Vẽ nút "Sửa thông tin"
    gotoXY(x2, y);
    if (selected == 2) {
        cout << "[ Sua thong tin ]"; // Nút đang được chọn
    }
    else {
        cout << "  Sua thong tin   ";
    }
}

int handleButtonSelection() {
    int selected = 1; // 1: "Lưu thông tin", 2: "Sửa thông tin"
    char key;

    while (true) {
        // Vẽ các nút, hiển thị trạng thái hiện tại
        drawButtons(selected);

        // Nhập phím từ người dùng
        key = _getch(); // Sử dụng _getch() để bắt phím (cần include <conio.h>)

        if (key == 75) { // Mũi tên trái
            selected = (selected == 1) ? 2 : 1;
        }
        else if (key == 77) { // Mũi tên phải
            selected = (selected == 2) ? 1 : 2;
        }
        else if (key == 13) { // Enter
            return selected; // Trả về lựa chọn
        }
    }
}

// Hàm đếm số ký tự không phải khoảng trắng
int countNonSpaceChars(const string& str) {
    return count_if(str.begin(), str.end(), [](char c) { return !isspace(c); });
}


istream& operator>>(istream& is, User& p) {
    string gtTemp;
    bool valid = false; // Biến kiểm tra tổng thể
    bool validName = false, validBietDanh = false, validGioiTinh = false, validDate = false;

    do {
        system("cls");
        drawInputForm();

        // Nhập họ tên khai sinh
        if (!validName) {
            gotoXY(24, 4);
            getline(is, p.Ten);

            // Kiểm tra tên khai sinh: ít nhất 2 ký tự không phải khoảng trắng
            validName = (countNonSpaceChars(p.Ten) >= 2);
            if (!validName) {
                gotoXY(12, 13);
                cout << "Loi: Ten khai sinh phai co it nhat 2 ky tu";
                gotoXY(24, 4); // Quay lại vị trí nhập tên khai sinh
                cout << string(40, ' '); // Xóa nội dung nhập sai
            }
        }
        else {
            gotoXY(24, 4);
            cout << p.Ten;
        }

        // Nhập biệt danh
        if (!validBietDanh) {
            gotoXY(33, 8);
            getline(is, p.BietDanh);
            validBietDanh = true; // Biệt danh không cần kiểm tra
        }
        else {
            gotoXY(33, 8);
            cout << p.BietDanh;
        }

        // Nhập giới tính
        if (!validGioiTinh) {
            gotoXY(73, 8);
            getline(is, p.GioiTinh);
            gtTemp = p.GioiTinh;
            for (char& c : gtTemp) c = tolower(c); // Chuyển về chữ thường
            validGioiTinh = (gtTemp == "nam" || gtTemp == "nu" || gtTemp == "khac");
            if (!validGioiTinh) {
                gotoXY(12, 14);
                cout << "Loi: Gioi tinh chi duoc la Nam, Nu hoac Khac!";
                gotoXY(73, 8); // Quay lại vị trí nhập giới tính
                cout << string(10, ' '); // Xóa nội dung nhập sai
            }
        }
        else {
            gotoXY(73, 8);
            cout << p.GioiTinh;
        }

        // Nhập ngày, tháng, năm
        if (!validDate) {
            gotoXY(17, 12);
            is >> p.day.ngay;
            gotoXY(47, 12);
            is >> p.day.thang;
            gotoXY(74, 12);
            is >> p.day.nam;

            // Kiểm tra ngày tháng năm hợp lệ
            validDate = isPastOrPresentDate(p.day.ngay, p.day.thang, p.day.nam);
            if (!validDate) {
                gotoXY(12, 14);
                cout << "Loi: Ngay thang nam sinh khong hop le!";
                // Xóa nội dung nhập sai
                gotoXY(17, 12);
                cout << "  ";
                gotoXY(47, 12);
                cout << "  ";
                gotoXY(74, 12);
                cout << "    ";
            }
        }
        else {
            gotoXY(17, 12);
            cout << p.day.ngay;
            gotoXY(47, 12);
            cout << p.day.thang;
            gotoXY(74, 12);
            cout << p.day.nam;
        }

        // Kiểm tra tất cả các trường đã hợp lệ
        valid = validName && validBietDanh && validGioiTinh && validDate;

        if (valid) {
            // Hiển thị các nút
            int action = handleButtonSelection();

            if (action == 1) { // "Lưu thông tin"
                cout << "\nThong tin da duoc luu!";
                break;
            }
            else if (action == 2) { // "Sửa thông tin"
                // Đặt lại trạng thái kiểm tra
                valid = false;
                validName = false;
                validBietDanh = false;
                validGioiTinh = false;
                validDate = false;

                // Xóa bộ nhớ đệm nếu cần (tránh lỗi nhập liệu mới)
                while (is.peek() != '\n' && is.peek() != EOF) {
                    is.get(); // Đọc và bỏ qua từng ký tự trong luồng
                }
                is.get(); // Bỏ ký tự '\n' cuối cùng
            }
        }
    } while (!valid);

    return is;
}


NgaySinh User::getDay(){
    return day;
}

string User::getName(){
    return Ten;
}

string User::getGT() {
    return GioiTinh;
}

string User::getBD() {
    return BietDanh;
}