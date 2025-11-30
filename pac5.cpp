#include <iostream>
#include <memory>
#include <string>

using namespace std;

// --------- Prototype Interface ---------
class Shape {
public:
    virtual unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// --------- Concrete Prototypes ---------
class Circle : public Shape {
private:
    string color;
    double radius;
public:
    Circle(string c, double r) : color(std::move(c)), radius(r) {}

    unique_ptr<Shape> clone() const override {
        // TODO: trả về bản copy của chính nó
        return std::make_unique<Circle> (color, radius);
    }

    void draw() const override {
        cout << "Circle color=" << color << ", radius=" << radius << "\n";
    }

    // có thể thêm setter nếu muốn chỉnh sau khi clone
};

class Square : public Shape {
private:
    string color;
    double side;
public:
    Square(string c, double s) : color(std::move(c)), side(s) {}

    unique_ptr<Shape> clone() const override {
        // TODO
        return std::make_unique<Square> (color, side);
    }

    void draw() const override {
        cout << "Square color=" << color << ", side=" << side << "\n";
    }
};

// --------- Demo ---------
int main() {
    // 1. Tạo prototype gốc
    Circle baseCircle("red", 10.0);
    Square baseSquare("blue", 5.0);

    // 2. Clone ra vài bản
    // TODO: dùng baseCircle.clone(), baseSquare.clone()
    auto c1 = baseCircle.clone();
    auto c2 = baseCircle.clone();
    auto s1 = baseSquare.clone();
    // ...

    // 3. Gọi draw() để kiểm tra
    c1->draw();
    s1->draw();

    return 0;
}
