#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition of ListNode
 */ 
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val) 
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/recover-rotated-sorted-array/-39-»Ö¸´Ðý×ªÅÅÐòÊý×é 
     * @param nums: The rotated sorted array.
     * @return: none
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int i = 0, size = nums.size();
        int index = 0;
        for(i=0; i<size-1; i++) {
            if(nums[i] > nums[i+1]) {
                index = i+1;
                break;
            }
        }
        for(i=0; i<index/2; i++) {
            int temp = nums[i];
            nums[i] = nums[index-1-i];
            nums[index-1-i] = temp;
        }
        for(i=0; i<(size-index)/2; i++) {
            int temp = nums[index+i];
            nums[index+i] = nums[size-1-i];
            nums[size-1-i] = temp;
        }
        for(i=0; i<size/2; i++) {
            int temp = nums[i];
            nums[i] = nums[size-1-i];
            nums[size-1-i] = temp;
        }
    }

    void displayVector(vector<int> &order) {
        vector<int>::iterator i;
        for(i=order.begin(); i!=order.end(); i++) {
            cout<<(*i)<<",";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    s.displayVector(nums);
    s.recoverRotatedSortedArray(nums);
    s.displayVector(nums);

    return 0;
}