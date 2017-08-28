#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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
     * http://www.lintcode.com/zh-cn/problem/minimum-depth-of-binary-tree/-155-二叉树的最小深度
     *  @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        leftDepth = (leftDepth == 0 ? INT_MAX : leftDepth);
        rightDepth = (rightDepth == 0 ? INT_MAX : rightDepth);
        
        return (leftDepth < rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }

    void display(TreeNode *TreeRoot) {
        if (TreeRoot == NULL) {
            //cout<<"null"<<endl;
        }
        else {
            cout << TreeRoot->val << " ";
            display(TreeRoot->left);
            display(TreeRoot->right);
        }
    }
};

int main()
{
    Solution s;

    TreeNode t1(1), t2(2), t3(3), t4(4), t5(5);
    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;

    cout << s.minDepth(&t1) << endl;
    return 0;
}