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
     * http://www.lintcode.com/zh-cn/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height/-177-把排序数组转换为高度最小的二叉搜索树
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return nullptr;
        }
        TreeNode *root;
        root = sortedArrayToBST(A, 0, size-1);
        return root;
    }
    TreeNode * sortedArrayToBST(vector<int> &A,  int low, int high) {
        if (low <= high) {
            int mid = low + (high - low) / 2;
            TreeNode * root = new TreeNode(A[mid]);
            root->left = sortedArrayToBST(A, low, mid - 1);
            root->right = sortedArrayToBST(A, mid + 1, high);
            return root;
        }
        else {
            return nullptr;
        }
    }

    void display(TreeNode *TreeRoot) {
        if (TreeRoot == NULL) {
            //cout<<"null"<<endl;
        }
        else {
            display(TreeRoot->left);
            cout << TreeRoot->val << " ";
            display(TreeRoot->right);
        }
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    int A[] = { 1,2,3,4,5,6,7 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    s.display(s.sortedArrayToBST(nums));

    return 0;
}