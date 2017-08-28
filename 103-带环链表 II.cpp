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
     * http://www.lintcode.com/problem/linked-list-cycle-ii-103-´ø»·Á´±í II
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
     ListNode * detectCycle(ListNode *head) {
        // write your code here
        ListNode * fast = head, *slow = head, *result = NULL;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) {
                break;
            }
        }
        
        if(fast != NULL && fast->next != NULL) {
            fast = head;
            while(fast != slow) {
                slow = slow->next;
                fast = fast->next;
            }
            result = fast;
        }
        return result;
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

    
    ListNode l1(1),l2(4),l3(3),l4(2),l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l2;

    ListNode * cycle = s.detectCycle(&l1);
    if(cycle != NULL)
        cout<<cycle->val<<endl;

    return 0;
}