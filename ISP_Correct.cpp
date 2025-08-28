#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract base for 2D shapes
class Shape2D {
public:
    virtual double area() const = 0; // Pure virtual
};

// Abstract base for 3D shapes (inherits 2D for surface area)
class Shape3D : public Shape2D {
public:
    virtual double volume() const = 0; // Pure virtual
};

class Square : public Shape2D {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape2D {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
};

class Cube : public Shape3D {
    double side;
public:
    Cube(double s) : side(s) {}
    double area() const override {
        return 6 * side * side;
    }
    double volume() const override {
        return side * side * side;
    }
};

class Client {
    private:
    vector<Shape2D*> shapes2D;
    vector<Shape3D*> shapes3D;
    public:
    void addShape(Shape2D* shape) {
        shapes2D.push_back(shape);
    }
    void addShape(Shape3D* shape) {
        shapes3D.push_back(shape);
    }
    void displayAreasAndVolumes() {
        for (const auto& shape : shapes2D) {
            cout << "Area: " << shape->area() << endl;
        }
        for (const auto& shape : shapes3D) {
            cout << "Area: " << shape->area() << ", Volume: " << shape->volume() << endl;
        }
    }

};

int main() {
    Client client;
    client.addShape(new Square(4));
    client.addShape(new Rectangle(3, 5));
    client.addShape(new Cube(2));

    client.displayAreasAndVolumes();

    return 0;
}


