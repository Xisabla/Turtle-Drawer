#include <iostream>
#include <map>
#include <string>

typedef bool strfunc_t(int arg);

using namespace std;

bool a(int arg) {
    cout << "a " << arg << endl;
    return true;
}

bool b(int arg) {
    cout << "b " << arg << endl;
    return true;
}

int main() {
    map < string, strfunc_t * > m;

    m["a"] = a;
    m["b"] = b;

    m.find("a")->second(1);

    return 0;
}