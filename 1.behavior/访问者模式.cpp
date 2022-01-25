#include <iostream>
#include <string>

using namespace std;

// 不改变类的前提下 定义作用于 这些元素的新操作

class Node;
class Visitor {
public:
    virtual ~Visitor() {}

    virtual void visit(Node* node) = 0;
    
};

class Node {
public:
    virtual ~Node() {};
    virtual void accept(Visitor* visitor) = 0;
};

class NodeA :public Node {
    friend class VisitorA;
public: 
    NodeA() {
        s = "hello v";
    }
    void accept(Visitor* visitor) override {
        visitor->visit(this);
    }

private:
    string s;
};

class NodeB : public Node {
    friend class VisitorB;
public:
    NodeB() {
        s = "hello cb" ;
    }
    void accept(Visitor* visitor) override{
        visitor->visit(this);
    }
private:
    string s;
};

class VisitorA : public Visitor {
public:
    void visit(Node* node) override {
        NodeA* p = dynamic_cast<NodeA*>(node); 
        if (p) {
            cout << "Node A---" << p->s.c_str() << endl;
        }
    }
};

class VisitorB : public Visitor {
public:
    void visit(Node* node) override {
        NodeB* p = dynamic_cast<NodeB*>(node);
        if (p) {
            cout << "Node B---" << p->s.c_str() << endl;
        }
    }
};

void test1() {
    Node* p1 = new NodeA();
    Node* p2 = new NodeB();

    Visitor* p3 = new VisitorA();
    Visitor* p4 = new VisitorB();

    p1->accept(p3);
    p2->accept(p4);

}

int main(){

    test1();

    return 0;
}