#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>  
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
     * http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list-ii/-113-删除排序链表中的重复数字 II 
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = new ListNode(0);
        ListNode *next = newHead;
        ListNode *current = head;

        while(current != NULL) {
            if(current->next != NULL && current->val == current->next->val) {
                while(current->next != NULL && current->val == current->next->val) {
                    current = current->next;
                }
            }
            else {
                next->next = current;
                next = next->next;
            }
            current = current->next;
        }
        next->next = current;
        return newHead->next;
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
    
    ListNode l1(1),l2(2),l3(2),l4(3),l5(3),l6(4),l7(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;

    s.display(&l1);
    s.display(s.deleteDuplicates(&l1));

    return 0;
}