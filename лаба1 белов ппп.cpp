#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>

#define REGION_INFO_SIZE 32
#define MAX_HOUSE_NUM 256
#define MAX_PRICE_PER_MONTH 20000

class Service {
public:
    char country[REGION_INFO_SIZE] = "\0";
    char city[REGION_INFO_SIZE] = "\0";
    char region[REGION_INFO_SIZE] = "\0";
    char street[REGION_INFO_SIZE] = "\0";

    unsigned int houseNum;
    unsigned int countResidents;
    unsigned int paidResidents;

    double pricePerMonth;

    void registerHouse() {

        while (country[0] == '\0') {
            std::cout << "Введите страну: ";
            scanf_s("%[^\n]", &country, REGION_INFO_SIZE);
            if (country[0] == '\0') {
                std::cout << "Введите значение!" << std::endl;
                std::cin.ignore(256, '\n');
            }
        }
        std::cin.ignore(256, '\n');

        while (region[0] == '\0') {
            std::cout << "Введите регион: ";
            scanf_s("%[^\n]", &region, REGION_INFO_SIZE);
            if (region[0] == '\0') {
                std::cout << "Введите значение!" << std::endl;
                std::cin.ignore(256, '\n');
            }
        }
        std::cin.ignore(256, '\n');

        while (city[0] == '\0') {
            std::cout << "Введите город: ";
            scanf_s("%[^\n]", &city, REGION_INFO_SIZE);
            if (city[0] == '\0') {
                std::cout << "Введите значение!" << std::endl;
                std::cin.ignore(256, '\n');
            }
        }
        std::cin.ignore(256, '\n');

        while (street[0] == '\0') {
            std::cout << "Введите улицу: ";
            scanf_s("%[^\n]", &street, REGION_INFO_SIZE);
            if (street[0] == '\0') {
                std::cout << "Введите значение!" << std::endl;
                std::cin.ignore(256, '\n');
            }
        }
        std::cin.ignore(256, '\n');

        std::cout << "Введите номер дома: ";
        while (!isValidType(houseNum, "Номер дома должен быть целым числом!\n", MAX_HOUSE_NUM)) {
            std::cout << "Введите номер дома: ";
        };

        std::cout << "Введите количество жильцов в доме: ";
        while (!isValidType(countResidents, "Число жильцов должно быть натуральным!\n", (int)1e+6)) {
            std::cout << "Введите количество жильцов в доме: ";
        }

        std::cout << "Введите сумму оплаты за ЖЭС в месяц: ";
        while (!isValidType(pricePerMonth, "Сумма ЖЭС должна быть вещественным числом!\n", MAX_PRICE_PER_MONTH)) {
            std::cout << "Введите сумму оплаты за ЖЭС в месяц: ";
        }

        std::cout << "Дом по адресу: регион " << region << ", г. " << city << ", ул. " << street << ", д. " << houseNum << " зарегестрирован в системе!" << std::endl;
        printf_s("Число жильцов: %d чел.\nУстановленная плата: %.2f р/мес\nОбщая сумма платы ЖЭС: %.2f р/мес\n", countResidents, pricePerMonth, totalCost());
    }

    double totalCost() {
        return countResidents * pricePerMonth;
    }

    double currentCost() {
        return totalCost() - (paidResidents * pricePerMonth);
    }

    void editResident(int act) {
        switch (act) {
        case 1:
            countResidents++;
        case 0:
            countResidents--;
        default:
            countResidents++;
        }
    }

    void editPrice(double price) {
        pricePerMonth = price;
    }

    void reset() {
        paidResidents = 0;
    }

private:
    bool isValidType(double& value, const char* error_msg = "Введён неверный тип данных!\n", double max_value = MAX_PRICE_PER_MONTH) {

        char c;
        char result[16];
        size_t index = 0;

        while (std::cin.get(c)) {
            if (c == '\n') break;
            if (isdigit(c) || c == '.') {
                result[index] = c;
                index++;
            }
            else {
                std::cout << error_msg;
                std::cin.ignore(64, '\n');
                return false;
            }

        }

        result[index] = '\0';

        value = std::stod(result);
        if (value > max_value) {
            std::cout << "Превышено максимальное число! (" << max_value << ")" << std::endl;
            return false;
        }

        std::cin.clear();
        return true;
    }

    bool isValidType(unsigned int& value, const char* error_msg = "Введён неверный тип данных!\n", unsigned int max_value = 1e+6) {

        char c;
        char result[16];
        size_t index = 0;

        while (std::cin.get(c)) {
            if (c == '\n') break;
            if (isdigit(c)) {
                result[index] = c;
                index++;
            }
            else {
                std::cout << error_msg;
                std::cin.ignore(64, '\n');
                return false;
            }
        }

        result[index] = '\0';

        value = std::atoi(result);
        if (value > max_value) {
            std::cout << "Превышено максимальное число! (" << max_value << ")" << std::endl;
            return false;
        }

        std::cin.clear();
        return true;
    }

};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Service service;
    service.registerHouse();
}