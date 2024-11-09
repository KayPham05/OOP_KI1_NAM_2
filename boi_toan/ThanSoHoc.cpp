    #include "ThanSoHoc.h"

    int reduceToSingleDigit(int num) {
    while (num > 9 ) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}
    int ThanSoHoc::calculateNumerology(User& user) {
        int sum=reduceToSingleDigit(user.getDay().ngay)+reduceToSingleDigit(user.getDay().thang)+reduceToSingleDigit(user.getDay().nam);
        if(sum == 11|| sum == 22){
            return sum;
        }else{
            return reduceToSingleDigit(sum);
        }
    }
    void ThanSoHoc:: display(User& user) {
        int number=calculateNumerology(user);
        cout<<user.getDay().ngay<<"\n"<<user.getDay().thang<<"\n"<<user.getDay().nam<<endl;
        switch (number) {
        case 1:
                    cout << "So 10:Đai dien cho su tao bao, doi moi, chap nhan rui ro, kha nang phuc hoi va di theo tieng noi ben trong, co to chat lanh dao." << endl;
                    break;
                case 2:
                    cout << "So 2: Dai dien cho su kien nhan, cong bang, kha nang ngoai giao va tam long yeu thuong, nhan ai." << endl;
                    break;
                case 3:
                    cout << "So 3: Dai dien cho su nang dong, tu tin, vui tuoi, kha nang can bang cam xuc, bieu cam tu nhien va truyen duoc nhieu nguon cam hung." << endl;
                    break;
                case 4:
                    cout << "So 4: Dai dien cho dinh huong thuc te, su chia se thuc te, lam viec de thiet lap cam giac an toan, dong thoi hieu va thuc hien duoc suc manh cua qua trinh san xuat." << endl;
                    break;
                case 5:
                    cout << "So 5: Dai dien cho su mao hiem, thich phieu luu, khong so hai, luon ky luat ban than va muon chi cho moi nguoi dat duoc cach song tu do." << endl;
                    break;
                case 6:
                    cout << "So 6: Dai dien cho su trach nhiem, khong phan xet, khong chi trich nhung hanh dong va lua chon cua nguoi khac, ban co tam nhin xa, nhin thay toan canh truoc mat. San long giup do nguoi khac mot cach chan thanh." << endl;
                    break;
                case 7:
                    cout << "So 7: Dai dien cho truc giac, tri tue, luon tim kiem ban chat cua van de, su vat, hien tuong." << endl;
                    break;
                case 8:
                    cout << "So 8: Dai dien cho su thoai mai, du da ve tai chinh, su dung quyen luc mot cach khon ngoan vi loi ich cua nguoi khac." << endl;
                    break;
                case 9:
                    cout << "So 9: Dai dien cho tinh than nhan dao, thuong nghi cho nguoi khac, cho cong dong. Dong thoi, day la nguoi co nghi luc va y chi manh me, dung cam." << endl;
                    break;
                case 11:
                    cout << "So 11/2: Dai dien cho su tinh te, so huu mot truc giac vo cung tot, co kha nang thau hieu nhung nguoi xung quanh." << endl;
                    break;
                case 22:
                    cout << "So  22/4: Dai dien cho su kien cuong, thong minh va quyet doan. Ngoai ra, day la con so co trach nhiem, nguyen tac va ky luat trong cong viec va cuoc song." << endl;
                    break;
                default:
                    cout << "Khong co y nghia cho so nay." << endl;
                    break;
        }
    }
