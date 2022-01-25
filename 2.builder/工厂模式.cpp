#include <iostream>

using namespace std;

class AbstructCar {
public:
    ~AbstructCar() {}
    virtual void printName() = 0;
    //virtual void debug() = 0;
};


class BWM :public AbstructCar {
    void printName() {
        cout << "name = " << "BWM" << endl;
    }
};

class BENZ :public AbstructCar {
    void printName() {
        cout << "name = " << "BENZ" << endl;
    }
};

class Factory {
public:
    AbstructCar* getCar(std::string name) {
        if (name == "bmw") {
            return new BWM();
        }else if (name == "benz") {
            return new BENZ();
        }else {
            cout << "can not create" << endl;
        }
        return nullptr;
    }

};

void test1() {
    Factory factory;
    AbstructCar* arr[6];
    arr[0] = factory.getCar("bmw");
    arr[1] = factory.getCar("bmw");
    arr[2] = factory.getCar("bmw");
    arr[3] = factory.getCar("benz");
    arr[4] = factory.getCar("benz");
    arr[5] = factory.getCar("benz");

    for (int i = 0; i < 6; i++) {
        arr[i]->printName();
        cout << endl;
    }

    delete [] arr;
}

int main() {
   test1();
    return 0;
}