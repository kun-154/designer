#include <iostream>

using namespace std;

// �������Ͷ���������֮���ͨ�Ÿ����ԣ� ����ģʽ �ṩ�� һ���н��࣬ ���� ͨ������ ��ͬ��֮���ͨ�ţ� ��֧������ϣ�
// ��ʹ�� ��������ά��
class Colleague;
class Mediator {
public: 
    virtual void deal(Colleague* p) = 0;
    virtual void setMediator(Colleague* from, Colleague* to) {
        _from = from;
        _to = to;
    }

protected:
    Colleague* _from;
    Colleague* _to;

};


class Colleague {
public:
    Colleague(Mediator* p): _mediator(p) {

    }

    virtual ~Colleague() {}

    virtual void send() = 0;
    virtual void receive(string s) = 0;

protected:
    Mediator* _mediator;
};

class ColleagueA : public Colleague {
public:
    ColleagueA(Mediator* p): Colleague(p) {
        
    }

    void send() override{
        _mediator->deal(this);
    }

    void receive(string s) {
        cout << s << endl;
    }
};

class ColleagueB : public Colleague {
public:
    ColleagueB(Mediator* p): Colleague(p) {

    }

    void send() override{
        _mediator->deal(this);
    }

    void receive(string s) {
        cout << s << endl;
    }
};


class MediatorA : public Mediator {
public:
    void deal(Colleague* p) override {
        if (p == _to) {
            _to->receive("from--to");
        }else {
            _from->receive("to--from");
        }
    }
};


void test1(){
    Mediator* mediator = new MediatorA();
    Colleague* p1 = new ColleagueA(mediator);
    Colleague* p2 = new ColleagueB(mediator);
    mediator->setMediator(p1, p2);

    p1->send();
    p2->send();
    
}

int main() {
    test1();

    return 0;
}