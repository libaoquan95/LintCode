#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

/**
* Definition of SegmentTreeNode:
*/
class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/segment-tree-modify/-203-线段树的修改
     * @param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (root == NULL) {
            return;
        }
        if (root->start == root->end) {
            if (root->start == index) {
                root->max =  value;
            }
            return;
        }
        modify(root->left, index, value);
        modify(root->right, index, value);

        root->max = max(root->left->max, root->right->max);
    }

    SegmentTreeNode * build(int start, int end, vector<int> &nums) {
        // write your code here
        if (start > end) {
            return nullptr;
        }
        int max = nums[start];
        for (int i = start + 1; i <= end; i++) {
            if (max < nums[i]) {
                max = nums[i];
            }
        }
        SegmentTreeNode *root = new SegmentTreeNode(start, end, max);
        if (start != end) {
            root->left = build(start, (start + end) / 2, nums);
            root->right = build((start + end) / 2 + 1, end, nums);
        }
        return root;
    }

    void display(SegmentTreeNode *TreeRoot) {
        if (TreeRoot == NULL) {
            //cout<<"null"<<endl;
        }
        else {
            cout << "[" << TreeRoot->start << "," << TreeRoot->end << "," << TreeRoot->max << "]";
            cout << endl;
            display(TreeRoot->left);
            display(TreeRoot->right);
        }
    }
};

int main()
{
    Solution s;
    int A[] = { 1, 4, 2, 3 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    SegmentTreeNode *root = s.build(0, 3, nums);
    s.display(root);
    s.modify(root, 0, 5);
    s.display(root);

    return 0;
}
