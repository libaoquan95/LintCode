#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/3sum/-62-ËÑË÷Ðý×ªÅÅÐòÊý×é
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int low = 0, high = A.size()-1, size = A.size(), mid = 0;

        if(size <= 0) {
            return -1;
        }
        while(low <= high) {
            mid = (high + low) / 2; 
            if(A[mid] == target) {
                return mid;
            }
            if(A[mid] >= A[low]) {
                if(A[low] <= target && target < A[mid]) {
                    high = mid - 1;
                }
                else  {
                    low = mid + 1;
                }
            }
            else {
                if(A[mid] < target && target <= A[high])  {
                    low = mid + 1;
                }
                else  {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(2);
    
    cout<<s.search(nums, 1)<<endl;
    cout<<s.search(nums, 0)<<endl;

    
    return 0;
}