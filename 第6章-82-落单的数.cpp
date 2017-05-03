#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第6章-82-落单的数
     * @param A: Array of integers.
	 * @return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int ans = 0;
        for(int i=0; i<A.size(); ++i)
            ans ^= A[i];
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(5);

    cout<<s.singleNumber(nums)<<endl;
    
    return 0;
}