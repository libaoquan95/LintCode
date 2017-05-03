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
     * http://www.lintcode.com/zh-cn/ladder/6/-第3章-372-在O(1)时间复杂度删除链表节点
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(node->next == NULL)  //  删除的是尾节点或是只有一个节点的头结点
        {
            return;
        }
        node->val = node->next->val;
        node->next = node->next->next;      
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
    s.deleteNode(&l3);
    s.display(&l1);
    return 0;
}