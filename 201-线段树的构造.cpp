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
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/segment-tree-build/-201-线段树的构造
    * @param start, end: Denote an segment / interval
    * @return: The root of Segment Tree
    */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end) {
            return nullptr;
        }
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start != end) {
            root->left = build(start, (start + end) / 2);
            root->right = build((start + end) / 2 + 1, end);
        }
        return root;
    }

    void display(SegmentTreeNode *TreeRoot) {
        if (TreeRoot == NULL) {
            //cout<<"null"<<endl;
        }
        else {
            cout << "[" << TreeRoot->start << " , " << TreeRoot->end << "]";
            display(TreeRoot->left);
            display(TreeRoot->right);
        }
    }
};

int main()
{
    Solution s;

    s.display(s.build(1, 6));
    cout << endl;

    return 0;
}
