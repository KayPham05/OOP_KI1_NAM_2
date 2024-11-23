#include "ThanSoHoc.h"
#include <cctype>
#include <cstring>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Phương thức reduceToSingleDigit để giảm số về một chữ số
int ThanSoHoc::reduceToSingleDigit(int num) {
    while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}



// Lớp con SoDuongDoi
int SoDuongDoi::tinhSo(User& user) {
    int sum = reduceToSingleDigit(user.getDay().ngay) + reduceToSingleDigit(user.getDay().thang) + reduceToSingleDigit(user.getDay().nam);
    if (sum == 11 || sum == 22) {
        return sum;
    } else {
        return reduceToSingleDigit(sum);
    }
}

void SoDuongDoi::thongTin(User& user) {
    int number = tinhSo(user);
    cout << "Ngay thang nam sinh cua ban:" << endl;
    cout << user.getDay().ngay << "/" << user.getDay().thang << "/" << user.getDay().nam << endl;
    cout << "Co so duong doi la: " << number << endl;

    switch (number) {

    case 1:
        cout << "So 2 la hien than cho su kien nhan, cong bang, kha nang ngoai giao va mot tam long yeu thuong, nhan ai. "
            "Nhiem vu cua so chu dao 2 la tro thanh nguoi ket noi, hoa giai, dem tinh yeu thuong vao cac moi quan he trong moi khia canh cuoc song. "
            "Muc dich song cua nhung nguoi nay la hoc duoc cach lam viec hai hoa, can bang va ton trong lan nhau.";
        break;
            case 2:
                cout<<"So 2 la hien than cho su kien nhan, cong bang, kha nang ngoai giao va mot tam long yeu thuong, nhan ai. "
           "Nhiem vu cua so chu dao 2 la tro thanh nguoi ket noi, hoa giai, dem tinh yeu thuong vao cac moi quan he trong moi khia canh cuoc song. "
           "Muc dich song cua nhung nguoi nay la hoc duoc cach lam viec hai hoa, can bang va ton trong lan nhau.";
            break;
            case 3:
                 cout<<"So 3 la hien than cua su nang dong, vui tuoi, kha nang can bang cam xuc va truyen duoc nhieu nguon cam hung. "
           "Nhiem vu cua nhung nguoi mang so 3 trong Than so hoc la nguoi su dung cach dien dat sang tao, phat trien kha nang ket noi, tinh cam lanh manh trong moi khia canh cua cuoc song. "
           "Muc dich song cua nhung nguoi nay la su dung cam xuc, tai nang sang tao cua minh de nang cao tinh than va truyen cam hung toi moi nguoi.";
            break;
            case 4:
                 cout<<"So 4 la hien than cho nhung dinh huong, su chia se thuc te, lam viec chin chu. "
           "Nhiem vu cua ban la tao ra su on dinh va an toan khi can hoan thanh mot dieu gi do mang gia tri lau dai. "
           "Muc dich cua nhung nguoi nay la tao nen su ben vung trong qua trinh huong toi muc tieu cuoc doi. "
           "Viec mang lai su an toan cho chinh minh va moi nguoi la dieu ma nhan so hoc so 4 khao khat manh me.";    
            break;        
            case 5:
               cout<<"So 5 la hien than cho su mao hiem, ban tinh thich phieu luu, khong so hai va muon truyen tai toi moi nguoi cach song tu do. "
           "Nhiem vu cua so 5 trong than so hoc la phat trien su tu do theo thien huong xay dung, ban vua co ky luat vua co mong muon trai nghiem nhung dieu tot dep cuoc song mang lai. "
           "Muc dich cuoc song cua ban la tim thay su tu do ben trong nhung quy tac, luat le va trai nghiem cuoc song.";
            break;
            case 6:
               cout<<"So 6 la hien than cho trach nhiem, khong phan xet, khong chi trich nhung hanh dong va lua chon cua nguoi khac, ban co tam nhin xa va kha nang nhin thay toan canh truoc mat. "
           "Nhiem vu cua than so hoc so 6 la phat trien va trau doi kha nang nhin xa trông rong, cung nhu hoc cach chap nhan cuoc song da chieu. "
           "Muc dich song cua nhan so hoc so 6 la dung hoa ly tuong cao dep voi nhung thu khiem khuyet, khong ngung boi bo them tinh yeu thuong trong moi viec ban da, dang va se lam.";
            break;
            case 7:
              cout<<"So 7 la hien than cua truc giac, tri tue, khong ngai mo long voi nguoi khac. "
           "Nhiem vu cua than so hoc so 7 la phat trien niềm tin vao dòng chảy cua cuoc song, mo ra su phat trien va nhan thuc cho cac gia tri ca nhan va tinh than. "
           "Muc dich cuoc song cua ban la tin tuong vao ban than, vao qua trinh ban cam thay an toan de co the mo long va chia se tri tue ben trong cua minh ra the gioi.";
            break;
            case 8:
               cout<<"So 8 la hien than cho su du da ve tai chinh, su dung quyen luc khon ngoan, luon danh nhieu thoi gian, tien bac va suc anh huong cua minh de lam the gioi tot dep hon. "
           "Nhiem vu cua so 8 trong nhan so hoc la tao ra su doi dao ve vat chat. "
           "Muc dich cuoc song cua ban la su dung anh huong, quyen luc tai chinh cua minh de tao ra dau an tren the gioi va giup do nhung nguoi khac.";
            break;
            case 9:
               cout<<"So 9 la hien than cua nguoi lang nghe, biet dong cam va coi mo trong cuoc song. "
           "Nhiem vu cua nhan so hoc so 9 la tro thanh nguoi chinh truc tren con duong theo duoi su sang tao va cong hien. "
           "Muc dich cua ban la song voi cac tieu chuan chinh truc, sap xep cuoc song song song giua tri tue va trai tim, truyen cam hung cho moi nguoi.";
            break;
            case 11:
                cout<<"So 11 nhan duoc mon qua thuong de ban cho ban la truc giac rat phong phu. "
           "Ban tot bung va ban la nguoi gioi gin giu hoa binh. Nhan so hoc so 11 co kha nang phat hien cac xu huong moi "
           "va vuot qua cac ranh gioi co huu. Ban cung co the bi loi keo va co kha nang cuc doan. Bai hoc danh cho ban "
           "la tinh quyet doan va kien tri, khong tu bo uoc mo cua minh.";
            break;
            case 22:
                 cout<<"So 22 la mot trong bo ba so quan trong trong Nhan so hoc (11, 22, 33). "
           "Theo do, ca 3 so nay duoc lien ket voi nhau va tao thanh \"Tam giac cua su khai sang\". "
           "Moi con so tren deu mang mot bieu tuong lon va nhieu y nghia nho dac thuc. "
           "Nhung nguoi mang van menh than so hoc so 22 thuong co tham vong lon, khat khao phat trien cuoc doi. "
           "Dac biet, ho luon co to chat, phong thai cua nha lanh dao thong minh, tai ba.";
            break;
            default:
                cout<<"Khong co y nghia cho so nay.";
        }
    } 


// Lớp con LinhHon
int LinhHon::tinhSo(User& user) {
    int sum = 0;
    string name = user.getName();

    // Duyệt qua từng ký tự trong tên để tính tổng giá trị của nguyên âm
    for (char c : name) {
        if (isalpha(c)) {
            c = toupper(c);
            if (strchr("AEIOU", c)) {
                if (c == 'A') sum += 1;
                else if (c == 'E') sum += 5;
                else if (c == 'I') sum += 9;
                else if (c == 'O') sum += 6;
                else if (c == 'U') sum += 3;
            }
        }
    }
    return reduceToSingleDigit(sum);
}

void LinhHon::thongTin(User& user) {
    int number = tinhSo(user);
    cout << "So linh hon cua ban la " << number << endl;
    switch (number) {
       case 1:
            cout<<"Chi so linh hon 1:\n"
                   "Khao khat tro thanh mot ca nhan doc lap, nam giu su doc nhat vo nhi cua minh va tu duy dot pha.\n"
                   "Duoc thuc day bang cach chiu trach nhiem va khoi xuong cac du an, la chinh minh trong su tranh dau, ganh dua.\n"
                   "Khong thich bi bao phai lam gi va khong co y dinh di theo dam dong, chinh phuc, chien thang va vinh quang.";
                 break;
        case 2:
            cout<<"Chi so linh hon 2:\n"
                   "Muon tro thanh nguoi hoa giai hop tac, nguoi thuc day hoa binh va hoa thuan cho cong dong.\n"
                   "Muon phat trien trong mot moi truong hai hoa noi moi nguoi deu hanh phuc.\n"
                   "Duoc thuc day boi tinh yeu, su hoa hop, tinh ban va cac moi quan he trong cuoc song. Muon ho tro, nuoi duong, yeu thuong va chua lanh vet thuong cho nguoi khac.";
                 break;
        case 3:
            cout<<"Chi so linh hon 3:\n"
                   "Duoc thoa man dam me sang tao, pha vo gioi han va le loi thong thuong.\n"
                   "Muon vui ve va hanh phuc cho ban than va nguoi khac. So 3 cam thay rang cuoc song co nghia la phai vui ve, vi vay hay song het minh.\n"
                   "Duoc thuc day tu moi nguoi, cuoc tro chuyen, tieng cuoi, giai tri va nghe thuat.";
                 break;
        case 4:
            cout<<"Chi so linh hon 4:\n"
                   "Duoc tim toi, hoc tap va chia se hieu biet voi nguoi khac, thuc te, chan thuc. Chu toan trong moi viec.\n"
                   "Mong muon mang lai su on dinh, to chuc va trat tu cho gia dinh, noi lam viec va cong dong cua minh.\n"
                   "Muon su on dinh ve tai chinh, tinh cam va the chat de co the song mot cuoc song an toan.";
                 break;
        case 5:
            cout<<"Chi so linh hon 5:\n"
                   "Duoc la chinh minh khi tu do, kham pha nhu tham hiem, du lich, huong thu cuoc song theo cach rieng cua ban than, duoc giao tiep va ket noi voi moi nguoi.\n"
                   "Mong muon tu do, la chinh minh va song ma khong bi gioi han va han che trong khi nam lay su tu do do mot cach xay dung.\n"
                   "Duoc thuc day boi nhung trai nghiem moi, con nguoi, du lich, su da dang, hung thu va phieu luu.";
                 break;
        case 6:
            cout<<"Chi so linh hon 6:\n"
                   "Duoc la chinh minh khi nuoi duong nguoi khac, cham soc, quan tam gan gui nhung nguoi ma ho yeu thuong.\n"
                   "Muon mang tinh yeu, ve dep va su hoa hop vao the gioi de moi nguoi co the cam thay hanh phuc, duoc yeu thuong va duoc chua lanh.\n"
                   "Duoc thuc day boi sac dep, tinh yeu, gia dinh, cac moi quan he va phuc vu cham soc cho nguoi khac.";
                 break;
        case 7:
            cout<<"Chi so linh hon 7:\n"
                   "Duoc lam nhung dieu ban than tin tuong cho du di nguoc voi phan con lai.\n"
                   "Khao khat tro thanh nguoi tim kiem chan ly chiem nghiem, nguoi kham pha ra nhung bi mat va bi an cua cuoc doi.\n"
                   "Muon di den tan cung cua moi thu de xem dieu gi an giau, co the dat duoc dieu nay trong linh vuc khoa hoc, sieu hinh, cong nghe, tam ly hoc, triet hoc, ton giao hoac cac muc tieu hoc thuat khac.";
                 break;
        case 8:
            cout<<"Chi so linh hon 8:\n"
                   "Duoc la chinh minh khi duoc doc lap ve tai chinh, cong viec an toan, ngoi nha rieng.\n"
                   "Muon tro thanh mot nha lanh dao co dau oc kinh doanh, song theo ly tuong cao ca hon va thai do phong phu.\n"
                   "Mong muon cong bang, duoc trao quyen va phong phu trong cuoc song va cong viec.";
                 break;
        case 9:
            cout<<"Chi so linh hon 9:\n"
                   "Duoc la chinh minh khi duoc cong hien voi nhung dieu thieng lieng nhat.\n"
                   "Muon tro thanh mot nguoi nhan dao nhan ai, nguoi gop phan lam cho the gioi tro thanh mot noi tot dep hon.\n"
                   "Muon su dung moi co hoi duoc trao de thuc day hoa binh, thong nhat, hieu biet, tha thu va tinh yeu dai chung.";
                 break;
        case 11:
            cout<<"Chi so linh hon 11:\n"
                   "Khao khat su dong hanh, giong nhu tren bat ky hanh trinh nao cung muon co nguoi ban di chung, nhung o so 11 thi can nguoi ban tinh than hon.\n"
                   "Khao khat nam giu nhung thong tin cung nhu kien thuc ve tam linh.\n"
                   "Duoc tiep xuc voi nhung nguoi thuoc tang lop giong minh la dieu can thiet.";
                 break;
        case 22:
            cout<<"Chi so linh hon 22:\n"
                   "Duoc lam dieu gi do that vi dai va to lon va lam cho xa hoi tot dep hon.\n"
                   "Duoc la chinh minh khi da chu toan moi viec, thuc hien tat ca suy nghi trong dau.\n"
                   "Duoc tim toi, hoc tap va chia se hieu biet va giup do nguoi khac.";
                 break;
        default:
            cout<<"Chi so linh hon khong hop le.";
    }
		}	
		


// Lớp con BieuDat
int BieuDat::tinhSo(User& user) {
    int sum = 0;
    string name = user.getName();
    const int letterToNumber[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8}; 

    for (char c : name) {
        if (isalpha(c)) {
            c = toupper(c);
            sum += letterToNumber[c - 'A'];
        }
    }
    return reduceToSingleDigit(sum);
}

void BieuDat::thongTin(User& user) {
    int number = tinhSo(user);
    cout << "So bieu dat cua ban la: " << number << endl;
    switch (number) {
        case 1:
            cout << "Y NGHIA SO BIEU DAT 1 Nhung nguoi co con so bieu dat 1 thuong rat thich nhung mon the thao ca nhan hoac lam viec mot minh. Ho rat thich duoc tu do lam moi viec theo nhip do rieng, de co the dat duoc su hai long cao nhat va xay dung su tu tin cua ho trong cac hoat dong the chat." << endl;
            break;
        case 2:
            cout << "Y NGHIA SO BIEU DAT 2 Nhung nguoi thuoc nhom nay thich lam viec theo nhom trong nhung moi truong vui ve. Ho la nguoi hoat bat, th, niem vui va nhung hoat dong thoai mai. Dieu nay khong co nghia ho la nguoi nong can, ma dung hon, ho co kha nang tan huong niem vui ma nhung hoat dong Co to chuc mang lai." << endl;
            break;
        case 3:
        cout<<"Y NGHIA SO BIEU DAT 4 Con so mang dam tinh than thuc te, va nhung nguoi so huu no thuong rat kheo tay, thich nhung hoat dong the chat, van dung do kheo lech cua doi tay va doi chan. Ho dac biet yeu thich the thao, hoat dong xay dung, lap rap hoat sua chua do dac.";
        break;
        case 4:
        cout<<"Y NGHIA SO BIEU DAT 4 Con so mang dam tinh than thuc te, va nhung nguoi so huu no thuong rat kheo tay, thich nhung hoat dong the chat, van dung do kheo lech cua doi tay va doi chan. Ho dac biet yeu thich the thao, hoat dong xay dung, lap rap hoat sua chua do dac.  ";
        break;
        case 5:
        cout<<"Y NGHIA SO BIEU DAT 5 Mot trong nhung dieu thuong thay o nhung nguoi so huu con so bieu dat nay la nhu cau duoc tu do bieu dat thoat khoi rang buoc cua the gioi vat chat. Nhung doi khi ho de cho su hieu lam hoac ve ngai ngung can tro minh bieu dat mot cach tron ven nhat. De tranh dieu nay, ho nen tim nhung cong viec khong go bo va nhung nguoi ban ma ho cam thay de chiu khi tuong tac. Noi mot cach don gian, ho can nhung nguoi ban dong hanh chiu tuong tac, thoai mai va linh hoat.";
        break;
        case 6:
        cout<<"Y NGHIA SO BIEU DAT 6 Nhom nay co xu huong tap trung nang luong va tam tri cho mai am cua minh. Hien nhien dieu do rat co loi cho cac thanh vien trong gia dinh, nhung no cung co the khiên ho 'duoc nuong chieu qua nen sinh hu'. Do do, nhung nguoi co con so bieu dat 6 can tranh the hien dac diem nay qua da, bang cach can bang giua su chieu chuong va viec quan tam den nhung nhu cau thuc su cua nguoi than.";
        break;
        case 7:
        cout<<"Y NGHIA SO BIEU DAT 7 diep khi ban lien tuc thay so ngay sinh cua minh o moi noi Dac diem cua nguoi Co Con so bieu dat 7 la su thoi thuc duoc lam viec doc lap, tu trai nghiem va hoc hoi theo kieu rieng cua ho. Ho thich tan huong thanh tuu ca nhan va cam giac thoa man khi duoc tu minh kham pha, hon la hoc hoi tu nguoi khac.";
        break;
        case 8:
        cout<<"Y NGHIA SO BIEU DAT 8 Nguoi thuoc nhom nay co mot khao khat manh liet duoc the hien su doc lap cua ban than, thich lam moi chuyen mot minh va khong ngai to ra khac biet neu can. Bang cach nay, ho boc lo mot ca tinh manh me, vi ho y thuc duoc con nguoi khong bao gio co the dat den muc do phat trien ban than cao hon neu cu chap nhan 'tu duy bay dan'.";
        break;
        case 9:
        cout<<"Y NGHIA SO BIEU DAT 9 Cuoc song luon ton tai hai khia canh nghiem tuc va hai huoc. Nguoi co cuoc song can bang la nguoi ma hai khia canh nay hoa hop voi nhau mot cach tot dep nhat trong doi song ca nhan ho. Tuy nhien, nguoi co con so bieu dat 9 co xu huong qua tap trung vao su nghiem tuc, va bang cach nay, ho thuong thu hut noi buon, va doi khi la ca su co doc, vi ho cho rang khia canh hai huoc nhe nhang cua cuoc song la khong quan trong. Ho co kha nang suy ngam, tu duy phan tich sac ben va chuan muc song tot dep de phuc vu cho ly tuong cao dep cua minh. Nhung nhom nay cung can hoc cach can bang cuoc song bang nhung niem vui nhe nhang de phuc hoi nang luong cho tam tri va co the minh.";
        break;
        case 10:
        cout<<"Y NGHIA SO BIEU DAT 10 Dac diem cua Con so bieu dat 10 gan nhu trai nguoc voi Con so bieu dat 9. Nhung nguoi so huu Con so nay thuong qua tap trung vao khia canh nhe nhang, vui ve cua cuoc song, va co phan xem nhe tinh nghiem tuc. Ho can tranh tro nen khiem nha va nong can, thay vao do, hay tap trung vao kha nang that su cua con so 10, do la nang luc thich nghi voi nhieu hoan canh va tinh huong khac nhau. Nguoi mang Con so bieu dat nay quyet tam manh me hon de hoan thanh vai tro cua minh trong cuoc song, vi chi khi can bang duoc tinh nghiem tuc va thoai mai thi ho moi gat hai duoc thanh cong.";
        break;
        case 11:
        cout<<"Y NGHIA SO BIEU DAT 11 Nhu cau noi bat cua nguoi co con so bieu dat 11 la su hai hoa. Cam xuc va tinh than can bang la dac diem cua con so nay. Muc dich dac biet cua nhom nay la lan toa mong muon ve su hai hoa voi moi truong xung quanh, kiem soat cam xuc, cung nhu phat trien va chia se nhung hieu biet sau sac ve cuoc song. Chi khi di theo con duong nay thi ho moi co the den duoc ben bo hanh phuc.";
        break;
        case 22:
        cout<<"Y NGHIA SO BIEU DAT 22/4 Nhung nguoi co con so bieu dat 22/4 thuong rat co nang luc to chuc, dac biet la trong kinh doanh va thuong mai. Neu co con so chu dao la 4, 8 hay 22/4 thi ho can dac biet luu y de duy tri trang thai can bang vi luc nay ho se de bi lech ve huong kiem tien, den muc gan nhu bi am anh. Loi khuyen nay cung duoc ap dung neu ho co Con so chu dao khac: Hay no luc phat huy ky nang to chuc trong nhung linh vuc phi thuong mai, chang han nhu cac hoat dong hoac to chuc thien nguyen dang tin cay, dac biet la nhung to chuc mang den phuc loi cho nhung dua tre chiu nhieu thiet thoi va gap kho khan trong cuoc song. Bang cach nay, nhung nguoi co Con so bieu dat 22/4 moi co the dat duoc mot cuoc song can bang.";
        break;

        default:
            cout << "Khong co y nghia cho so nay." << endl;
            break;
    }
}

// Lớp con NhanCach
int NhanCach::tinhSo(User& user) {
    int sum = 0;
    string name = user.getName();
    const int vowelValues[5] = {1, 5, 9, 6, 3};  // A=1, E=5, I=9, O=6, U=3
    string vowels = "AEIOU";  

    for (char c : name) {
        c = toupper(c);
        size_t pos = vowels.find(c);
        if (pos != string::npos) {  // Nếu ký tự là nguyên âm
            sum += vowelValues[pos];  // Thêm giá trị của nguyên âm vào tổng
        }
    }

    return reduceToSingleDigit(sum);
}

void NhanCach::thongTin(User& user) {
    int number = tinhSo(user);
    cout << "So nhan cach cua ban la " << number << endl;

    switch (number) {
      case 1:
        cout<<"So su menh 1: Tich cuc:\n"
               "Co y chi, suc manh, long quyet tam, su sang tao, ky luat, doc lap de dua so 1 toi vi tri lanh dao.\n"
               "Lam chu van menh va duong doi cua minh, hanh phuc khi nam quyen, co tinh doc lap manh me.\n"
               "Tieu cuc:\n"
               "Co the thieu kien nhan voi nhung nguoi khong phu hop voi minh.\n"
               "Doi khi co the hach dich voi moi nguoi, khien mot so nguoi roi vao tinh huong khong thoai mai.\n"
               "Nghe nghiep phu hop: doanh nhan, CEO, hieu truong, chinh tri gia.";
             break;
    case 2:
        cout<<"So su menh 2: Tich cuc:\n"
               "Ngoai giao, binh tinh, kheo leo, thuyet phuc, biet lang nghe, quan tam, yeu thuong nguoi khac.\n"
               "Kha nang thuyet phuc bam sinh, khon kheo va binh tinh de giai quyet van de.\n"
               "Tieu cuc:\n"
               "Bao ve nguoi khac qua muc, noi doi de moi thu yen binh.\n"
               "Bat chap de loi keo nguoi khac (bieu hien khi ban hang).\n"
               "Nghe nghiep phu hop: nha ngoai giao, ban hang, dien vien, giao vien, nha tam ly hoc, co van.";
             break;
    case 3:
        cout<<"So su menh 3: Tich cuc:\n"
               "Lac quan, sang tao, nhiet tinh, lang man, hai huoc…lam nguoi khac vui ve khi o ben canh.\n"
               "Ky nang lanh dao sang tao tuyet voi, may man trong kinh doanh.\n"
               "Tieu cuc:\n"
               "De mat tap trung.\n"
               "Khi gap kho khan thi khong muon cho nguoi khac biet, that vong khi khong lam duoc viec gi do.\n"
               "Nghe nghiep phu hop: dien vien, nhac si, nghe si, giao duc.";
             break; 
    case 4:
        cout<<"So su menh 4: Tich cuc:\n"
               "Cham chi, tan tam, trung thanh, dang tin cay…mong muon xay dung nhung thu co gia tri lau dai.\n"
               "Cham chi cho den khi hoan thanh cong viec.\n"
               "Tieu cuc:\n"
               "Tinh cach te nhat, cung nhac, thieu suc tuong tuong.\n"
               "Doi khi qua nguyen tac, thieu linh hoat.\n"
               "Nghe nghiep phu hop: nha quan ly xuat sac, to chuc.";
             break;
    case 5:
        cout<<"So su menh 5: Tich cuc:\n"
               "Vo tu, thich mao hiem, cau tien, nhiet tinh, thich phieu luu… Yeu thich su thay doi va moi me.\n"
               "La nguoi giao tiep dang kinh ngac, co the ket ban qua nhung trai nghiem.\n"
               "Thich di du lich, kham pha nhung dia diem moi va nen van hoa moi.\n"
               "Tieu cuc:\n"
               "De bi nghien nhung thu tieu cuc de giai toa cang thang.\n"
               "Nghe nghiep phu hop: nha van, nha bao, nghe si, giao vien, nha chinh tri.";
             break;
    case 6:
        cout<<"So su menh 6: Tich cuc:\n"
               "Tinh cam, doi noi, co trach nhiem, trung thanh, dong cam…\n"
               "Nhieu tinh yeu thuong, luon giup do nguoi khac, cham soc khi can.\n"
               "Muoi ly tuong hoa tinh yeu va lan toa den moi nguoi.\n"
               "Tieu cuc:\n"
               "Doi khi qua cau toan.\n"
               "Dat tieu chuan qua cao dan den ap luc.\n"
               "Quan tam qua muc dan den kiem soat.\n"
               "Nghe nghiep phu hop: giao vien, dien vien, nha van, lanh dao.";
             break;
    case 7:
        cout<<"So su menh 7: Tich cuc:\n"
               "Tri thuc, can dam, trung thuc, phan tich, khon ngoan … phat trien dua tren su that.\n"
               "Quan tam den nhung dieu huyen bi, co kha nang tam linh o muc nao do.\n"
               "Tieu cuc:\n"
               "Co the khong lang nghe y kien khac, tro nen kieu ngao.\n"
               "It thay doi quan diem, co chap ve y kien cua minh.\n"
               "Nghe nghiep phu hop: nha giao duc, lanh dao, lam tu thien, truyen giao.";
     break;
    case 8:
        cout<<"So su menh 8: Tich cuc:\n"
               "Dong luc lon, quyet tam, kha nang lanh dao, trach nhiem, manh me, co to chuc, thanh cong…\n"
               "Co kha nang chien thang trong bat ky cuoc canh tranh nao, dam chap nhan rui ro.\n"
               "Tieu cuc:\n"
               "Canh tranh qua muc, khong lanh manh.\n"
               "Can bang la viec kho khan doi voi so 8.\n"
               "Nghe nghiep phu hop: doanh nhan, quan doi, chinh phu, tai chinh, ngan hang.";
             break;
    case 9:
        cout<<"So su menh 9: Tich cuc:\n"
               "Nghe thuat, hao phong, duy tam, tho mong, nhin xa trong rong…co long vi tha lon.\n"
               "Luon thich lam tu thien, giup do nguoi khac, biet cach thuong thuc nghe thuat va cai dep.\n"
               "Tieu cuc:\n"
               "De chan nan, de tin nguoi, doi khi nong nay va de that vong.\n"
               "Thieu thuc te trong cong viec, muon moi thu duoc lam ngay lap tuc.\n"
               "Nghe nghiep phu hop: lam tu thien, nghe thuat.";
             break;
    case 11:
        cout<<"So su menh 11: Tich cuc:\n"
               "Tham vong, hoa giai, than thien…\n"
               "Co kha nang giao tiep tuyet voi, huong ngoai va co dinh huong.\n"
               "La nhung nha lanh dao tuyet voi, co dau oc kinh doanh tot.\n"
               "Tieu cuc:\n"
               "Doi khi kieu ngao, khong khoan nhuong voi nhung nguoi co y kien trai chieu.\n"
               "Nghe nghiep phu hop: su nghiep nghe thuat, cong dong, lanh dao, kinh doanh.";
             break;
    case 22:
        cout<<"So su menh 22: Tich cuc:\n"
               "Bien nhung giac mo thanh hien thuc, thuc hien cac du an lon loi ich cho nhan loai.\n"
               "Nhan dao, than thien, co suc hut, duy tam, thuc te, tu tin…\n"
               "Tieu cuc:\n"
               "Kieu ngao, tham lam, ham muon quyen luc nguy hiem neu khong kiem soat.\n"
               "Co the luoi bieng hon nguoi khac, di kem long tham.\n"
               "Nghe nghiep phu hop: nha ngoai giao, tam ly hoc, quan ly.";
             break;
    default:
        cout<<"Chi so su menh khong hop le.";
    }
}
