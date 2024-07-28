#include <iostream>
#include <string>

struct Car 
{
    std::string color;
    std::string model;
    union {
        int number; // пятизначный номер
        char word[9]; // слово до 8 символов
    } plateNumber;
    bool isNumber; // флаг, чтобы определить тип номера

    // Функция для заполнения автомобиля
    void fillCar() 
    {
        setlocale(LC_ALL, "rus");

        std::cout << "Введите цвет: ";
        std::cin >> color;
        std::cout << "Введите модель: ";
        std::cin >> model;
        std::cout << "Введите номер (5 цифр или до 8 символов): ";
        std::string temp;
        std::cin >> temp;
        if (temp.size() == 5 && std::isdigit(temp[0])) 
        {
            plateNumber.number = std::stoi(temp);
            isNumber = true;
        }
        else 
        {
            strcpy_s(plateNumber.word, temp.c_str());
            isNumber = false;
        }
    }

    // Функция для печати информации о машине
    void printCar() const 
    {
        setlocale(LC_ALL, "rus");

        std::cout << "Цвет: " << color << ", Модель: " << model << ", Номер: ";
        if (isNumber) 
        {
            std::cout << plateNumber.number;
        }
        else 
        {
            std::cout << plateNumber.word;
        }
        std::cout << std::endl;
    }
};

// Функции для работы с массивом машин
void printAllCars(Car cars[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cars[i].printCar();
    }
}

// Пример поиска машины по номеру можно реализовать дополнительно

int main() {
    Car garage[10]; // Массив из 10 машин
    for (int i = 0; i < 10; i++) 
    {
        garage[i].fillCar();
    }
    printAllCars(garage, 10);
    return 0;
}