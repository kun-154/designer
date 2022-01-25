#include <iostream>

using namespace std;


// 将 逻辑/ 算法 放在抽象基类中， 并定义好需要实现细节的 接口， 子类中实现细节
class Factory {
public:
    virtual void buildCar() {
        this->buildA();        
        this->buildB();
        this->buildC();
        this->buildD();        
    }

    virtual void buildA() = 0;
    virtual void buildB() = 0;
    virtual void buildC() = 0;
    virtual void buildD() = 0;

};

class FactoryBMW : public Factory {
public:
    void buildA() {
        cout << "Build in BWM Factory" << endl;
    }    
    void buildB() {
        cout << "Build in BWM Factory" << endl;
    }
    void buildC() {
        cout << "Build in BWM Factory" << endl;
    }
    void buildD() {
        cout << "Build in BWM Factory" << endl;
    }

};

class FactoryBENZ :public Factory {
public:
    void buildA() {
        cout << "Build in BENz Factory" << endl;
    }    
    void buildB() {
        cout << "Build in BENZ Factory" << endl;
    }
    void buildC() {
        cout << "Build in BNEZ Factory" << endl;
    }
    void buildD() {
        cout << "Build in BENZ Factory" << endl;
    }

};


void test1() {
    Factory* p1 = new FactoryBMW();
    Factory* p2 = new FactoryBENZ();

    p1->buildCar();

}

int main() {

    test1();

    return 0;
}