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

using vec_type = vector<vector<int>>;

/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vecContainer> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que1;
        que1.push(root);
        while(!que1.empty()){
            int size =  que1.size();
            vecContainer vec;
            while(size--){
                if (que1.front()->left)
                    que1.push(que1.front()->left);
                if (que1.front()->right)
                    que1.push(que1.front()->right);
                vec.emplace_back(que1.front()->val);
                que1.pop();
            }
            res.emplace_back(vec);
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vec_type vec;
        queue<TreeNode *> queue1;
        if (root == nullptr)
            return vec;
        queue1.push(root);
        while (!queue1.empty()) {
            int size = queue1.size();
            vector<int> now_vec;
            for (int i = 0; i < size; ++i) {
                TreeNode *Node = queue1.front();
                queue1.pop();
                now_vec.emplace_back(Node->val);
                if (Node->left)
                    queue1.push(Node->left);
                if (Node->right)
                    queue1.push(Node->right);
            }
            vec.emplace_back(now_vec);
        }
        return vec;
    }
};

int main() {
    Solution s;

    return 0;
}