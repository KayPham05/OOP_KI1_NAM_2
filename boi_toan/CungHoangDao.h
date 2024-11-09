#ifndef CUNGHOANGDAO_H
#define CUNGHOANGDAO_H

#include <string>
#include "User.h"
#include "Boi.cpp"
using namespace std;

class CungHoangDao : public Boi {
    public:
    void print(User& user);
};

#endif 
