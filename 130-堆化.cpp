#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

/**
 * Definition of ListNode
 */
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/heapify/-130-¶Ñ»¯
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int size = A.size();
        if(size <= 0) {
            return;
        }
        for(int i=(size-1)/2; i>=0; i--) {
            heapify(A, i);
        }
    }
    void heapify(vector<int> &A, int i) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int minNode = i;

        if(leftChild < A.size() && A[leftChild] < A[minNode]) {
            minNode = leftChild;
        }
        if(rightChild < A.size() && A[rightChild] < A[minNode]) {
            minNode = rightChild;
        }

        if(minNode != i) {
            swap(A[i], A[minNode]);  
            heapify(A, minNode);
        }
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++) {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(5);

    s.display(nums);
    s.heapify(nums);
    s.display(nums);

    return 0;
}