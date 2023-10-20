#include <iostream>
#include <string>
#include <numbers>  //since C++ 20
class Shape {

public:
    Shape() {}

    std::string description() const {
        return "I'm  a " + name () + " and my area is " + std::to_string(area());
    }

    virtual ~Shape() = default;

    virtual double area() const = 0;

    virtual std::string name() const {
        return "shape";
    }

};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(double radius): radius(radius) {}

    double get_radius() const {
        return radius;
    }

    double area() const override {
        return  2 * radius * radius * std::numbers::pi; //Since c++ 20
    }

    std::string name() const override {
        return "circle";
    }
};

int main() {
    using namespace std;

    Circle circle{4};
    cout << "description of circle: " << circle.description() << endl;
    //description of circle: I'm  a circle and my area is 100.530965


    //Shape shape;
    //Error, cannot instantiate a shape.

    //but we can have a Shape reference to a instance of a concrete class.
    Shape &circle_ref = circle;
    cout << circle_ref.area() << endl;
    //100.531

    //or a Shape pointer to an instance of a concrete class.
    Shape *circle_ptr = &circle;
    cout << circle_ptr-> name() << endl;
    //circle

    return 0;
}


