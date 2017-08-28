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
    * http://www.lintcode.com/zh-cn/problem/segment-tree-query/-202-线段树的查询
    * @param root, start, end: The root of segment tree and
    *                         an segment / interval
    * @return: The maximum number in the interval [start, end]
    */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        int mid = (root->start + root->end) / 2;
        if (start <= root->start && end >= root->end) {
            return root->max;
        }
        else if (mid < start) {
            return query(root->right, start, end);
        }
        else if (mid + 1 > end) {
            return query(root->left, start, end);
        }
        else {
            return max(query(root->left, start, mid), query(root->right, mid + 1, end));
        }
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
    int A[] = { 1, 4, 2, 3 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    SegmentTreeNode *root = s.build(0, 3, nums);
    s.display(root);
    cout << s.query(root, 1, 1) << endl;
    cout << s.query(root, 1, 2) << endl;
    cout << s.query(root, 2, 3) << endl;
    cout << s.query(root, 0, 2) << endl;

    return 0;
}
