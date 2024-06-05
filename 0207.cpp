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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *Node1 = headA;
        ListNode *Node2 = headB;
        int lenA = 0;
        int lenB = 0;
        while (Node1 != nullptr) {
            lenA++;
            Node1 = Node1->next;
        }
        while (Node2 != nullptr) {
            lenB++;
            Node2 = Node2->next;
        }
        Node1 = headA;
        Node2 = headB;
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(Node1, Node2);
        }
        int gap = lenA - lenB;
        while (gap--) {
            Node1 = Node1->next;
        }
        while (Node1 != nullptr) {
            if (Node1 == Node2)
                return Node1;
            Node1 = Node1->next;
            Node2 = Node2->next;
        }
        return nullptr;
    }
};

int main() {
    Solution s;

    return 0;
}