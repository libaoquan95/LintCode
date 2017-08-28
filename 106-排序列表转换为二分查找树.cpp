#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
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

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/convert-sorted-list-to-balanced-bst/-106-排序列表转换为二分查找树
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        TreeNode *root = NULL;

        if(head != NULL) {
            ListNode *left = NULL, *right = NULL;
            root = new TreeNode(dichotomyList(head, left, right));
            root->left = sortedListToBST(left);
            root->right = sortedListToBST(right);
        }

        return root;
    }

    int dichotomyList(ListNode *head, ListNode *&left, ListNode *&right) {
        if(head->next != NULL) {
            ListNode *fast = head, *slow = head, *temp = head;
            while(fast != NULL && fast->next != NULL) {
                temp = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = NULL;
        
            left = head;
            right = slow->next;

            return slow->val;
        }
        else {
            left = NULL;
            right = NULL;
            return head->val;
        }
    }

    void display(ListNode *head) {
        ListNode *l = head;
        while(l != NULL) {
            cout<<l->val<<"->";
            l = l->next;
        }
        cout<<"null"<<endl;
    }

	void display(TreeNode *TreeRoot) {
		if(TreeRoot == NULL) {
			//cout<<"null"<<endl;
		}
		else {
			display(TreeRoot->left);
			cout<<TreeRoot->val<<" ";
			display(TreeRoot->right);
		}
	}
};

int main()
{
    Solution s;

    ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    //l6.next = &l7;

    s.display(s.sortedListToBST(&l1));
    

    return 0;
}