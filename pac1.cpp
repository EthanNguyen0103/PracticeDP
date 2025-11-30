#include <iostream>
#include <memory>
#include <string>

using namespace std;

// --------- Product Interface ---------
class Car {
public:
    virtual void run() = 0;
    virtual ~Car() = default;
};

// --------- Concrete Products ---------
class Toyota : public Car {
public:
    void run() override { cout << "Toyota is running...\n"; }
};

class Honda : public Car {
public:
    void run() override { cout << "Honda is running...\n"; }
};

class Mazda : public Car {
public:
    void run() override { cout << "Mazda is running...\n"; }
};

class BMW : public Car {
public:
    void run() override { cout << "BMW is running...\n"; }
};

// --------- Factory Method ---------
class CarFactory {
public:
    static unique_ptr<Car> createCar(const string& type) {

        // TODO: Hoàn thiện logic tạo object đúng loại
        // Gợi ý: dùng if/else đơn giản
        // if (type == "Toyota") return make_unique<Toyota>();
        // ...
        if(type == "Toyota"){
            return std::make_unique<Toyota> ();
        }
        else if (type == "Honda"){
            return std::make_unique<Honda> ();
        }
        else if (type == "Mazda"){
            return std::make_unique<Mazda> ();
        }
        else if(type == "BMW"){
            return std::make_unique<BMW> ();
        }
        else{
            return nullptr;
        }
        return nullptr;
    }
};

// --------- Demo ---------
int main() {
    string userInput;
    cout << "Enter car brand (Toyota / Honda / Mazda/ BMW): ";
    cin >> userInput;

    auto car = CarFactory::createCar(userInput);

    if (car) car->run();
    else cout << "Unknown car type!\n";

    return 0;
}
