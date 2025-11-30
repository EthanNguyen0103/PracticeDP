#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

using namespace std;

// --------- Flyweight Interface ---------
class MapIcon {
public:
    virtual void draw(int x, int y) = 0;
    virtual ~MapIcon() = default;
};

// --------- Concrete Flyweights ---------
class RestaurantIcon : public MapIcon {
public:
    void draw(int x, int y) override {
        cout << "Restaurant Icon at (" << x << ", " << y << ")\n";
    }
};

class HospitalIcon : public MapIcon {
public:
    void draw(int x, int y) override {
        cout << "Hospital Icon at (" << x << ", " << y << ")\n";
    }
};

class ParkIcon : public MapIcon {
public:
    void draw(int x, int y) override {
        cout << "Park Icon at (" << x << ", " << y << ")\n";
    }
};

// --------- Flyweight Factory ---------
class IconFactory {
private:
    unordered_map<string, shared_ptr<MapIcon>> pool; // intrinsic shared
public:
    shared_ptr<MapIcon> getIcon(const string& type) {
        // TODO:
        // 1. nếu pool chứa rồi → trả về
        // 2. nếu không → tạo → lưu → trả về
        if(pool.find(type) != pool.end()){
            return pool[type];
        }else{
            if(type == "Restaurant"){
                pool[type] = std::make_shared<RestaurantIcon> ();
                
            }
            else if(type == "Hospital"){
                pool[type] = std::make_shared<HospitalIcon> ();
            }
            else if(type == "Park"){
                pool[type] = std::make_shared<ParkIcon> ();
            }
            return pool[type];
        }
        return nullptr; 
    }

    size_t count() const {
        return pool.size();
    }
};

// --------- Demo ---------
int main() {
    IconFactory factory;

    // TODO: tạo vài icon với vị trí random
    // gợi ý:
    //  shared_ptr<MapIcon> icon = factory.getIcon("Restaurant");
    //  icon->draw(x, y);
    shared_ptr<MapIcon> icon1 = factory.getIcon("Restaurant");
    icon1->draw(10, 20);    

    cout << "Total icons created: " << factory.count() << "\n";
}
