
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/reverse-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* cursor = NULL;
        ListNode* cursor_tmp = NULL;

        while (head != NULL) {
            cursor_tmp = head;
            head = head->next;
            cursor_tmp->next = cursor;
            cursor = cursor_tmp;
        }
        return cursor;
    }
};

int main() {

    Solution solution;
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        ListNode* result = solution.reverseList(head);
        cout << endl;
    }
    {
        ListNode* head = new ListNode(1);
        ListNode* result = solution.reverseList(head);
        cout << endl;
    }
    {
        ListNode* result = solution.reverseList(NULL);
        cout << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        ListNode* result = solution.reverseList(head);
        cout << endl;
    }
    cout << "end";

    return 0;
}