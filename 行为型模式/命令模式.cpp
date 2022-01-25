#include <iostream>

using namespace std;

// 命令模式 通过将请求 封装到一个对像中， 并将请求者存放到具体的 类中， 从而实现调用操作的对象与操作 的具体实现之间 的解耦


class Receiver {
public:
    Receiver() {}
    virtual ~Receiver() {}
    virtual void operator()() {
        cout << "Ececute Command" << endl;
    }
};

class Receiver2 : public Receiver{
public:
    void operator()() override {
        cout << "Execute Command2! " << endl;
    }
};

class Command {
public:
    Command(Receiver* p) : _receiver(p) {}
    virtual ~Command() {}
    virtual void doCommand(int n) = 0;
protected: 
    Receiver* _receiver;

};

class CommandA : public Command {
public:
    CommandA(Receiver* p1, Receiver2* p2) : Command(p1), _receiver2(p2) {}

    void doCommand(int n) {
        if (n == 1) {
            (*_receiver)();
        }else {
            (*_receiver2)();
        }
    }
protected:

    Receiver2* _receiver2;
};

class Invoker {
public:
    Invoker(): _command(nullptr) {}
    virtual ~Invoker() {}
    void setCommand(Command* p) {
        _command = p;
    }

    void executeCommand(int n) {
        if (_command) _command->doCommand(n);
    }
private:   
    Command* _command;
};


void test1() {
    Invoker* invoker = new Invoker();
    Receiver* receiver = new Receiver();
    Receiver2* receiver2 = new Receiver2();

    Command* command = new CommandA(receiver, receiver2);

    invoker->setCommand(command);
    invoker->executeCommand(1);
    invoker->executeCommand(2);

    delete command;
    delete receiver2;
    delete receiver;
    delete invoker;
}

int main() {

    test1();

    return 0;
}