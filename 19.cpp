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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *x = head;
        int length = 0;
        while (x) {
            length++;
            x = x->next;
        }
        if (n == length)
            return p->next;
        for (int i = 0; i < n; ++i) {
            q = q->next;
        }
        while (q->next != nullptr) {
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};

int main() {

    return 0;
}