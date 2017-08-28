#include <iostream>
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
     * http://www.lintcode.com/zh-cn/problem/single-number-iii/-85-在二叉查找树中插入节点
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        TreeNode* curNode = root, *curNodeNext = root;
        if(root == NULL) {
            root = node;
        }
        while(curNodeNext != NULL) {
            if(curNodeNext->val > node->val) {
                curNode = curNodeNext;
                curNodeNext = curNodeNext->left;
                if(curNode->left == NULL) {
                    curNode->left = node;
                    break;
                }
            }
            else if(curNodeNext->val < node->val) {
                curNode = curNodeNext;
                curNodeNext = curNodeNext->right;
                if(curNode->right == NULL) {
                    curNode->right = node;
                    break;
                }
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
    
    TreeNode t1(2),t2(1),t3(4),t4(3);
    t1.left  = &t2;
    t1.right = &t3;
    t3.left  = &t4;

    TreeNode node(6);

    s.display(&t1);
    cout<<endl;
    s.insertNode(&t1, &node);
    s.display(&t1);
    cout<<endl;

    return 0;
}