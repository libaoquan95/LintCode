#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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
     * http://www.lintcode.com/zh-cn/problem/validate-binary-search-tree/-95-验证二叉查找树
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = NULL;

        return isValidBST(root, pre);
    }

    bool isValidBST(TreeNode *root, TreeNode *&pre) {
        if (root == NULL) {
            return true;
        }
        if (!isValidBST(root->left, pre)) {
            return false;
        }
        if (pre != NULL && pre->val >= root->val) {
            return false;
        }
        pre = root;
        return isValidBST(root->right, pre);
    }

    void display(TreeNode *TreeRoot) {
        if(TreeRoot == NULL) {
            //cout<<"null"<<endl;
        }
        else  {
            cout<<TreeRoot->val<<" ";
            display(TreeRoot->left);
            display(TreeRoot->right);
        }
    }
};

int main()
{
    Solution s;

    TreeNode t1(2),t2(1),t3(4),t4(3);
    t1.left  = &t2;
    t1.right = &t3;
    t3.left  = &t4;

    s.display(&t1);
    cout<<endl;
    cout<<s.isValidBST(&t1)<<endl;

    return 0;
}