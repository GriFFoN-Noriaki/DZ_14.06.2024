#include <iostream>
#include <string>
#include <vector>

enum class EntityType {Bird, Livestock, Human};

struct Characteristic 
{
    union 
    {
        double flightSpeed; // Для птицы
        bool isUngulate;    // Для скота
        int iqLevel;        // Для человека
    };
};

struct LivingEntity 
{
    double speed;
    EntityType type;
    std::string color;
    Characteristic characteristic;

    void input() 
    {
        setlocale(LC_ALL, "rus");

        std::cout << "Введите скорость: ";
        std::cin >> speed;
        int typeInput;
        std::cout << "Введите тип (0 - Птица, 1 - Скот, 2 - Человек): ";
        std::cin >> typeInput;
        type = static_cast<EntityType>(typeInput);
        std::cout << "Введите цвет: ";
        std::cin >> color;

        if (type == EntityType::Bird) 
        {
            std::cout << "Введите скорость полета: ";
            std::cin >> characteristic.flightSpeed;
        }
        else if (type == EntityType::Livestock) 
        {
            std::cout << "Парнокопытное? (1 - Да, 0 - Нет): ";
            std::cin >> characteristic.isUngulate;
        }
        else if (type == EntityType::Human) 
        {
            std::cout << "Введите уровень IQ: ";
            std::cin >> characteristic.iqLevel;
        }
    }

    void print() 
    {
        setlocale(LC_ALL, "rus");

        std::cout << "Скорость: " << speed << ", Тип: " << static_cast<int>(type)
            << ", Цвет: " << color << ", ";
        if (type == EntityType::Bird) 
        {
            std::cout << "Скорость полета: " << characteristic.flightSpeed << "\\n";
        }
        else if (type == EntityType::Livestock) 
        {
            std::cout << "Парнокопытное: " << (characteristic.isUngulate ? "Да" : "Нет") << "\\n";
        }
        else if (type == EntityType::Human) 
        {
            std::cout << "Уровень IQ: " << characteristic.iqLevel << "\\n";
        }
    }
};

int main() 
{
    std::vector<LivingEntity> entities(10);

    // Ввод информации для всех сущностей
    for (auto& entity : entities) 
    {
        entity.input();
    }

    // Печать всего списка
    for (auto& entity : entities) 
    {
        entity.print();
    }

    return 0;
}