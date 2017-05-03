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
     * http://www.lintcode.com/zh-cn/ladder/6/-第4章-376-二叉树的路径和
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int> > binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int> > result;
        vector<int> order;
        TreeNode *p=root;
        int path=0;

        if(root == NULL)
        {
            return result;
        }
        else
        {
            path = 0;
            findPath(root, target, order, path, result);
            return result;
        }
    }

    void findPath(TreeNode *root, int target, vector<int> &order, int &path, vector<vector<int> > &result)
    {
        path += root->val;
        order.push_back(root->val);

        if(path == target && (root->left==NULL&&root->right==NULL))
        {
            result.push_back(order);
        }

        if(root->left != NULL)
            findPath(root->left, target, order, path, result);
        if(root->right != NULL)
            findPath(root->right, target, order, path, result);

        path -= root->val;
        order.pop_back();
    }
};

int main()
{
    Solution s;
   
    TreeNode t1(1),t2(2),t3(4),t4(2),t5(3);
    t1.left  = &t2;
    t1.right = &t3;
    t2.left  = &t4;
    t2.right = &t5;

    vector<vector<int> > order = s.binaryTreePathSum(&t1, 5);

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