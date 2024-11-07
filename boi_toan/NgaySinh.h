#ifndef NGAYSINH_H
#define NGAYSINH_H

struct NgaySinh {
    int ngay, thang, nam;
};

bool isLeapYear(int nam);
bool isValidDate(int ngay, int thang, int nam);

#endif // NGAYSINH_H
