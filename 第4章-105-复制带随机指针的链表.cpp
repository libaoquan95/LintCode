#include <iostream>
#include<stack>
#include <map>
using namespace std;
/**
 * Definition for singly-linked list with a random pointer.
 */
 struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第4章-105-复制带随机指针的链表
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode * newHead;
        RandomListNode * p=head, *q;

        if(head == NULL)
            return NULL;

        q = newHead = new RandomListNode(p->label);
        q->random = p->random;
        p = p->next;

        while(p != NULL)
        {
            q->next = new RandomListNode(p->label);
            q->next->random = p->random;
            q = q->next;
            p = p->next;
        }

        return newHead;
    }
    */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode * newHead;
        map<RandomListNode *, RandomListNode *> mapRandom;

        newHead = createListNext(head, mapRandom);
        newHead = createListRandom(head, newHead, mapRandom);

        return newHead;
    }

    RandomListNode *createListNext(RandomListNode *head, map<RandomListNode *, RandomListNode *> &mapRandom) {
        // write your code here
        RandomListNode * newHead;
        RandomListNode * p=head, *q;

        if(head == NULL)
            return NULL;

        q = newHead = new RandomListNode(p->label);
        mapRandom.insert(pair<RandomListNode *, RandomListNode *>(p, q));
        p = p->next;
        //q = q->next;

        while(p != NULL)
        {
            q->next = new RandomListNode(p->label);
            mapRandom.insert(pair<RandomListNode *, RandomListNode *>(p, q->next));
            q = q->next;
            p = p->next;
        }

        return newHead;
    }
    RandomListNode *createListRandom(RandomListNode *head,RandomListNode *newHead, map<RandomListNode *, RandomListNode *> &mapRandom) {
        // write your code here
        RandomListNode * p=head;
        RandomListNode * q=newHead;
        
        if(head == NULL)
            return NULL;

        while(p != NULL)
        {
            if(p->random != NULL)
            {
                map<RandomListNode *, RandomListNode *>::iterator it = mapRandom.find(p->random); 
                q->random = it->second;
            }
            p = p->next;
            q = q->next;
        }

        return newHead;
    }

    void display(RandomListNode *head)
    {
        RandomListNode *l = head;
        while(l != NULL)
        {
            cout<<" "<<l->label;
            if(l->random != NULL)
                cout<<"→"<<l->random->label;
            else
                cout<<"→null";
            cout<<endl<<"↓"<<endl;
            l = l->next;
        }
        cout<<"null"<<endl;
    }
};

int main()
{
    Solution s;
    RandomListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(8);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;

    l1.random = &l4;
    l3.random = &l3;
    l4.random = &l5;
    l6.random = &l2;
    l8.random = &l1;

    s.display(&l1);
    cout<<endl;

    s.display(s.copyRandomList(&l1));
    cout<<endl;
    return 0;
}