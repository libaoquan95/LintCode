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
     * http://www.lintcode.com/zh-cn/problem/partition-list/-96-Á´±í»®·Ö
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head == NULL) {
            return head;
        }

        ListNode *lessHead = NULL, *lessNext = NULL;
        ListNode *moreHead = NULL, *moreNext = NULL;
        ListNode *current = head;
        bool isLessHead = true, isMoreHead = true;

        while(current != NULL) {
            if(current->val < x) {
                if(isLessHead){
                    lessHead = lessNext = current;
                    isLessHead = false;
                }
                else {
                    lessNext->next = current;
                    lessNext = lessNext->next;
                }
            }
            else {
                if(isMoreHead){
                    moreHead = moreNext = current;
                    isMoreHead = false;
                }
                else {
                    moreNext->next = current;
                    moreNext = moreNext->next;
                }
            }
            current = current->next;
        }

        if(lessNext != NULL && moreNext != NULL) {
            lessNext->next = moreHead;
            moreNext->next = NULL;
            return lessHead;
        }
        else if(lessNext == NULL){
            moreNext->next = NULL;
            return moreHead;
        }
        else if(moreNext == NULL) {
            lessNext->next = NULL;
            return lessHead;
        }
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
    s.display(s.partition(&l1, 55));

    return 0;
}