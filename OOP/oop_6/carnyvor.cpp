#include <iostream>

class Animal
{
protected:
 double mass;
 double speed;
public:
 Animal() {}
 virtual ~Animal() {}
 // Создаём зверушку с заданной массой и скоростью
 Animal(double mass, double speed) {
 this->mass = mass;
 this->speed = speed;
 }
 // Получить массу зверя
 virtual double getMass() const {
 return mass;
 }
 // Получить скорость зверя
 virtual double getSpeed() const {
 return speed;
 }
 // Может ли зверушка нападать на других зверей
 // (не может, зверь мирный)
 virtual bool canAtack() const {
 return false;
 }
 // Съесть другого зверя, не делает ничего, мы же мирные
 virtual void eat(const Animal& a) {
 }
};


class Predator : public Animal {
public:
    using Animal::Animal;

    // Перегрузка метода canAtack
    virtual bool canAtack() const override {
        return true;
    }

    // Перегрузка метода eat
    virtual void eat(const Animal& a) override {
        if (a.getMass() <= mass && a.getSpeed() <= speed) {
            mass += a.getMass();
        }
    }
};

int main() {
    Animal* predator = new Predator(1, 10);
    std::cout << "Current mass: " << predator->getMass() << std::endl;

    if (predator->canAtack()) {
        predator->eat(Animal(2, 1)); // Этого не съедим - слишком большой
        std::cout << "Current mass: " << predator->getMass() << std::endl;

        predator->eat(Animal(1, 1)); // А вот этого вполне
        std::cout << "Current mass: " << predator->getMass() << std::endl;

        predator->eat(Animal(1, 20)); // Этого не выйдет - слишком быстрый
        std::cout << "Current mass: " << predator->getMass() << std::endl;

        predator->eat(Animal(2, 2)); // А вот этого догоним
        std::cout << "Current mass: " << predator->getMass() << std::endl;
    }

    delete predator;

    return 0;
}

