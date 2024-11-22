#include "User.h"
#include <fstream>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <limits>
#include <vector>

void setColor1(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
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

//giới hạn kí tự 
string inputWithLimit(int limit) {
    string result = "";
    char ch;

    while (true) {
        ch = _getch(); // Đọc một ký tự

        // Kiểm tra nếu nhấn Enter
        if (ch == '\r') {
            break;
        }

        // Kiểm tra nếu nhấn Backspace
        if (ch == '\b' && !result.empty()) {
            result.pop_back();          // Xóa ký tự cuối
            cout << "\b \b";            // Xóa hiển thị trên màn hình
        }
        // Kiểm tra số ký tự nhập vào, chỉ cho phép nhập nếu chưa đạt giới hạn
        else if (result.length() < limit && isprint(ch)) {
            result += ch;               // Thêm ký tự vào chuỗi
            cout << ch;                 // Hiển thị ký tự
        }
        // Nếu đã đạt giới hạn, không cho nhập thêm (bỏ qua ký tự)
    }
    return result;
}
string inputNumberWithLimit(int limit) {
    string result = "";
    char ch;

    while (true) {
        ch = _getch(); // Đọc một ký tự

        // Nhấn Enter để hoàn thành
        if (ch == '\r') {
            break;
        }

        // Nhấn Backspace
        if (ch == '\b' && !result.empty()) {
            result.pop_back();          // Xóa ký tự cuối
            cout << "\b \b";            // Xóa hiển thị trên màn hình
        }
        // Chỉ cho phép nhập số và giới hạn số ký tự
        else if (result.length() < limit && isdigit(ch)) {
            result += ch;               // Thêm ký tự vào chuỗi
            cout << ch;                 // Hiển thị ký tự
        }
    }
    return result;
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



void drawBox(int x, int y, int width, int height, int borderColor, int bgColor = 7) {
    // Đặt màu cho khung
    setColor1(borderColor);

    // Vẽ góc khung
    gotoXY(x, y);
    cout << char(201); // Góc trên trái
    gotoXY(x + width, y);
    cout << char(187); // Góc trên phải
    gotoXY(x, y + height);
    cout << char(200); // G�c d�?i tr�i
    gotoXY(x + width, y + height);
    cout << char(188); // G�c d�?i ph?i

    // Vẽ cạnh trên và dưới
    for (int i = 1; i < width; i++) {
        gotoXY(x + i, y);
        cout << char(205); // K? t? ngang
        gotoXY(x + i, y + height);
        cout << char(205); // K? t? ngang
    }

    // Vẽ cạnh trái và phải
    for (int i = 1; i < height; i++) {
        gotoXY(x, y + i);
        cout << char(186); // K? t? d?c
        gotoXY(x + width, y + i);
        cout << char(186); // K? t? d?c
    }

    // Tô nền bên trong khung (nếu cần)
    if (bgColor != 7) {
        setColor1(bgColor);
        for (int i = 1; i < height; i++) {
            for (int j = 1; j < width; j++) {
                gotoXY(x + j, y + i);
                cout << " "; // Vẽ nền bên trong khung
            }
        }
        setColor1(borderColor); // Đặt lại màu khung
    }
    setColor1(7); // Khôi phục màu mặc định
}


    //gotoXY(x, y);
    //cout << char(201); // G�c tr�n tr�i
    //gotoXY(x + width, y);
    //cout << char(187); // G�c tr�n ph?i
    //gotoXY(x, y + height);
    //cout << char(200); // G�c d�?i tr�i
    //gotoXY(x + width, y + height);
    //cout << char(188); // G�c d�?i ph?i

    //// V? c?nh tr�n v� c?nh d�?i
    //for (int i = 1; i < width; i++) {
    //    gotoXY(x + i, y);
    //    cout << char(205); // K? t? ngang
    //    gotoXY(x + i, y + height);
    //    cout << char(205); // K? t? ngang
    //}

    //// V? c?nh tr�i v� c?nh ph?i
    //for (int i = 1; i < height; i++) {
    //    gotoXY(x, y + i);
    //    cout << char(186); // K? t? d?c
    //    gotoXY(x + width, y + i);
    //    cout << char(186); // K? t? d?c
    //}
    //setColor1(7);

void drawInputForm() {

    gotoXY(41, 2);
    setColor1(14);
    cout << "NHAP THONG TIN CA NHAN";
    drawBox(16, 1, 74, 3, 11);
    drawBox(6, 4, 94, 23, 11);
    gotoXY(16, 4);
    setColor1(11);
    cout << char(202);
    gotoXY(90, 4);
    cout << char(202);
    setColor1(7);
    // V? khung v� ti�u �? cho t?ng ph?n nh?p
    gotoXY(10, 6);
    cout << "Ho ten khai sinh:";
    drawBox(10, 7, 86, 2, 13); // Khung nh?p h? t�n khai sinh
    gotoXY(12, 8);
    cout << "Nhap ho ten: ";
    gotoXY(24, 8);
    cout << string(40, ' '); // V�ng nh?p li?u
    gotoXY(10, 10);
    cout << "Ten thuong dung neu co (VD: Louis Pham)";
    drawBox(10, 11, 50, 2, 10); // Khung nh?p t�n th�?ng d�ng
    gotoXY(12, 12);
    cout << "Nhap ten thuong dung: ";
    gotoXY(33, 12);
    cout << string(20, ' '); // V�ng nh?p li?u

    drawBox(61, 11, 35, 2, 14); // Khung nh?p t�n th�?ng d�ng
    gotoXY(63, 12);
    cout << "Gioi tinh: ";
    gotoXY(82, 12);
    cout << "(Nam/Nu/Khac)";
    gotoXY(73, 12);
    cout << string(4, ' '); // V�ng nh?p li?u
    gotoXY(10, 14);
    cout << "Ngay/thang/nam sinh duong lich:";
    drawBox(10, 15, 28, 2, 11);
    gotoXY(12, 16);
    cout << "Ngay:";
    gotoXY(17, 16);
    cout << string(2, ' ');
    drawBox(39, 15, 28, 2, 12);
    gotoXY(41, 16);
    cout << "Thang:";
    gotoXY(47, 16);
    cout << string(2, ' ');
    drawBox(68, 15, 28, 2, 9);
    gotoXY(70, 16);
    cout << "Nam:";
    gotoXY(74, 16);
    cout << string(4, ' ');

}

void drawButtons(int selected) {
    // Vị trí các nút
    int x1 = 30, x2 = 50, y = 23;

    // Màu nút đang chọn và không chọn
    int selectedColor = 14;  // Màu vàng
    int defaultColor = 7;    // Màu trắng

    // Vẽ nút "Lưu thông tin"
    gotoXY(x1, y);
    if (selected == 1) {
        setColor1(selectedColor);  // Đổi màu nút được chọn
        cout << "[ Luu thong tin ]";
    }
    else {
        setColor1(defaultColor);  // Đổi màu nút không được chọn
        cout << "  Luu thong tin   ";
    }

    // Vẽ nút "Sửa thông tin"
    gotoXY(x2, y);
    if (selected == 2) {
        setColor1(selectedColor);  // Đổi màu nút được chọn
        cout << "[ Sua thong tin ]";
    }
    else {
        setColor1(defaultColor);  // Đổi màu nút không được chọn
        cout << "  Sua thong tin   ";
    }

    // Reset lại màu sắc về mặc định
    setColor1(7);
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
        int coutTmp1 = 0;
        int coutTmp2 = 0;
        int coutTmp3 = 0;
        system("cls");
        drawInputForm();

        // Nhập họ tên khai sinh
        if (!validName) {
            gotoXY(24, 8);
            p.Ten = inputWithLimit(40); // Giới hạn 40 ký tự

            // Kiểm tra tên khai sinh: ít nhất 2 ký tự không phải khoảng trắng
            validName = (countNonSpaceChars(p.Ten) >= 2);
            if (!validName) {
                coutTmp1 = 1;
                gotoXY(12, 18);
                cout << "Loi: Ten khai sinh phai co it nhat 2 ky tu";
                gotoXY(24, 8); // Quay lại vị trí nhập tên khai sinh
                cout << string(40, ' '); // Xóa nội dung nhập sai
            }
        }
        else {
            gotoXY(24, 8);
            cout << p.Ten;
        }

        // Nhập biệt danh
        if (!validBietDanh) {
            gotoXY(33, 12);
            p.BietDanh = inputWithLimit(20); // Giới hạn 20 ký tự
            validBietDanh = true; // Biệt danh không cần kiểm tra
        }
        else {
            gotoXY(33, 12);
            cout << p.BietDanh;
        }

        // Nhập giới tính
        if (!validGioiTinh) {
            gotoXY(73, 12);
            p.GioiTinh = inputWithLimit(4); // Giới hạn 4 ký tự
            gtTemp = p.GioiTinh;
            for (char& c : gtTemp) c = tolower(c); // Chuyển về chữ thường
            validGioiTinh = (gtTemp == "nam" || gtTemp == "nu" || gtTemp == "khac");
            if (!validGioiTinh) {
                if (coutTmp1 == 1) {
                    coutTmp2 = 1;
                    gotoXY(12, 19);
                    cout << "Loi: Gioi tinh chi duoc la Nam, Nu hoac Khac!";
                    gotoXY(73, 10); // Quay lại vị trí nhập giới tính
                    cout << string(10, ' '); // Xóa nội dung nhập sai
                }
                else {
                    coutTmp2 = 1;
                    gotoXY(12, 18);
                    cout << "Loi: Gioi tinh chi duoc la Nam, Nu hoac Khac!";
                    gotoXY(73, 12); // Quay lại vị trí nhập giới tính
                    cout << string(10, ' '); // Xóa nội dung nhập sai
                }

            }
        }
        else {
            gotoXY(73, 12);
            cout << p.GioiTinh;
        }

        // Nhập ngày, tháng, năm
        if (!validDate) {
            gotoXY(17, 16);
            string ngayStr = inputNumberWithLimit(2);
            p.day.ngay = stoi(ngayStr); // Chuyển từ chuỗi sang số
            gotoXY(47, 16);
            string thangStr = inputNumberWithLimit(2);
            p.day.thang = stoi(thangStr);
            gotoXY(74, 16);
            string namStr = inputNumberWithLimit(4);
            p.day.nam = stoi(namStr);

            // Kiểm tra ngày tháng năm hợp lệ
            validDate = isPastOrPresentDate(p.day.ngay, p.day.thang, p.day.nam);
            if (!validDate) {
                if (coutTmp1 == 1 && coutTmp2 == 1) {
                    gotoXY(12, 20);
                    cout << "Loi: Ngay thang nam sinh khong hop le!";
                    // Xóa nội dung nhập sai
                    gotoXY(17, 16);
                    cout << "  ";
                    gotoXY(47, 16);
                    cout << "  ";
                    gotoXY(74, 16);
                    cout << "    ";
                }
                else if (coutTmp1 == 1 || coutTmp2 == 1) {
                    gotoXY(12, 19);
                    cout << "Loi: Ngay thang nam sinh khong hop le!";
                    // Xóa nội dung nhập sai
                    gotoXY(17, 16);
                    cout << "  ";
                    gotoXY(47, 16);
                    cout << "  ";
                    gotoXY(74, 16);
                    cout << "    ";
                }
                else {
                    gotoXY(12, 18);
                    cout << "Loi: Ngay thang nam sinh khong hop le!";
                    // Xóa nội dung nhập sai
                    gotoXY(17, 16);
                    cout << "  ";
                    gotoXY(47, 16);
                    cout << "  ";
                    gotoXY(74, 16);
                    cout << "    ";
                }
                gotoXY(24, 21);
                cout << "Nhan phim bat ky de nhap lai...";
                char tempKey = _getch();
            }
        }
        else {
            gotoXY(17, 14);
            cout << p.day.ngay;
            gotoXY(47, 14);
            cout << p.day.thang;
            gotoXY(74, 14);
            cout << p.day.nam;
        }

        // Kiểm tra tất cả các trường đã hợp lệ
        valid = validName && validBietDanh && validGioiTinh && validDate;

        if (valid) {
            // Hiển thị các nút
            int action = handleButtonSelection();
            if (action == 1) { // "Lưu thông tin"
                gotoXY(40, 25);
                setColor1(12);
                cout << "THONG TIN DA DUOC LUU!";
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