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

/*
void change(ListNode** start, ListNode** cur){
    ListNode * tmp1 = new ListNode();
    ListNode * tmp2 = new ListNode();
    tmp1 = (*cur)->next;
    (*cur)->next = (*cur)->next->next;
    tmp2 = (*start)->next;
    tmp1 = (*start)->next;
    tmp1->next = tmp2;
}

void merge(ListNode** start, ListNode** cur){
    while ((*start)->next != nullptr && (*cur)->next != nullptr){
        if ((*start)->next->val <= (*cur)->next->val){
            (*start) = (*start)->next;
        }else{
            change(&(*start), &(*cur));
        }
    }
    while ((*cur)->next != nullptr){
        change(&(*start), &(*cur));
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (empty(lists) || lists.size() == 1)
            return lists[0];
        ListNode* res = new ListNode(0, lists[0]);
        for (int i = 1; i < lists.size(); ++i) {
            ListNode* start = res;
            ListNode* cur = new ListNode(0, lists[i]);
            merge(&start, &cur);
        }
        return res->next;
    }
};*/

vector<int> change(ListNode *cur) {
    vector<int> vec;
    while (cur != nullptr) {
        vec.emplace_back(cur->val);
        cur = cur->next;
    }
    return vec;
}

void mergeTwoLists(vector<int> vec1, vector<int> vec2, ListNode **cur) {
    ListNode *head = (*cur);
    int i = 0, j = 0;
    while (true) {
        if (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] <= vec2[j]) {
                ListNode *tmp = new ListNode(vec1[i++]);
                (*cur)->next = tmp;
                (*cur) = (*cur)->next;
            } else {
                ListNode *tmp = new ListNode(vec2[j++]);
                (*cur)->next = tmp;
                (*cur) = (*cur)->next;
            }
        } else
            break;
    }
    while (i < vec1.size()) {
        ListNode *tmp = new ListNode(vec1[i++]);
        (*cur)->next = tmp;
        (*cur) = (*cur)->next;
    }
    while (j < vec2.size()) {
        ListNode *tmp = new ListNode(vec2[j++]);
        (*cur)->next = tmp;
        (*cur) = (*cur)->next;
    }
    (*cur) = head;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (empty(lists))
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        ListNode *res = lists[0];
        vector<int> vec1;
        vector<int> vec2;
        for (int i = 1; i < lists.size(); ++i) {
            ListNode *cur = new ListNode(0);
            vec1 = change(res);
            vec2 = change(lists[i]);
            mergeTwoLists(vec1, vec2, &cur);
            res = cur->next;
        }
        return res;
    }
};


int main() {
    Solution s;
    ListNode *head3 = new ListNode(5);
    ListNode *head2 = new ListNode(4, head3);
    ListNode *head1 = new ListNode(1, head2);
    ListNode *head6 = new ListNode(4);
    ListNode *head5 = new ListNode(3, head6);
    ListNode *head4 = new ListNode(1, head5);
    ListNode *head8 = new ListNode(6);
    ListNode *head7 = new ListNode(2, head8);
    vector<ListNode *> lists = {head1, head4, head7};
    vector<ListNode *> lists1 = {};
    s.mergeKLists(lists1);

    return 0;
}