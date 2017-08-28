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
     * http://www.lintcode.com/zh-cn/problem/add-two-numbers-ii/-221-链表求和 II
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    ListNode * addLists2(ListNode * l1, ListNode * l2) {
        // write your code here
        l1 = reverse(l1);
        l2 = reverse(l2);
        return reverse(addLists(l1, l2));
    }
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;

        l1 = head;
        //  链表没有节点或有一个节点 
        if (l1 == NULL || l1->next == NULL) {
            return l1;
        }
        l2 = l1->next;
        //  链表有2节点
        if (l2->next == NULL) {
            l2->next = l1;
            l1->next = NULL;
            return l2;
        }
        l3 = l2->next;
        //  链表有3个以上节点
        if (l2->next != NULL) {
            while (l2 != l3) {
                l2->next = l1;
                if (l1 == head)
                    l1->next = NULL;
                l1 = l2;
                l2 = l3;

                if (l3->next != NULL)
                    l3 = l3->next;
            }
            l2->next = l1;
            return l2;
        }
    } 
    
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            ListNode *node = new ListNode(sum % 10);
            carry = (sum >= 10);
            temp->next = node;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + carry;
            ListNode *node = new ListNode(sum % 10);
            carry = (sum >= 10);
            temp->next = node;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + carry;
            ListNode *node = new ListNode(sum % 10);
            carry = (sum >= 10);
            temp->next = node;
            l2 = l2->next;
            temp = temp->next;
        }
        if (l1 == NULL && l2 == NULL && carry == 1) {
            ListNode *node = new ListNode(carry);
            temp->next = node;
        }
        return head->next;
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
    ListNode l11(6), l12(1), l13(7);
    l11.next = &l12;
    l12.next = &l13;

    ListNode l21(2), l22(9), l23(5);
    l21.next = &l22;
    l22.next = &l23;

    s.display(s.addLists2(&l11, &l21));

    return 0;
}
