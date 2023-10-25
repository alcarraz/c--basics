# Conversion constructors and user-defined conversion functions

In this 8th post in the C++ basics series, let's talk about a really nice C++ feature: user defined conversions.

One of the things I love about C++ is the ability to customize the language. One of the features that enable that, is the topic of today, which lets you  specify what and how other types can be converted to your class and how your class can be converted to other types. However, you should not abuse this feature, since it can also easily produce illegible code.

A conversion constructor is a constructor that converts its parameter to the class of the constructor, and a user-defined function defines how your class is converted to another type.

Both, conversion functions and constructor, can also be explicit or implicit (the default). When declared as explicit they will not be used by the compiler to automatically convert between types. Implicit conversions are nice when the conversion is natural, but if abused it can be hard to detect bugs and debug the code that uses them. 

It can be really confused to understand for someone reading the code, where the code implementing the conversion is, so by default, consider to make them explicit. This is done with the explicit specifier in front of the conversion constructor or function.



Compiler explorer link to play with the example: https://godbolt.org/z/Teb4EP6dG

GitHub link: https://github.com/alcarraz/cpp-basics/blob/main/day-08-user-defined-conversions/src/c%2B%2B-basics.cpp

The rectangle class has conversion from braced initializer list and to string.

```c++
class Rectangle {
    double width, height;
public:
    explicit Rectangle( double width, double height): width(width), height(height) {}

    explicit operator std::string() {   //explicit conversion to string
        return "Rectangle{" + std::to_string(width) + "," + std::to_string(height) + "}";
    }
};
```

The Square class has  explicit conversion from int and to Rectangle.

```
class Square {
    double side;
public:
    explicit Square(double side) : side(side) {    //explicit conversion from double
        std::cout << "Square{" << side << "}" << std::endl;
    }

    explicit operator Rectangle() {                 // explicit user-defined conversion to rectangle
        return Rectangle(side, side);
    }
};

```

Since the Fraction class represents a number it may make sense to have implicit conversions from and to some numerical types, we added conversion from int, braced initializer list of two ints, and to double. 

```
class Fraction {
    int num, den;
public:
    Fraction(int num, int den = 1): num(num), den(den) {   //implicit constructor from int, and {int, int}
        std::cout << "Fraction{" << num << "," << den << "}" << std::endl;
    }
    operator double() {                                     //implicit conversion to double
        return num/(double)den;
    }
};
```

 #Cpp #begginers #practice #tips #Cplusplus