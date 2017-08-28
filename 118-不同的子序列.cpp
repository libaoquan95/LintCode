#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/distinct-subsequences/-118-不同的子序列
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int sizeS = S.size(), sizeT = T.size(), i = 0, j = 0;
        if(sizeS <= 0 || sizeT <= 0) {
            return 1;
        }

        vector<int> dp(sizeT+1, 0);
        dp[0] = 1;

        for(i=1; i<=sizeS; i++) {
            for(j=sizeT; j>0; j--) {
                if(S[i-1] == T[j-1]) {
                    dp[j] += dp[j-1];
                }
            }
            display(dp);
        }

        return dp[sizeT];
    }

    void display(string s) {
        for(int i=0; i<s.size(); i++) {
            cout<<s[i];
        }
        cout<<endl;
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
    string S("d");
    string T("d");
    
    cout<<s.numDistinct(S, T)<<endl;
    
    return 0;
}