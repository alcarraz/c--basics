#include <iostream>
#include <string>
#include <numbers>  //since C++ 20
#include <list>

class Shape {
    std::string name;
public:
    Shape(std::string name): name(name) {}

    virtual ~Shape() = default;

    virtual double area() const = 0;

    virtual std::string type() const = 0;

    std::string get_name() const {
        return name;
    }
};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(std::string name, double radius): Shape(name), radius(radius) {}

    double area() const override {
        return  2 * radius * radius * std::numbers::pi; //Since c++ 20
    }

    std::string type() const override {
        return "circle";
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(std::string name, double width, double height): Shape(name), width(width), height(height) {}

    double area() const override{
        return width * height;
    }

    std::string type() const override {
        return "rectangle";
    }
};

void print_shapes(std::list<const Shape *> shapes){
    for (const Shape *shape : shapes) {
        std::cout << shape->get_name() << " is a " << shape->type() << " and its area is " << shape->area() << std::endl;
    }
}

int main() {
    Circle circle {"nice shape", 4};

    Rectangle rectangle {"nicer shape", 4, 5};

    std::list<const Shape *> shapes = {&circle, &rectangle};

    print_shapes(shapes);
    //nice shape is a circle and its area is 100.531
    //nicer shape is a rectangle and its area is 20

    return 0;
}


