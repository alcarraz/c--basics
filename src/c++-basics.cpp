#include <iostream>
#include <string>

class Shape {

public:
    virtual std::string description() const {
        return "I'm  a shape";
    }

    virtual ~Shape() = default;

};

class Circle : public Shape {
    double radius;
public:
    Circle(double radius): radius(radius) {}

    std::string description() const override{
        return "I'm a Circle";
    }

    double get_radius() const {
        return radius;
    }

    void set_radius(double radius) {
        this -> radius = radius;
    }
};

int main() {
    using namespace std;

    const Circle circle{4};
    cout << "description of circle: " << circle.description() << endl;
    //description of circle: I'm a circle

    cout << "radius of circle: " << circle.get_radius() << endl;
    //radius of circle: 4

    //circle.set_radius(5);
    //wouldn't work, we cannot call set_radius on circle because it's const.

    Circle mutable_circle{5};
    mutable_circle.set_radius(6);

    cout << "radius of mutable_circle: " << mutable_circle.get_radius() << endl;
    //radius of mutable_circle: 6

    return 0;
}


