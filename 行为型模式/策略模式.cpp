#include <iostream>

using namespace std;

// ����ģʽ �� ģ��ģʽ Ҫ�������������ͬ�� ��Ϊ�˸�ҵ���߼�/ �㷨����ʵ�ֺͳ���ӿ��� �� ����ģʽ ���߼�/ �㷨 ��װ��һ�����У� ͨ����ϵķ�ʽ�������㷨��ʵ�� ����϶�����ʵ�֣�
// ��ͨ�� ί�еķ�ʽ�� ����ӿ� ��ʵ��ί�и���϶���ʵ��

class Stragegy {
public:
    virtual ~Stragegy(){}
    virtual void sort(int arr[], int n) = 0;
};

class BubbleSort : public Stragegy {
    void sort(int arr[], int n) {
        cout << "Bubble" << endl;
    }
};

class InsertSort : public Stragegy {
    void sort(int arr[], int n) {
        cout << "InsertSort" << endl; 
    }
};

class SelectSort : public Stragegy {
    void sort(int arr[], int n) {
        cout << "SelectSort" << endl;
    }
};

class Context {
public:

    void setdata(int arr[], int size) {
        _arr = arr;
        _size = size;
    }

    void setStragegy(Stragegy* p) {
        _stragegy = p;
    }

    void sort() {
        _stragegy->sort(_arr, _size);
    }

    void show() {
        for (int i= 0; i < _size; i++) {
            cout << _arr[i] << " ";
        }
        cout << endl;
    }

private:
    Stragegy* _stragegy; 
    int *_arr;
    int _size;

};


void test1() {
    Stragegy *p1 = new BubbleSort(); 
    Stragegy *p2 = new InsertSort(); 
    Stragegy *p3 = new SelectSort(); 


    Context *p = new Context();
    int size = 3;
    int arr[3] = {1,2 ,3};
    p->setdata(arr, size);
    p->setStragegy(p1);

    p->sort();
    p->show();
}

int main() {
    test1();


    return 0;
}