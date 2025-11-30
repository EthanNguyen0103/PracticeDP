🧱 I. CREATIONAL PATTERNS (5/5)

Creational Patterns giải quyết vấn đề khởi tạo object sao cho linh hoạt, giảm phụ thuộc, dễ mở rộng.

1️⃣ Factory Method
✔ Ý nghĩa

Cho phép subclass quyết định tạo đối tượng cụ thể nào.

✔ Dùng khi

Có nhiều class cùng interface

Muốn tạo object dựa trên runtime input

Không muốn dùng nhiều new trong client

✔ Cấu trúc
Product <|-- ConcreteProduct  
Creator <|.. FactoryMethod

✔ Ví dụ bạn đã làm

CarFactory -> createCar("Toyota")

2️⃣ Abstract Factory
✔ Ý nghĩa

Tạo một họ các object liên quan (product family) mà không cần biết class cụ thể.

✔ Dùng khi

Muốn đảm bảo object được tạo đồng bộ theo hãng/OS/theme

Muốn đổi tất cả product 1 lần (Windows UI → Mac UI)

✔ Cấu trúc
AbstractFactory <|-- ConcreteFactory  
AbstractProduct <|-- ConcreteProduct

✔ Ví dụ bạn đã làm

IKEAFactory tạo:

IKEAChair

IKEATable

IKEALamp

3️⃣ Builder
✔ Ý nghĩa

Xây dựng object phức tạp theo từng bước (step-by-step).

✔ Dùng khi

Object có nhiều bước xây dựng

Cần nhiều biến thể khác nhau (gaming PC, office PC)

✔ Cấu trúc
Director --> Builder --> Product

✔ Ví dụ bạn đã làm

GamingPCBuilder, OfficePCBuilder

4️⃣ Prototype
✔ Ý nghĩa

Tạo object mới bằng cách clone object có sẵn.

✔ Dùng khi

Việc tạo object tốn tài nguyên

Muốn nhân bản nhanh

✔ Cấu trúc
Prototype <|-- ConcretePrototype  
clone()

✔ Ví dụ bạn đã làm

Circle và Square clone nhiều bản.

5️⃣ Singleton
✔ Ý nghĩa

Đảm bảo 1 class chỉ có duy nhất 1 instance.

✔ Dùng khi

Logger

Config manager

Database connection

✔ Ví dụ bạn đã làm

Logger::getInstance() (static local variable)

🎯 Tổng kết CREATIONAL bằng 1 câu

Factory tạo từng object → Abstract Factory tạo cả họ → Builder tạo object phức tạp → Prototype clone → Singleton 1 instance.

🧩 II. STRUCTURAL PATTERNS (7/7)

Structural Patterns giúp tổ chức class và object để tạo cấu trúc lớn, dễ bảo trì.

1️⃣ Adapter
✔ Ý nghĩa

Chuyển đổi interface A → interface B.

✔ Dùng khi

Có code cũ không sửa được

API không tương thích

✔ Ví dụ bạn đã làm

VietnameseSensorAdapter chuyển
docNhietDo() → getTemperature()

2️⃣ Bridge
✔ Ý nghĩa

Tách abstraction (Shape) và implementation (Color) để mở rộng độc lập.

✔ Dùng khi

Có 2 dimension mở rộng (Shape x Color)

✔ Ví dụ

Shape sử dụng Color qua aggregation
Circle → Red
Square → Blue

3️⃣ Decorator
✔ Ý nghĩa

Thêm chức năng cho object mà không cần sửa class gốc.

✔ Ví dụ

BasicCoffee → +Milk → +Sugar → +Caramel

Cấu trúc:

CoffeeDecorator has-a Coffee

4️⃣ Composite
✔ Ý nghĩa

Tạo cấu trúc dạng cây (tree) với Leaf & Composite.

✔ Ví dụ

FolderItem chứa nhiều FileItem hoặc FolderItem
Hàm getSize() chạy đệ quy.

5️⃣ Facade
✔ Ý nghĩa

Cung cấp interface đơn giản cho hệ thống phức tạp.

✔ Ví dụ

ComputerFacade.startComputer() → gọi CPU, Disk, Memory

6️⃣ Flyweight
✔ Ý nghĩa

Share object giống nhau để giảm memory.

✔ Ví dụ

Map icon (Restaurant, Hospital, Park)
Factory chỉ tạo 1 đối tượng mỗi loại.

7️⃣ Proxy
✔ Ý nghĩa

Đại diện cho object thật, thêm lazy load / bảo vệ / cache.

✔ Ví dụ

ProxyImage lazy-load RealImage khi gọi display() lần đầu.

🎯 Tổng kết STRUCTURAL bằng 1 câu

Adapter đổi interface → Bridge tách 2 hướng phát triển → Decorator thêm chức năng → Composite cây
→ Facade đơn giản hóa → Flyweight share → Proxy thay mặt & lazy-load.

📌 Tổng quan UML ngắn gọn (để học thuộc)
Factory:              Creator -> Product
Abstract Factory:     AF -> ProductFamily
Builder:              Director -> Builder -> Product
Prototype:            clone()
Singleton:            static getInstance()

Adapter:              Adapter -> Adaptee
Bridge:               Abstraction --(has)--> Implementor
Decorator:            Decorator --(has)--> Component
Composite:            Composite -(contains)-> Leaf
Facade:               Facade -(uses)-> Subsystems
Flyweight:            Factory -> shared Intrinsic
Proxy:                Proxy -(has)-> RealSubject
# PracticeDP
