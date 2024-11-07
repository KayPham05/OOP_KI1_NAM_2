#ifndef THANSOHOCH_H
#define THANSOHOCH_H

#include <iostream>
#include "User.h"
using namespace std;

class ThanSoHoc : public User{
    public:
        ThanSoHoc() : User() {}
    void display(User& user);
    int calculateNumerology(User& user);
};

#endif // THANSOHOCH_H
