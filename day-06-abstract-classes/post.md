# Abstract classes in c++

Abstract classes in c++



This is  the 5th post in C++ basics series, and today we talk about abstract classes.

In C++, there isn't a keyword to make a class abstract, instead an abstract class is any class that has a pure virtual function. A pure virtual function is the same as an abstract method in other languages, a method with no implementation that concrete subclasses must implement, to not be also abstract.



An abstract class cannot be instantiated, you need to instantiate one of the derived concrete ones. A pure virtual function is declared by appending = 0, to its declaration.



In the example, a generic shape does not know how to calculate its area. However, we ask all concrete shapes to provide that method, a concrete shape will have an area, and one way or another, it should be able to calculate it. The concrete class Circle does provide that method.



You can also see that while a Shape cannot be instantiated, you can have a reference or a pointer to an instance of the concrete class Circle.