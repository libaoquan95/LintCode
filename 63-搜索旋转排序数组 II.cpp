#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array-ii/-63-ËÑË÷Ğı×ªÅÅĞòÊı×é II
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int low = 0, high = A.size()-1, size = A.size(), mid = 0;

        if(size <= 0 ) {
            return 0;
        }
        while(low <= high) {
            mid = low + (high - low) / 2; 
            if(A[mid] == target) {
                return 1;
            }
            if(A[mid] > A[low]) {
                if(A[low] <= target && target < A[mid]) {
                    high = mid - 1;
                }
                else  {
                    low = mid + 1;
                }
            }
            else if(A[mid] < A[low]){
                if(A[mid] < target && target <= A[high])  {
                    low = mid + 1;
                }
                else  {
                    high = mid - 1;
                }
            }
            else {
                low++;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    /*nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);*/
    nums.push_back(9);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(9);
    
    cout<<s.search(nums, 4)<<endl;
    cout<<s.search(nums, 0)<<endl;
    cout<<s.search(nums, 8)<<endl;

    
    return 0;
}