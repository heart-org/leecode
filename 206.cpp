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
    ListNode *reverseList(ListNode *head) {
        ListNode *p = new ListNode(0, head);
        ListNode *s = new ListNode(0, head);
        stack<int> st;
        s = p;
        while (s->next != nullptr) {
            st.push(s->next->val);
            s = s->next;
        }
        while (!st.empty()) {
            p->next->val = st.top();
            st.pop();
            p = p->next;
        }
        return head;
    }
};

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
 *
 */

int main() {

    return 0;
}