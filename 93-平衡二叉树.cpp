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
     * http://www.lintcode.com/zh-cn/problem/balanced-binary-tree/-93-Æ½ºâ¶þ²æÊ÷
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return isSubTreeBalanced(root) != -1;
    }

    int isSubTreeBalanced(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int left = isSubTreeBalanced(root->left);
        int right = isSubTreeBalanced(root->right);
        
        if(left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        else {
            return (left > right ? left : right) + 1;
        }
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

    TreeNode t1(3),t2(9),t3(20),t4(15),t5(7);
    t1.left  = &t2;
    t1.right = &t3;
    t3.left  = &t4;
    t3.right = &t5;

    s.display(&t1);
    cout<<endl;
    cout<<s.isBalanced(&t1)<<endl;

    return 0;
}