#include <iostream>
#include<vector>
using namespace std;
/**
 * Definition for singly-linked list with a random pointer.
 */

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};
class DoublyListNode {
 public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第4章-378-将二叉查找树转换成双链表
     *@param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        DoublyListNode* head=NULL;
        vector<int> list;
        if(root == NULL)
            return head;

        treeToList(root, list);
        head = listToDlist(list);

        return head;
    }

    void treeToList(TreeNode *TreeRoot, vector<int> &list) {
        if(TreeRoot != NULL)
        {
            treeToList(TreeRoot->left, list);
            list.push_back(TreeRoot->val);
            treeToList(TreeRoot->right, list);
        }
    }

    DoublyListNode* listToDlist(vector<int> &list) {
        DoublyListNode* head=NULL,* p=NULL,* q=NULL;
        int size = list.size();
        if(0 == size)
            return head;

        head = p = q = new DoublyListNode(list[0]);

        for(int i=1; i<size; i++)
        {
            p->next = new DoublyListNode(list[i]);
            p->next->prev = q;
            q = p->next;
            p = p->next;
        }
        return head;
    }

    void displayTree(TreeNode *TreeRoot) {
        if(TreeRoot != NULL)
        {
            displayTree(TreeRoot->left);
            cout<<TreeRoot->val<<" ";
            displayTree(TreeRoot->right);
        }
    }

    void displayList(DoublyListNode *head)
    {
        if(head == NULL)
            return;

        DoublyListNode *l = head;
        cout<<"next:";
        while(l->next != NULL)
        {
            cout<<l->val<<"->";
            l = l->next;
        }
        cout<<l->val<<"->null"<<endl;

        cout<<"prev:";
        while(l->prev != NULL)
        {
            cout<<l->val<<"->";
            l = l->prev;
        }
        cout<<l->val<<"->null"<<endl;
    }
};

int main()
{
    Solution s;
   
    TreeNode t1(1),t2(2),t3(3),t4(4),t5(5);
    t4.left  = &t2;
    t4.right = &t5;
    t2.left  = &t1;
    t2.right = &t3;

    s.displayTree(&t4);
    cout<<endl;

    /*DoublyListNode l1(1),l2(2),l3(3),l4(4),l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l2.prev = &l1;
    l3.prev = &l2;
    l4.prev = &l3;
    l5.prev = &l4;

    s.displayList(&l1);

    s.displayList(s.bstToDoublyList(&t4));*/

    s.displayList(s.bstToDoublyList(&t4));

    return 0;
}