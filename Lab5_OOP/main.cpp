#include <iostream>
#include <string>
#include <vector>

// Абстрактный базовый класс PERSON
class PERSON {
protected:
    std::string name;
    int age;
public:
    PERSON(const std::string& name, int age) : name(name), age(age) {}
    virtual ~PERSON() {}

    // Виртуальные методы для изменения полей (чисто виртуальные - абстрактные)
    virtual void setName(const std::string& name) = 0;
    virtual void setAge(int age) = 0;

    // Метод для вывода информации
    virtual void printInfo() const {
        std::cout << "Имя: " << name << ", Возраст: " << age; 
    }
};

// Производный класс TEACHER
class TEACHER : public PERSON {
private:
    std::string subject;
    int hours;
public:
    TEACHER(const std::string& name, int age, const std::string& subject, int hours) 
        : PERSON(name, age), subject(subject), hours(hours) {}

    // Переопределение виртуальных методов
    void setName(const std::string& name) override { this->name = name; }
    void setAge(int age) override { this->age = age; }

    // Методы для изменения полей предмета и часов
    void setSubject(const std::string& subject) { this->subject = subject; }
    void setHours(int hours) { this->hours = hours; }
    void addHours(int additionalHours) { hours += additionalHours; }
    void reduceHours(int hoursToReduce) { 
        if (hoursToReduce <= hours) {
            hours -= hoursToReduce;
        } else {
            std::cout << "Попытка уменьшить большее количество часов, чем их указано" << std::endl;
        }
    }

    // Переопределение метода вывода информации
    void printInfo() const override {
        PERSON::printInfo(); // Вызов метода базового класса
        std::cout << ", Предмет: " << subject << ", Часы: " << hours << std::endl;
    }
};

// Класс Vector для хранения указателей на объекты PERSON
class PersonVector {
private:
    std::vector<PERSON*> persons;
public:
    // Добавление объекта в вектор
    void addPerson(PERSON* person) {
        persons.push_back(person);
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const PersonVector& vector) {
        for (const PERSON* person : vector.persons) {
            person->printInfo(); // Полиморфный вызов printInfo
        }
        return os;
    }
};

int main() {
    // Создание объектов
    TEACHER teacher1("Иван Петрович", 50, "Математика", 20);
    TEACHER teacher2("Мария Ивановна", 45, "Физика", 18);

    // Создание вектора и добавление объектов
    PersonVector personVector;
    personVector.addPerson(&teacher1);
    personVector.addPerson(&teacher2);

    // Вывод информации о всех объектах в векторе
    std::cout << personVector << std::endl;
    
    // Использование методов
    teacher1.setSubject("Алгебра"); // Изменение предмета для учителя 1
    teacher1.addHours(5); // Увеличение часов для учителя 2
    teacher2.reduceHours(3); // Уменьшение часов для учителя 2
    
    // Вывод информации о всех объектах в векторе
    std::cout << personVector << std::endl;

    return 0;
}