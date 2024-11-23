#include "CungHoangDao.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// Hàm thay ??i màu ch?
void Setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void Openwebsite() {
    // URL of the website
    string url = "https://honghala.com/12-cung-hoang-dao/";
    // Open the URL in the default web browser
    string command = "start " + url;
    system(command.c_str());
}
// Hàm hi?n th? hi?u ?ng nh?p nháy
void CungHoangDao::print(User& user) {
    NgaySinh ngaySinh = user.getDay();
    int ngay = ngaySinh.ngay;
    int thang = ngaySinh.thang;
    string noiDung;

    // Xác ??nh cung hoàng ??o và n?i dung t??ng ?ng
    if ((thang == 3 && ngay >= 21) || (thang == 4 && ngay <= 19)) {
        noiDung =
            "    +-------------------------------------------------------------------------------------+\n"
            "    |                              +=====================+                                |\n"
            "    |                              |  Bach Duong (Aries) |                                |\n"
            "    |                              +=====================+                                |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |  Cung Bach Duong co ten goi tieng Anh la Aries sinh vao khoang thoi gian 21/03      |\n"
            "    |  den 20/04. Nhung nguoi thuoc cung Bach Duong duoc nu than tri tue va chien tranh   |\n"
            "    |  Athena bao ho.                                                                     |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Trong 12 cung hoang dao, Bach Duong noi tieng cho su thang than, don gian, yeu     |\n"
            "    |  thich canh tranh cong bang. Ngoai ra, ho con la nhung nguoi phan dau no luc vi     |\n"
            "    |  muc tieu cua minh. Nhung tiec rang ho khong thuc su nhan nai khi gap kho khan.     |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Voi nguon nang luong doi dao, ho luon co tham vong dung dau trong tap the. Ho cung |\n"
            "    |  mang den nguon nang luong tich cuc, su vui ve cho nhung nguoi xung quanh minh.     |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Diem tru cua Bach Duong chinh la su nong nay, chinh dieu nay se dem lai rac roi.   |\n"
            "    |  Khi tuc gian, Bach Duong chi muon lam theo nhung gi thuoc ve ban nang chu khong    |\n"
            "    |  suy nghi thau dao truoc khi dua ra quyet dinh.                                     |\n"
            "    +-------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 4 && ngay >= 20) || (thang == 5 && ngay <= 20)) {
        noiDung =
            "    +-------------------------------------------------------------------------------------------+\n"
            "    |                              +=====================+                                      |\n"
            "    |                              |  Kim Nguu (Taurus)  |                                      |\n"
            "    |                              +=====================+                                      |\n"
            "    |-------------------------------------------------------------------------------------------|\n"
            "    |  Kim Nguu, ten goi tieng Anh la Taurus, thuoc nhung nguoi sinh tu 21/04 - 20/05.          |\n"
            "    |  Than tinh yeu va sac dep Aphrodite la than bao ho cho mot trong 12 cung hoang dao        |\n"
            "    |  nay.                                                                                     |\n"
            "    |-------------------------------------------------------------------------------------------|\n"
            "    |                                                                                           |\n"
            "    |  Chan thanh va khong tinh toan thiet hon chinh la diem cong cua Kim Nguu. Dieu nay        |\n"
            "    |  khien ho duoc yeu quy va tin tuong cua nhieu nguoi. Ho yeu thich su tu do, phong khoang  |\n"
            "    |  nen nghien ve xu huong nhung cong viec lien quan den nghe thuat.                         |\n"
            "    |-------------------------------------------------------------------------------------------|\n"
            "    |                                                                                           |\n"
            "    |  Tuy nhien, su co chap va cung dau cua Kim Nguu khien ai cung ngan ngam. Kim Nguu         |\n"
            "    |  se khong dong y tiep thu y kien va thuc hien nhung gi minh muon cho den khi di vao       |\n"
            "    |  ngo cuoi moi nhan ra.                                                                    |\n"
            "    +-------------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 5 && ngay >= 21) || (thang == 6 && ngay <= 20)) {
        noiDung =
            "    +-------------------------------------------------------------------------------------+\n"
            "    |                              +===================+                                  |\n"
            "    |                              |   Xu Nu (Virgo)   |                                  |\n"
            "    |                              +===================+                                  |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |  Cung Xu Nu thuoc ve nguoi sinh tu 23/08 - 22/09, co ten tieng Anh la Virgo,        |\n"
            "    |  duoc nu than Demeter bao ho.                                                       |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Cung Xu Nu duoc biet den trong 12 cung hoang dao voi su thong minh, sac sao, ly    |\n"
            "    |  tri va chu toan. Ho luon can than truoc moi quyet dinh dua ra. Ben canh do, cach   |\n"
            "    |  giai quyet van de khon kheo khong lam mat long ai. Xu Nu con duoc biet den la      |\n"
            "    |  nhung nguoi tiet che cam xuc gioi nen luon xuat hien voi hinh anh dam tinh, diu    |\n"
            "    |  dang.                                                                              |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Tuy nhien, mot trong nhung nhuoc diem cua Xu Nu khien nguoi khac met moi do la     |\n"
            "    |  theo duoi su hoan my. Xu Nu yeu thich su tuyet doi nen khong chi yeu cau cao cho   |\n"
            "    |  ban than ma ca nhung nguoi xung quanh.                                             |\n"
            "    +-------------------------------------------------------------------------------------+\n";


    }
    else if ((thang == 6 && ngay >= 21) || (thang == 7 && ngay <= 22)) {
        noiDung = "Cu Giai (Cancer): Cam xuc va tinh cam...";
    }
    else if ((thang == 7 && ngay >= 23) || (thang == 8 && ngay <= 22)) {
        noiDung =
            "    +-------------------------------------------------------------------------------------+\n"
            "    |                              +===================+                                  |\n"
            "    |                              |    Su Tu (Leo)    |                                  |\n"
            "    |                              +===================+                                  |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |  Cung Su Tu thuoc nhung nguoi sinh tu 23/07 - 22/08, cung hoang dao thu 5 trong     |\n"
            "    |  12 cung hoang dao. Su Tu con co ten goi tieng Anh la Leo do than toi cao Zeus bao  |\n"
            "    |  ho.                                                                                |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Mang trong minh hinh anh cua chua te muon loai, khong kho hieu khi Su Tu toat len  |\n"
            "    |  khi chat cua nguoi dan dau. Su Tu co su tu tin bam sinh, tinh cach manh me va doc  |\n"
            "    |  lap cao, khong thich dua dam vao nguoi khac. Ho mang den cho nguoi khac nguon nang |\n"
            "    |  luong tich cuc, khong ngai lan xa. Ngoai ra, Su Tu con la nguoi ban dang tin cay,  |\n"
            "    |  san sang xa than vi ban be.                                                        |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Nhuc diem cua Su Tu chinh la su tu tin thai qua dan den bao thu. Ho san sang dau   |\n"
            "    |  tranh den cung de bao ve quan diem cua minh. Tu do dan den su do vo trong nhieu    |\n"
            "    |  moi quan he khi khong lang nghe y kien tu nguoi khac.                              |\n"
            "    +-------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 8 && ngay >= 23) || (thang == 9 && ngay <= 22)) {
        noiDung = "Xu Nu (Virgo): Chinh xac va can than...";
    }
    else if ((thang == 9 && ngay >= 23) || (thang == 10 && ngay <= 22)) {
        noiDung =
            "    +--------------------------------------------------------------------------------------+\n"
            "    |                              +=====================+                                 |\n"
            "    |                              |  Thien Binh (Libra) |                                 |\n"
            "    |                              +=====================+                                 |\n"
            "    |--------------------------------------------------------------------------------------|\n"
            "    |  Cung Thien Binh thuoc ve nguoi sinh tu 23/09 - 23/10, co ten tieng Anh la Libra,    |\n"
            "    |  duoc su bao ho cua than Hephaestus.                                                 |\n"
            "    |--------------------------------------------------------------------------------------|\n"
            "    |                                                                                      |\n"
            "    |  Nhung nguoi thuoc cung Thien Binh du khong sinh ra voi ve dep noi bat thi cung      |\n"
            "    |  so huu net duyen ngam rat cuon hut. Ho mang den cho nguoi ngoai mot hinh anh luon   |\n"
            "    |  vui ve, nang dong va than thien. It khi thay Thien Binh buon rau vi ho biet cach    |\n"
            "    |  can bang cam xuc ban than.                                                          |\n"
            "    |--------------------------------------------------------------------------------------|\n"
            "    |                                                                                      |\n"
            "    |  Diem tru cua Thien Binh nen duoc nhac toi chinh la su phan van luong lu. Ho hay     |\n"
            "    |  gap phai tinh trang nhu dung giua nga ba duong. Muon lam cai nay nhung lai so vuot  |\n"
            "    |  mat cai kia, cai nao tot hon cai nao… Chi can mot chut cung ran va quyet tam Thiens |\n"
            "    |  Binh se co duoc nhung quyet dinh dung dan cho ban than.                             |\n"
            "    +--------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 10 && ngay >= 23) || (thang == 11 && ngay <= 21)) {
        noiDung =
            "    +-------------------------------------------------------------------------------------+\n"
            "    |                              +======================+                               |\n"
            "    |                              |   Bo Cap (Scorpius)  |                               |\n"
            "    |                              +======================+                               |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |  Cung Bo Cap co ten goi tieng Anh la Scorpius, duoc su bao ho cua than chien tranh  |\n"
            "    |  Ares. Nhung nguoi sinh vao 24/10 - 22/11 thuoc cung Bo Cap.                        |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Cung Bo Cap noi tieng nhat voi su bi an trong 12 cung hoang dao. Day co the la     |\n"
            "    |  diem khien Bo Cap thu hut nguoi khac khi khong the hien qua nhieu cam xuc trong    |\n"
            "    |  moi tinh huong. Tuy nhien ho khong phai co tinh che giau ma do la tinh cach cua    |\n"
            "    |  Bo Cap. Khiem ton, khong on ao, pho truong hay khoe me.                            |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Bo Cap la nhung nguoi kha da nghi va ghen tuong, lai them phan khong the hien cam  |\n"
            "    |  xuc. Do do noi tam da phan phuc tap. Ho hay co don nhung lai chon cach khong muon  |\n"
            "    |  giai bai cung ai.                                                                  |\n"
            "    +-------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 11 && ngay >= 22) || (thang == 12 && ngay <= 21)) {
        noiDung =
            "    +---------------------------------------------------------------------------------------+\n"
            "    |                              +=========================+                              |\n"
            "    |                              |   Nhan Ma (Sagittarius) |                              |\n"
            "    |                              +=========================+                              |\n"
            "    |---------------------------------------------------------------------------------------|\n"
            "    |  Cung Nhan Ma sinh vao 23/11 - 21/12, co ten goi tieng Anh la Sagittarius, duoc       |\n"
            "    |  nu than tho san Artemis bao ho.                                                      |\n"
            "    |---------------------------------------------------------------------------------------|\n"
            "    |                                                                                       |\n"
            "    |  Trong tinh cach cua 12 cung hoang dao, Nhan Ma duoc biet den la nhung nguoi phuong   |\n"
            "    |  khoang va yeu thich su tu do. Ho duoc nhieu nguoi yeu men nho su de dang tha thu     |\n"
            "    |  va khong de bung chuyen gi lau. Hiem co 12 cung hoang dao nao yeu thich su di chuyen |\n"
            "    |  nhu Nhan Ma. Doi voi ho, doi la nhung chuyen di, la kham pha nhung vung dat moi.     |\n"
            "    |---------------------------------------------------------------------------------------|\n"
            "    |                                                                                       |\n"
            "    |  Duoc xem la con ngua bat kham, Nhan Ma de bi nham chan neu phai lap di lap lai mot   |\n"
            "    |  viec gi do. Su tu do, phong khoang khien ho co su dao hoa. Ngoai ra con hay gap      |\n"
            "    |  rac roi voi cac deadline voi su khong tap trung cua minh.                            |\n"
            "    +---------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 12 && ngay >= 22) || (thang == 1 && ngay <= 19)) {
        noiDung =
            "    + -------------------------------------------------------------------------------------+\n"
            "    |                              +========================+                              |\n"
            "    |                              |   Ma Ket (Capricorn)   |                              |\n"
            "    |                              +========================+                              |\n"
            "    |--------------------------------------------------------------------------------------|\n"
            "    |  Cung Ma Ket thuoc ve nhung nguoi sinh tu 22/12 - 19/01, ten goi tieng Anh la        |\n"
            "    |  Capricorn, do Nu than lua Hestia bao ho.                                            |\n"
            "    |--------------------------------------------------------------------------------------|\n"
            "    |                                                                                      |\n"
            "    |  Tinh cach cua 12 cung hoang dao Ma Ket noi bat la su nghiem tuc. Ho nghiem tuc      |\n"
            "    |  trong moi hoan canh, moi viec lam va loi noi. Tu do khien nguoi khac tin tuong      |\n"
            "    |  nhung lai bi cho la kho gan. Tuy kha kiem loi nhung khi than thiet voi ai do,       |\n"
            "    |  Ma Ket san sang bay to moi cam xuc bang loi noi cung nhu hanh dong.                 |\n"
            "    |--------------------------------------------------------------------------------------|\n"
            "    |                                                                                      |\n"
            "    |  Khong kheo an noi, khong biet lua loi nen Ma Ket de bi mat long nguoi khac.         |\n"
            "    |  Lai them phan nghiem tuc nen de lam nguoi khac hieu lam co y xau. Nhung thuc ra Ma  |\n"
            "    |  Ket chi la nhung nguoi khong gioi trong giao tiep ma thoi.                          |\n"
            "    +--------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 1 && ngay >= 20) || (thang == 2 && ngay <= 18)) {
        noiDung =
            "    +-------------------------------------------------------------------------------------+\n"
            "    |                              +========================+                             |\n"
            "    |                              |   Bao Binh (Aquarius)  |                             |\n"
            "    |                              +========================+                             |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |  Cung Bao Binh thuoc ve nhung nguoi sinh tu 20/01 - 18/02, ten goi tieng Anh la     |\n"
            "    |  Aquarius, duoc su bao ho cua than Hera.                                            |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Cung Bao Binh yeu thich su ro rang va khoa hoc. Ho lam gi cung dan do suy nghi,    |\n"
            "    |  phan tich va dan chung day du. Do do ho kha chu toan, quan tam moi thu va luon     |\n"
            "    |  trong trang thai de phong cac kha nang xay ra.                                     |\n"
            "    |-------------------------------------------------------------------------------------|\n"
            "    |                                                                                     |\n"
            "    |  Bao Binh kha kin tieng trong nhung van de ca nhan. It khi thay ho qua than thiet   |\n"
            "    |  voi ai va ho cung khong thich nguoi khac qua than thiet voi minh. Do li tri luon   |\n"
            "    |  dat len tren nen Bao Binh khien nguoi khac cam thay kho khan, khong tinh cam nen   |\n"
            "    |  cac moi quan he de bi pha vo.                                                      |\n"
            "    +-------------------------------------------------------------------------------------+\n";
    }
    else if ((thang == 2 && ngay >= 19) || (thang == 3 && ngay <= 20)) {
        noiDung =
            "    +---------------------------------------------------------------------------------------+\n"
            "    |                              +=====================+                                  |\n"
            "    |                              |  Song Ngu (Pisces)  |                                  |\n"
            "    |                              +=====================+                                  |\n"
            "    |---------------------------------------------------------------------------------------|\n"
            "    |  Cung Song Ngu la cung hoang dao thu 12 trong 12 cung hoang dao, thuoc ve nhung       |\n"
            "    |  nguoi sinh tu 19/02 - 20/03. Song Ngu do vi than bien ca Poseidon la nguoi bao ho.   |\n"
            "    |  Ten goi tieng Anh cua cung Song Ngu la Pisces.                                       |\n"
            "    |---------------------------------------------------------------------------------------|\n"
            "    |                                                                                       |\n"
            "    |  Trong 12 cung hoang dao, Song Ngu duoc noi tieng voi su trong sang, tot bung. Ho     |\n"
            "    |  hay nhun nhuong va cam thong nen rat duoc long nguoi khac. Du so huu nhung tai       |\n"
            "    |  nang dac biet rieng nhung Song Ngu van rat khiem ton, khong hao thang va the hien    |\n"
            "    |  cai toi.                                                                             |\n"
            "    |---------------------------------------------------------------------------------------|\n"
            "    |                                                                                       |\n"
            "    |  Su trong sang lai hay di kem voi mo mong, Song Ngu thuong dam chim vao the gioi      |\n"
            "    |  cua rieng minh. Do do khi gap van de, Song Ngu rat de khoc va tut cam xuc. Ho con    |\n"
            "    |  rat hay bi nguoi khac loi dung vi long tot cua minh do khong biet cach tu choi.      |\n"
            "    |---------------------------------------------------------------------------------------|\n"
            "    |                                                                                       |\n"
            "    |  Tinh cach cua 12 cung hoang dao chi the hien phan lon dac diem chung trong cung,     |\n"
            "    |  chua di chi tiet vao tung ca nhan. Hy vong ban co the tham khao va nhin nhan lai     |\n"
            "    |  de biet cach tan dung va khac che diem manh diem yeu cua ban than de phat trien hon. |\n"
            "    +---------------------------------------------------------------------------------------+\n";
    }
    else {
        noiDung = "Ngay thang khong hop le!";
    }

    // Vòng l?p nh?p nháy
    int colors[] = { 12, 14, 10, 11, 13 }; // ??, Vàng, Xanh lá, Xanh l?, H?ng
    int numColors = sizeof(colors) / sizeof(colors[0]);

    // Vòng l?p nh?p nháy
    for (int i = 0; i < 10; i++) {
        system("cls"); // Xóa màn hình ?? t?o hi?u ?ng
        Setcolor(colors[i % numColors]); // Ch?n màu theo th? t? trong m?ng
        cout << noiDung << endl;
        cout << "+-----------------------------------------------+" << endl;
        cout << "|    https://honghala.com/12-cung-hoang-dao/    |" << endl;
        cout << "+-----------------------------------------------+" << endl;// Hi?n th? n?i dung
        Sleep(500); // D?ng 0.5 giây
    }


    Setcolor(7); // Reset v? màu m?c ??nh
}
