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

    ListNode() : val(0), next(nullptr) {};

    ListNode(int x) : val(x), next(nullptr) {};

    ListNode(int x, ListNode *next) : val(x), next(next) {};
};


void move(queue<int> s, ListNode *cur, int &flag) {
    ListNode *tmp = new ListNode(0);
    cur->next = tmp;
    cur = cur->next;
    int sum = 0;
    while (s.size()) {
        sum = s.front() + flag;
        s.pop();
        if (sum / 10 != 0)
            flag = 1;
        else
            flag = 0;
        cur->val = sum % 10;
        if (s.size() > 0) {
            if (cur->next == nullptr) {
                ListNode *tmp = new ListNode(0);
                cur->next = tmp;
                cur = cur->next;
            } else
                cur = cur->next;
        }
    }
}


class Solution {
public:
    //friend void move(queue<int> s, ListNode *cur, int &flag);
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        queue<int> s1;
        queue<int> s2;
        while (head1 != nullptr) {
            s1.push(head1->val);
            head1 = head1->next;
        }
        while (head2 != nullptr) {
            s2.push(head2->val);
            head2 = head2->next;
        }
        ListNode *head = s1.size() < s2.size() ? l1 : l2;
        ListNode *cur = head;
        int flag = 0;
        int sum = 0;
        int check = s1.size() <= s2.size() ? s1.size() : s2.size();
        while (check) {
            sum = s1.front() + s2.front() + flag;
            check -= 1;
            s1.pop();
            s2.pop();
            if (sum >= 10)
                flag = 1;
            else
                flag = 0;
            cur->val = sum % 10;
            if (check > 0)
                cur = cur->next;
        }
        if (!s1.empty()) {
            move(s1, cur, flag);
        } else if (!s2.empty()) {
            move(s2, cur, flag);
        }
        if (flag != 0) {
            ListNode *tmp = new ListNode(1);
            cur->next = tmp;
        }
        return head;
    }
};


int main() {
    Solution s;
    ListNode *head = new ListNode(9);
    ListNode *head1 = new ListNode(9);
    ListNode *head2 = new ListNode(9);
    ListNode *head3 = new ListNode(9);
    ListNode *head4 = new ListNode(9);
    ListNode *head5 = new ListNode(9);
    ListNode *head6 = new ListNode(9);
    head->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = head6;

    ListNode *head8 = new ListNode(9);
    ListNode *head9 = new ListNode(9);
    ListNode *head10 = new ListNode(9);
    ListNode *head11 = new ListNode(9);
    head8->next = head9;
    head9->next = head10;
    head10->next = head11;
    s.addTwoNumbers(head, head8);


    return 0;
}