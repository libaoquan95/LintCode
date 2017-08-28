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
     * http://www.lintcode.com/zh-cn/problem/palindrome-linked-list/-223-回文链表 
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *last = slow->next;
        slow->next = NULL;
        last = reverse(last);

        while (last != NULL) {
            if (head->val != last->val) {
                return false;
            }
            head = head->next;
            last = last->next;
        }
        if (head == NULL || head->next == NULL) {
            return true;
        }
        return false;
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
    ListNode l1(1), l2(2), l3(3), l4(2), l5(1);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    cout << s.isPalindrome(&l1) << endl;

    return 0;
}
