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
     * http://www.lintcode.com/zh-cn/problem/linked-list-cycle/-102-´ø»·Á´±í 
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode * fast = head, *slow = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) {
                return true;
            }
        }

        return false;
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
    cout<<s.hasCycle(&l1)<<endl;

    return 0;
}