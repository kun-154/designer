#include <iostream>

using namespace std;

// 将 类的构建 与 类的表示分离， （应用场景 常常是， 一个结构复杂的对象， ）
// 四要素： 产品类（结构复杂的对象）， 抽象建造者（便于管理子类）， 建造者（组建产品， 将 产品返回）， 导演类（负责调度 适当的建造者组件产品）

class AbstructCar {
protected:
    int wheel;
    int engine;
    int color;

public:
    ~AbstructCar() {}
    virtual void printName() = 0;
    virtual void debug() = 0;
};


class BMW :public AbstructCar {
    void printName() override{
        cout << "name = " << "BMW" << endl;
    }
     void debug() override{
        cout << "name = " << "BMW" << endl;
    }
};

class BENZ :public AbstructCar {
    void printName() override{
        cout << "name = " << "BENZ" << endl;
    }
     void debug() override{
        cout << "name = " << "BENZ" << endl;
    }
};

class AbstructBuilder {
public:
    virtual void builderA() = 0;
    virtual void builderB() = 0;
    virtual void builderC() = 0;

    virtual AbstructCar* getCar() = 0;

};

class BMWBuilder : public AbstructBuilder {
public:
    void builderA() override {
        cout << "WMWBuilder BuilderA" << endl;
    }
    void builderB() override {
        cout << "WMWBuilder BuilderB" << endl;
    }
    void builderC() override {
        cout << "WMWBuilder BuilderC" << endl;
    }

    AbstructCar* getCar() {
        AbstructCar* car = new BMW();
        builderA();
        builderB();
        builderC();
        return car;
    }
};

class BENZBuilder : public AbstructBuilder {
public:
    void builderA() override {
        cout << "BENZBuilder BuilderA" << endl;
    }
    void builderB() override {
        cout << "BENZBuilder BuilderB" << endl;
    }
    void builderC() override {
        cout << "BENZBuilder BuilderC" << endl;
    }

    AbstructCar* getCar() {
        AbstructCar* car = new BENZ();
        builderC();
        builderB();
        builderA();
        return car;
    }
};

class Director {
private:
    AbstructBuilder* _builder;
public:
    void setBuilder(AbstructBuilder* builder) {
        _builder = builder;
    }

    AbstructCar* getCar() {
        return _builder->getCar();
    }

   

};

void test1() {
   Director director;
   BMWBuilder* builder1 = new BMWBuilder();
   BENZBuilder* builder2 = new BENZBuilder();
    director.setBuilder(builder1);
    auto car1 = director.getCar();
    car1->debug();

    director.setBuilder(builder2);
    auto car2 = director.getCar();
    car2->debug();   

}

int main() {
   test1();
    return 0;
}