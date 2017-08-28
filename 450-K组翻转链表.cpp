#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

/**
* Definition of ListNode
*/
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/reverse-nodes-in-k-group/-450-K组翻转链表
     * @param head: a ListNode
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode * reverseKGroup(ListNode * head, int k) {
        // write your code here
        if (k <= 0 || head == NULL || head->next == NULL) {
            return head;
        }
        stack<int> stack;
        ListNode *begin = head, *end = head;
        while (end != NULL) {
            for (int i = 0; i < k && end != NULL; i++) {
                stack.push(end->val);
                end = end->next;
            }
            if (stack.size() == k) {
                for (int i = 0; i < k; i++) {
                    begin->val = stack.top();
                    begin = begin->next;
                    stack.pop();
                }
            }
        }
        return head;
    }

    void display(ListNode *head) {
        ListNode *l = head;
        while (l->next != NULL) {
            cout << l->val << "->";
            l = l->next;
        }
        cout << l->val << "->null" << endl;
    }
};

int main()
{
    Solution s;

    ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    s.display(&l1);
    s.display(s.reverseKGroup(&l1, 5));

    return 0;
}