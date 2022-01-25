#include <iostream>

using namespace std;


class AbstructGame {
public:
    virtual void play() = 0;
};

class BMWGame : public AbstructGame {
public:
    void play() {
        cout << "BMW ï¿½ï¿½" << endl;
    }
};

class BENZGame : public AbstructGame {
public:
    void play() {
        cout << "BENZÍê" << endl;
    }
};

class AbstructPhone {
public:
    AbstructGame* game;
    void setphone(AbstructGame* g) {
        game = g;
    }
    void runGame() {
        if (game) {
            game->play();
        }else {
            cout << "failed" << endl;
        }
        
    }
};



void test1() {
    AbstructGame* gameA = new BMWGame();
    AbstructGame* gameB = new BENZGame();

    AbstructPhone* phone = new AbstructPhone();
    phone->setphone(gameA);
    phone->runGame();
   
}

int main() {
   test1();
    return 0;
}