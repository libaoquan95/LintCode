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
     * http://www.lintcode.com/zh-cn/problem/segment-tree-build-ii/-439-线段树的构造 II
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> A) {
        if (A.size() <= 0) {
            return nullptr;
        }
        return build(0, A.size() - 1, A);
    }
    SegmentTreeNode * build(int start, int end, vector<int> &nums) {
        // write your code here
        if (start > end) {
            return nullptr;
        }
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);
        if (start != end) {
            root->left = build(start, (start + end) / 2, nums);
            root->right = build((start + end) / 2 + 1, end, nums);
            root->max = max(root->left->max, root->right->max);
        }
        else {
            root->max = nums[start];
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
    int A[] = { 3,2,1,4 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(s.build(nums));

    return 0;
}