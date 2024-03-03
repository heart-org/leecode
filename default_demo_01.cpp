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

class Solution {
public:
    Solution();

    ~Solution() = delete;

    void print_count() {
        cout << a << endl;
    }

private:
    int a;
};

union U {
    int x1;
    float x2;
};

Solution::Solution() {
    a = 100;
}

int main() {
    Solution *s = new Solution;
    s->print_count();

    U u;
    u.x1 = 10;
    cout << u.x1 << " " << u.x2 << endl;

    u.x2 = 0.5;
    cout << u.x1 << " " << u.x2 << endl;

    cout << u.x1 << " " << u.x2 << endl;


    return 0;
}