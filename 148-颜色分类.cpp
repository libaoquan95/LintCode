#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/sort-colors/-148-—’…´∑÷¿‡
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size <= 0) {
            return ;
        }
        int left = 0, right = size - 1;
        for(int i = 0; i < right+1; ){
            while(i == left && nums[left] == 0) {
                i++;
                left++;
            }
            while(nums[right] == 2) {
                right--;
            }
            if(nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }
            else {
                i++;
            }
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

    int A[] = {2,0,0,1,2,0,2};
    vector<int> nums(&A[0], &A[sizeof(A)/sizeof(int)]);

    s.display(nums);
    s.sortColors(nums);
    s.display(nums);

    return 0;
}