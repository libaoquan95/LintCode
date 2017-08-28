#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/palindrome-partitioning-ii/-108-·Ö¸î»ØÎÄ´® II
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int size = s.size(), i = 0, j = 0;
        if(size <= 0) {
            return 0;
        }

        bool **isPalindrome = new bool*[size];
		for (i=0; i<size; i++) {
			isPalindrome[i] = new bool[size];
		}
		initIsPalindrome(isPalindrome, s);

        vector<int> dp(size+1, 0x7FFFFFFF);
        for(i=size-1; i>=0; i--) {
            if(isPalindrome[i][size-1]) {
                dp[i] = 0;
                continue;
            }
            for(j=i+1; j<size; j++) {
                if(isPalindrome[i][j-1]) {
                    dp[i] = (dp[i] < dp[j]+1) ? dp[i] : dp[j]+1;
                }
            }
        }

        return dp[0];
    }

    void initIsPalindrome(bool ** isPalindrome, const string& s) {
		int len = s.length();
		for (int L = 1; L <= len; ++L) {
			for (int i = 0; i < len - L + 1; ++i) {
				int j = i + L - 1;
				if (L == 1) {
					isPalindrome[i][j] = true;
				} else if (L == 2) {
					isPalindrome[i][j] = s[i] == s[j];
				} else {
					isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
				}
			}
		}
	}

    int minCut_Time_Limit_Exceeded(string s) {
        // write your code here
        int size = s.size(), i = 0, j = 0;
        if(size <= 0) {
            return 0;
        }

        vector<int> dp(size+1, 0x7FFFFFFF);
        for(i=size-1; i>=0; i--) {
            if(isPalindromeFun(s, i, size-1)) {
                dp[i] = 0;
                continue;
            }
            for(j=i+1; j<size; j++) {
                if(isPalindromeFun(s, i, j-1)) {
                    dp[i] = (dp[i] < dp[j]+1) ? dp[i] : dp[j]+1;
                }
            }
        }

        return dp[0];
    }

    bool isPalindromeFun(string s, int begin, int end) {
        for(int i=begin, j=end; i<j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void display(string s) {
        for(int i=0; i<s.size(); i++) {
            cout<<s[i];
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    string str("aab");
    cout<<s.minCut(str)<<endl;
    
    return 0;
}