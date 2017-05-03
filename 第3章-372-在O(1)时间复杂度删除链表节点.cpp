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
     * http://www.lintcode.com/zh-cn/ladder/6/-��3��-372-��O(1)ʱ�临�Ӷ�ɾ������ڵ�
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if(node->next == NULL)  //  ɾ������β�ڵ����ֻ��һ���ڵ��ͷ���
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