#include <iostream>
#include <utility>
using namespace std;

int main() {
    cout << "fu" << endl;
    auto pair = make_pair(10, "func");
    cout << pair.first << endl;
    return 0;
}
