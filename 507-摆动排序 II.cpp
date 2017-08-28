#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/wiggle-sort-ii/-507-摆动排序 II
    * @param nums a list of integer
    * @return void
    */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        int size = nums.size();
        if (size <= 0) {
            return;
        }
        vector<int> temp = nums;
        int k = (size + 1) / 2, j = size;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < size; ++i) {
            nums[i] = i & 1 ? temp[--j] : temp[--k];
        }
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

    int A[] = { 3, 5, 2, 1, 6, 4};
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    s.wiggleSort(nums);
    s.display(nums);

    return 0;
}