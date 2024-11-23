#ifndef CUNGHOANGDAO_H
#define CUNGHOANGDAO_H

#include <string>
#include "User.h"
using namespace std;

class CungHoangDao : public User {
private:
    string TenCungHoangDao;      // Tên cung hoàng ??o
    string YNgiaCungHoangDao;    // Ý ngh?a c?a cung hoàng ??o

public:
    // Constructor
    CungHoangDao(string tenCungHoangDao = "", string yNgiaCungHoangDao = "");

    // Setters
    void setTenCung(string tenCung);
    void setYNgia(string yNghia);

    // Getters
    string getTenCung() const;
    string getYNgia() const;

    // Hàm hi?n th? thông tin cung hoàng ??o
    void Display(User& user) ;

    // Hàm xác ??nh cung hoàng ??o t? ngày sinh
    void determineCungHoangDao(int ngay, int thang, string& tenCung, string& yNghia);
};

#endif // CUNGHOANGDAO_H
