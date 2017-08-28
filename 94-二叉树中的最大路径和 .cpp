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
     * http://www.lintcode.com/zh-cn/problem/binary-tree-maximum-path-sum/-94-二叉树中的最大路径和 
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        int maxSum = 0x80000000;
        findMaxSum(root, maxSum);
        return maxSum;
    }

    int findMaxSum(TreeNode *root, int &curMax) {
        // write your code here
        int maxLeft = 0, maxRight = 0, maxValue = 0;

        if(root == NULL) {
            return 0;
        }

        maxLeft = findMaxSum(root->left, curMax);
        maxRight = findMaxSum(root->right, curMax);

        int temp = (0>maxLeft?0:maxLeft) + (0>maxRight?0:maxRight) + root->val;
        curMax = curMax > temp ? curMax : temp;


        return ( 0>(maxRight>maxLeft?maxRight:maxLeft) ? 0 : (maxRight>maxLeft?maxRight:maxLeft) ) + root->val;
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

    TreeNode t1(1),t2(2),t3(3);
    t1.left  = &t2;
    t1.right = &t3;

    s.display(&t1);
    cout<<endl;
    cout<<s.maxPathSum(&t1)<<endl;

    return 0;
}