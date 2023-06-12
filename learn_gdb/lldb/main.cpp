#include <iostream>
using std::cout;
using std::endl;

int globalVar = 50;

struct Demo {
    int memberVar;
    void demo() {
        cout << "hello from demo class" << endl;
    }
};

int square(int a) {
    return a * a;
}

namespace LLDBDemo {
    int add(int a, int b) {
        return a+b;
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        cout << argv[1] << endl;
    }
    int value = 5;
    int result = square(value);
    cout << result << endl;

    result = globalVar;
    Demo d;
    d.demo();

    int result2 = square(10);
    cout << result2 << endl;

    globalVar = 75;
    d.memberVar = 10;
    d.memberVar = 0;

    return 0;
}
