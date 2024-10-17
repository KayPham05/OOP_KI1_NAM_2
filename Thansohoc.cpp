#include <iostream>
#include <string>
#include <cctype>

// Hàm tính tổng các chữ số cho đến khi có số đơn
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

// Hàm tính Số Đường đời dựa trên ngày, tháng, năm sinh
int calculateLifePathNumber(int day, int month, int year) {
    int sum = day + month + year;
    return reduceToSingleDigit(sum);
}

// Hàm tính Số Tên dựa trên giá trị chữ cái trong tên
int calculateExpressionNumber(const std::string& name) {
    int sum = 0;
    for (char c : name) {
        if (std::isalpha(c)) {
            sum += std::toupper(c) - 'A' + 1; // A=1, B=2, ..., Z=26
        }
    }
    return reduceToSingleDigit(sum);
}

int main() {
    // Nhập tên và ngày sinh từ người dùng
    std::string name;
    int day, month, year;

    std::cout << "Nhap ho va ten cua ban: ";
    std::getline(std::cin, name);
    std::cout << "Nhap ngay sinh(cach nhau bang khoang trang) ";
    std::cin >> day >> month >> year;

    // Tính toán số Đường đời và Số Tên
    int lifePathNumber = calculateLifePathNumber(day, month, year);
    int expressionNumber = calculateExpressionNumber(name);

    // Hiển thị kết quả
    std::cout << "So duong doi (Life Path Number): " << lifePathNumber << std::endl;
    std::cout << "So ten (Expression Number): " << expressionNumber << std::endl;

    return 0;
}
