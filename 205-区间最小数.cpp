#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

/**
* Definition of Interval:
*/
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

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
    * http://www.lintcode.com/zh-cn/problem/interval-minimum-number/-205-区间最小数
    * @param A, queries: Given an integer array and an query list
    * @return: The result list
    */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        if (A.empty() || queries.empty()) {
            return vector<int>();
        }

        vector<int> result;
        SegmentTreeNode * root = build(0, A.size() - 1, A);
        for (int i = 0; i < queries.size(); i++) {
            result.push_back(query(root, queries[i].start, queries[i].end));
        }
        return result;
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
            root->max = min(root->left->max, root->right->max);
        }
        else {
            root->max = nums[start];
        }
        return root;
    }

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
            return min(query(root->left, start, mid), query(root->right, mid + 1, end));
        }
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }

    void display(vector<Interval> &nums) {
        vector<Interval>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << "[" << (*i).start << " , " << (*i).end << "]   ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    int A[] = { 1,2,7,8,5 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    vector<Interval> queries;
    queries.push_back(Interval(1, 2));
    queries.push_back(Interval(0, 4));
    queries.push_back(Interval(2, 4));

    //s.display(nums);
    //s.display(queries);
    s.display(s.intervalMinNumber(nums, queries));

    return 0;
}
