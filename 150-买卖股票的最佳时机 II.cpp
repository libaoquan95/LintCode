#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock-ii/-150-买卖股票的最佳时机 II
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int size = prices.size();
        if(size <= 0) {
            return 0;
        }

        int max = 0;
        for(int i=1; i<size; i++) {
            if(prices[i] - prices[i-1] > 0) {
                max += (prices[i] - prices[i-1]);
            }
        }
        return max;
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

    int A[] = {3,2,3,1,2};
    vector<int> nums(&A[0], &A[sizeof(A)/sizeof(int)]);

    s.display(nums);
    cout<<s.maxProfit(nums)<<endl;
    s.display(nums);

    return 0;
}