#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第5章-380-两个链表的交叉
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        stack<ListNode *> stackA, stackB;
        ListNode * result=NULL,*pA=headA,*pB=headB;

        if(headA==NULL || headB==NULL)
            return result;

        while(pA != NULL)
        {
            stackA.push(pA);
            pA = pA->next;
        }
        while(pB != NULL)
        {
            stackB.push(pB);
            pB = pB->next;
        }

        while(!stackA.empty() && !stackB.empty())
        {
            if(stackA.top() == stackB.top())
            {
                result = stackA.top();
                stackA.pop();
                stackB.pop();
            }
            else
            {
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;

    ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l6;
    l6.next = &l7;

    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;

    cout<<s.getIntersectionNode(&l1, &l4)<<endl;

    return 0;
}