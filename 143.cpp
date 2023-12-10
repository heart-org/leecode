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

/*class Solution {
public:
    void reorderList(ListNode* head) {
        if (head->next == nullptr || head->next->next == nullptr)
            return;
        ListNode *left = head;
        ListNode *right = new ListNode(0);
        right->next = head;
        vector<ListNode*> vec;
        while(right->next != nullptr){
            vec.push_back(right->next);
            right = right->next;
        }
        int slow = 0;
        int fast = vec.size() - 1;
        ListNode * l_tmp;
        ListNode * r_tmp;
        ListNode * cur = new ListNode(0);
        while(slow < fast){
            l_tmp = left->next;
            r_tmp = vec[fast - 1];
            r_tmp->next = nullptr;
            left->next = nullptr;
            cur->next = left;
            cur = cur->next;
            cur->next = right;
            cur = cur->next;
            left = l_tmp;
            right = r_tmp;
            fast--;
            slow++;
        }
        if (slow == fast)
            cur->next = vec[fast];
    }
};*/


class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr)
            return;
        ListNode *right = new ListNode(0);
        right->next = head;
        vector<ListNode *> vec;
        while (right->next != nullptr) {
            vec.emplace_back(right->next);
            right = right->next;
        }
        int slow = 0;
        int fast = vec.size() - 1;
        while (slow < fast) {
            vec[slow++]->next = vec[fast];
            if (slow == fast)
                break;
            vec[fast--]->next = vec[slow];
        }
        vec[fast]->next = nullptr;
    }
};


int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *head1 = new ListNode(2);
    ListNode *head2 = new ListNode(3);
    ListNode *head3 = new ListNode(4);
    //ListNode * head4 = new ListNode(5);
    head->next = head1;
    head1->next = head2;
    head2->next = head3;
    s.reorderList(head);


    return 0;
}