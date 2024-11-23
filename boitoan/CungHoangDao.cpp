#include "CungHoangDao.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <ctime>
#include "Tarot.h"
#include <conio.h>
#include "User.h"

using namespace std;

// Hàm thay đổi màu chữ
void setColor3(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Hàm di chuyển con trỏ đến vị trí (x, y)
void gotoXY1(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm mở website
void Openwebsite() {
    string url = "https://honghala.com/12-cung-hoang-dao/";
    string command = "start " + url;
    system(command.c_str());
}

// Hàm vẽ khung
void drawBox1(int x, int y, int width, int height, int color) {
    setColor3(color);
    gotoXY1(x, y);
    cout << char(201); // Góc trên trái
    gotoXY1(x + width, y);
    cout << char(187); // Góc trên phải
    gotoXY1(x, y + height);
    cout << char(200); // Góc dưới trái
    gotoXY1(x + width, y + height);
    cout << char(188); // Góc dưới phải

    // Vẽ cạnh trên và dưới
    for (int i = 1; i < width; i++) {
        gotoXY1(x + i, y);
        cout << char(205); // Ký tự ngang
        gotoXY1(x + i, y + height);
        cout << char(205); // Ký tự ngang
    }

    // Vẽ cạnh trái và phải
    for (int i = 1; i < height; i++) {
        gotoXY1(x, y + i);
        cout << char(186); // Ký tự dọc
        gotoXY1(x + width, y + i);
        cout << char(186); // Ký tự dọc
    }

    setColor3(7); // Trả về màu mặc định
}

// Hiển thị thông tin cung hoàng đạo
void CungHoangDao::Display(User & user) const  {
    vector<int> colors = { 9, 10, 11, 12, 13, 14 }; // Mảng màu
    int colorIndex = 0;
    int ngay = user.getDay().ngay;
    int thang = user.getDay().thang;
    string tenCung, yNghia;

    determineCungHoangDao(ngay, thang, tenCung, yNghia);

    while (true) {
        system("cls");
      
        int color1 = colors[colorIndex % colors.size()];
        int color2 = colors[(colorIndex + 1) % colors.size()];
        int color3 = colors[(colorIndex + 2) % colors.size()];
        int textColor = colors[(colorIndex + 3) % colors.size()];

        // Vẽ khung
        drawBox1(15, 2, 74, 30, color1);
        drawBox1(25, 4, 54, 2, textColor);
        drawBox1(27, 10, 49, 20, color2); // Khung nhỏ 1


        // Hiển thị nội dung
        setColor3(textColor);
        gotoXY1(44, 5);
        cout << TenCungHoangDao;

        gotoXY1(44, 14);
        cout << YNgiaCungHoangDao;

        setColor3(7);

        Sleep(800);
        colorIndex++;

        if (_kbhit()) {
            char key = _getch();
            if (key == '\r') {
                break;
            }
        }
    }
}

CungHoangDao::CungHoangDao(string tenCungHoangDao, string yNgiaCungHoangDao)
    : TenCungHoangDao(tenCungHoangDao), YNgiaCungHoangDao(yNgiaCungHoangDao) {
}

// Setters
void CungHoangDao::setTenCung(string tenCung) {
    TenCungHoangDao = tenCung;
}

void CungHoangDao::setYNgia(string yNgia) {
    YNgiaCungHoangDao = yNgia;
}

// Getters
string CungHoangDao::getTenCung() const {
    return TenCungHoangDao;
}

string CungHoangDao::getYNgia() const {
    return YNgiaCungHoangDao;
}

// Hàm xác định cung hoàng đạo
void CungHoangDao::determineCungHoangDao(int ngay, int thang, string& tenCung, string& yNghia) {
    if ((thang == 3 && ngay >= 21) || (thang == 4 && ngay <= 19)) {
        tenCung = "Bạch Dương";
        yNghia = "Người tiên phong, mạnh mẽ và đầy tham vọng.";
    }
    else if ((thang == 4 && ngay >= 20) || (thang == 5 && ngay <= 20)) {
        tenCung = "Kim Ngưu";
        yNghia = "Kiên nhẫn, thực tế và đáng tin cậy.";
    }
    else if ((thang == 5 && ngay >= 21) || (thang == 6 && ngay <= 20)) {
        tenCung = "Song Tử";
        yNghia = "Thông minh, nhanh nhạy, dễ thích nghi.";
    }
    else if ((thang == 6 && ngay >= 21) || (thang == 7 && ngay <= 22)) {
        tenCung = "Cự Giải";
        yNghia = "Nhạy cảm, đầy tình cảm, bảo vệ gia đình.";
    }
    else if ((thang == 7 && ngay >= 23) || (thang == 8 && ngay <= 22)) {
        tenCung = "Sư Tử";
        yNghia = "Tự tin, mạnh mẽ, thích lãnh đạo.";
    }
    else if ((thang == 8 && ngay >= 23) || (thang == 9 && ngay <= 22)) {
        tenCung = "Xử Nữ";
        yNghia = "Chăm chỉ, tỉ mỉ, yêu thích sự hoàn hảo.";
    }
    else if ((thang == 9 && ngay >= 23) || (thang == 10 && ngay <= 22)) {
        tenCung = "Thiên Bình";
        yNghia = "Công bằng, hòa đồng, thích sự cân bằng.";
    }
    else if ((thang == 10 && ngay >= 23) || (thang == 11 && ngay <= 21)) {
        tenCung = "Bọ Cạp";
        yNghia = "Đam mê, kiên định, bí ẩn.";
    }
    else if ((thang == 11 && ngay >= 22) || (thang == 12 && ngay <= 21)) {
        tenCung = "Nhân Mã";
        yNghia = "Lạc quan, yêu tự do, thích phiêu lưu.";
    }
    else if ((thang == 12 && ngay >= 22) || (thang == 1 && ngay <= 19)) {
        tenCung = "Ma Kết";
        yNghia = "Chăm chỉ, có mục tiêu, kiên định.";
    }
    else if ((thang == 1 && ngay >= 20) || (thang == 2 && ngay <= 18)) {
        tenCung = "Bảo Bình";
        yNghia = "Sáng tạo, độc lập, tư duy sáng suốt.";
    }
    else if ((thang == 2 && ngay >= 19) || (thang == 3 && ngay <= 20)) {
        tenCung = "Song Ngư";
        yNghia = "Mơ mộng, nhạy cảm, giàu cảm xúc.";
    }
}
