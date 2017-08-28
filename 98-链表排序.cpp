#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition of ListNode
 */
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/sort-list/-98-Á´±íÅÅÐò
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *fast = head, *slow = head, *temp = head;;
        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        return mergeList(sortList(head), sortList(slow));
    }
    
    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        if(head1 == NULL) {
            return head2;
        }
        if(head2 == NULL) {
            return head1;
        }

        ListNode newHead(0);
        ListNode *temp = &newHead;
        while(head1 != NULL && head2 != NULL) {
            if(head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if(head1 != NULL) {
            temp->next = head1;
        }
        else if(head2 != NULL) {
            temp->next = head2;
        }

        return newHead.next;
    }
    
    void display(ListNode *head) {
        ListNode *l = head;
        while(l->next != NULL) {
            cout<<l->val<<"->";
            l = l->next;
        }
        cout<<l->val<<"->null"<<endl;
    }
};

int main()
{
    Solution s;

    ListNode l1(1),l2(4),l3(3),l4(2),l5(5),l6(2);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;

    s.display(&l1);
    s.display(s.sortList(&l1));

    return 0;
}