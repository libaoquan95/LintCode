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
     * http://www.lintcode.com/problem/remove-linked-list-elements/-452-删除链表中的元素
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        // write your code here
        if (head == NULL) {
            return head;
        }
        ListNode * newHead = new ListNode(0);
        newHead->next = head;
        ListNode * temp = head, *p = newHead, *q = temp->next;
        while (temp != NULL && temp->next != NULL) {
            if (temp->val == val) {
                p->next = q;
                //delete temp;
            }
            else {
                p = p->next;
            }
            temp = temp->next;
            if (q->next != NULL) {
                q = q->next;
            }
        }
        if (temp->next == NULL && temp->val == val) {
            p->next = NULL;
        }
        return newHead->next;
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
    s.display(s.removeElements(&l1,5));

    return 0;
}