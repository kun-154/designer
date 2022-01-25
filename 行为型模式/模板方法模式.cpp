#include <iostream>

using namespace std;


// �� �߼�/ �㷨 ���ڳ�������У� ���������Ҫʵ��ϸ�ڵ� �ӿڣ� ������ʵ��ϸ��
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