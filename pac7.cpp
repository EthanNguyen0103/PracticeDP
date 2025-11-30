#include <iostream>
#include <memory>
#include <string>

using namespace std;

// --------- Implementor (Color) ---------
class Color {
public:
    virtual string getColor() const = 0;
    virtual ~Color() = default;
};

class Red : public Color {
public:
    string getColor() const override { return "Red"; }
};

class Blue : public Color {
public:
    string getColor() const override { return "Blue"; }
};

// --------- Abstraction (Shape) ---------
class Shape {
protected:
    shared_ptr<Color> color;   // Bridge here
public:
    Shape(shared_ptr<Color> c) : color(std::move(c)) {}
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {

public:
    // using Shape::Shape; // inherit constructor
    Circle(shared_ptr<Color> c) : Shape(std::move(c)) {};
    void draw() const override {
        cout << "Circle with color " << color->getColor() << "\n";
    }
};

class Square : public Shape {
public:
    Square(shared_ptr<Color> c) : Shape(std::move(c)) {};
    void draw() const override {
        cout << "Square with color " << color->getColor() << "\n";
    }
};

// --------- Demo ---------
int main() {
    auto red = make_shared<Red>();
    auto blue = make_shared<Blue>();

    // TODO: tạo Circle Red, Circle Blue, Square Red
    std::unique_ptr<Circle> circle = std::make_unique<Circle> (red);
    circle->draw();

    return 0;
}
