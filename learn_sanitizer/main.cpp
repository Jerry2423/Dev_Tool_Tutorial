// #include <string>
//
// int main() {
//     const char* names[] = {"ddd", "jjj"};
//     std::string s = names[3];
//     return s.size();
// }
// #include <iostream>
//
// void set_val(bool& b, const int val) {
//     if (val > 1) {
//         b = false;
//     }
// }
//
// int main(const int argc, const char *[]) {
//     bool b;
//     set_val(b, argc);
//     if (b) {
//         std::cout << "set_val" << std::endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

class A {
    public:
        A(int val) : a(val) {}

    private:
        int a;
};

int main() { 
    auto a = new A(10);
    delete a;
    delete a;
    return 0;
}
