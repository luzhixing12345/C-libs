

#include <iostream>

class Base {
public:
    virtual void Fun() {
        std::cout << "Base Class function called" << std::endl;
    }
};

class Derive: public Base {
public:
    virtual void Fun() {
        std::cout << "Derive Class funtion called" << std::endl;
    }
};

int main() {

    Base *p = new Derive();
    p->Fun();
    delete p;
    return 0;
}