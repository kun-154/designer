#include <iostream>

using namespace std;

// 解决 老旧 接口 不适配的问题， 通过 创建一个新的类，继承 老接口 ， 并 增加新功能， 
// 此时， 调用， 新创建的类就能 在保留老接口的基础上， 增加新功能
// 可以使用，继承 也可以使用 封装的思想 

class Target {
public:
    virtual int request() = 0;

};

class Adaptee {
public:
    virtual ~Adaptee() {}
    virtual int specialRequest() {
        cout << "Apdatee Special Reqyest" << endl;
        return 999;
    }
};


// 利用继承 实现 接口转换
class Adapter : public Target, public Adaptee {
public:
    int request() override {
        return this->specialRequest();
    }
};


// 通过封装 实现转换
class AAdapter : public Target {
private:
    Adaptee* _adaptee;

public:
    AAdapter() = delete;
    AAdapter(Adaptee* p) : _adaptee(p) {

    }

    virtual ~AAdapter(){}
    int request() override{
        return _adaptee->specialRequest();
    }
};

// 实现 接口
void interfaceRequest(Target* target) {
    auto ret = target->request();
    cout << "ret = " << ret << endl;
}

void test1() {
    Adapter* adapter = new Adapter();
    interfaceRequest(adapter);
    
    delete adapter;
    
}

void test2() {
    Adaptee* adaptee = new Adaptee();
    Target* target = new AAdapter(adaptee);
    interfaceRequest(target);

}


int main() {

    test1();


    return 0;
}