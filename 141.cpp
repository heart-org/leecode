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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
                continue;
            }
            return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    return 0;
}