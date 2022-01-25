#include <iostream>
#include <vector>

using namespace std;

class AbstractFacade {  // 连接 多个系统， 在最后的接口处 自动 统一连续登录系统，中间任一系统登录失败，则登录失败
// 实际是 封装 接口
// 为 子系统中的 一组接口提供一个一致的 界面（接口）
public:
    virtual ~AbstractFacade() {}
    virtual bool Register() = 0;
    virtual bool Login() = 0;

};

class SystemA : public AbstractFacade {
public:
    SystemA() {}
    ~SystemA() {}

    bool Register() override {
        cout << "SystemA Register" << endl; 
        return true;
    }

    bool Login() override {
        cout << "SystemA Login" << endl;
        return true;
    }
    
};

class SystemB : public AbstractFacade {
public:
    SystemB() {}
    ~SystemB() {}

    bool Register() override {
        cout << "SystemB Register" << endl; 
        return true;
    }

    bool Login() override {
        cout << "SystemB Login" << endl;
        return true;
    }
    
};

class SystemC : public AbstractFacade {
public:
    SystemC() {}
    ~SystemC() {}

    bool Register() override {
        cout << "SystemC Register" << endl; 
        return true;
    }

    bool Login() override {
        cout << "SystemC Login" << endl;
        return true;
    }
    
};

class Facace : public AbstractFacade {
public:
    Facace(){}
    ~Facace(){}

    bool Register() {
        for (auto p : _systems) {
            p->Register();
        }
        return true;
    }

    bool Login() override {
        for (auto p : _systems) {
            p->Login();
        }
        return true;
    }

    bool addSystem(AbstractFacade* sys) {
        _systems.push_back(sys);
    }
private:
    vector<AbstractFacade*> _systems;
};


bool test1() {
    Facace facace;
    AbstractFacade* sys1 = new SystemA();
    AbstractFacade* sys2 = new SystemB();
    AbstractFacade* sys3 = new SystemC();

    facace.addSystem(sys1);
    facace.addSystem(sys2);
    facace.addSystem(sys3);

    facace.Register();
    facace.Login();

    delete sys1;
    delete sys2;
    delete sys3;


}

int main() {

    test1();


    return 0;
}