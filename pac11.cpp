#include <iostream>
#include <memory>

using namespace std;

// ------- Subsystems -------
class CPU {
public:
    void freeze() {
        cout << "CPU: freeze\n";
    }
    void jump(long position) {
        cout << "CPU: jump to " << position << "\n";
    }
    void execute() {
        cout << "CPU: execute\n";
    }
};

class Memory {
public:
    void load(long position, const string& data) {
        cout << "Memory: load data '" << data 
             << "' at position " << position << "\n";
    }
};

class Disk {
public:
    string read(long lba, int size) {
        cout << "Disk: read " << size << " bytes at " << lba << "\n";
        return "OS_BOOT_DATA";
    }
};

// ------- Facade -------
class ComputerFacade {
private:
    // TODO: giữ CPU, Memory, Disk (composition)
    // gợi ý: unique_ptr hoặc object bình thường
    std::unique_ptr<CPU> cpu = std::make_unique<CPU> ();
    std::unique_ptr<Memory> memory = std::make_unique<Memory> ();
    std::unique_ptr<Disk> disk = std::make_unique<Disk> ();
public:
    ComputerFacade() {
        // TODO: khởi tạo các subsystem nếu cần
    }

    void startComputer() {
        // TODO:
        // 1. freeze CPU
        // 2. read data từ Disk
        // 3. load vào Memory
        // 4. jump + execute
        cpu->freeze();
        string data = disk->read(0, 1024);
        memory->load(0, data);
        cpu->jump(0);
        cpu->execute();
    }

    void shutdownComputer() {
        // TODO: mô phỏng tắt máy (in vài dòng cho dễ thấy)
        cout << "Shutting down computer...\n";
    }
};

// ------- Demo -------
int main() {
    // TODO:
    // 1. tạo ComputerFacade
    // 2. gọi startComputer()
    // 3. gọi shutdownComputer()
    std::unique_ptr<ComputerFacade> computer = std::make_unique<ComputerFacade> ();
    computer->startComputer();
    computer->shutdownComputer();
    return 0;
}
