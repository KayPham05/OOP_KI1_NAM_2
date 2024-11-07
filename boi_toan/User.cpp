#include "User.h"
#include "NgaySinh.h"
#include "CungHoangDao.h"
#include "ThanSoHoc.h"
#include <fstream>
#include <ctime>

User::User(){}

istream& operator>>(istream &is, User &p) {
    // Nhập thông tin người dùng từ bàn phím
    cout << "Nhap ten cua ban: ";
    getline(is, p.Ten);
    cout << "Nhap vao gioi tinh cua ban (nam/nu)\n";
    getline(cin, p.GioiTinh);
    while (p.GioiTinh != "nam" && p.GioiTinh != "nu") {
        cout << "Gioi tinh ban nhap khong hop le. Moi nhap lai!\n";
        cout << "Nhap vao gioi tinh cua ban (nam/nu)\n";
        getline(is, p.GioiTinh); 
    }

    cout << "Nhap vao nam sinh cua ban: ";
    is >> p.day.nam;
    while (p.day.nam <= 0) {
        cout << "Ban sinh truoc Cong Nguyen ha? Moi nhap lai!\n";
        cout << "Nhap vao nam sinh cua ban: ";
        is >> p.day.nam;
    }

    cout << "Nhap vao thang sinh cua ban: ";
    is >> p.day.thang;
    while (p.day.thang < 1 || p.day.thang > 12) {
        cout << "Thang sinh ban nhap vao khong hop le. Moi nhap lai!\n";
        cout << "Nhap vao thang sinh cua ban: ";
        is >> p.day.thang;
    }

    cout << "Nhap vao ngay sinh cua ban: ";
    is >> p.day.ngay;
    while (!isValidDate(p.day.ngay, p.day.thang, p.day.nam)) {
        cout << "Ngay sinh khong hop le. Moi nhap lai!\n";
        cout << "Nhap vao ngay sinh cua ban: ";
        is >> p.day.ngay;
    }

    // Lưu thông tin người dùng vào file
    ofstream outFile("thong_tin_nguoi_dung.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Ten: " << p.Ten << ", Ngay Sinh: " << p.day.ngay << "/" << p.day.thang << "/" << p.day.nam << ", Gioi Tinh: " << p.GioiTinh << endl;
        outFile.close();
        cout << "Thong tin da duoc luu lai!" << endl;
    } else {
        cout << "Khong the mo file!" << endl;
    }
    return is;
}

void User::output() {
    cout << "Ten: " << Ten << ", Ngay Sinh: " << day.ngay << "/" << day.thang << "/" << day.nam << ", Gioi Tinh: " << GioiTinh << endl;
}

void User::readFromFile() {
    ifstream inFile("thong_tin_nguoi_dung.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Khong the mo file!" << endl;
    }
}

int User::calculateAge() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    int age = currentYear - day.nam;
    if (currentMonth < day.thang || (currentMonth == day.thang && currentDay < day.ngay)) {
        age--;
    }
    return age;
}

NgaySinh User::getDay(){
    return day;
}
