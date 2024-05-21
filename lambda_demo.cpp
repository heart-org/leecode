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
using vecContainer = vector<int>;



int main() {
//    int x = 2;
//    auto y = [num = 10](int x) -> int { return num + x; };
//    cout << y(x) << endl;
//
//    cout << "x = " << x << endl;
//    vecContainer  vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 1;
    int y = 2;
    auto foo = [&x, &y] {
        x += 2;
        y += 2;
        return x * y;
    };
    cout << foo() << endl;

    int x1 = 1;
    int y1 = 2;
    auto foo1 = [=]()mutable {
        x1 += 2;
        y1 += 2;
        return x1 * y1;
    };
    cout << foo1() << endl;

    map<int, int> map1;
    map1.insert(make_pair(1, 2));
    map1.insert(make_pair(2, 2));
    map1.insert(make_pair(5, 2));
    map1.insert(make_pair(7, 2));
    map1.insert({8, 4});
    int val = 8;
    auto it = find_if(map1.begin(), map1.end(), [val](pair<int, int> cur) { return val == cur.first; });
    if (it == map1.end())
        cout << "None!" << endl;
    else
        cout << "The key's value is " << it->second << endl;

    return 0;
}