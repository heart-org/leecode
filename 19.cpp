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
        ListNode *s = head;
        int sum = 1;
        while (s->next != nullptr) {
            s = s->next;
            ++sum;
        }
        if (sum == n) {
            head = head->next;
            return head;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return head;
        }
        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < n - 1; ++i) {
            q = q->next;
        }
        while (q->next != nullptr) {
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        while (p->next != nullptr) {
            p = p->next;
        }
        return head;
    }
};

int main() {

    return 0;
}