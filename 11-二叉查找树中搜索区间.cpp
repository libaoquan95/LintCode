#include <iostream>
#include <vector>
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
     * http://www.lintcode.com/zh-cn/problem/search-range-in-binary-search-tree/-11-二叉查找树中搜索区间
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        if(root == NULL)
            return vector<int>();

        vector<int> result;
        inorderTraversal(root, result, k1, k2);
        return result;
    }

    void inorderTraversal(TreeNode *root, vector<int> &order, int k1, int k2) {
        if(root->left != NULL)
            inorderTraversal(root->left, order, k1, k2);

        if(root->val >= k1 && root->val <= k2) {
            order.push_back(root->val);
        }
        if(root->right != NULL)
            inorderTraversal(root->right, order, k1, k2);
    }
};

int main()
{
    Solution s;

    
    TreeNode t1(20),t2(8),t3(22),t4(4),t5(12);
    t1.left  = &t2;
    t1.right = &t3;
    t2.left  = &t4;
    t2.right = &t5;

    vector<int> order;
    order = s.searchRange(&t1, 10, 22);

    vector<int>::iterator i;
    for(i=order.begin(); i!=order.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    return 0;
}