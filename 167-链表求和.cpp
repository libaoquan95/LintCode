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
     * http://www.lintcode.com/zh-cn/problem/add-two-numbers/-167-Á´±íÇóºÍ
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        int carry = 0;
        while (l1!= NULL && l2 != NULL) {
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

    ListNode l11(0), l12(1), l13(1), l14(1), l15(1);
    //l11.next = &l12;
    //l12.next = &l13;
    //l13.next = &l14;
    //l14.next = &l15;

    ListNode l21(0), l22(8), l23(8), l24(8), l25(8);
    //l21.next = &l22;
    //l22.next = &l23;
    //l23.next = &l24;
    //l24.next = &l25;

    s.display(&l11);
    s.display(&l21);
    s.display(s.addLists(&l11, &l21));
    return 0;
}