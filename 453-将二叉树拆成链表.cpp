#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

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
     * http://www.lintcode.com/zh-cn/problem/flatten-binary-tree-to-linked-list/-453-将二叉树拆成链表
     * @param root: a TreeNode, the root of the binary tree
     * @return: 
     */
    void flatten(TreeNode * root) {
        // write your code here
        if (root == NULL) {
            return ;
        }
        stack<TreeNode *>stack;
        TreeNode * node = root;
        bool isContinue = true;
        while (isContinue) {
            if (node->left != NULL && node->right != NULL) {
                stack.push(node->right);
                node->right = node->left;
                node->left = NULL;
            }
            else if (node->left != NULL && node->right == NULL) {
                node->right = node->left;
                node->left = NULL;
            }
            else if (node->left == NULL && node->right == NULL) {
                if (!stack.empty()) {
                    node->right = stack.top();
                    stack.pop();
                }
                else {
                    isContinue = false;
                }
            }
            node = node->right;
        }
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

    void display2(TreeNode *TreeRoot) {
        TreeNode *node = TreeRoot;
        while (node != NULL) {
            cout << node->val << " ";
            node = node->right;
        }
    }
};

int main()
{
    Solution s;

    TreeNode t1(1), t2(2), t3(3), t4(4), t5(5), t6(6);
    t1.left = &t2;
    t1.right = &t5;

    t2.left = &t3;
    t2.right = &t4;

    t5.right = &t6;

    s.display(&t1);
    cout << endl;

    s.flatten(&t1);

    s.display2(&t1);
    cout << endl;

    return 0;
}