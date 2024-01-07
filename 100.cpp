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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using vecType = vector<int>;

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        preOrder(p, v1);
        preOrder(q, v2);
        if (v1 == v2)
            return true;
        return false;
    }

private:
    vecType v1;
    vecType v2;

    void preOrder(TreeNode *Node, vecType &vec) {
        if (Node == nullptr) {
            vec.emplace_back(INT_MAX);
            return;
        }
        vec.emplace_back(Node->val);
        preOrder(Node->left, vec);
        preOrder(Node->right, vec);
    }
};

int main() {


    return 0;
}

