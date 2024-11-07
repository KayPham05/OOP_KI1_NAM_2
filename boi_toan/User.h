#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "NgaySinh.h" 

using namespace std;

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
    int calculateAge();
    NgaySinh getDay();
};

#endif 
