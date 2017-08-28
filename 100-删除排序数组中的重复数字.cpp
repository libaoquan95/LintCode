#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array/-100-删除排序数组中的重复数字 
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int size = nums.size(), i = 0, j = 1;
        if(size <= 0) {
            return 0;
        }
        int  newSize = 1;
        while(j<size) {
            if(nums[i] < nums[j]){
                nums[i+1] = nums[j];
                i++;
                j = i+1;
                newSize++;
            }
            else {
                j++;
            }
        }

        return newSize;
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
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(5);

    s.displayVector(nums);
    cout<<s.removeDuplicates(nums)<<endl;
    s.displayVector(nums);

    return 0;
}