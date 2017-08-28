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

struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/merge-k-sorted-lists/-104-合并k个排序链表 
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;

        for(int i=0; i<lists.size(); i++) {
            if(lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        ListNode *newHead = NULL, *current = NULL, *temp = NULL;
        while (!minHeap.empty()) {
            temp = minHeap.top();
            minHeap.pop();

            if (current == NULL) {
                newHead = temp;
            }
            else {
                current->next = temp;
            }
            current = temp;
            if (temp->next != NULL) {
                minHeap.push(temp->next);
            }
        }
        return newHead;
    }



    ListNode *mergeKLists_1(vector<ListNode *> &lists) {
        // write your code here
        ListNode * newHead = new ListNode(-1);
        ListNode * current = newHead;

        while(!isAllListEmpty(lists)) {
            current->next = findMin(lists);
            current = current->next;
        }

        return newHead->next;
    }

    bool isAllListEmpty(vector<ListNode *> &lists) {
        for(int i=0; i<lists.size(); i++) {
            if(lists[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    ListNode *findMin(vector<ListNode *> &lists) {
        int minValue = 0x7FFFFFFF;
        int minIndex = 0;
        ListNode * result = NULL;

        for(int i=0; i<lists.size(); i++) {
            if(lists[i] != NULL && lists[i]->val < minValue) {
                minValue = lists[i]->val;
                result = lists[i];
                minIndex = i;
            }
        }
        lists[minIndex] = lists[minIndex]->next;
        return result;
    }

    void display(ListNode *head) {
        ListNode *l = head;
        while(l != NULL) {
            cout<<l->val<<"->";
            l = l->next;
        }
        cout<<"null"<<endl;
    }
};

int main()
{
    Solution s;

    
    ListNode l1(2),l2(4),l3(-1);
    l1.next = &l2;
    ListNode * cycle = NULL;

    vector<ListNode *> list;
    list.push_back(&l1);
    list.push_back(cycle);
    list.push_back(&l3);

    cycle = s.mergeKLists(list);

    s.display(cycle);

    return 0;
}