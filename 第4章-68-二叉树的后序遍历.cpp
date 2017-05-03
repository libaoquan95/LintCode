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
     * http://www.lintcode.com/zh-cn/ladder/6/-第4章-68-二叉树的后序遍历
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> order;
        if(root == NULL)
            return order;

        stack<TreeNode*> s;
        TreeNode *cur;                      //当前结点 
        TreeNode *pre=NULL;                 //前一次访问的结点 
        s.push(root);

        while(!s.empty())
        {
            cur=s.top();
            
            //如果当前结点没有孩子结点或者孩子节点都已被访问过 
            if((cur->left==NULL&&cur->right==NULL)|| (pre!=NULL&&(pre==cur->left||pre==cur->right)))
            {
                order.push_back(cur->val);
                s.pop();
                pre=cur; 
            }
            else
            {
                if(cur->right!=NULL)
                    s.push(cur->right);
                if(cur->left!=NULL)    
                    s.push(cur->left);
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
            display(TreeRoot->right);
            cout<<TreeRoot->val<<" ";
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

    
    vector<int> order = s.postorderTraversal(&t1);
    vector<int>::iterator i;
    
    for(i=order.begin(); i!=order.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    /**/

    return 0;
}