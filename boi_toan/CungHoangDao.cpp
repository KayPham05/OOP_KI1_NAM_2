#include "CungHoangDao.h"
#include "User.h"

void CungHoangDao::print(User& user)  {
    NgaySinh ngaySinh = user.getDay();  // Sử dụng getDay() từ lớp User
    int ngay = ngaySinh.ngay;
    int thang = ngaySinh.thang;
    if ((thang == 3 && ngay >= 21) || (thang == 4 && ngay <= 19)) {
        cout << "Bach Duong (Aries): Cung hoang dao thuoc nguyen to Lua, tuoi tre, nang dong, voi tinh cach kiem soat, thich thu thach. Bach Duong thuong chu dong, dap da trong nhung hoat dong, la nguoi linh hoat, dai dien cho suc manh va su qua quyet.";
    } else if ((thang == 4 && ngay >= 20) || (thang == 5 && ngay <= 20)) {
        cout << "Kim Nguu (Taurus): Cung hoang dao thuoc nguyen to Dat, ton trong gia dinh va truyen thong, yeu su an toan, yeu thuong cuoc song mat chat. Kim Nguu trung thanh, can cu, doi song chan thanh va de dat ra muc tieu.";
    } else if ((thang == 5 && ngay >= 21) || (thang == 6 && ngay <= 20)) {
        cout << "Song Tu (Gemini): Cung hoang dao thuoc nguyen to Khong Khi, di chuyen nhanh, linh hoat, giao tiep gioi. Song Tu hieu nhieu ve nhung moi quan he, thich chia se thong tin, mang kha nang doc dao va hieu suong.";
    } else if ((thang == 6 && ngay >= 21) || (thang == 7 && ngay <= 22)) {
        cout << "Cu Giai (Cancer): Cung hoang dao thuoc nguyen to Nuoc, tinh cam, yeu thuong gia dinh, nha cua. Cu Giai duoc danh gia cao ve su chu dao va bao ve gia dinh.";
    } else if ((thang == 7 && ngay >= 23) || (thang == 8 && ngay <= 22)) {
        cout << "Su Tu (Leo): Cung hoang dao thuoc nguyen to Lua, dai dien cho quyen luc va su lanh dao. Su Tu manh me, tu tin, luon thich lam trung tam chu y, day tham vong va khao khat thanh cong.";
    } else if ((thang == 8 && ngay >= 23) || (thang == 9 && ngay <= 22)) {
        cout << "Xu Nu (Virgo): Cung hoang dao thuoc nguyen to Dat, tinh vi, ti mi, am hieu viec. Xu Nu thich doi hoan hao, soi moi, khong thich phung phi hay lo lang vo ich.";
    } else if ((thang == 9 && ngay >= 23) || (thang == 10 && ngay <= 22)) {
        cout << "Thien Binh (Libra): Cung hoang dao thuoc nguyen to Khong Khi, thich su can bang, hoa hop. Thien Binh duyen dang, hoa dong va yeu hoa giai moi tranh chap.";
    } else if ((thang == 10 && ngay >= 23) || (thang == 11 && ngay <= 21)) {
        cout << "Bo Cap (Scorpio): Cung hoang dao thuoc nguyen to Nuoc, co tinh cam sau sac va day bi an. Bo Cap co tinh than manh me, dai dien cho su khong chiu khuat phuc.";
    } else if ((thang == 11 && ngay >= 22) || (thang == 12 && ngay <= 21)) {
        cout << "Nhan Ma (Sagittarius): Cung hoang dao thuoc nguyen to Lua, vui ve, linh hoat, thich du lich, khao khat kien thuc. Nhan Ma yeu tu do, toan tam khai pha nhung dieu moi trong cuoc song.";
    } else if ((thang == 12 && ngay >= 22) || (thang == 1 && ngay <= 19)) {
        cout << "Ma Ket (Capricorn): Cung hoang dao thuoc nguyen to Dat, kien tri, tham vong cao, dai dien cho su can cu vung chac. Ma Ket xay dung ke hoach lau dai va co kha nang dieu hanh cong viec hieu qua.";
    } else if ((thang == 1 && ngay >= 20) || (thang == 2 && ngay <= 18)) {
        cout << "Bao Binh (Aquarius): Cung hoang dao thuoc nguyen to Khong Khi, doc lap, thich doi moi. Bao Binh co tri tue sac ben, sang tao, va mang tu tuong tien tien, thich the hien quan diem ca nhan.";
    } else if ((thang == 2 && ngay >= 19) || (thang == 3 && ngay <= 20)) {
        cout << "Song Ngu (Pisces): Cung hoang dao thuoc nguyen to Nuoc, tinh te, cam xuc, day sang tao. Song Ngu co truc giac manh me, nhay cam voi cam xuc cua nguoi khac, thich tim kiem su hoa binh va su yen tinh trong cuoc song.";
    } else {
        cout << "Ngay thang khong hop le";
    }
}
