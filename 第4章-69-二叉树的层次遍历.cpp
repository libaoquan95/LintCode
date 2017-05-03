#include <iostream>
#include<vector>
#include<queue>
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
     * http://www.lintcode.com/zh-cn/ladder/6/-第4章-69-二叉树的层次遍历
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > order;
        queue<TreeNode*> queue;
        int len;

        if(root == NULL)
        {
            return order;
        }

        queue.push(root);
        len = queue.size();

        while(!queue.empty())
        {  
            vector<int> base;  
            len = queue.size();  
  
            while(len--)
            {
                TreeNode *tmp=queue.front();  
                base.push_back(tmp->val);
                queue.pop();  
                if(tmp->left)  
                    queue.push(tmp->left);  
                if(tmp->right)      
                    queue.push(tmp->right);  
            }  
            order.push_back(base);  
        }  

        vector<vector<int> > order2;
        int i;
    
        for(i=order.size()-1; i>=0; i--)
        {
            order2.push_back(order[i]);
        }

        return order2;
    }

    void display(TreeNode *TreeRoot) {
        if(TreeRoot == NULL)
        {
            //cout<<"null"<<endl;
        }
        else
        {
            cout<<TreeRoot->val<<" ";
            display(TreeRoot->left);
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

    vector<vector<int> > order = s.levelOrder(&t1);
    vector<vector<int> >::iterator i;
    vector<int>::iterator j;
    
    for(i=order.begin(); i!=order.end(); i++)
    {
        for(j=i->begin(); j!=i->end(); j++)
        {
            cout<<*j<<" ";
        }
        cout<<endl;
    }

    return 0;
}