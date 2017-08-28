#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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
     * http://www.lintcode.com/zh-cn/problem/nth-to-last-node-in-list/-166-链表倒数第n个节点
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }
        while (p1 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
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
    cout << s.nthToLast(&l1, 2)->val << endl;
    return 0;
}