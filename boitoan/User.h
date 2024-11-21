#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>


using namespace std;

struct NgaySinh {
    int ngay, thang, nam;
};

bool isLeapYear(int nam);
bool isValidDate(int ngay, int thang, int nam);
class User {
private:
    string Ten;
    string GioiTinh;
    NgaySinh day;

public:
    User();
    friend istream& operator>>(istream &is, User &p);
    void output();
    void readFromFile();
    NgaySinh getDay();
    string getName();
    string getGT();
};

#endif 
