#include <iostream>
#include<vector>
using namespace std;

/**
 * Definition of TreeNode:
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
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ4ÕÂ-375-¿ËÂ¡¶þ²æÊ÷
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        if(root != NULL)
        {
            TreeNode* pNewRoot = new TreeNode(root->val);

            if(root->left != NULL)
                pNewRoot->left = cloneTree(root->left);
            if(root->right != NULL)
                pNewRoot->right = cloneTree(root->right);

            return pNewRoot;
        }
        return NULL;
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

    
    TreeNode t8(8),t9(9),t10(2);
    t8.left  = &t9;
    t8.right = &t10;

    s.display(&t1);
    cout<<endl;

    s.display(&t8);
    cout<<endl;

    s.display(s.cloneTree(&t1));
    cout<<endl;

    return 0;
}