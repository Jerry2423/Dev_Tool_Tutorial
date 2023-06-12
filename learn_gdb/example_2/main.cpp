#include <iostream>
using namespace std;

int fac(const int & n) {
    if (n) {
        return n*fac(n-1);
    } else {
        return 1;
    }
}

int main() {
    int n;
    cin >> n;
    if (n >= 0) {
        cout << fac(n) << endl;
    } else {
        cout << "wrong input" << endl;
    }
    return 0;
}
