#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iii-151-买卖股票的最佳时机 III
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int size = prices.size();
        if(size <= 0) {
            return 0;
        }
        
        int max = 0, i = 0, min = 0;
        vector<int> left(size, 0);
        vector<int> right(size, 0);

        min = prices[0];
        for(i=1; i<size; i++) {
            if(prices[i] >= min) {
                left[i] = (left[i-1] > prices[i]-min) ? left[i-1] : prices[i]-min;
            }
            else {
                left[i] = left[i-1];
                min = prices[i];
            }
        }
        max = prices[size-1];
        for(i=size-2; i>=0; i--) {
            if(prices[i] <= max) {
                right[i] = (right[i+1] > max-prices[i]) ? right[i+1]  : max-prices[i];
            }
            else {
                right[i] = right[i+1];
                max = prices[i];
            }
        }

        max = INT_MIN;
        for(i=0; i<size; i++){
            max = (max > left[i]+right[i])? max : left[i]+right[i];
        }
        return max;
    }

    int maxProfit_TLE(vector<int> &prices) {
        // write your code here
        int size = prices.size();
        if(size <= 0) {
            return 0;
        }

        int max = 0;
        for(int i=1; i<size; i++) {
            int maxLeft  = maxProfit(prices, 0, i);
            int maxRight = maxProfit(prices, i+1, size-1);
            max = (maxLeft+maxRight) > max ? (maxLeft+maxRight) : max;
        }

        return max;
    }
    
    int maxProfit(vector<int> &prices, int begin, int end) {
        int max = 0;
        int buyIn = begin;
        for(int i=begin; i<=end; i++) {
            if(prices[i] < prices[buyIn]) {
                buyIn = i;
            }
            else {
                if(max <= prices[i]-prices[buyIn]) {
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

    int A[] = {2,1};
    //int A[] = {4,4,6,1,1,4,2,5};
    vector<int> nums(&A[0], &A[sizeof(A)/sizeof(int)]);

    s.display(nums);
    cout<<s.maxProfit(nums)<<endl;
    s.display(nums);

    return 0;
}