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

using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> st1;

    MinStack() {
        st1.push(INT_MAX);
    }

    void push(int val) {
        s.push(val);
        st1.push(min(val,st1.top()));
    }

    void pop() {
        s.pop();
        st1.pop();
    }

    int top() {
        if (!s.empty()){
            return s.top();
        }
        return 0;
    }

    int getMin() {
        if (!st1.empty()) {
            return st1.top();
        }
        return 0;
    }
};

int main() {


    return 0;
}