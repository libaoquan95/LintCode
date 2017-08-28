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
    * http://www.lintcode.com/zh-cn/problem/wiggle-sort/-508-摆动排序
    * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        int size = nums.size();
        if (size <= 0) {
            return;
        }
        sort(nums.begin(), nums.end());

        for (int i = 1; i < size - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }

    void wiggleSort2(vector<int>& nums) {
        // Write your code here
        int size = nums.size();
        if (size <= 0) {
            return;
        }
        for (int i = 1; i < size; i += 2) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
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