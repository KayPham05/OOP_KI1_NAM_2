#include "CungHoangDao.h"

void CungHoangDao::print(User& user)  {
    NgaySinh ngaySinh = user.getDay(); 
    int ngay = ngaySinh.ngay;
    int thang = ngaySinh.thang;
    if ((thang == 3 && ngay >= 21) || (thang == 4 && ngay <= 19)) {
    cout << "Bach Duong (Aries): Dai dien cho su manh me va nang luong tuoi tre, Bach Duong luon chay theo nhung thu thach moi, day tinh tranh dau va thich lam nguoi dan dau. Ho co tinh khiem khich, thanh thuc, nhung doi khi cung de nong nay va quyen ruong thieu kien nhan.";
} else if ((thang == 4 && ngay >= 20) || (thang == 5 && ngay <= 20)) {
    cout << "Kim Nguu (Taurus): Bieu tuong cua tinh ben bi va su trung thanh, Kim Nguu de danh gia cao su an toan va ben vung trong cuoc song. Ho rat yeu thich viec huong thu tai san va gia dinh. Kim Nguu la nguoi can cu, co tinh than chiu kho va luon huong den su on dinh lau dai.";
} else if ((thang == 5 && ngay >= 21) || (thang == 6 && ngay <= 20)) {
    cout << "Song Tu (Gemini): La nguoi thong minh, linh hoat, Song Tu yeu su tu do va ham hoc hoi. Ho thich ket noi va giao tiep, co kha nang hieu nhieu ve moi truong xung quanh. Tuy nhien, doi khi ho co the bi nhan xet la hay doi thay va kho doan.";
} else if ((thang == 6 && ngay >= 21) || (thang == 7 && ngay <= 22)) {
    cout << "Cu Giai (Cancer): Cam xuc va tinh cam, Cu Giai rat gan bo voi gia dinh va ban be. Ho rat de men, cham soc va co kha nang bao ve manh me. Tuy nhien, Cu Giai doi khi cung rat de bi anh huong boi qua khu va thuong dat nang cam xuc.";
} else if ((thang == 7 && ngay >= 23) || (thang == 8 && ngay <= 22)) {
    cout << "Su Tu (Leo): Dai dien cho su tu tin va quyet doan, Su Tu luon thu hut su chu y va yeu thich viec lam trung tam. Ho co kha nang lanh dao tu nhien, va rat quyet tam theo duoi muc tieu cua minh. Tuy nhien, doi khi Su Tu cung de choi voi cai toi cao.";
} else if ((thang == 8 && ngay >= 23) || (thang == 9 && ngay <= 22)) {
    cout << "Xu Nu (Virgo): Chinh xac va can than, Xu Nu la nguoi hoan hao va rat ky luong trong cong viec. Ho co kha nang quan sat tinh vi va thuong la nguoi cham chi, biet cham lo cho chi tiet. Tuy nhien, doi khi Xu Nu de gay ap luc cho ban than va nguoi xung quanh.";
} else if ((thang == 9 && ngay >= 23) || (thang == 10 && ngay <= 22)) {
    cout << "Thien Binh (Libra): Bieu tuong cua su can bang va hoa dong, Thien Binh co kha nang ket noi moi nguoi va de gay thien cam. Ho luon tim kiem su hoa hop trong moi quan he va rat coi trong cong bang. Tuy nhien, doi khi Thien Binh rat kho dua ra quyet dinh.";
} else if ((thang == 10 && ngay >= 23) || (thang == 11 && ngay <= 21)) {
    cout << "Bo Cap (Scorpio): Manh me va sau sac, Bo Cap co tinh cam manh me va thuong rat bi an. Ho co kha nang chiu dung va phuc vu muc tieu cua minh den cung. Tuy nhien, Bo Cap doi khi cung rat kin dao va de tro nen thu dich khi bi phan boi.";
} else if ((thang == 11 && ngay >= 22) || (thang == 12 && ngay <= 21)) {
    cout << "Nhan Ma (Sagittarius): Yeu tu do va khat vong hoc hoi, Nhan Ma rat linh hoat va huong ngoai. Ho thich du lich va kham pha, rat coi trong ly tuong va tuong lai. Tuy nhien, doi khi Nhan Ma cung rat thieu kien nhan va de chuyen doi muc tieu.";
} else if ((thang == 12 && ngay >= 22) || (thang == 1 && ngay <= 19)) {
    cout << "Ma Ket (Capricorn): La nguoi ki luat va co kha nang chiu dung, Ma Ket biet cach dat ke hoach va thuc hien mot cach ki luong. Ho thuong coi trong su nghiep va yeu thich viec dap ung muc tieu lau dai. Tuy nhien, doi khi Ma Ket cung co the bi chi phoi qua nhieu boi cong viec.";
} else if ((thang == 1 && ngay >= 20) || (thang == 2 && ngay <= 18)) {
    cout << "Bao Binh (Aquarius): Doc lap va sang tao, Bao Binh co tu duy khac biet va huong den su moi la. Ho rat thich the hien ca tinh va thuong co y tuong tien phong. Tuy nhien, doi khi Bao Binh cung co the kho giao tiep voi nhung ai co quan diem khac biet.";
} else if ((thang == 2 && ngay >= 19) || (thang == 3 && ngay <= 20)) {
    cout << "Song Ngu (Pisces): Nhay cam va tinh te, Song Ngu co kha nang dong cam va rat yeu thuong moi nguoi. Ho rat de tham gia vao the gioi cam xuc cua nguoi khac va thuong co kha nang nghe thuat. Tuy nhien, Song Ngu cung de bi lang quen va rat de ton thuong.";
} else {
    cout << "Ngay thang khong hop le\n";
}

}