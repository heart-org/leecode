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

    ListNode(int val) : val(val), next(nullptr) {}

    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *left = new ListNode();
        left->next = pre;
        ListNode *res = new ListNode(0, head->next);
        while (cur != nullptr && pre != nullptr) {
            ListNode *right = cur->next;
            left->next = nullptr;
            pre->next = nullptr;
            cur->next = pre;
            left->next = cur;
            pre->next = right;
            left = pre;
            pre = right;
            if (pre != nullptr)
                cur = pre->next;
        }
        return res->next;
    }
};

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * res = new ListNode(0, head);
        ListNode * slow = res;
        ListNode * fast = res;
        while(n-- && fast != nullptr){
            fast = fast->next;
        }
        while (fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return res->next;
    }
};
*/

int main() {
    Solution s;
    ListNode *Node1 = new ListNode(4);
    ListNode *Node2 = new ListNode(3, Node1);
    ListNode *Node3 = new ListNode(2, Node2);
    ListNode *head = new ListNode(1, Node3);
    s.swapPairs(head);

    return 0;
}