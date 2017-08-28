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
    * http://www.lintcode.com/zh-cn/problem/invert-binary-tree/-175-翻转二叉树
    * @param root: a TreeNode, the root of the binary tree
    * @return: nothing
    */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root == NULL) {
            return;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode * node = queue.front();
            queue.pop();
            if (node->left != NULL) {
                queue.push(node->left);
            }
            if (node->right != NULL) {
                queue.push(node->right);
            }
            swap(node->left, node->right);
        }
    }

    void invertBinaryTree_R(TreeNode *root) {
        // write your code here
        if (root == NULL) {
            return;
        }
        swap(root->left, root->right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
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


    s.display(&t1);
    cout << endl;
    s.invertBinaryTree(&t1);
    s.display(&t1);
    cout << endl;

    return 0;
}