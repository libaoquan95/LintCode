#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition of TreeNode
 */:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
}

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第7章-88-最近公共祖先
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
    }
};

int main()
{
    Solution s;

    return 0;
}