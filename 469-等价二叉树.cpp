#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
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
     * http://www.lintcode.com/zh-cn/problem/identical-binary-tree/-469-等价二叉树
     * @param a: the root of binary tree a.
     * @param b: the root of binary tree b.
     * @return: true if they are identical, or false.
     */
    bool isIdentical(TreeNode * a, TreeNode * b) {
        // write your code here
        if (a == NULL && b == NULL) {
            return true;
        }
        if ((a == NULL && b != NULL) || (a != NULL && b == NULL)) {
            return false;
        }
        if (a->val != b->val) {
            return false;
        }
        return isIdentical(a->left, b->left) & isIdentical(a->right, b->right);
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

    TreeNode t11(3), t12(9), t13(20), t14(15), t15(7);
    t11.left = &t12;
    t11.right = &t13;
    t13.left = &t14;
    t13.right = &t15;

    TreeNode t21(3), t22(9), t23(20), t24(15), t25(7);
    t21.left = &t22;
    t21.right = &t23;
    t23.left = &t24;
    t23.right = &t25;

    cout << s.isIdentical(&t11, &t22) << endl;

    return 0;
}