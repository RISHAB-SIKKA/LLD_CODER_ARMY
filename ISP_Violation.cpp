#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Shape{
    public:
        virtual double area() const = 0; // Pure virtual function
        virtual double volume() const = 0; // Pure virtual function
};

class square : public Shape{
    private:
        double side;
    public:
        square(double s) : side(s) {}
        double area() const override {
            return side * side;
        }
        double volume() const override { // Violation of ISP
            throw runtime_error("Volume not applicable for 2D shape");
        }
};
class rectangle : public Shape{
    private:
        double length, width;
    public:
        rectangle(double l, double w) : length(l), width(w) {}
        double area() const override {
            return length * width;
        }
        double volume() const override {  // Violation of ISP
            throw runtime_error("Volume not applicable for 2D shape");
        }
};

class cube : public Shape{
    private:
        double side;
    public:
        cube(double s) : side(s) {}
        double area() const override {
            return 6 * side * side;
        }
        double volume() const override {
            return side * side * side;
        }
};

class Client{
    private: 
        vector<Shape*> shapes;
    public:
    void addShape(Shape* shape){
        shapes.push_back(shape);
    }
    void displayAreasAndVolumes(){
        for(const auto& shape : shapes){
            try{
                cout << "Area: " << shape->area() << endl;
                cout << "Volume: " << shape->volume() << endl;
            }catch(const exception& e){
                cout << "Error: " << e.what() << endl;
            }
        }
    }
};

int main(){
    Client client;
    client.addShape(new square(4));
    client.addShape(new rectangle(4, 5));
    client.addShape(new cube(3));

    client.displayAreasAndVolumes();

    return 0;
}