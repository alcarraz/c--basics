#include <iostream>
#include <string>

class Shape {

public:
    virtual std::string description() {
        return "I'm  a shape";
    }

    virtual ~Shape() = default;

};

class Circle : public Shape {
    double radius;
public:
    Circle(double radius): radius(radius) {}
    double get_radius() {return radius;}

    std::string description() override{
        return "I'm a Circle";
    }
};

int main() {
    using namespace std;
    Shape shape;
    cout << "description of shape:  " << shape.description() << endl;
    //description of shape:  I'm a shape

    Circle circle{4};
    cout << "description of circle: " << circle.description() << endl;
    //description of circle: I'm a circle

    Shape &circle_shape = circle; //reference assignment
    cout << "description of a reference to circle: " << circle_shape.description() << endl;
    //description of a reference to circle: I'm a Circle


    cout << "radius of circle: " << circle.get_radius() << endl;
    //radius of circle: 4

    return 0;
}


