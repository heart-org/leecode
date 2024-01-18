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

//method1
using map_type = map<int, int>;
using vec_type = vector<int>;

class Solution1 {
public:
    vector<int> findMode(TreeNode *root) {
        search(root);
        int sum = INT_MIN;
        for (auto i: map) {
            if (i.second > sum) {
                res.clear();
                sum = i.second;
                res.emplace_back(i.first);
            } else if (i.second == sum)
                res.emplace_back(i.first);
        }
        return res;
    }

private:
    map_type map;
    vec_type res;

    void search(TreeNode *Node) {
        if (Node == nullptr)
            return;
        map[Node->val]++;
        search(Node->left);
        search(Node->right);
    }
};

//method2
using vec_type = vector<int>;

class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        search(root);
        return res;
    }

private:
    TreeNode *pre = nullptr;
    vec_type res;
    int max_sum = 0;
    int sum;

    void search(TreeNode *cur) {
        if (cur == nullptr)
            return;
        search(cur->left);
        if (pre == nullptr) {
            sum = 1;
        } else if (pre->val == cur->val) {
            ++sum;
        } else {
            sum = 1;
        }
        pre = cur;
        if (sum == max_sum)
            res.emplace_back(pre->val);
        if (sum > max_sum) {
            res.clear();
            max_sum = sum;
            res.emplace_back(pre->val);
        }
        search(cur->right);
        return;
    }
};

int main() {
    Solution s;

    return 0;
}