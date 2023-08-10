#include <iostream>

using namespace std;

// https://leetcode.cn/problems/palindrome-linked-list/


/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

 
示例 1：

输入：head = [1,2,2,1]
输出：true


示例 2：

输入：head = [1,2]
输出：false
 

提示：

链表中节点数目在范围[1, 105] 内
0 <= Node.val <= 9
 

进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (head->next == NULL) { return true; }

        int count = 0;
        ListNode *cache = head;
        while (cache != NULL) {
            count++;
            cache = cache->next;
        }

        int flip_count = count / 2;
        cache = head;
        ListNode *tmp = cache;
        ListNode *pre = NULL;
        while (flip_count > 0) {
            cache = cache->next;
            tmp->next = pre;
            pre = tmp;
            tmp = cache;
            flip_count--;
        }
        if (count % 2 == 1) {
            cache = cache->next;
        }

        while (pre != NULL && cache != NULL) {
            if (pre->val != cache->val) {
                return false;
            }
            pre = pre->next;
            cache = cache->next;
        }
        
        return true;
    }
};

int main() {

    Solution solution;
    {
        ListNode *input = new ListNode(1);
        input->next = new ListNode(2);
        input->next->next = new ListNode(2);
        input->next->next->next = new ListNode(1);
        bool result = solution.isPalindrome(input);
        cout << endl;
    }
    {
        ListNode *input = new ListNode(1);
        input->next = new ListNode(2);
        input->next->next = new ListNode(5);
        input->next->next->next = new ListNode(2);
        input->next->next->next->next = new ListNode(1);
        bool result = solution.isPalindrome(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}