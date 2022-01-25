#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
// 观察者模式要解的问题是 ： 建立一个一对多的 依赖关系， 并且做到 当“ 一 ” 变化时 依赖这个 “一” 的多 也能够 同步 改变

class Subject;
class AbstractObserver {
public:
    AbstractObserver(string name): _name(name) {}
    virtual void update(string p) = 0;
    virtual const string& getname()const {
        return _name;
    }

protected:
    string _name;

};

class ObserverA: public AbstractObserver {
public:
    ObserverA(string s) : AbstractObserver(s) {}
    ~ObserverA(){}
    void update(string name) override {
        cout << "Before Update ObeserveA name = " << _name << "address = " << this << endl;
        _name = name;
        cout << "After Update ObeserveA name = " << _name << "address = " << this << endl;

    }

};


class ObserverB: public AbstractObserver {
public:
    ObserverB(string s) : AbstractObserver(s) {}
    ~ObserverB(){}

    void update(string name) override {
        cout << "Before Update ObeserveA name = " << _name << "address = " << this << endl;
        _name = name;
        cout << "After Update ObeserveA name = " << _name << "address = " << this << endl;
    }
    
};

class Subject {
public: 
    void addobservers(AbstractObserver* p) {
        auto arr = _observers.find(p->getname());
        if (arr != _observers.end()) {
            _observers[p->getname()].push_back(p);
        }else {
            std::vector<AbstractObserver*> v;
            v.push_back(p);
            _observers[p->getname()] = v;
        }
    }

    void remove() {
         
    }   

    void notify(string s, string name) {
        if (_observers.find(s) != _observers.end()) {
            for (auto ob : _observers[s]) {
                ob->update(name);
            }
        }else {
            cout << "no observers" << endl;
        }
    }

protected:
    // key 当作 观察id
    std::map<string, std::vector<AbstractObserver*>> _observers;
};


void test1() {
    Subject subject;
    AbstractObserver* p1 = new ObserverA("ad");    
    AbstractObserver* p2 = new ObserverA("df");
    AbstractObserver* p3 = new ObserverA("ddf");
    AbstractObserver* p4 = new ObserverA("123");
    AbstractObserver* p5 = new ObserverA("1234");

    subject.addobservers(p1);
    subject.addobservers(p2);
    subject.addobservers(p3);
    subject.addobservers(p4);    
    subject.addobservers(p5);

    //subject.notify("ad");
    //subject.notify("df");
    //subject.notify("123");

    subject.notify("ad", "abc");
    subject.notify("df", "dfg");
    subject.notify("123", "1234"); // 画蛇添足



}

int main() {
    test1();

    return 0;
}