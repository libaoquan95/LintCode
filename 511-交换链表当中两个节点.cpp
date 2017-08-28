#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
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
    * http://www.lintcode.com/zh-cn/problem/swap-two-nodes-in-linked-list/-511-交换链表当中两个节点
    * @param head: a ListNode
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        // write your code here
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (v1 == v2) {
            return head;
        }
        ListNode * newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *node1Prec = NULL, *node1 = NULL, *node1Next = NULL;
        ListNode *node2Prec = NULL, *node2 = NULL, *node2Next = NULL;
        ListNode *tempPrec = newHead, *temp = head, *tempNext = head->next;

        // 遍历链表，找到待交换节点
        while (temp != NULL) {
            if (temp->val == v1) {
                node1Prec = tempPrec;
                node1 = temp;
                node1Next = tempNext;
            }
            else if (temp->val == v2) {
                node2Prec = tempPrec;
                node2 = temp;
                node2Next = tempNext;
            }
            // 找到 2 个节点，退出寻找
            if (node1 != NULL && node2 != NULL) {
                break;
            }

            tempPrec = tempPrec->next;
            temp = temp->next;
            if (tempNext != NULL) {
                tempNext = tempNext->next;
            }
        }

        // 找到 2 个节点
        if (node1 != NULL && node2 != NULL) {
            if (node1->next == node2) {
                node1->next = node2Next;
                node2->next = node1;
                node1Prec->next = node2;
            }
            else if (node2->next == node1) {
                node2->next = node1Next;
                node1->next = node2;
                node2Prec->next = node1;
            }
            else {
                node1Prec->next = node2;
                node1->next = node2Next;

                node2Prec->next = node1;
                node2->next = node1Next;
            }
        }

        return newHead->next;
    }

    void display(ListNode *head) {
        ListNode *l = head;
        while (l->next != NULL) {
            cout << l->val << "->";
            l = l->next;
        }
        cout << l->val << "->null" << endl;
    }
};

int main()
{
    Solution s;

    ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    s.display(&l1);
    s.display(s.swapNodes(&l1, 3, 4));

    return 0;
}