#include <iostream>
#include <memory>
#include <string>

using namespace std;

// --------- Product Interfaces ---------
class Chair { /* TODO: add virtual API */ 
public:
    virtual void create() = 0;
};
class Table { /* TODO */ 
public:
    virtual void create() = 0;
};
class Lamp  { /* TODO */ 
public:
    virtual void create() = 0;
};

//---------Concreate Product ------------
class IKEAChair : public Chair{
public:
    void create() override {
        cout << "IKEA Chair created\n";
    }
};
class IKEATable : public Table{
public:
    void create() override {
        cout << "IKEA Table created\n";
    }
};
class IKEALamp : public Lamp{
public:
    void create() override {
        cout << "IKEA Lamp created\n";
    }
};

class PanasonicChair : public Chair{
public:
    void create() override {
        cout << "Panasonic Chair created\n";
    }
};

class PanasonicTable : public Table{
public:
    void create() override {
        cout << "Panasonic Table created\n";
    }
};

class PanasonicLamp : public Lamp{
public:
    void create() override {
        cout << "Panasonic Lamp created\n";
    }
};

// --------- Abstract Factory -----------
class FurnitureFactory {
public:
    // TODO: declare createChair(), createTable(), createTable()
    virtual std::unique_ptr<Chair> createChair() = 0; 
    virtual std::unique_ptr<Table> createTable() = 0; 
    virtual std::unique_ptr<Lamp> createLamp() = 0; 
    virtual ~FurnitureFactory() = default;
};

// --------- Concrete Factories ----------
class IKEAFactory : public FurnitureFactory {
    // TODO
public:
    std::unique_ptr<Chair> createChair() override{
        return std::make_unique<IKEAChair> ();
    }
    std::unique_ptr<Table> createTable() override{
        return std::make_unique<IKEATable> ();
    }
    std::unique_ptr<Lamp> createLamp() override{
        return std::make_unique<IKEALamp> ();
    }
};

class PanasonicFactory : public FurnitureFactory {
    // TODO
public:
    std::unique_ptr<Chair> createChair() override{
        return std::make_unique<PanasonicChair> ();
    }
    std::unique_ptr<Table> createTable() override{
        return std::make_unique<PanasonicTable> ();
    }
    std::unique_ptr<Lamp> createLamp() override{
        return std::make_unique<PanasonicLamp> ();
    }
};

// --------- Demo ----------
int main() {
    string brand;
    cin >> brand;

    unique_ptr<FurnitureFactory> factory;
    // TODO: chọn đúng factory theo brand, không được dùng switch-case
    // TODO: tạo chair/table/lamp từ factory và gọi API của chúng
    if(brand == "IKEA"){
        factory = std::make_unique<IKEAFactory> ();
    }
    unique_ptr<Chair> chair = factory->createChair();
    unique_ptr<Table> table = factory->createTable();
    unique_ptr<Lamp> lamp = factory->createLamp();

    chair->create();
    table->create();
    lamp->create();

    return 0;
}
