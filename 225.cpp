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

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1 = q2;
        while (!q2.empty()) {
            q2.pop();
        }
        return res;
    }

    int top() {
        return q1.back();
    }

    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

int main() {
    MyStack myStack;

    return 0;
}