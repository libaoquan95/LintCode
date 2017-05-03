#include <iostream>
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
     * http://www.lintcode.com/zh-cn/ladder/6/-第2章-35-翻转链表
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *l1=NULL,*l2=NULL,*l3=NULL;

        l1 = head; 
        if(l1 == NULL || l1->next == NULL)//  链表没有节点或有一个节点 
        {
            return l1;
        }
        l2 = l1->next;
        if(l2->next == NULL)      //  链表有2节点 
        {
            l2->next = l1;
            l1->next = NULL;
            return l2;
        }
        l3 = l2->next;
        if(l2->next != NULL)      //  链表有3个以上节点
        {
            while(l2 != l3)
            {
                l2->next = l1;
                if(l1 == head)
                    l1->next = NULL;
                l1 = l2;
                l2 = l3;

                if(l3->next != NULL)
                    l3 = l3->next;
            }
            l2->next = l1;
            return l2;
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

    ListNode l1(1),l2(2),l3(3),l4(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;

    s.display(&l1);
    s.display(s.reverse(&l1));

    return 0;
}