#include "User.h"
#include "ThanSoHoc.h"
#include "CungHoangDao.h"
int main() {
    ThanSoHoc t;
    CungHoangDao d;
    User user;
    cin >> user;
    user.output();
    cout << "Tuoi cua ban: " << user.calculateAge() << endl;
    cout<<user.getDay().ngay<<"++"<<user.getDay().thang<<endl;
    t.display(user);
    d.print(user);
    return 0;
}
