#include <iostream>

using namespace std;

class produce1 {
public:
    static produce1* _instance;
    static produce1* instance() {
    }
    virtual ~produce1() {};
private:
    produce1() :count(1) {}
    int count;
};

produce1* produce1::_instance = nullptr;
produce1* produce1::instance() {
    if (_instance == nullptr) {
        _instance = new produce1();
    }
    return _instance;
}
class produce2 :public produce1 {
    
};

class produce3 :public produce1 {
    
};

int main() {



    return 0;
}