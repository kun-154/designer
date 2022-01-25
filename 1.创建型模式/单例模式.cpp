#include <iostream>
#include <thread>
#include <mutex>


using namespace std;

class Signal {
public:
    static Signal* instance();
    static Signal* _instance;
    static mutex _mtx;

};

Signal* Signal::_instance = nullptr;
mutex Signal::_mtx;

Signal* Signal::instance() {
    if (_instance == nullptr) {
        _mtx.lock();
        this_thread::sleep_for(chrono::milliseconds(100));
        if (_instance == nullptr) {
           _instance = new Signal(); 
        }
        _mtx.unlock();
    }
    return _instance;
}

void GetInstance() {
    cout << "instance" << Signal::instance() << endl;
}

void test1() { // 多线程级 的单例模式
    thread t1(GetInstance);
    thread t2(GetInstance);
    thread t3(GetInstance);


    t1.join();    
    t2.join();
    t3.join();

}



int main() {
    test1();


    return 0;
}