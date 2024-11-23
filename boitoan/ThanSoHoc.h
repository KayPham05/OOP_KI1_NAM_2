#ifndef THANSOHOCH_H
#define THANSOHOCH_H

#include <iostream>
#include "User.h"
using namespace std;

class ThanSoHoc {
public:
    // Phương thức trừu tượng để giảm số về một chữ số
    int reduceToSingleDigit(int num);

    // Các phương thức ảo mà các lớp con phải cài đặt
    virtual int tinhSo(User& user) = 0;
    virtual void thongTin(User& user) = 0;
};

class SoDuongDoi : public ThanSoHoc {
public:
    int tinhSo(User& user) override;
    void thongTin(User& user) override;
};

// Lớp con LinhHon
class LinhHon : public ThanSoHoc {
public:
    int tinhSo(User& user) override;
    void thongTin(User& user) override;
};

// Lớp con BieuDat
class BieuDat : public ThanSoHoc {
public:
    int tinhSo(User& user) override;
    void thongTin(User& user) override;
};

// Lớp con NhanCach
class NhanCach : public ThanSoHoc {
public:
    int tinhSo(User& user) override;
    void thongTin(User& user) override;
};

#endif // THANSOHOCH_H