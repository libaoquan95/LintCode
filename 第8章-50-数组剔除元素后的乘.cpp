#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第8章-50-数组剔除元素后的乘积
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<_int64> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n = nums.size(),i;
        vector<_int64> left(n, 1);
        vector<_int64> right(n, 1);
        vector<_int64> res(n, 1);

        for(i = 1; i < n; ++i)
            left[i] = left[i-1] * nums[i-1];
        for(i = n-2; i >= 0; --i)
            right[i] = right[i+1] * nums[i+1];

        for(i = 0; i != nums.size(); ++i)
            res[i] = left[i] * right[i];

        return res;
    }
};

int main()
{
    Solution s;
   
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<_int64> order = s.productExcludeItself(nums);

	vector<_int64>::iterator i;
	
	for(i=order.begin(); i!=order.end(); i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
    return 0;
}
