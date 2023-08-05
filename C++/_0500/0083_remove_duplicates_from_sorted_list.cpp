#include <iostream>

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* point = head;
        while (point->next!=NULL&&point!=NULL) {
            if (point->val == point->next->val) {
                ListNode* next = point->next;
                point->next = next->next;
                next->next = NULL;
                next = NULL;
            } else {
                point = point->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;

    ListNode head11 = ListNode(1);
    ListNode head12 = ListNode(1);
    ListNode head13 = ListNode(2);
    head11.next = &head12;
    head12.next = &head13;

    ListNode head21 = ListNode(1);
    ListNode head22 = ListNode(1);
    ListNode head23 = ListNode(2); 
    ListNode head24 = ListNode(3); 
    ListNode head25 = ListNode(3);      
    head21.next = &head22;
    head22.next = &head23;
    head23.next = &head24;
    head24.next = &head25;

    solution.deleteDuplicates(&head11);
    solution.deleteDuplicates(&head21);
    // cout << solution.climbStairs(2) << endl;
    // cout << solution.climbStairs(3) << endl; 
    // cout << solution.climbStairs(15) << endl; // 987
    // cout << solution.climbStairs(25) << endl; // 121393

    cout << "end";

    return 0;
}