#include "NgaySinh.h"

bool isLeapYear(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

bool isValidDate(int ngay, int thang, int nam) {
    if (thang < 1 || thang > 12) return false;
    
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (thang == 2 && isLeapYear(nam)) {
        daysInMonth[1] = 29;
    }
    
    return (ngay >= 1 && ngay <= daysInMonth[thang - 1]);
}
