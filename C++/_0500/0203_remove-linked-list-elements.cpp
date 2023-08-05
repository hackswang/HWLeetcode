#include <iostream>

using namespace std;

// https://leetcode.cn/problems/remove-linked-list-elements/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }
        ListNode* cursor = head;
        while (cursor != NULL) {
            if (cursor->next != NULL && cursor->next->val == val) {
                cursor->next = cursor->next->next;
                continue;
            }
            cursor = cursor->next;    
        }
        return head;
    }
};

int main() {

    Solution solution;
    {
        // 1,2,6,3,4,5,6 -> 6
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(6);
        ListNode *result = solution.removeElements(head, 6);
        cout << endl;
    }
    {
        ListNode *result = solution.removeElements(NULL, 6);
        cout << endl;
    }
    {
        // 7,7,7,7 -> 7
        ListNode *head = new ListNode(7);
        head->next = new ListNode(7);
        head->next->next = new ListNode(7);
        head->next->next->next = new ListNode(7);
        ListNode *result = solution.removeElements(head, 7);
        cout << endl;
    }
    cout << "end";

    return 0;
}