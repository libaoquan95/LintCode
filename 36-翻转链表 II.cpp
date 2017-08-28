#include <iostream>
#include <vector>
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
     * http://www.lintcode.com/zh-cn/problem/n-queens-ii/-36-·­×ªÁ´±í II 
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode newHead1(-1), newHead2(-1);
        newHead1.next = &newHead2;
        newHead2.next = head;

        ListNode *nowNode=head, *subHead=head, *subEnd=NULL, *lastEnd=&newHead1, *nextHead=NULL;
        int i=1;
        while(nowNode != NULL) {
            if(i <= m) {
                lastEnd = lastEnd->next;
                subEnd = nowNode;
                nextHead = nowNode;
                nowNode = nowNode->next;
                i++;
            }
            else if(i <= n) {
                ListNode *temp = nowNode->next;
                nextHead->next = NULL;
                lastEnd->next = nowNode;
                lastEnd->next->next = subEnd;
                subEnd = nowNode;
                nowNode = temp;
                i++;
            }
            else {
                nextHead->next = nowNode;
                break;
            }
        }

        if(m == 1) {
            return lastEnd->next;
        }
        else {
            return head;
        }
    }

    void display(ListNode *head) {
        ListNode *l = head;
        while(l->next != NULL)
        {
            cout<<l->val<<"->";
            l = l->next;
        }
        cout<<l->val<<"->null"<<endl;
    }
};

int main()
{
    Solution s;

    ListNode l1(1),l2(2),l3(3),l4(4),l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    s.display(&l1);
    s.display(s.reverseBetween(&l1, 4, 5));

    return 0;
}