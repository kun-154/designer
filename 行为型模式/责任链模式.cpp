#include <iostream>

using namespace std;

// ʹ������� ���л��� �������� �Ӷ���������ķ����� �� ������ ֮�����Ϲ�ϵ
// ������������� һ������ �������������������� ֱ����һ����������Ϊֹ

struct Request {
    int days;
    int type;
    string desc;
};

class Handler {
public: 
    Handler() {}
    virtual ~Handler() {}
    virtual void setNextHandler(Handler* p) {
        _nextHandler = p;
    }
    virtual void dealRequest(Request* p) = 0;
    virtual void request(int days, int type, string desc) {
        Request* p = new Request{days, type, desc};
        this->dealRequest(p);
        delete p;
    }
protected:
    Handler* _nextHandler;
};

class Employee : public Handler {
public: 
    void dealRequest(Request* p) override {
        cout << "û��Ȩ�ޣ� ��Ҫ�ϼ�����" << endl;
        if (this->_nextHandler) {
            this->_nextHandler->dealRequest(p);
        }
    }

};

class teamLeader : public Handler {
public: 
    void dealRequest(Request* p) override {
        if (p->days < 3) {
            cout << "�������죬 ֱ������" << endl;
        }else {
            cout << "û��Ȩ�ޣ� ��Ҫ�ϼ�����" << endl;
            if (this->_nextHandler) {
                this->_nextHandler->dealRequest(p);
            }
        }
    }
    
};

class Manager : public Handler {
public: 
    void dealRequest(Request* p) override {
        if (p->days < 5) {
            cout << "�������죬 ֱ������" << endl;
        }else {
            cout << "û��Ȩ�ޣ� ��Ҫ�ϼ�����" << endl;
            if (this->_nextHandler) {
                this->_nextHandler->dealRequest(p);
            }
        }
    }
    
};

class Boss : public Handler {
public: 
    void dealRequest(Request* p) override {
        if (p->days < 10) {
            cout << "�������죬 ֱ������" << endl;
        }else {
            cout << "����ʮ�죬 �ܾ�����" << endl;
            if (this->_nextHandler) {
                this->_nextHandler->dealRequest(p);
            }
        }
    }
    
};

void test1() {
    Handler* p1 = new Boss();    
    Handler* p2 = new Manager();
    Handler* p3 = new teamLeader();
    Handler* p4 = new Employee();

    p4->setNextHandler(p3);
    p3->setNextHandler(p2);
    p2->setNextHandler(p1);

    p4->request(2, 0, "2");
    p4->request(5, 0, "2");
    p4->request(10, 0, "2");


    delete p4;
    delete p3;
    delete p2;
    delete p1;

}

int main() {
    test1();

    return 0;
}