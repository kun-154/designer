#include <iostream>
#include<vector>

using namespace std;


struct StateInfo{
    int _a, _b;
};

class CareTaker{
public:
    static CareTaker* _instance;
    static CareTaker* instance() {
        if(_instance == nullptr) {
            _instance = new CareTaker();
        }
        return _instance;
    }

    virtual ~CareTaker() {
        for (auto it : _states) {
            delete it;
        }
    }

    void addState(int a, int b) {
        _states.push_back(new StateInfo{a, b});
    }

    StateInfo* getState(int index) {
        if (_states.size() <= index) return nullptr;
        return _states[index];
    }

private:    
    std::vector<StateInfo*> _states;
};

class Origiantor {
public:
    Origiantor() : _a(0), _b(0) {}

    void setA(int n) {
        _a = n;
        this->savestate();
    }
    void setB(int n) {
        _b = n;
        this->savestate();
    }

    void getState(int index) {
        auto p = CareTaker::instance()->getState(index);
        if (p) {
            _a = p->_a;
            _b = p->_b;
        }
    }

    void debug()  {
        cout << "a = " << _a << " b = " << _b << endl;
    }

    void savestate() {
        CareTaker::instance()->addState(_a, _b);
    }

private:
    int _a, _b;
};



CareTaker* CareTaker::_instance = nullptr;

void test1() {
    Origiantor *p = new Origiantor();
    p->setA(1);
    p->setB(1);
    p->setA(2);
    p->setB(2);

    
    p->getState(0);
    p->debug();
    
    p->getState(1);
    p->debug();


}

int main() {
    test1();

    return 0;
}