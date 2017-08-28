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

    vector<TreeNode *> inorder;
    int current;

    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        inorder = inorderTraversal(root);
        current = 0;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        if(current == inorder.size()) {
            return false;
        }
        else {
            return true;
        }
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        return inorder[current++];
    }

    vector<TreeNode *> inorderTraversal(TreeNode *root) {
        vector<TreeNode *> order;

        if(root == NULL) {
            return vector<TreeNode *>();
        }

        stack<TreeNode *> s;
        TreeNode *p = root;
        while(p != NULL || !s.empty()) {
            while(p != NULL) {
                s.push(p);
                p = p->left;
            }
            if(!s.empty()) {
                p = s.top();
                order.push_back(p);
                s.pop();
                p = p->right;
            }
        } 
        return order;
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