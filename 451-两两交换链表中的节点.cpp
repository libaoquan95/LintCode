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
     * http://www.lintcode.com/zh-cn/problem/swap-nodes-in-pairs/-451-两两交换链表中的节点
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * newHead = new ListNode(0);
        newHead->next = head;
        ListNode * temp = head, *p = newHead, *q = temp->next;
        while (temp != NULL && temp->next != NULL) {
            temp->next = q->next;
            q->next = temp;
            p->next = q;

            if (temp->next != NULL && temp->next->next != NULL) {
                p = temp;
                temp = temp->next;
                q = temp->next;
            }
            else {
                break;
            }
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
    s.display(s.swapPairs(&l1));

    return 0;
}