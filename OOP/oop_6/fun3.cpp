#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Item {
protected:
 string title;
 int weight;
 int level;
 bool magical;
public:
 // Так можно создать предмет, указав его название, вес, уровень и магичность
 Item(string title, int weight, int level, bool magical) {
 this->title = title;
 this->weight = weight;
 this->level = level;
 this->magical = magical;
 }
 // Получить вес предмета
 int getWeight() const {
 return weight;
 }
 // Получить уровень предмета
 int getLevel() const {
 return level;
 }
 // Получить, является ли предмет магичным
 int isMagical() const {
 return magical;
 }
};
// Базовый класс героя
class Player {
protected:
 // Сила и уровень героя
 int strength;
 int level;
public:
 // Создать героя, все подробности будут указаны позже
 Player() { }
 // Удалить героя, ничего умного эта процедура пока что не требует
 virtual ~Player() { }
 // Базовые методы, пока что очень простые.
 // На данном этапе можно считать, что для всех героев они ведут себя одинаково,
 // так что пусть будут в базовом классе.
 // Задать силу
 virtual void setStrength(int strength) final {
 this->strength = strength;
 }
 // Задать уровень
 virtual void setLevel(int level) final {
 this->level = level;
 }
 // Получить силу
 virtual int getStrength() const final {
 return strength;
 }
 // Получить уровень
 virtual int getLevel() const final {
 return level;
 }
 // Проверка, может ли игрок использовать предмет.
 // Рыцарь может использовать (а) только немагические предметы и только если
 // (б) сила героя не меньше веса предмета, (в) уровень героя не меньше уровня

 virtual bool canUse(const Item& item) const = 0;
 // Может ли игрок колдовать, зависит от конкретного класса игрока
 virtual bool canCast() const = 0;
 // Проверка, может ли игрок лечить других игроков.
 // Лечить умеет или любой волшебник, или
 // игрок достаточно высокого уровня.
 virtual bool canHeal() const {
 return canCast() || getLevel() > 10;
 }
};

// Класс рыцаря
class Knight : public Player {
public:
    // Создать рыцаря
    Knight() {
        strength = 10;
        level = 1;
    }

    // Проверка, может ли игрок использовать предмет.
    // Рыцарь может использовать (а) только немагические предметы и только если
    // (б) сила героя не меньше веса предмета, (в) уровень героя не меньше уровня
    // предмета.
    bool canUse(const Item& item) const override {
        return !item.isMagical() && strength >= item.getWeight() && level >= item.getLevel();
    }

    // Может ли рыцарь колдовать? Нет, конечно.
    bool canCast() const override {
        return false;
    }
};

// Класс волшебника
class Wizard : public Player {
public:
    // Создать волшебника
    Wizard() {
        strength = 3;
        level = 1;
    }

    // Проверка, может ли игрок использовать предмет.
    // Волшебник может использовать все предметы, если его уровень
    // не меньше уровня предмета.
    bool canUse(const Item& item) const override {
        return level >= item.getLevel();
    }

    // Может ли волшебник колдовать? Да, конечно.
    bool canCast() const override {
        return true;
    }
};

int main(){
    Item items[3] = {
 Item("Small sword", 1, 1, false),
 Item("Big sword", 5, 3, false),
 Item("Ward", 1, 3, true)
 };
 Player* players[2];
 players[0] = new Wizard();
 players[0]->setStrength(3);
 players[0]->setLevel(5);
 players[1] = new Knight();
 players[1]->setStrength(6);
 players[1]->setLevel(5);
 for(int i = 0; i < 2; i++) {
 cout << "Can heal: " << players[i]->canHeal() << endl;
 }
 for(int i = 0; i < 2; i++) {
 for(int j = 0; j < 3; j++) {
 cout << "Can use: " << players[i]->canUse(items[j]) << endl;
 }
 }
 for(int i = 0; i < 2; i++)
 delete players[i];
}