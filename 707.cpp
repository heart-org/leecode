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

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int val) : val(val), next(nullptr) {}

        ListNode(int val, ListNode *next) : val(val), next(next) {}
    };

    MyLinkedList() {
        _prehead = new ListNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index < 0 || index > (_size - 1)) {
            return -1;
        }
        ListNode *tmp = _prehead->next;
        while (index--) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void addAtHead(int val) {
        ListNode *head = new ListNode(val);
        head->next = _prehead->next;
        _prehead->next = head;
        _size++;
    }

    void addAtTail(int val) {
        ListNode *Node = new ListNode(val);
        ListNode *cur = _prehead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = Node;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        ListNode *Node = new ListNode(val);
        ListNode *cur = _prehead;
        while (index--) {
            cur = cur->next;
        }
        Node->next = cur->next;
        cur->next = Node;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0)
            return;
        ListNode *cur = _prehead;
        while (index--) {
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }

private:
    int _size;
    ListNode *_prehead;
};

int main() {


    return 0;
}