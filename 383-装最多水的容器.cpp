#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/container-with-most-water/-383-装最多水的容器 
     * @param : a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> heights) {
        // write your code here
        int size = heights.size();
        if (size <= 0) {
            return 0;
        }

        int result = 0, left = 0, right = size-1;
        while (left < right) {
            result = max(result, min(heights[left], heights[right])*(right - left));
            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return result;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    int A[] = { 1,3,2 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    cout << s.maxArea(nums) << endl;

    return 0;
}