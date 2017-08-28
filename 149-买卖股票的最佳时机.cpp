#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock/-149-买卖股票的最佳时机
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
        int buyIn = 0;
        for(int i=0; i<size; i++) {
            if(prices[i] < prices[buyIn]) {
                buyIn = i;
            }
            else {
                if(max < prices[i]-prices[buyIn]) {
                    max = prices[i]-prices[buyIn];
                }
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