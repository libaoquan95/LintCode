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
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第3章-174-删除链表中倒数第n个节点
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(n > 0)
        {
            ListNode *pBegin=head, *pEnd=head;
            while(n-- && pEnd!=NULL)
            {
                pEnd = pEnd->next;
            }
            if(n == -1 && pEnd!=NULL)            //  n<链表长度
            {
                while(pEnd->next != NULL)
                {
                    pBegin = pBegin->next;
                    pEnd = pEnd->next;
                }
                pBegin->next = pBegin->next->next;
                return head;
            }
            else if(n > -1 && pEnd!=NULL)       //  n>链表长度
            {
                return head;
            }
            else                               //  n=链表长度
            {
                return head->next;
            }
        }
    }

    void display(ListNode *head)
    {
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

    ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8),l9(9);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    l8.next = &l9;

    s.display(&l1);
    s.display(s.removeNthFromEnd(&l1, 5));
    return 0;
}