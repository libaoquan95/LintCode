#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition of TreeNode
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
     * http://www.lintcode.com/zh-cn/ladder/6/-第8章-112-删除排序链表中的重复元素
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(NULL == head)
            return NULL;

        ListNode *p1=head, *p2=head->next;

        if(NULL == p2)
            return head;
        
        while(p2 != NULL) {
            if(p1->val == p2->val) {
                p1->next = p2->next;
                p2 = p2->next;
            }
            else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return head;
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

    ListNode l1(1),l2(1),l3(3),l4(4),l5(5),l6(5),l7(5),l8(8),l9(9);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    l8.next = &l9;

    s.display(&l1);
    s.display(s.deleteDuplicates(&l1));

    return 0;
}