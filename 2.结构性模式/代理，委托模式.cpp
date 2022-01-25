#include <iostream>

using namespace std;

class Person{
public:
    virtual ~Person() {}


    virtual void rentHouse() = 0;
    virtual void setDelegate(Person* p) {_delegate = p;}

protected:
    Person* _delegate;
};

class Proxy : public Person {
public:
    Proxy() {}
    ~Proxy() {}

    void rentHouse() override {
        if (!_delegate) {
            return ;
        }
        _delegate->rentHouse();
        cout << "Proxy Help to Rent HOuse" << endl;
        cout << "Proxy Need to charge fees " << endl;
    }

};

class client : public Person {
public:
    ~client() {}
    client() {}

    void rentHouse() override {
        cout << "Need to rent house" << endl;
    }
};


void test1() {
    Person* p1 = new client();
    Person* p2 = new Proxy();

    p2->setDelegate(p1);
    p2->rentHouse();

}

int main() {
    test1();

    return 0;
}