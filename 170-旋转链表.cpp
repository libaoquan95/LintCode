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
     * http://www.lintcode.com/problem/rotate-list/-170-Ðý×ªÁ´±í
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (k <= 0 || head == NULL) {
            return head;
        }
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        ListNode *p1 = head, *p2 = head, *p3 = head;
        k = k % len;
        if (k == 0) {
            return head;
        }
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }
        while (p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
            p3 = p3->next;
        }
        p2 = p2->next;
        p3->next = NULL;
        p1->next = head;
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

    ListNode l11(1), l12(2), l13(3), l14(4), l15(5);
    l11.next = &l12;
    l12.next = &l13;
    l13.next = &l14;
    l14.next = &l15;

    s.display(&l11);
    s.display(s.rotateRight(&l11, 1));
    return 0;
}