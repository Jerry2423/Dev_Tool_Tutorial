#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int j = 10;
    int* ptr = &j;
    j += i;
    cout << "hi" << endl;
    return 0;
}
