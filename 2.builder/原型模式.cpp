#include <iostream>
#include <string>

using namespace std;

// �� ����֮��� �ظ�����������һ�£� ������Ҫ����1000������ ���У� ����ֵΪ1�� ����ֵΪ2�������ĸ�����Ҫ���� 100���� 
// ��Ȼ�� �ڹ��캯��������������Ч���� ���ǣ� һ��һ��д�ֹ����鷳�� ��Ӧ�ó����� �ʼ��ַ��� ��Ҫ��һ�� �ʼ� һ���Եķ����������

// �ܶ���֮�� ԭ��ģʽ�����ǽ��Լ�����һ�ݣ� ���� �� ����ѡ���ԵĿ��� �Լ��е�ĳЩ���ԣ�

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