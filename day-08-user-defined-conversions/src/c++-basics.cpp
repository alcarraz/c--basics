#include <iostream>
#include <string>

class Rectangle {
    double width, height;
public:
    explicit Rectangle( double width, double height): width(width), height(height) {}

    explicit operator std::string() {   //explicit conversion to string
        return "Rectangle{" + std::to_string(width) + "," + std::to_string(height) + "}";
    }
};


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

int main() {
    Square square{4};                       //conversion constructor from double
    //prints Square{4}

    //Square square = 4                     //doesn't work, conversion needs to be explicit

    Rectangle rec = Rectangle{square};      //user-defined function conversion square to double
    std::cout << (std::string)rec << std::endl; //uses explicit conversion to string to print.
    //Rectangle{4,4}

    //Rectangle rec = square                //doesn't work, conversion needs to be explicit.

    Fraction fraction = 5;                  //Implicit constructor conversion from int;
    //Fraction{5,1}

    double d = fraction;                    //implicit conversion from fraction to d
    std::cout << d << std::endl;
    //5

    fraction = {5,4};                       //implicit conversion from braced initialization list.
    //Fraction{5,4}

    std::cout << fraction << std::endl;     //implicitly converts fraction to double for printing.
    //1.25

    square = Square(fraction);              //implicit conversion from fraction to double, explicit conversion to square
    //Square{1.25}


    return 0;
}


