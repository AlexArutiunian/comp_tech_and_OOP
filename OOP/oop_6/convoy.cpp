#include <iostream>
#include <vector>

class Car
{
protected:
 bool allowesBoarding;
 bool allowesLoading;
 unsigned int numberOfSeats;
 unsigned int numberOfContainers;
public:
 Car(bool allowesBoarding, bool allowesLoading, unsigned int numberOfSeats,
unsigned int numberOfContainers) {
 this->allowesBoarding = allowesBoarding;
 this->allowesLoading = allowesLoading;
 this->numberOfSeats = numberOfSeats;
 this->numberOfContainers = numberOfContainers;
 }
 ~Car() {}
 bool isBoardingAllowed() const {
 return allowesBoarding;
 }
 bool isLoadingAllowed() const {
 return allowesLoading;
 }
 unsigned int getNumberOfSeats() const {
 return numberOfSeats;
 }
 unsigned int getNumberOfContainers() const {
 return numberOfContainers;
 }
};

class ConvoyManager {
public:
    // Зарегистрировать новую машину в колонне
    void registerCar(const Car& c) {
        if (c.isBoardingAllowed()) {
            totalSeats_ += c.getNumberOfSeats();
        }
        if (c.isLoadingAllowed()) {
            totalContainers_ += c.getNumberOfContainers();
        }
        cars_.push_back(c);
    }

    // Сообщить, сколько всего пассажиров может принять колонна
    unsigned int getTotalSeats() const {
        return totalSeats_;
    }

    // Сообщить, сколько всего грузовых контейнеров может взять колонна
    unsigned int getTotalContainers() const {
        return totalContainers_;
    }

private:
    std::vector<Car> cars_;
    unsigned int totalSeats_ = 0;
    unsigned int totalContainers_ = 0;
};




int main() {
    ConvoyManager cm;

    Car c1(true, false, 12, 3);
    cm.registerCar(c1);

    Car c2(false, true, 12, 3);
    cm.registerCar(c2);

    Car c3(true, true, 12, 3);
    cm.registerCar(c3);

    Car c4(false, false, 12, 3);
    cm.registerCar(c4);

    std::cout << "Total available seats: " << cm.getTotalSeats() << std::endl;
    std::cout << "Total available containers: " << cm.getTotalContainers() << std::endl;

    return 0;
}
