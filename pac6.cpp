#include <iostream>
#include <string>
#include <memory>

using namespace std;

// --------- Old API (cannot modify) ---------
class VietnameseSensor {
public:
    string docNhietDo() { return "Nhiệt độ: 30°C"; }
};

// --------- New API (target interface) ---------
class TemperatureSensor {
public:
    virtual string getTemperature() = 0;
    virtual ~TemperatureSensor() = default;
};

// --------- Adapter (YOU write this) ---------
class VietnameseSensorAdapter : public TemperatureSensor {
private:
    // TODO: giữ 1 VietnameseSensor (composition)
    std::shared_ptr<VietnameseSensor> vNMSS;
public:
    // TODO: constructor nhận VietnameseSensor*
    VietnameseSensorAdapter(VietnameseSensor* p_vNMSS) : vNMSS(std::move(p_vNMSS)) {}; 
    string getTemperature() override {
        // TODO:
        // 1. gọi API tiếng Việt
        // 2. convert chuỗi "Nhiệt độ:" --> "Temperature:"
        // 3. return
        if(vNMSS){
            std::cout << vNMSS->docNhietDo();
            return vNMSS->docNhietDo();
        }
        return "Unknown\n";
    }
};

// --------- Demo ---------
int main() {
    // TODO:
    // 1. tạo VietnameseSensor
    // 2. wrap bằng adapter
    // 3. gọi getTemperature()
    VietnameseSensor* vn = new VietnameseSensor();
    std::unique_ptr<VietnameseSensorAdapter> vnn = std::make_unique<VietnameseSensorAdapter> (vn);
    vnn->getTemperature();

    return 0;
}
