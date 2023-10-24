# Polymorphism in C++

This is the 7th post in C++ basics series, continuing with the last posts about method overriding and abstract classes, let's talk about polymorphism.


Polymorphism is one of the most powerful features of object oriented programming. It allows you to write code that can perform different actions depending on the actual type of an object. 

As you'll see, even without knowing all the possible types. This makes your code more flexible and reusable.


When you have a reference, or a pointer to a class with a virtual method, the actual object can be of any subclass, and as we saw in day 4 (method overriding). And therefore, any virtual method you call on it, will call the implementation of the concrete class of the object.

In the code example, the print_shapes function is polymorphic on the `type` and `area` methods, but not on `get_name` method because it's not virtual and thus it cannot be overwritten by subclasses.

We code add as many `Shape` implementations as we want, and the `print_shapes` will continue to work for all of them, as long as they correctly implement its `name` and `area` methods.

Compiler explorer link to play with the example: https://godbolt.org/z/vsM3zs51G

github link: https://github.com/alcarraz/cpp-basics/blob/main/day-07-polymorphism/src/c%2B%2B-basics.cpp


```c++
class Shape {
    std::string name;
public:
...
    virtual double area() const = 0;

    virtual std::string type() const = 0;

    std::string get_name() const {return name;}
};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(std::string name, double radius): Shape(name), radius(radius) {}

    double area() const override {
        return  2 * radius * radius * std::numbers::pi; //Since c++ 20
    }

    std::string type() const override {return "circle";}
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

```

 #Cpp #begginers #practice #tips #Cplusplus