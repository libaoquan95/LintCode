#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/3sum/-60-ËÑË÷²åÈëÎ»ÖÃ
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int low = 0, high = A.size()-1, size = A.size(), mid = (low+high)/2;
        if(size <= 0) {
            return 0;
        }
        while(low <= high) {
            if(A[mid] == target) {
                return mid;
            }
            else if(A[mid] > target) {
                high = mid - 1;
                mid = (low+high)/2;
            }
            else {
                low = mid + 1;
                mid = (low+high)/2;
            }
        }

        if(A[mid] > target) {
            return mid-1>0 ? mid-1: 0;
        }
        else if(A[mid] < target) {
            return mid+1;
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    
    cout<<s.searchInsert(nums, 6)<<endl;

    
    return 0;
}