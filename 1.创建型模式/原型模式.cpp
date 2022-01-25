#include <iostream>
#include <string>

using namespace std;

// 简化 对象之间的 重复创建（想象一下， 假设需要创建1000个对象， 其中， 属性值为1， 属性值为2，。。的各自需要创建 100个， 
// 显然， 在构造函数中做不到这样效果， 但是， 一个一个写又过于麻烦） （应用场景： 邮件分发， 需要将一份 邮件 一次性的发给多个对象）

// 总而言之， 原型模式，就是将自己拷贝一份， 但是 ， 可以选择性的拷贝 自己中的某些属性，

class AbstructProto {
public:
    virtual AbstructProto* clone() = 0;
    virtual ~AbstructProto() {}
    virtual void debug() = 0;
int x;
};

class ProtoTypeA: public AbstructProto {
    public:
    AbstructProto* clone() override {
        return new ProtoTypeA(*this);
    }

    void debug() override {
        cout << this << "  ProtoTypeA" << x << endl;
    }
};

class ProtoTypeB: public AbstructProto {
        public:

    AbstructProto* clone() override {
        return new ProtoTypeB(*this);
    }

    void debug() override {
        cout << this << "  ProtoTypeB" << x << endl;
    }
};


void test1() {
    AbstructProto* p1 = new ProtoTypeA();
    p1->x = 10;
    AbstructProto* p2 = new ProtoTypeB();
    p2->x = 20;
    AbstructProto* p3 = p1->clone();
    AbstructProto* p4 = p2->clone();
    p1->debug();    
    p2->debug();
    p3->debug();
    p4->debug();

    delete p1;
    delete p2;
    delete p3;
    delete p4;


}

int main() {
   test1();
    return 0;
}