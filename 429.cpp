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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

using vecContainer = vector<int>;

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node *> que1;
        vector<vecContainer> res;
        if (root == nullptr)
            return res;
        que1.push(root);
        while (!que1.empty()) {
            int size = que1.size();
            vecContainer vec;
            while (size--) {
                Node *node1 = que1.front();
                if (node1->children.size() > 0) {
                    for (int i = 0; i < node1->children.size(); ++i) {
                        que1.push(node1->children[i]);
                    }
                }
                vec.emplace_back(node1->val);
                que1.pop();
            }
            res.emplace_back(vec);
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}