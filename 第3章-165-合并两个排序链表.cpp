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
     * http://www.lintcode.com/zh-cn/ladder/6/-第3章-165-合并两个排序链表
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *pnew,*phead = l1;

		if(l1==NULL && l2==NULL)
		{
			return NULL;
		}
        else if(l1==NULL && l2!=NULL)
        {
            return l2;
        }
        else if(l2==NULL && l1!=NULL)
        {
            return l1;
        }
        else
        {
            if(l1->val <= l2->val)
            {
                phead = pnew = l1;
                l1 = l1->next;
            }
            else
            {
                phead = pnew = l2;
                l2 = l2->next;
            }
            while(l1!=NULL && l2!=NULL)
            {
                if(l1->val <= l2->val)
                {
                    pnew->next = l1;
                    l1 = l1->next;
                    pnew = pnew->next;
                }
                else
                {
                    pnew->next = l2;
                    l2 = l2->next;
                    pnew = pnew->next;
                }
            }
            if(l1!=NULL && l2==NULL)
            {
                pnew->next = l1;
            }
            if(l2!=NULL && l1==NULL)
            {
                pnew->next = l2;
            }
            return phead;
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

    ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8),l9(9),l10(10),l11(11);

    l1.next = &l3;
    l3.next = &l5;
    l5.next = &l7;
    l7.next = &l10;
    l10.next = &l11;

    l2.next = &l4;
    l4.next = &l6;
    l6.next = &l8;
    l8.next = &l9;

    s.display(&l1);
    s.display(&l2);
    s.display(s.mergeTwoLists(&l1, &l2));
    return 0;
}