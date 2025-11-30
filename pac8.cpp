#include <iostream>
#include <memory>
#include <string>

using namespace std;

// ---------- Component ----------
class Coffee {
public:
    virtual int cost() const = 0;
    virtual string info() const = 0;
    virtual ~Coffee() = default;
};

// ---------- Concrete Component ----------
class BasicCoffee : public Coffee {
public:
    int cost() const override {
        return 20; // 20k
    }

    string info() const override {
        return "Basic Coffee";
    }
};

// ---------- Decorator Base ----------
class CoffeeDecorator : public Coffee {
protected:
    shared_ptr<Coffee> inner; // aggregation
public:
    CoffeeDecorator(shared_ptr<Coffee> c) : inner(std::move(c)) {}
};

// ---------- Concrete Decorators ----------
class MilkDecorator : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;

    int cost() const override {
        // TODO: giá = inner + 10
        return inner->cost() + 10;
    }

    string info() const override {
        // TODO: nối chuỗi với " + Milk"
        return inner->info() + " + Milk";
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;

    int cost() const override { /* TODO */ 
        return inner->cost() + 5;
    }

    string info() const override { /* TODO */ 
        return inner->info() + " + Sugar";
    }
};

class CaramelDecorator : public CoffeeDecorator {
public:
    using CoffeeDecorator::CoffeeDecorator;

    int cost() const override { /* TODO */ 
        return inner->cost() + 7;
    }

    string info() const override { /* TODO */ 
        return inner->info() + " + Caramel";
    }
};

// ---------- Demo ----------
int main() {
    // Yêu cầu:
    // Tạo BasicCoffee -> add Milk -> add Caramel
    // In info() và cost()

    shared_ptr<Coffee> c = make_shared<BasicCoffee>();
    c = make_shared<MilkDecorator>(c);
    c = make_shared<SugarDecorator>(c);
    // c = make_shared<CaramelDecorator>(c);

    cout << c->info() << "\n";
    cout << "Total: " << c->cost() << "k\n";

    return 0;
}
