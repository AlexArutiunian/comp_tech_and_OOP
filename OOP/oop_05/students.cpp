#include <iostream>
#include <string>

class Student {
public:
    // Задать имя студента
    void setName(std::string name) {
        name_ = name;
    }

    // Указать количество баллов за контрольную
    void setScore(unsigned int score) {
        score_ = score;
    }

    // Получить имя студента
    std::string getName() const {
        return name_;
    }

    // Получить количество баллов студента
    unsigned int getScore() const {
        return score_;
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Student& student) {
        std::getline(is, student.name_);
        student.score_ = 0;
        return is;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "'" << student.name_ << "': " << student.score_;
        return os;
    }

private:
    std::string name_;
    unsigned int score_ = 0;
};

int main() {
    Student s;
    std::cin >> s;
    s.setScore(10);
    std::cout << s << std::endl;

    return 0;
}

