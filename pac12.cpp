#include <iostream>
#include <memory>
#include <string>

using namespace std;

// --------- Subject Interface ---------
class IImage {
public:
    virtual void display() = 0;
    virtual ~IImage() = default;
};

// --------- Real Subject ---------
class RealImage : public IImage {
private:
    string filename;
public:
    RealImage(string f) : filename(std::move(f)) {
        cout << "Loading big image from disk: " << filename << "\n";
    }

    void display() override {
        cout << "Displaying image: " << filename << "\n";
    }
};

// --------- Proxy ---------
class ProxyImage : public IImage {
private:
    string filename;
    unique_ptr<RealImage> realImage;  // lazy load target
public:
    ProxyImage(string f) : filename(std::move(f)) {}

    void display() override {
        // TODO:
        // 1. Nếu realImage == nullptr → new RealImage(filename)
        // 2. Gọi realImage->display()
        if(realImage == nullptr){
            realImage = std::make_unique<RealImage> (filename);
        }
        realImage->display();
    }
};

// --------- Demo ---------
int main() {
    // TODO:
    // 1. Tạo ProxyImage("test_photo.png")
    // 2. Gọi display() 2 lần
    //    Lần 1: phải load + display
    //    Lần 2: chỉ display (không load lại)
    std::unique_ptr<ProxyImage> img = std::make_unique<ProxyImage>("test_photo.png");
    img->display();
    img->display();
}
