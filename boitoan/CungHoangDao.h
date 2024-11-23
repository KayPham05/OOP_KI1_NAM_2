#ifndef CUNGHOANGDAO_H
#define CUNGHOANGDAO_H

#include <string>
#include "User.h"
using namespace std;

class CungHoangDao : public User {
private:
    string TenCungHoangDao;      // T�n cung ho�ng ??o
    string YNgiaCungHoangDao;    // � ngh?a c?a cung ho�ng ??o

public:
    // Constructor
    CungHoangDao(string tenCungHoangDao = "", string yNgiaCungHoangDao = "");

    // Setters
    void setTenCung(string tenCung);
    void setYNgia(string yNghia);

    // Getters
    string getTenCung() const;
    string getYNgia() const;

    // H�m hi?n th? th�ng tin cung ho�ng ??o
    void Display(User& user) ;

    // H�m x�c ??nh cung ho�ng ??o t? ng�y sinh
    void determineCungHoangDao(int ngay, int thang, string& tenCung, string& yNghia);
};

#endif // CUNGHOANGDAO_H
