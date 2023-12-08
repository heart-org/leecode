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

    ListNode(int x) : val(0), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode *cur = dummyhead;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode *p = cur->next;
                cur->next = cur->next->next;
                delete p;
            } else
                cur = cur->next;
        }
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};

int main() {
    Solution s;

    return 0;
}