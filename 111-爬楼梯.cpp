#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/climbing-stairs/-111-ÅÀÂ¥Ìİ 
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n <= 0) {
            return 0;
        }

        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
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
    
    cout<<s.climbStairs(3)<<endl;
    
    return 0;
}