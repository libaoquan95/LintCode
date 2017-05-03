#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
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
     * http://www.lintcode.com/zh-cn/ladder/6/-第6章-97-二叉树的最大深度
     *@param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(root  == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return (leftDepth>rightDepth)?(leftDepth+1):(rightDepth+1);
    }
};

int main()
{
    Solution s;

    TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7);
    t1.left  = &t2;
    t1.right = &t3;
    t2.left  = &t4;
    t2.right = &t5;
    t3.right = &t6;
    t5.left  = &t7;

    cout<<s.maxDepth(&t1)<<endl;
    
    return 0;
}