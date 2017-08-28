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

class BSTIterator {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/binary-search-tree-iterator/-86-¶þ²æ²éÕÒÊ÷µü´úÆ÷
     * Example of iterate a tree:
     * BSTIterator iterator = BSTIterator(root);
     * while (iterator.hasNext()) {
     *    TreeNode * node = iterator.next();
     *    do something for node
     * }
     */

    stack<TreeNode *> inorder;

    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        putIntoStack(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !inorder.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here 
        TreeNode *current = inorder.top();
        TreeNode *temp = current;
        inorder.pop();

        putIntoStack(current->right);

        return current;
    }

    void putIntoStack(TreeNode *root) {
        TreeNode *node = root;
        while(node != NULL) {
            inorder.push(node);
            node = node->left;
        }
    }
};

int main()
{
    TreeNode t1(10), t2(1), t3(11), t4(6), t5(12);
    t1.left  = &t2;
    t1.right = &t3;
    t2.right  = &t4;
    t3.right  = &t5;

    BSTIterator iterator = BSTIterator(&t1);
    while (iterator.hasNext()) {
        TreeNode * node = iterator.next();
        cout<< node->val<<" ";
    }
    cout<<endl;
    return 0;
}