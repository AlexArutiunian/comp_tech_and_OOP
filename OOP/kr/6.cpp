
#include <vector>
#include <iostream>

class Point
{
protected:
 double _x;
 double _y;
 double _z;
public:
 Point(double x, double y, double z): _x(x), _y(y), _z(z) {
 }

 double x() const {
 return _x;
 }
 double y() const {
 return _y;
 }
 double z() const {
 return _z;
 }
};



class Scene {
public:
    virtual bool contains(const Point& p) const {
        return true; // Базовая реализация - принимаем все точки
    }

    void append(const Point& p) {
        if (contains(p)) {
            _points.push_back(p);
        }
    }

    unsigned long size() const {
        return _points.size();
    }

    const Point& operator[](int index) const {
        return _points[index];
    }

protected:
    std::vector<Point> _points;
};


class CroppedScene : public Scene {
public:
    CroppedScene(double xMin, double yMin, double zMin,
                 double xMax, double yMax, double zMax)
        : _xMin(xMin), _yMin(yMin), _zMin(zMin),
          _xMax(xMax), _yMax(yMax), _zMax(zMax) {}

    bool contains(const Point& p) const override {
        return (p.x() >= _xMin && p.x() <= _xMax &&
                p.y() >= _yMin && p.y() <= _yMax &&
                p.z() >= _zMin && p.z() <= _zMax);
    }

private:
    double _xMin, _yMin, _zMin;
    double _xMax, _yMax, _zMax;
};

int main() {
    // Создаем базовую сцену
    Scene s;

    // Создаем несколько точек
    Point p1(10.1, 10.1, 10.1);
    Point p2(2, 2, 2);

    // Добавляем точки в сцену
    s.append(p1);
    s.append(p2);

    // Проверяем количество точек в сцене и перебираем их
    for (unsigned int i = 0; i < s.size(); i++) {
        const Point& p = s[i];
        std::cout << p.x() << " " << p.y() << " " << p.z() << std::endl;
    }

    // Создаем обрезанную сцену
    CroppedScene cropped(-1, -1, -1, 5, 5, 5);

    // Добавляем точки в обрезанную сцену
    cropped.append(p1);
    cropped.append(Point(0, 0, 0));

    // Проверяем количество точек в обрезанной сцене и перебираем их
    for (unsigned int i = 0; i < cropped.size(); i++) {
   const Point& p = cropped[i];
    std::cout << p.x() << " " << p.y() << " " << p.z() << std::endl;
}

return 0;
}
