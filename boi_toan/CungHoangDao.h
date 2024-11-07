#ifndef CUNGHOANGDAO_H
#define CUNGHOANGDAO_H

#include <string>
#include "User.h"
using namespace std;

class CungHoangDao : public User{
    public:
    CungHoangDao():User(){}
    void print(User& user);
};

#endif 
