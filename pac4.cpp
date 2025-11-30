#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Logger {
private:
    // TODO: private constructor
    // TODO: static instance pointer (unique_ptr or raw pointer)
    Logger() = default;
    Logger (const Logger& other) = delete;
    Logger (Logger && other) = delete;
    Logger& operator =(const Logger&) = delete;
    Logger& operator =(Logger &&) = delete;

public:
    // TODO: delete copy constructor
    // TODO: delete operator=
    
   static Logger& getInstance() {
        // TODO: lazy initialization (hard mode)
        static Logger instanse;
        return instanse;
    }

    void logInfo(const string& msg) {
        cout << "[INFO]: " << msg << "\n";
    }

    void logError(const string& msg) {
        cout << "[ERROR]: " << msg << "\n";
    }
};

int main() {
    // TODO: gọi logger nhiều lần để chứng minh cùng 1 instance
    Logger::getInstance().logError("10");

    return 0;
}
