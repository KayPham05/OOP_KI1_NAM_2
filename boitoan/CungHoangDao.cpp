#include "CungHoangDao.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <ctime>
#include "Tarot.h"
#include <conio.h>
#include "User.h"

using namespace std;

// Hàm thay đổi màu chữ
void setColor3(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Hàm di chuyển con trỏ đến vị trí (x, y)
void gotoXY1(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm mở website
void Openwebsite() {
    string url = "https://honghala.com/12-cung-hoang-dao/";
    string command = "start " + url;
    system(command.c_str());
}

// Hàm vẽ khung
void drawBox1(int x, int y, int width, int height, int color) {
    setColor3(color);
    gotoXY1(x, y);
    cout << char(201); // Góc trên trái
    gotoXY1(x + width, y);
    cout << char(187); // Góc trên phải
    gotoXY1(x, y + height);
    cout << char(200); // Góc dưới trái
    gotoXY1(x + width, y + height);
    cout << char(188); // Góc dưới phải

    // Vẽ cạnh trên và dưới
    for (int i = 1; i < width; i++) {
        gotoXY1(x + i, y);
        cout << char(205); // Ký tự ngang
        gotoXY1(x + i, y + height);
        cout << char(205); // Ký tự ngang
    }

    // Vẽ cạnh trái và phải
    for (int i = 1; i < height; i++) {
        gotoXY1(x, y + i);
        cout << char(186); // Ký tự dọc
        gotoXY1(x + width, y + i);
        cout << char(186); // Ký tự dọc
    }

    setColor3(7); // Trả về màu mặc định
}
void printWithLineBreaks1(const string& text, int maxCharsPerLine, int x, int y) {
    int currentLineLength = 0; // Độ dài dòng hiện tại
    string currentWord;        // Từ hiện tại đang xử lý
    int currentY = y;          // Vị trí dòng y hiện tại

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (c == ' ' || i == text.length() - 1) {
            // Thêm ký tự cuối nếu là ký tự cuối cùng
            if (i == text.length() - 1 && c != ' ') {
                currentWord += c;
            }

            // Nếu từ hiện tại không vừa dòng, xuống dòng
            if (currentLineLength + currentWord.length() > maxCharsPerLine) {
                currentY++;                 // Tăng dòng
                currentLineLength = 0;      // Đặt lại độ dài dòng
                gotoXY(x, currentY);        // Di chuyển con trỏ đến đầu dòng mới
            }

            // In từ hiện tại
            if (currentLineLength > 0) {
                cout << " ";                // Thêm khoảng cách giữa các từ
                currentLineLength++;
            }
            cout << currentWord;            // In từ
            currentLineLength += currentWord.length();
            currentWord.clear();
        }
        else {
            // Ghép ký tự vào từ hiện tại
            currentWord += c;
        }
    }
}



// Hiển thị thông tin cung hoàng đạo
void CungHoangDao::Display(User& user) {
    vector<int> colors = { 9, 10, 11, 12, 13, 14 }; // Mảng màu
    int colorIndex = 0;
    int ngay = user.getDay().ngay;
    int thang = user.getDay().thang;

    string tenCung, yNghia;
    determineCungHoangDao(ngay, thang, tenCung, yNghia); // Xác định cung hoàng đạo

    while (true) {
        system("cls");

        int color1 = colors[colorIndex % colors.size()];
        int color2 = colors[(colorIndex + 1) % colors.size()];
        int color3 = colors[(colorIndex + 2) % colors.size()];
        int textColor = colors[(colorIndex + 3) % colors.size()];

        // Vẽ khung
        drawBox1(15, 2, 74, 30, color1);
        drawBox1(25, 4, 54, 2, textColor);
        drawBox1(27, 10, 49, 20, color2); // Khung nhỏ 1

        // Hiển thị nội dung
        setColor3(textColor);
        gotoXY1(44, 5);
        cout << tenCung;

        gotoXY1(30, 12);
        printWithLineBreaks1(yNghia, 42, 30, 12);
        setColor3(7);

        Sleep(800);
        colorIndex++;

        if (_kbhit()) {
            char key = _getch();
            if (key == '\r') { // Nhấn Enter để thoát
                break;
            }
        }
    }
}

CungHoangDao::CungHoangDao(string tenCungHoangDao, string yNgiaCungHoangDao)
    : TenCungHoangDao(tenCungHoangDao), YNgiaCungHoangDao(yNgiaCungHoangDao) {
}

// Hàm xác định cung hoàng đạo
void CungHoangDao::determineCungHoangDao(int ngay, int thang, string& tenCung, string& yNghia) {
    if ((thang == 3 && ngay >= 21) || (thang == 4 && ngay <= 19)) {
        tenCung = "Bach Duong (Aries)";
        yNghia = "Cung Bach Duong co ten goi tieng Anh la Aries sinh vao khoang thoi gian 21/03 den 20/04. Nhung nguoi thuoc cung Bach Duong duoc nu than tri tue va chien tranh Athena bao ho.Trong 12 cung hoang dao, Bach Duong noi tieng cho su thang than, don gian, yeu thich canh tranh cong bang. Ngoai ra, ho con la nhung nguoi phan dau no luc vi muc tieu cua minh. Nhung tiec rang ho khong thuc su nhan nai khi gap kho khan.     ";
    }
    else if ((thang == 4 && ngay >= 20) || (thang == 5 && ngay <= 20)) {
        tenCung = "Kim Nguu (Taurus)";
        yNghia = "Kim Nguu (Taurus) la mot cung hoang dao noi bat voi nhung dac diem nhu chan thanh, kien dinh, va yeu thich su tu do. Nhung nguoi thuoc cung Kim Nguu thuong rat dang tin cay va trung thuc, dieu nay giup ho xay dung moi quan he vung chac voi nhung nguoi xung quanh. Ho thuong co xu huong tim kiem cong viec trong cac linh vuc nghe thuat, noi ho co the the hien su sang tao va tu do cua ban than, mot phan tinh cach cua Kim Nguu, do la su lang man va yeu thich cai dep.";
    }
    else if ((thang == 5 && ngay >= 21) || (thang == 6 && ngay <= 20)) {
        tenCung = "Cung Song Tu (Gemini)";
        yNghia = "Cung Song Tu (Gemini) la cung hoang dao noi bat voi tinh ham hoc hoi, linh hoat trong xu ly tinh huong va tai an noi, duoc bao ho boi than anh sang Apollo, thuoc nhung nguoi sinh vao khoang 21/05 den 21/06. Song Tu la nguoi sôi noi, thich giao luu va co kha nang noi bat trong dam dong. Tuy nhien, ho cung co nhieu dac diem khien nguoi khac khong may hai long, nhu tinh sang nang chieu mua va xu huong lam viec theo cam hung, khi cam xuc xuong thap, ho se mat di su hang hai.";
    }
    else if ((thang == 6 && ngay >= 21) || (thang == 7 && ngay <= 22)) {
        tenCung = "Cung Cu Giai (Cancer";
        yNghia = "Cung Cu Giai (Cancer) la cung hoang dao duoc bao ho boi su gia cua cac vi than Hermes, thuoc nhung nguoi sinh vao 22/06 den 22/07. Cu Giai noi bat voi trai tim am ap, su hien sinh cho nguoi khac va tinh cam chan thanh. Ho thong minh, da tai, luon co gang trong cong viec va xung dang la ban be dang tin cay trong moi quan he. Tuy nhien, do quan tam qua nhieu cho nguoi khac, Cu Giai thuong hay buon va tam trang, nhay cam, de xuc dong va can nhung nguoi ban thuc su hieu va chia se.";
    }
    else if ((thang == 7 && ngay >= 23) || (thang == 8 && ngay <= 22)) {
        tenCung = "Cung Su Tu (Leo)";
        yNghia = "Cung Su Tu (Leo) thuoc nhung nguoi sinh tu 23/07 den 22/08, cung hoang dao thu 5 trong 12 cung hoang dao, duoc bao ho boi than toi cao Zeus. Su Tu mang hinh anh cua chua te muon loai, toat len khi chat cua nguoi dan dau, voi su tu tin bam sinh, tinh cach manh me va doc lap cao, khong thich dua dam vao nguoi khac. Ho mang den nguoi khac nguon nang luong tich cuc, khong ngai lan xa. Su Tu cung la nguoi ban dang tin cay, san sang xả than vi ban be.";
    }
    else if ((thang == 8 && ngay >= 23) || (thang == 9 && ngay <= 22)) {
        tenCung = "Cung Xu Nu (Virgo)";
        yNghia = "Cung Xu Nu (Virgo) thuoc ve nguoi sinh tu 23/08 den 22/09, duoc nu than Demeter bao ho. Xu Nu noi bat trong 12 cung hoang dao voi su thong minh, sac sao, ly tri va chu toan. Ho luon can than truoc moi quyet dinh đưa ra, va co kha nang giai quyet van de khon kheo ma khong lam mat long ai. Xu Nu cung la nguoi tiet che cam xuc gioi, luon xuat hien voi hinh anh dam tinh, diu dang.";
    }
    else if ((thang == 9 && ngay >= 23) || (thang == 10 && ngay <= 22)) {
        tenCung = "Cung Thien Binh (Libra)h";
        yNghia = "Cung Thien Binh (Libra) gom nhung nguoi sinh trong khoang 23/09 den 23/10, duoc than Hephaestus bao ho. Mặc dù không sinh ra với vẻ đẹp nổi bật, Thiên Bình sở hữu nét duyên ngầm rất cuốn hút. Ho mang đến cho người ngoài hình ảnh luôn vui vẻ, năng động và thân thiện, ít khi thấy họ buồn rầu vì biết cách cân bằng cảm xúc bản thân..";
    }
    else if ((thang == 10 && ngay >= 23) || (thang == 11 && ngay <= 21)) {
        tenCung = "Cung Bo Cap (Scorpius)";
        yNghia = "Cung Bo Cap (Scorpius) thuoc nhung nguoi sinh tu 24/10 den 22/11, duoc than chien tranh Ares bao ho. Bo Cap noi tieng voi su bi an trong 12 cung hoang dao, dieu nay giup Bo Cap thu hut nguoi khac khi khong the hien qua nhieu cam xuc trong moi tinh huong. Tuy nhien, ho khong co y che giau, ma do la tinh cach cua Bo Cap. Khiem ton, khong on ao, pho truong hay khoe me.";
    }
    else if ((thang == 11 && ngay >= 22) || (thang == 12 && ngay <= 21)) {
        tenCung = "Cung Nhan Ma (Sagittarius)";
        yNghia = "Cung Nhan Ma (Sagittarius) sinh tu 23/11 den 21/12, duoc nu than tho san Artemis bao ho. Trong tinh cach cua 12 cung hoang dao, Nhan Ma noi bat voi su phong khoang va yeu thich su tu do. Ho duoc nhieu nguoi yeu men nho su de dang tha thu va khong de buon chuyen gi lau. Nhan Ma la nguoi hiem khi yeu thich su di chuyen. Doi voi ho, cuoc doi la nhung chuyen di, la kham pha nhung vung dat moi.";
    }
    else if ((thang == 12 && ngay >= 22) || (thang == 1 && ngay <= 19)) {
        tenCung = "Cung Ma Ket (Capricorn)";
        yNghia = "Cung Ma Ket (Capricorn) thuoc ve nhung nguoi sinh tu 22/12 den 19/01, duoc nu than lua Hestia bao ho. Tinh cach cua Ma Ket noi bat trong 12 cung hoang dao la su nghiem tuc. Ho nghiem tuc trong moi hoan canh, moi viec lam va loi noi, dieu nay giup ho duoc nguoi khac tin tuong nhung cung bi cho la kho gan. Tuy kham loi, Ma Ket khi than thiet voi ai do, san sang bay to moi cam xuc bang loi noi va hanh dong.";
    }
    else if ((thang == 1 && ngay >= 20) || (thang == 2 && ngay <= 18)) {
        tenCung = "Cung Bao Binh (Aquarius)";
        yNghia = "Cung Bao Binh (Aquarius) thuoc ve nguoi sinh tu 20/01 den 18/02, duoc than Hera bao ho. Bao Binh yeu thich su ro rang va khoa hoc. Ho lam gi cung de dang suy nghi, phan tich va dan chung day du. Do do, Bao Binh kha chu toan, quan tam moi thu va luon trong trang thai de phong cac kha nang xay ra. Bao Binh kha kin tieng trong nhung van de ca nhan.It khi thay ho qua than thiet voi ai, va ho cung khong thich nguoi khac qua than thiet voi minh. ";
    }
    else if ((thang == 2 && ngay >= 19) || (thang == 3 && ngay <= 20)) {
        tenCung = "Cung Song Ngu (Pisces)";
        yNghia = "Cung Song Ngu (Pisces) la cung hoang dao thu 12 trong 12 cung hoang dao, thuoc ve nhung nguoi sinh tu 19/02 den 20/03. Song Ngu duoc vi than bien ca Poseidon bao ho. Trong 12 cung hoang dao, Song Ngu noi tieng voi su trong sang, tot bung.Ho hay nhun nhuong va cam thong, nen rat duoc long nguoi khac.Du so huu nhung tai nang dac biet rieng, Song Ngu van rat khiem ton, khong hao thang va khong the hien cai toi.";
    }
}
