#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// ------------- Component --------------
class FileSystemItem {
public:
    virtual int getSize() const = 0;
    virtual void show(int indent = 0) const = 0;
    virtual ~FileSystemItem() = default;
};

// ------------- Leaf: File --------------
class FileItem : public FileSystemItem {
private:
    string name;
    int size;
public:
    FileItem(string n, int s) : name(std::move(n)), size(s) {}

    int getSize() const override {
        // TODO
        return size;
    }

    void show(int indent = 0) const override {
        // TODO: In dạng "File: name (size)"
        cout << string(indent, ' ') 
             << "File: " << name << " (" << size << ")\n";
    }
};

// ------------- Composite: Folder --------------
class FolderItem : public FileSystemItem {
private:
    string name;
    vector<shared_ptr<FileSystemItem>> children;  // COMPOSITION
public:
    FolderItem(string n) : name(std::move(n)) {}

    void add(const shared_ptr<FileSystemItem>& item) {
        children.push_back(item);
    }

    int getSize() const override {
        // TODO: tính tổng size (đệ quy)
        int total = 0;
        for (auto& c : children)
            total += c->getSize();
        return total;
    }

    void show(int indent = 0) const override {
        // TODO
        cout << string(indent, ' ')
             << "Folder: " << name << "\n";
        for (auto& c : children)
            c->show(indent + 2);
    }
};

// ------------- Demo --------------
int main() {
    auto root = make_shared<FolderItem>("Root");

    root->add(make_shared<FileItem>("a.txt", 10));
    root->add(make_shared<FileItem>("b.txt", 20));

    auto docs = make_shared<FolderItem>("Docs");
    docs->add(make_shared<FileItem>("report.pdf", 50));

    root->add(docs);

    root->show();
    cout << "Total size = " << root->getSize() << "\n";
}
