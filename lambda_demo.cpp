#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "algorithm"
#include "cstring"
#include "cmath"
#include "set"
#include "map"
#include "numeric"
#include "unordered_set"
#include "unordered_map"
#include "array"
#include "cctype"
#include "list"

using namespace std;

using fun_type = void (*)(int);

int main() {
    int x = 2;
    auto y = [num = 10](int x) -> int { return num + x; };
    cout << y(x) << endl;


    return 0;
}