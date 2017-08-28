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
     * http://www.lintcode.com/zh-cn/problem/remove-node-in-binary-search-tree/-87-删除二叉查找树的节点
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(root == NULL) {
            return NULL;
        }

        if(root->val > value) {
            root->left = removeNode(root->left, value);
        }
        else if(root->val < value) {
            root->right = removeNode(root->right, value);
        }
        else {
            if (root->left == NULL || root->right == NULL) {
                root = (root->left != NULL) ? root->left : root->right;
            }
            else {
                TreeNode *cur = root->right;
                while (cur->left != NULL) {
                    cur = cur->left;
                }
                root->val = cur->val;
                root->right = removeNode(root->right, cur->val);
            }
        }
        return root;
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

    TreeNode t1(5), t2(3), t3(6), t4(2), t5(4);
    t1.left  = &t2;
    t1.right = &t3;
    t2.left  = &t4;
    t2.right = &t5;

    s.display(&t1);
    cout<<endl;
    s.display(s.removeNode(&t1, 3));
    cout<<endl;

    return 0;
}