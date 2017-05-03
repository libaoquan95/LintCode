#include <iostream>
#include<vector>
#include<stack>
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

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第4章-67-二叉树的中序遍历
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> order;
        if(root == NULL)
            return order;

        stack<TreeNode*> s;
        TreeNode *p=root;
        while(p!=NULL||!s.empty())
        {
            while(p!=NULL)
            {
                s.push(p);
                p=p->left;
            }
            if(!s.empty())
            {
                p=s.top();
                order.push_back(p->val);
                s.pop();
                p=p->right;
            }
        } 
        return order;
    }

    void display(TreeNode *TreeRoot) {
        if(TreeRoot == NULL)
        {
            //cout<<"null"<<endl;
        }
        else
        {
            display(TreeRoot->left);
            cout<<TreeRoot->val<<" ";
            display(TreeRoot->right);
        }
    }
};

int main()
{
    Solution s;
   
    TreeNode t1(8),t2(8),t3(7),t4(9),t5(2),t6(4),t7(7);
    t1.left  = &t2;
    t1.right = &t3;
    t2.left  = &t4;
    t2.right = &t5;
    t5.left  = &t6;
    t5.right = &t7;

    s.display(&t1);
    cout<<endl;

    
    vector<int> order = s.inorderTraversal(&t1);
    vector<int>::iterator i;
    
    for(i=order.begin(); i!=order.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    /**/

    return 0;
}