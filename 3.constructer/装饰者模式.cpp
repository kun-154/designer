#include <iostream>

using namespace std;


class AbstractPerson {
public:
    virtual ~AbstractPerson() {}
    virtual void run() = 0;
    virtual void walk() = 0;

};

class Person : public AbstractPerson {
public:
    Person() {}
    ~Person() {}

    void run() override {
        cout << "Person run" << endl;
    }

    void walk() override {

        cout << "Person Walk" << endl;
    }

};

class AbstractDecorator : public AbstractPerson
{
public:
    AbstractDecorator(AbstractPerson* p): _person(p) {}
    ~AbstractDecorator(){}
    void run() override {
        cout << "Decorator person run" << endl;
        _person->run();
    }

    void walk() {
        cout << "Decorator Person walk" << endl;
        _person->walk();
    }
protected:
    AbstractPerson* _person;
};

class PersonBlack : public AbstractDecorator {
public:
    PersonBlack(AbstractPerson* p): AbstractDecorator(p) {}
    ~PersonBlack() {}
    void run() override{
        cout << "Black"; // 装饰
        _person->run();  // + 原本的行为
    }
    void walk() override{
        cout << "Black" ;
        _person->walk();
    }
};

class PersonOld : public AbstractDecorator {
public:
    PersonOld(AbstractPerson* p): AbstractDecorator(p) {}
    ~PersonOld() {}
    void run() override{
        cout << "Old";
        _person->run();
    }
    void walk() override{
        cout << "Old";
        _person->walk();
    }
};

void executeRun(AbstractPerson* p) {
    p->run();
}

void executeWalk(AbstractPerson* p) {
    p->walk();
}

void  test1() {

    AbstractPerson* p = new Person();
    p->run();
    p->walk();

    executeRun(p);
    executeWalk(p);
    cout << "=========================" << endl;
    PersonBlack* p1 = new PersonBlack(p);  // 通过装饰器可以加上自己新增的相关行为
    PersonOld* p2 = new PersonOld(p);

    executeRun(p1);
    executeRun(p2);

}

int main() {

    test1();


    return 0;
}