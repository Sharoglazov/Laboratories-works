#include <iostream>
#include <string>

class PERSON {
private:
    std::string name;
    int age;
public:
    // Конструкторы
    PERSON() : name(""), age(0) {}
    PERSON(const std::string& name, int age) : name(name), age(age) {}
    PERSON(const PERSON& other) : name(other.name), age(other.age) {}

    // Деструктор
    ~PERSON() {}

    // Геттеры и сеттеры
    std::string getName() const { return name; }
    int getAge() const { return age; }
    void setName(const std::string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }

    // Перегрузка оператора присваивания 
    PERSON& operator=(const PERSON& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const PERSON& person) {
        os << "Имя: " << person.name << ", Возраст: " << person.age;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, PERSON& person) {
        std::cout << "Введите имя: ";
        is >> person.name;
        std::cout << "Введите возраст: ";
        is >> person.age;
        return is;
    }
};

// Производный класс STUDENT
class STUDENT : public PERSON {
private:
    std::string subject;
    int mark;
public:
    // Конструкторы
    STUDENT() : PERSON(), subject(""), mark(0) {}
    STUDENT(const std::string& name, int age, const std::string& subject, int mark)
        : PERSON(name, age), subject(subject), mark(mark) {}
    STUDENT(const STUDENT& other) : PERSON(other), subject(other.subject), mark(other.mark) {}

    // Деструктор
    ~STUDENT() {}

    // Геттеры и сеттеры
    std::string getSubject() const { return subject; }
    int getMark() const { return mark; }
    void setSubject(const std::string& subject) { this->subject = subject; }
    void setMark(int mark) { this->mark = mark; }

    // Проверка оценки
    void checkMark() {
        if (mark < 4) {
            std::cout << "Неудовлетворительная оценка " << getName() << " по " << subject << std::endl;
        }
    }

    // Перегрузка оператора присваивания 
    STUDENT& operator=(const STUDENT& other) {
        if (this != &other) {
            PERSON::operator=(other);
            subject = other.subject;
            mark = other.mark;
        }
        return *this;
    }

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const STUDENT& student) {
        os << static_cast<const PERSON&>(student) << ", Предмет: " << student.subject 
           << ", Оценка: " << student.mark;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, STUDENT& student) {
        is >> static_cast<PERSON&>(student);
        std::cout << "Введите предмет: ";
        is >> student.subject;
        std::cout << "Введите оценку: ";
        is >> student.mark;
        return is;
    }
};

// Функции для демонстрации принципа подстановки
void printPersonInfo(const PERSON& person) {
    std::cout << person << std::endl;
}

PERSON createPerson() {
    std::string name;
    int age;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    return PERSON(name, age);
}

int main() {
    PERSON person1("Иван", 30);
    PERSON person2;
    std::cin >> person2; 

    STUDENT student1("Петр", 20, "Математика", 5);
    STUDENT student2;
    std::cin >> student2;

    std::cout << "Person 1: " << person1 << std::endl;
    std::cout << "Person 2: " << person2 << std::endl; 
    std::cout << "Student 1: " << student1 << std::endl;
    std::cout << "Student 2: " << student2 << std::endl;

    student1.checkMark();
    student2.checkMark();

    // Принцип подстановки
    printPersonInfo(person1);
    printPersonInfo(student1); 

    PERSON person3 = createPerson();
    std::cout << "Created person: " << person3 << std::endl;

    return 0;
}