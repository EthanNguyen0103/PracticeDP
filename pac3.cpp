#include <iostream>
#include <memory>
#include <string>

using namespace std;

// --------- Product ---------
class Computer {
private:
    string cpu;
    string ram;
    string storage;
    string gpu;
public:
    void setCPU(const string& v)     { cpu = v; }
    void setRAM(const string& v)     { ram = v; }
    void setStorage(const string& v) { storage = v; }
    void setGPU(const string& v)     { gpu = v; }

    void showSpec() const {
        cout << "CPU: " << cpu << "\n"
             << "RAM: " << ram << "\n"
             << "Storage: " << storage << "\n"
             << "GPU: " << gpu << "\n";
    }
};

// --------- Builder Interface ---------
class ComputerBuilder {
public:
    virtual void reset() = 0;
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGPU() = 0;
    virtual unique_ptr<Computer> getResult() = 0;
    virtual ~ComputerBuilder() = default;
};

// --------- Concrete Builders ---------
class GamingPCBuilder : public ComputerBuilder {
    // TODO: giữ Computer (composition)
private:
    unique_ptr<Computer> computer;
public:
    void reset() override {
        computer = make_unique<Computer> ();
        std::cout << "Reset Office PC Builder\n";
    }
    void buildCPU() override {
        // TODO: CPU mạnh
        computer->setCPU("High-end Gaming CPU");
        std::cout << "Building Gaming CPU\n";
    }
    void buildRAM() override {
        // TODO: RAM nhiều
        computer->setRAM("32GB Gaming RAM");
        std::cout << "Building Gaming RAM\n";
    }
    void buildStorage() override {
        // TODO
        computer->setStorage("1TB NVMe SSD");
        std::cout << "Building Gaming Storage\n";
    }
    void buildGPU() override {
        // TODO: GPU rời mạnh
        computer->setGPU("High-end Gaming GPU");
        std::cout << "Building Gaming GPU\n";
    }
    unique_ptr<Computer> getResult() override {
        // TODO: move ra ngoài
        return std::move(computer);
    }
};

class OfficePCBuilder : public ComputerBuilder {
    // TODO: tương tự, cấu hình văn phòng
private:
    unique_ptr<Computer> computer;
public:
    void reset() override { /* TODO */
        computer = make_unique<Computer> ();
        std::cout << "Reset Office PC Builder\n";
    }
    void buildCPU() override { /* TODO */ 
        computer->setCPU("Efficient Office CPU");
        std::cout << "Building Office CPU\n";
    }
    void buildRAM() override { /* TODO */ 
        computer->setRAM("16GB Office RAM");
        std::cout << "Building Office RAM\n";
    }
    void buildStorage() override { /* TODO */ 
        computer->setStorage("512GB SSD");
        std::cout << "Building Office Storage\n";
    }
    void buildGPU() override { /* TODO */ 
        computer->setGPU("Integrated GPU");
        std::cout << "Building Office GPU\n";
    }
    unique_ptr<Computer> getResult() override {
        // TODO
        return std::move(computer);
    }
};

// --------- Director ---------
class Director {
private:
    ComputerBuilder* builder = nullptr; // aggregation
public:
    void setBuilder(ComputerBuilder* b) {
        builder = b;
    }

    void constructBasicPC() {
        // TODO: gọi các step theo thứ tự
        // builder->reset();
        // builder->buildCPU();
        // ...
        builder->reset();
        builder->buildCPU();
        builder->buildRAM();
        builder->buildStorage();
        builder->buildGPU();
    }
};

int main() {
    // TODO:
    // 1. tạo GamingPCBuilder, OfficePCBuilder
    // 2. tạo Director, setBuilder(...)
    // 3. gọi constructBasicPC()
    // 4. lấy result và showSpec()
    std::unique_ptr<ComputerBuilder> gamingBuilder = std::make_unique<GamingPCBuilder> ();
    std::unique_ptr<ComputerBuilder> officeBuilder = std::make_unique<OfficePCBuilder> ();
    std::unique_ptr<Director> director = std::make_unique<Director> ();

    director->setBuilder(gamingBuilder.get());
    director->constructBasicPC();

    return 0;
}
