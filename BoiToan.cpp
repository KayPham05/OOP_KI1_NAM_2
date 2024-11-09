#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <conio.h>     // Sử dụng thư viện getch() cho Windows
#include <windows.h>   // Sử dụng thư viện windows.h để làm việc với console
#include <fstream>     // Thư viện để làm việc với file
#include <ctime>       // Thư viện để sử dụng time

using namespace std;
// Hàm set màu
 void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
struct TarotCard {
    string name;
    string meaning;
};

vector<TarotCard> createTarotDeck() {
      return {
    {"The Fool (Ke Kho Khon): Dai dien cho su khoi dau, su ngau hung, va su tu do. Thuong lien quan den hanh trinh moi ma khong biet truoc ket qua, su chinh phuc su khong biet truoc.\n"
     "Y nghia sau sac: Bat dau mot hanh trinh moi ma khong co su chuan bi day du. Tuong trung cho su ngây thơ va tu do trong viec chap nhan nhung rui ro.\n"
     "Tinh huong: Bat dau mot cong viec moi, thay doi noi o, hoac bat dau mot moi quan he ma khong chac chan ve tuong lai."},

    {"The Magician (Nha Ao Thuat): Ky nang, kha nang dieu khien va tao ra thuc te bang suc manh y chi. Nhieu khi goi y su tap trung vao muc tieu va su tu tin.\n"
     "Y nghia sau sac: Kha nang bien uoc mo thanh hien thuc thong qua su tap trung va y chi. Khuyen khich ban tan dung tai nang cua minh.\n"
     "Tinh huong: Ban co the thanh cong bang cach su dung nhung ky nang va nguon luc da co."},

    {"The High Priestess (Nu Tu Te Cao Cap): Su truc giac, bi mat va tri tue noi tam. Khuyen nen lang nghe tieng noi ben trong va tim kiem hieu biet chinh minh.\n"
     "Y nghia sau sac: Khuyen khich viec lang nghe truc giac va kham pha nhung bi mat. Nu Tu Te bieu trung cho su hieu biet sau sac ve ban than.\n"
     "Tinh huong: Can tin vao cam giac truc giac khi doi mat voi mot quyet dinh quan trong."},

    {"The Empress (Hoang Hau): Dai dien cho su phong thinh, tinh yeu, me thien nhien, va su cham soc. La bieu tuong cua tinh thuong va nu tinh.\n"
     "Y nghia sau sac: Su nuoi duong va kha nang sinh san. Bieu tuong cho su phong phu, cham soc va tinh yeu.\n"
     "Tinh huong: Phat trien mot du an moi, nuoi duong cac moi quan he ca nhan, tim kiem su binh yen."},

    {"The Emperor (Hoang De): Su kiem soat, quyen luc va cau truc. La bieu tuong cua ke lanh dao, nguyen tac nam tinh va trat tu xa hoi.\n"
     "Y nghia sau sac: Quyen luc va su kiem soat. Khuyen khich su lanh dao va xay dung nen tang vung chac cho tuong lai.\n"
     "Tinh huong: Can co su quyet doan trong viec ra quyet dinh lon."},

    {"The Hierophant (Thay Tu Cao Cap): Dai dien cho truyen thong, giao duc, va dao ly tam linh. Goi y su can bang giua thuc hanh va hoc thuyet.\n"
     "Y nghia sau sac: Bieu trung cho truyen thong va giao duc. Khuyen khich tim kiem su chi dan va hoc hoi.\n"
     "Tinh huong: Tham gia mot khoa hoc, tim su tu van tu nguoi co kinh nghiem."},

    {"The Lovers (Nguoi Yeu Nhau): Su lua chon, moi quan he, va tinh yeu. Goi y tinh than doan ket, quyet dinh quan trong va tinh cam.\n"
     "Y nghia sau sac: Tinh yeu, su ket noi va su lua chon. Bieu tuong cho su gan ket sau sac giua hai nguoi.\n"
     "Tinh huong: Can ra quyet dinh ve mot moi quan he quan trong."},

    {"The Chariot (Xe Ngua): Chien thang bang y chi va su kiem soat. Goi y su tien bo, dat duoc thanh cong sau khi khac phuc kho khan.\n"
     "Y nghia sau sac: Su quyet tam va kha nang kiem soat. Khuyen khich ban giu vung quyet tam.\n"
     "Tinh huong: Doi mat voi mot thu thach lon trong cuoc song."},

    {"Strength (Suc Manh): Su manh me noi tai, su kien nhan va long dung cam. Khuyen nen dung cam doi mat voi kho khan.\n"
     "Y nghia sau sac: Su kien nhan, long dung cam. Khuyen khich ban doi mat voi kho khan.\n"
     "Tinh huong: Can phai doi mat voi mot noi so hoac thu thach."},

    {"The Hermit (Nha An Si): Su suy tu, co doc va tim kiem su that. Goi y su can thiet cua viec nghi lai, tu van va hieu biet noi tam.\n"
     "Y nghia sau sac: Tim kiem su tinh lang va hieu biet. Khuyen khich ban danh thoi gian de tu phan tich.\n"
     "Tinh huong: Can thoi gian rieng tu de hieu ro hon ve ban than."},

    {"Wheel of Fortune (Banh Xe Van Menh): Su thay doi, chu ky moi va van may. La nhac nho rang cuoc song la mot vong xoay khong ngung nghi.\n"
     "Y nghia sau sac: Chu ky va su thay doi. Khuyen khich ban chuan bi cho nhung thay doi bat ngo.\n"
     "Tinh huong: Doi mat voi nhung thang tram trong cuoc song."},

    {"Justice (Cong Ly): Su cong bang, can bang va trach nhiem. Goi y nhung quyet dinh cong minh va hau qua cua hanh dong.\n"
     "Y nghia sau sac: Su cong bang va trach nhiem. Khuyen khich ban ra quyet dinh cong bang.\n"
     "Tinh huong: Can can nhac ve quyet dinh cua ban."},

    {"The Hanged Man (Nguoi Bi TreoNguoc): Su hy sinh, goc nhin moi va tam dung. Khuyen nen nhin su viec tu goc do khac de tim ra giai phap.\n"
     "Y nghia sau sac: Su hy sinh va goc nhin moi. Khuyen khich ban nghi lai ve goc do khac.\n"
     "Tinh huong: Can tim kiem giai phap cho mot tinh huong khong the tien len."},

    {"Death (Cai Chet): Su ket thuc, bien doi va su doi moi. Dai dien cho su ket thuc cua mot chu ky va su khoi dau moi.\n"
     "Y nghia sau sac: Su ket thuc va bien doi. Khuyen khich ban chap nhan su thay doi trong cuoc song.\n"
     "Tinh huong: Ket thuc mot chu ky de mo ra chu ky moi."},

    {"The Devil (Quy Du): Su le thuoc, cam do va so hai. Goi y su can thiet cua viec giai phong khoi nhung rang buoc tinh than.\n"
     "Y nghia sau sac: Su le thuoc va cam do. Khuyen khich ban giai phong khoi nhung rang buoc.\n"
     "Tinh huong: Can thoat khoi nhung thoi quen xau."},

    {"The Tower (Toa Thap): Su tan vo, thay doi dot ngot va khung hoang. La bieu tuong cua su do vo de thanh lap lai.\n"
     "Y nghia sau sac: Su tan vo va khung hoang. Khuyen khich ban chuan bi cho nhung thay doi manh me.\n"
     "Tinh huong: Doi mat voi khung hoang trong cuoc song."},

    {"The Star (Ngoi Sao): Hy vong, chua lanh va cam hung. Dai dien cho su lac quan va niem tin vao tuong lai.\n"
     "Y nghia sau sac: Hy vong va cam hung. Khuyen khich ban tin tuong vao tuong lai.\n"
     "Tinh huong: Tim thay a sang hy vong trong luc kho khan."},

    {"The Moon (Mat Trang): Ao tuong, bi an va su khong chac chan. Goi y su hieu lam, lo so va nhung dieu an giau.\n"
     "Y nghia sau sac: Ao tuong va bi an. Khuyen khich ban tim kiem su ro rang trong cam xuc.\n"
     "Tinh huong: Can lam ro hon ve cac lo lang va nghi ngo."},

    {"The Sun (Mat Troi): Thanh cong, hanh phuc va su soi sang. Dai dien cho su thanh cong, hanh phuc va su khai sang.\n"
     "Y nghia sau sac: Thanh cong va hanh phuc. Bieu trung cho su toa sang va hanh phuc.\n"
     "Tinh huong: Thoi ky thinh vuong va nen tan huong."},

    {"Judgement (Phan Quyet): Su danh gia, tai sinh va loi nhan. Goi y su xem xet hanh dong va nhung quyet dinh ve tuong lai.\n"
     "Y nghia sau sac: Su danh gia va tai sinh. Khuyen khich ban xem xet hanh dong cua minh.\n"
     "Tinh huong: Can doi mat voi hau qua tu cac quyet dinh truoc do."},

    {"The World (The Gioi): Su hoan thanh, thanh tuu va su trọn ven. Dai dien cho su vien man va thanh cong trong cuoc song.\n"
     "Y nghia sau sac: Su hoan thanh va thanh tuu. Bieu trung cho su hoan thanh va ket thuc thanh cong.\n"
     "Tinh huong: Hoan thanh mot chu ky lon trong cuoc song."}
};

}

TarotCard drawRandomCard(const vector<TarotCard>& deck) {
    int randomIndex = rand() % deck.size();
    return deck[randomIndex];
}

int reduceToSingleDigit(int num) {
    while (num > 9 && num != 11 && num != 22) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int calculateLifePathNumber(int day, int month, int year) {
    int sum = day + month + year;
    return reduceToSingleDigit(sum);
}

int calculateExpressionNumber(const string& name) {
    int sum = 0;
    for (char c : name) {
        if (isalpha(c)) {
            sum += toupper(c) - 'A' + 1;
        }
    }
    return reduceToSingleDigit(sum);
}
int calculatePersonalityNumber(const string& name) {
    int sum = 0;
    for (char c : name) {
        if (isalpha(c) && isupper(c)) {
            sum += (c - 'A' + 1);
        }
    }
    return reduceToSingleDigit(sum);
}

int calculateMissionNumber(const string& name) {
    // Assuming the mission number is calculated similarly to the expression number
    // Implement logic here based on your numerology system
    return calculateExpressionNumber(name);
}

int calculateSoulUrgeNumber(const string& name) {
    int sum = 0;
    for (char c : name) {
        if (isalpha(c)) {
            // Example logic: consider only vowels for the soul urge number
            if (strchr("AEIOU", toupper(c))) {
                sum += toupper(c) - 'A' + 1;
            }
        }
    }
    return reduceToSingleDigit(sum);
}


class User {
private:
    string name;
    string birthDate;
    string gender;

public:
    User() {}

    User(string name, string birthDate, string gender) 
        : name(name), birthDate(birthDate), gender(gender) {}

    string getName() const {
        return name;
    }

    string getBirthDate() const {
        return birthDate;
    }

    string getGender() const {
        return gender;
    }

    friend istream& operator>>(istream& is, User& user) {
        cout << "Nhap ho va ten cua ban: ";
        is >> ws; // Bỏ qua khoảng trắng đầu
        getline(is, user.name);
        cout << "Nhap ngay sinh (dd-mm-yyyy): ";
        is >> user.birthDate;
        cout << "Nhap gioi tinh(Nam/Nu/Khac): ";
        is >> user.gender;
        return is;
    }

    friend ostream& operator<<(ostream& os, const User& user) {
        os << "Ten: " << user.name << "\nNgay sinh: " << user.birthDate 
           << "\nGioi tinh(Nam/Nu/Khac) : " << user.gender << endl;
        return os;
    }

    void saveToFile() const {
        ofstream outFile("user_info.txt", ios::trunc);
        if (outFile.is_open()) {
            outFile << "Ten: " << name << ", Ngay sinh: " << birthDate 
                    << ", Gioi tinh(Nam/Nu/Khac): " << gender << endl;
            outFile.close();
            cout << "Thong tin duoc luu vao  file user_info.txt!" << endl;
        } else {
            cout << "Khong the mo file!" << endl;
        }
    }

    void getBirthDateComponents(int& day, int& month, int& year) const {
        if (sscanf(birthDate.c_str(), "%d-%d-%d", &day, &month, &year) != 3) {
            cout << "Ngay sinh khong dung dinh dang!" << endl;
        }
    }
};

class FortuneTelling {
public:
    virtual void boiToan(User& user) = 0;
};
string getLifePathNumberMeaning(int lifePathNumber) {
        switch (lifePathNumber) {
            case 1:
                return "So 1 la hien than cua su tao bao, doi moi, chap nhan rui ro, kha nang phuc hoi va di theo trai tim minh. "
                   "Nhan so hoc so 1 giup phat trien su sang tao va su tu tin cua ban trong moi khia canh cua cuoc song. "
                   "Muc dich song cua nhung nguoi co so chu dao 1 la mang toi nang luong sang tao tich cuc, dat duoc su doc lap trong cac moi quan he cua ban than.";
            case 2:
                return "So 2 la hien than cho su kien nhan, cong bang, kha nang ngoai giao va mot tam long yeu thuong, nhan ai. "
           "Nhiem vu cua so chu dao 2 la tro thanh nguoi ket noi, hoa giai, dem tinh yeu thuong vao cac moi quan he trong moi khia canh cuoc song. "
           "Muc dich song cua nhung nguoi nay la hoc duoc cach lam viec hai hoa, can bang va ton trong lan nhau.";
            case 3:
                 return "So 3 la hien than cua su nang dong, vui tuoi, kha nang can bang cam xuc va truyen duoc nhieu nguon cam hung. "
           "Nhiem vu cua nhung nguoi mang so 3 trong Than so hoc la nguoi su dung cach dien dat sang tao, phat trien kha nang ket noi, tinh cam lanh manh trong moi khia canh cua cuoc song. "
           "Muc dich song cua nhung nguoi nay la su dung cam xuc, tai nang sang tao cua minh de nang cao tinh than va truyen cam hung toi moi nguoi.";
            case 4:
                 return "So 4 la hien than cho nhung dinh huong, su chia se thuc te, lam viec chin chu. "
           "Nhiem vu cua ban la tao ra su on dinh va an toan khi can hoan thanh mot dieu gi do mang gia tri lau dai. "
           "Muc dich cua nhung nguoi nay la tao nen su ben vung trong qua trinh huong toi muc tieu cuoc doi. "
           "Viec mang lai su an toan cho chinh minh va moi nguoi la dieu ma nhan so hoc so 4 khao khat manh me.";            
            case 5:
               return "So 5 la hien than cho su mao hiem, ban tinh thich phieu luu, khong so hai va muon truyen tai toi moi nguoi cach song tu do. "
           "Nhiem vu cua so 5 trong than so hoc la phat trien su tu do theo thien huong xay dung, ban vua co ky luat vua co mong muon trai nghiem nhung dieu tot dep cuoc song mang lai. "
           "Muc dich cuoc song cua ban la tim thay su tu do ben trong nhung quy tac, luat le va trai nghiem cuoc song.";
            case 6:
               return "So 6 la hien than cho trach nhiem, khong phan xet, khong chi trich nhung hanh dong va lua chon cua nguoi khac, ban co tam nhin xa va kha nang nhin thay toan canh truoc mat. "
           "Nhiem vu cua than so hoc so 6 la phat trien va trau doi kha nang nhin xa trông rong, cung nhu hoc cach chap nhan cuoc song da chieu. "
           "Muc dich song cua nhan so hoc so 6 la dung hoa ly tuong cao dep voi nhung thu khiem khuyet, khong ngung boi bo them tinh yeu thuong trong moi viec ban da, dang va se lam.";
            case 7:
              return "So 7 la hien than cua truc giac, tri tue, khong ngai mo long voi nguoi khac. "
           "Nhiem vu cua than so hoc so 7 la phat trien niềm tin vao dòng chảy cua cuoc song, mo ra su phat trien va nhan thuc cho cac gia tri ca nhan va tinh than. "
           "Muc dich cuoc song cua ban la tin tuong vao ban than, vao qua trinh ban cam thay an toan de co the mo long va chia se tri tue ben trong cua minh ra the gioi.";
            case 8:
               return "So 8 la hien than cho su du da ve tai chinh, su dung quyen luc khon ngoan, luon danh nhieu thoi gian, tien bac va suc anh huong cua minh de lam the gioi tot dep hon. "
           "Nhiem vu cua so 8 trong nhan so hoc la tao ra su doi dao ve vat chat. "
           "Muc dich cuoc song cua ban la su dung anh huong, quyen luc tai chinh cua minh de tao ra dau an tren the gioi va giup do nhung nguoi khac.";
            case 9:
               return "So 9 la hien than cua nguoi lang nghe, biet dong cam va coi mo trong cuoc song. "
           "Nhiem vu cua nhan so hoc so 9 la tro thanh nguoi chinh truc tren con duong theo duoi su sang tao va cong hien. "
           "Muc dich cua ban la song voi cac tieu chuan chinh truc, sap xep cuoc song song song giua tri tue va trai tim, truyen cam hung cho moi nguoi.";
            case 11:
                return "So 11 nhan duoc mon qua thuong de ban cho ban la truc giac rat phong phu. "
           "Ban tot bung va ban la nguoi gioi gin giu hoa binh. Nhan so hoc so 11 co kha nang phat hien cac xu huong moi "
           "va vuot qua cac ranh gioi co huu. Ban cung co the bi loi keo va co kha nang cuc doan. Bai hoc danh cho ban "
           "la tinh quyet doan va kien tri, khong tu bo uoc mo cua minh.";
            case 22:
                 return "So 22 la mot trong bo ba so quan trong trong Nhan so hoc (11, 22, 33). "
           "Theo do, ca 3 so nay duoc lien ket voi nhau va tao thanh \"Tam giac cua su khai sang\". "
           "Moi con so tren deu mang mot bieu tuong lon va nhieu y nghia nho dac thuc. "
           "Nhung nguoi mang van menh than so hoc so 22 thuong co tham vong lon, khat khao phat trien cuoc doi. "
           "Dac biet, ho luon co to chat, phong thai cua nha lanh dao thong minh, tai ba.";
            default:
                return "Khong co y nghia cho so nay.";
        }
    } 

string getMissionNumberMeaning(int missionNumber) {
    switch (missionNumber) {
  case 1:
        return "So su menh 1: Tich cuc:\n"
               "Co y chi, suc manh, long quyet tam, su sang tao, ky luat, doc lap de dua so 1 toi vi tri lanh dao.\n"
               "Lam chu van menh va duong doi cua minh, hanh phuc khi nam quyen, co tinh doc lap manh me.\n"
               "Tieu cuc:\n"
               "Co the thieu kien nhan voi nhung nguoi khong phu hop voi minh.\n"
               "Doi khi co the hach dich voi moi nguoi, khien mot so nguoi roi vao tinh huong khong thoai mai.\n"
               "Nghe nghiep phu hop: doanh nhan, CEO, hieu truong, chinh tri gia.";
        
    case 2:
        return "So su menh 2: Tich cuc:\n"
               "Ngoai giao, binh tinh, kheo leo, thuyet phuc, biet lang nghe, quan tam, yeu thuong nguoi khac.\n"
               "Kha nang thuyet phuc bam sinh, khon kheo va binh tinh de giai quyet van de.\n"
               "Tieu cuc:\n"
               "Bao ve nguoi khac qua muc, noi doi de moi thu yen binh.\n"
               "Bat chap de loi keo nguoi khac (bieu hien khi ban hang).\n"
               "Nghe nghiep phu hop: nha ngoai giao, ban hang, dien vien, giao vien, nha tam ly hoc, co van.";

    case 3:
        return "So su menh 3: Tich cuc:\n"
               "Lac quan, sang tao, nhiet tinh, lang man, hai huoc…lam nguoi khac vui ve khi o ben canh.\n"
               "Ky nang lanh dao sang tao tuyet voi, may man trong kinh doanh.\n"
               "Tieu cuc:\n"
               "De mat tap trung.\n"
               "Khi gap kho khan thi khong muon cho nguoi khac biet, that vong khi khong lam duoc viec gi do.\n"
               "Nghe nghiep phu hop: dien vien, nhac si, nghe si, giao duc.";

    case 4:
        return "So su menh 4: Tich cuc:\n"
               "Cham chi, tan tam, trung thanh, dang tin cay…mong muon xay dung nhung thu co gia tri lau dai.\n"
               "Cham chi cho den khi hoan thanh cong viec.\n"
               "Tieu cuc:\n"
               "Tinh cach te nhat, cung nhac, thieu suc tuong tuong.\n"
               "Doi khi qua nguyen tac, thieu linh hoat.\n"
               "Nghe nghiep phu hop: nha quan ly xuat sac, to chuc.";

    case 5:
        return "So su menh 5: Tich cuc:\n"
               "Vo tu, thich mao hiem, cau tien, nhiet tinh, thich phieu luu… Yeu thich su thay doi va moi me.\n"
               "La nguoi giao tiep dang kinh ngac, co the ket ban qua nhung trai nghiem.\n"
               "Thich di du lich, kham pha nhung dia diem moi va nen van hoa moi.\n"
               "Tieu cuc:\n"
               "De bi nghien nhung thu tieu cuc de giai toa cang thang.\n"
               "Nghe nghiep phu hop: nha van, nha bao, nghe si, giao vien, nha chinh tri.";

    case 6:
        return "So su menh 6: Tich cuc:\n"
               "Tinh cam, doi noi, co trach nhiem, trung thanh, dong cam…\n"
               "Nhieu tinh yeu thuong, luon giup do nguoi khac, cham soc khi can.\n"
               "Muoi ly tuong hoa tinh yeu va lan toa den moi nguoi.\n"
               "Tieu cuc:\n"
               "Doi khi qua cau toan.\n"
               "Dat tieu chuan qua cao dan den ap luc.\n"
               "Quan tam qua muc dan den kiem soat.\n"
               "Nghe nghiep phu hop: giao vien, dien vien, nha van, lanh dao.";

    case 7:
        return "So su menh 7: Tich cuc:\n"
               "Tri thuc, can dam, trung thuc, phan tich, khon ngoan…phat trien dua tren su that.\n"
               "Quan tam den nhung dieu huyen bi, co kha nang tam linh o muc nao do.\n"
               "Tieu cuc:\n"
               "Co the khong lang nghe y kien khac, tro nen kieu ngao.\n"
               "It thay doi quan diem, co chap ve y kien cua minh.\n"
               "Nghe nghiep phu hop: nha giao duc, lanh dao, lam tu thien, truyen giao.";

    case 8:
        return "So su menh 8: Tich cuc:\n"
               "Dong luc lon, quyet tam, kha nang lanh dao, trach nhiem, manh me, co to chuc, thanh cong…\n"
               "Co kha nang chien thang trong bat ky cuoc canh tranh nao, dam chap nhan rui ro.\n"
               "Tieu cuc:\n"
               "Canh tranh qua muc, khong lanh manh.\n"
               "Can bang la viec kho khan doi voi so 8.\n"
               "Nghe nghiep phu hop: doanh nhan, quan doi, chinh phu, tai chinh, ngan hang.";

    case 9:
        return "So su menh 9: Tich cuc:\n"
               "Nghe thuat, hao phong, duy tam, tho mong, nhin xa trong rong…co long vi tha lon.\n"
               "Luon thich lam tu thien, giup do nguoi khac, biet cach thuong thuc nghe thuat va cai dep.\n"
               "Tieu cuc:\n"
               "De chan nan, de tin nguoi, doi khi nong nay va de that vong.\n"
               "Thieu thuc te trong cong viec, muon moi thu duoc lam ngay lap tuc.\n"
               "Nghe nghiep phu hop: lam tu thien, nghe thuat.";

    case 11:
        return "So su menh 11: Tich cuc:\n"
               "Tham vong, hoa giai, than thien…\n"
               "Co kha nang giao tiep tuyet voi, huong ngoai va co dinh huong.\n"
               "La nhung nha lanh dao tuyet voi, co dau oc kinh doanh tot.\n"
               "Tieu cuc:\n"
               "Doi khi kieu ngao, khong khoan nhuong voi nhung nguoi co y kien trai chieu.\n"
               "Nghe nghiep phu hop: su nghiep nghe thuat, cong dong, lanh dao, kinh doanh.";

    case 22:
        return "So su menh 22: Tich cuc:\n"
               "Bien nhung giac mo thanh hien thuc, thuc hien cac du an lon loi ich cho nhan loai.\n"
               "Nhan dao, than thien, co suc hut, duy tam, thuc te, tu tin…\n"
               "Tieu cuc:\n"
               "Kieu ngao, tham lam, ham muon quyen luc nguy hiem neu khong kiem soat.\n"
               "Co the luoi bieng hon nguoi khac, di kem long tham.\n"
               "Nghe nghiep phu hop: nha ngoai giao, tam ly hoc, quan ly.";

    default:
        return "Chi so su menh khong hop le.";
    }
}
string getSoulUrgeNumberMeaning(int soulUrgeNumber) {
    switch (soulUrgeNumber) {
    	  case 1:
            return "Chi so linh hon 1:\n"
                   "Khao khat tro thanh mot ca nhan doc lap, nam giu su doc nhat vo nhi cua minh va tu duy dot pha.\n"
                   "Duoc thuc day bang cach chiu trach nhiem va khoi xuong cac du an, la chinh minh trong su tranh dau, ganh dua.\n"
                   "Khong thich bi bao phai lam gi va khong co y dinh di theo dam dong, chinh phuc, chien thang va vinh quang.";

        case 2:
            return "Chi so linh hon 2:\n"
                   "Muon tro thanh nguoi hoa giai hop tac, nguoi thuc day hoa binh va hoa thuan cho cong dong.\n"
                   "Muon phat trien trong mot moi truong hai hoa noi moi nguoi deu hanh phuc.\n"
                   "Duoc thuc day boi tinh yeu, su hoa hop, tinh ban va cac moi quan he trong cuoc song. Muon ho tro, nuoi duong, yeu thuong va chua lanh vet thuong cho nguoi khac.";

        case 3:
            return "Chi so linh hon 3:\n"
                   "Duoc thoa man dam me sang tao, pha vo gioi han va le loi thong thuong.\n"
                   "Muon vui ve va hanh phuc cho ban than va nguoi khac. So 3 cam thay rang cuoc song co nghia la phai vui ve, vi vay hay song het minh.\n"
                   "Duoc thuc day tu moi nguoi, cuoc tro chuyen, tieng cuoi, giai tri va nghe thuat.";

        case 4:
            return "Chi so linh hon 4:\n"
                   "Duoc tim toi, hoc tap va chia se hieu biet voi nguoi khac, thuc te, chan thuc. Chu toan trong moi viec.\n"
                   "Mong muon mang lai su on dinh, to chuc va trat tu cho gia dinh, noi lam viec va cong dong cua minh.\n"
                   "Muon su on dinh ve tai chinh, tinh cam va the chat de co the song mot cuoc song an toan.";

        case 5:
            return "Chi so linh hon 5:\n"
                   "Duoc la chinh minh khi tu do, kham pha nhu tham hiem, du lich, huong thu cuoc song theo cach rieng cua ban than, duoc giao tiep va ket noi voi moi nguoi.\n"
                   "Mong muon tu do, la chinh minh va song ma khong bi gioi han va han che trong khi nam lay su tu do do mot cach xay dung.\n"
                   "Duoc thuc day boi nhung trai nghiem moi, con nguoi, du lich, su da dang, hung thu va phieu luu.";

        case 6:
            return "Chi so linh hon 6:\n"
                   "Duoc la chinh minh khi nuoi duong nguoi khac, cham soc, quan tam gan gui nhung nguoi ma ho yeu thuong.\n"
                   "Muon mang tinh yeu, ve dep va su hoa hop vao the gioi de moi nguoi co the cam thay hanh phuc, duoc yeu thuong va duoc chua lanh.\n"
                   "Duoc thuc day boi sac dep, tinh yeu, gia dinh, cac moi quan he va phuc vu cham soc cho nguoi khac.";

        case 7:
            return "Chi so linh hon 7:\n"
                   "Duoc lam nhung dieu ban than tin tuong cho du di nguoc voi phan con lai.\n"
                   "Khao khat tro thanh nguoi tim kiem chan ly chiem nghiem, nguoi kham pha ra nhung bi mat va bi an cua cuoc doi.\n"
                   "Muon di den tan cung cua moi thu de xem dieu gi an giau, co the dat duoc dieu nay trong linh vuc khoa hoc, sieu hinh, cong nghe, tam ly hoc, triet hoc, ton giao hoac cac muc tieu hoc thuat khac.";

        case 8:
            return "Chi so linh hon 8:\n"
                   "Duoc la chinh minh khi duoc doc lap ve tai chinh, cong viec an toan, ngoi nha rieng.\n"
                   "Muon tro thanh mot nha lanh dao co dau oc kinh doanh, song theo ly tuong cao ca hon va thai do phong phu.\n"
                   "Mong muon cong bang, duoc trao quyen va phong phu trong cuoc song va cong viec.";

        case 9:
            return "Chi so linh hon 9:\n"
                   "Duoc la chinh minh khi duoc cong hien voi nhung dieu thieng lieng nhat.\n"
                   "Muon tro thanh mot nguoi nhan dao nhan ai, nguoi gop phan lam cho the gioi tro thanh mot noi tot dep hon.\n"
                   "Muon su dung moi co hoi duoc trao de thuc day hoa binh, thong nhat, hieu biet, tha thu va tinh yeu dai chung.";

        case 11:
            return "Chi so linh hon 11:\n"
                   "Khao khat su dong hanh, giong nhu tren bat ky hanh trinh nao cung muon co nguoi ban di chung, nhung o so 11 thi can nguoi ban tinh than hon.\n"
                   "Khao khat nam giu nhung thong tin cung nhu kien thuc ve tam linh.\n"
                   "Duoc tiep xuc voi nhung nguoi thuoc tang lop giong minh la dieu can thiet.";

        case 22:
            return "Chi so linh hon 22:\n"
                   "Duoc lam dieu gi do that vi dai va to lon va lam cho xa hoi tot dep hon.\n"
                   "Duoc la chinh minh khi da chu toan moi viec, thuc hien tat ca suy nghi trong dau.\n"
                   "Duoc tim toi, hoc tap va chia se hieu biet va giup do nguoi khac.";

        default:
            return "Chi so linh hon khong hop le.";
    }
		}	
					
class NumerologyReading : public FortuneTelling {
public:
    void boiToan(User& user) override {
        int day, month, year;
        user.getBirthDateComponents(day, month, year); // Lấy ngày sinh từ người dùng

        int lifePathNumber = calculateLifePathNumber(day, month, year);
        int expressionNumber = calculateExpressionNumber(user.getName());
        int personalityNumber = calculatePersonalityNumber(user.getName()); // Tính số nhân cách
        int missionNumber = calculateMissionNumber(user.getName()); // Tính số sứ mệnh
        int soulUrgeNumber = calculateSoulUrgeNumber(user.getName()); // Tính số linh hồn

        // Menu con cho bói thần số học
        int selected = 0;
        char key;
        do {
           system("cls");
    setColor(13); 
    cout << "+----------------------------------------------+" << endl;
    setColor(14); 
    cout << "|               MENU THAN SO HOC               |" << endl;
    setColor(15);
    cout << "+----------------------------------------------+" << endl;

    // Các tùy chọn với màu sắc khác nhau khi được chọn
    setColor(selected == 0 ? 11 : 7); // Màu xanh dương nhạt nếu được chọn
    cout << "|"<<(selected == 0 ? " -> " : "    ") << "Xem so duong doi (Life Path Number)       |"<<endl;

    setColor(selected == 1 ? 10 : 7); // Màu xanh lá nếu được chọn
    cout << "|"<<(selected == 1 ? " -> " : "    ") << "Xem so ten (Expression Number)            |"<<endl;

    setColor(selected == 2 ? 12 : 7); // Màu đỏ nếu được chọn
    cout << "|"<<(selected == 2 ? " -> " : "    ") << "Xem chi so nhan cach (Personality Number) |"<<endl;

    setColor(selected == 3 ? 13 : 7); // Màu tím nếu được chọn
    cout << "|"<<(selected == 3 ? " -> " : "    ") << "Xem chi so su menh (Mission Number)       |"<<endl;

    setColor(selected == 4 ? 9 : 7); // Màu xanh dương đậm nếu được chọn
    cout << "|"<<(selected == 4 ? " -> " : "    ") << "Xem chi so linh hon (Soul Urge Number)    |"<<endl;

    setColor(selected == 5 ? 14 : 7); // Màu vàng nếu được chọn
    cout << "|"<<(selected == 5 ? " -> " : "    ") << "Quay lai menu chinh                       |"<<endl;

    setColor(10); 
    cout << "+----------------------------------------------+" << endl;

            key = _getch();
            if (key == 72) { // Mũi tên lên
                selected = (selected - 1 + 6) % 6;
            } else if (key == 80) { // Mũi tên xuống
                selected = (selected + 1) % 6;
            } else if (key == 13) { // Phím Enter
                system("cls");
                if (selected == 0) {
                    cout << "So duong doi cua ban la: " << lifePathNumber << endl;
                   cout << "Y nghia:"<< getLifePathNumberMeaning(lifePathNumber) <<endl;
                } else if (selected == 1) {
                    cout << "So ten cua ban la: " << expressionNumber << endl;
                    cout << "Y nghia:"<< getLifePathNumberMeaning(expressionNumber ) <<endl;
                } else if (selected == 2) {
                    cout << "Chi so nhan cach cua ban la: " << personalityNumber << endl;
                     cout << "Y nghia:"<< getLifePathNumberMeaning(personalityNumber) <<endl;
                } else if (selected == 3) {
                    cout << "Chi so su menh cua ban la: " << missionNumber << endl;
    				cout << "Y nghia: " << getMissionNumberMeaning(missionNumber) << endl;
                } else if (selected == 4) {
                    cout << "Chi so linh hon cua ban la: " << soulUrgeNumber << endl;
                    cout << "Y nghia: " << getSoulUrgeNumberMeaning(soulUrgeNumber) << endl;
                } else {
                    break; // Quay lại menu chính
                }
                system("pause");
            }
        } while (true);
    }
};

class TarotReading : public FortuneTelling {
public:
    void boiToan(User& user) override {
        vector<TarotCard> deck = createTarotDeck();
        int selected = 0;
        char key;

        do {
            system("cls");
            setColor(5); 
            cout << "+------------------------------+" << endl;
            setColor(14); // Màu vàng
            cout << "|         MENU BOI TAROT       |" << endl;
            setColor(4); 
            cout << "+------------------------------+" << endl;

            // In các tùy chọn với màu sắc giống như menu chính
            setColor(selected == 0 ? 11 : 7); // Màu xanh lá cây nếu được chọn
            cout << "|"<<(selected == 0 ? " -> " : "    ") << "Boi su nghiep             |"<<endl;

            setColor(selected == 1 ? 10 : 7); // Màu xanh lá khác nếu được chọn
            cout << "|"<<(selected == 1 ? " -> " : "    ") << "Boi tinh yeu              |"<<endl;

            setColor(selected == 2 ? 12 : 7); // Màu đỏ nếu được chọn
            cout << "|"<<(selected == 2 ? " -> " : "    ") << "Boi gia dinh              |"<<endl;

            setColor(selected == 3 ? 13 : 7); // Màu tím nếu được chọn
            cout << "|"<<(selected == 3 ? " -> " : "    ") << "Boi qua khu               |"<<endl;

            setColor(selected == 4 ? 9 : 7); // Màu xanh dương nếu được chọn
            cout << "|"<<(selected == 4 ? " -> " : "    ") << "Boi hien tai              |"<<endl;

  		    setColor(selected == 5 ? 13 : 7); // Màu xanh dương nếu được chọn
            cout << "|"<<(selected == 5 ? " -> " : "    ") << "Boi tuong lai             |"<<endl;
            
            setColor(selected == 6 ? 14 : 7); // Màu vàng nếu được chọn
            cout << "|"<<(selected == 6 ? " -> " : "    ") << "Quay lai menu chinh       |"<<endl;

            setColor(6); // Trở lại màu trắng
            cout << "+------------------------------+" << endl;

            key = _getch(); // Nhận phím từ người dùng

            if (key == 72) { // Mũi tên lên
                selected = (selected - 1 + 7) % 7;
            } else if (key == 80) { // Mũi tên xuống
                selected = (selected + 1) % 7;
            } else if (key == 13) { // Phím Enter
                system("cls");
                if (selected <6) { // Chỉ số lựa chọn trong menu
                    TarotCard drawnCard = drawRandomCard(deck);
                    cout << "Ban da rut duoc la bai: " << drawnCard.name << endl;
                  
                } else {
                    break; // Quay lại menu chính
                }
                  system("pause");
            }
        } while (true);
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Khởi tạo hạt giống cho random


    User user;
    FortuneTelling* reading = nullptr; // Con trỏ cho việc bói toán
    int selected = 0;
    char key;
    do {
           system("cls");
    setColor(9); // Màu trắng mặc định
    cout << "+----------------------------------+" << endl;
    setColor(14);
    cout << "|             MENU CHINH           |" << endl;
    setColor(13);
    cout << "+----------------------------------+" << endl;

    setColor(selected == 0 ? 11 : 7); // Màu xanh lá cây cho mục đang chọn, màu trắng cho mục khác
    cout << "|"<<(selected == 0 ? " -> " : "    ") << "Nhap thong tin nguoi xem boi  |"<<endl;

    setColor(selected == 1 ? 10 : 7);
    cout << "|"<<(selected == 1 ? " -> " : "    ") << "Xem boi than so hoc           |"<<endl;

    setColor(selected == 2 ? 12 : 7);
    cout << "|"<<(selected == 2 ? " -> " : "    ") << "Xem boi tarot                 |"<<endl;

    setColor(selected== 3 ? 13 : 7);
    cout << "|"<<(selected == 3 ? " -> " : "    ") << "Thoat                         |"<<endl;

    setColor(4); // Trở lại màu trắng sau khi in menu
    cout << "+----------------------------------+" << endl;
        

        key = _getch();
        if (key == 72) { // Mũi tên lên
            selected = (selected - 1 + 4) % 4;
        } else if (key == 80) { // Mũi tên xuống
            selected = (selected + 1) % 4;
        } else if (key == 13) { // Phím Enter
            system("cls");
            if (selected == 0) {
                cin >> user; // Nhập thông tin từ người dùng
                user.saveToFile(); // Lưu thông tin vào file
                system("pause");
            } else if (selected == 1) {
                reading = new NumerologyReading(); 
                reading->boiToan(user);
                delete reading; // Giải phóng bộ nhớ
            } else if (selected == 2) {
                reading = new TarotReading();
                reading->boiToan(user);
                delete reading; // Giải phóng bộ nhớ
            } else {
                break; // Thoát chương trình
            }
        }
    } while (true); 

    return 0;
}
