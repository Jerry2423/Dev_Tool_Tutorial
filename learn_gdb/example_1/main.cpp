#include <iostream>
#include "black_box/black_box.h"
using std::cout;
using std::endl;
using BlackBox::foo;

void crash(int* i) {
    *i = 10;
}

void f(int* i) {
    int *j = i;
    foo(j);
    crash(j);
}

int main() {
   int i;
   f(&i);
}
