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
     * http://www.lintcode.com/zh-cn/problem/reorder-list/-99-ÖØÅÅÁ´±í
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode * &head) {
        // write your code here
        if(head != NULL && head->next != NULL) {
            ListNode *fast = head, *slow = head, *temp = head;
            while(fast != NULL && fast->next != NULL) {
                temp = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = NULL;

            slow = reverse(slow);
            
            ListNode *newHead = head;

            while(newHead != NULL) {
                if(newHead->next == NULL) {
                    newHead->next = slow;
                    break;
                }
                else{
                    temp = newHead->next;
                    newHead->next = slow;
                    slow = slow->next;
                    newHead->next->next = temp;
                    newHead = temp;
                }
            }
        }
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *l1=NULL,*l2=NULL,*l3=NULL;

        l1 = head; 
        if(l1 == NULL || l1->next == NULL) {
            return l1;
        }
        l2 = l1->next;
        if(l2->next == NULL) {
            l2->next = l1;
            l1->next = NULL;
            return l2;
        }
        l3 = l2->next;
        if(l2->next != NULL) {
            while(l2 != l3) {
                l2->next = l1;
                if(l1 == head) {
                    l1->next = NULL;
                }
                l1 = l2;
                l2 = l3;
                if(l3->next != NULL) {
                    l3 = l3->next;
                }
            }
            l2->next = l1;
            return l2;
        }
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

    ListNode l1(1),l2(4),l3(3),l4(2),l5(5),l6(2),l7(7);
    l1.next = &l2;
    //l2.next = &l3;
    //l3.next = &l4;
    //l4.next = &l5;
    //l5.next = &l6;
    //l6.next = &l7;

    ListNode * head = &l1;

    s.display(head);
    s.reorderList(head);
    s.display(head);

    return 0;
}