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

using vecType1 = vector<string>;
using vecType2 = vector<int>;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vecType1 vec;
        vecType2 vec1;
        nodePath(root, vec, vec1);
        return vec;
    }

private:
    void nodePath(TreeNode *Node, vecType1 &vec, vecType2 &vec1) {
        vec1.emplace_back(Node->val);
        if (Node->left == nullptr && Node->right == nullptr) {
            vec.emplace_back(Result(vec1));
            return;
        }
        if (Node->left) {
            nodePath(Node->left, vec, vec1);
            vec1.pop_back();
        }
        if (Node->right) {
            nodePath(Node->right, vec, vec1);
            vec1.pop_back();
        }
    }

    string Result(vecType2 &vec1) {
        string res = to_string(vec1[0]);
        for (int i = 1; i < vec1.size(); ++i) {
            res += "->";
            res += to_string(vec1[i]);
        }
        return res;
    }
};

int main() {
    Solution s;

    return 0;
}