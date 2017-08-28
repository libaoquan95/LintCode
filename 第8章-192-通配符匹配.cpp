#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ8ÕÂ-192-Í¨Åä·ûÆ¥Åä
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if(s == NULL && p == NULL)  
            return true;  
        if(s == NULL || p == NULL)  
            return false; 

        int sLen = strlen(s);  
        int pLen = strlen(p); 
        int i, j;

        vector<vector<int> > dp(sLen+1,vector<int>(pLen+1,0));  
        for(i=1;i <=sLen ; ++i)  
        {  
            for(j=1; j<=pLen; ++j)  
            {  
                dp[i][j] = 0;  
            } 
        }
          
        dp[0][0] = 1;  
        for(i=1; i<= sLen; ++i)  
        {  
            if(dp[i-1][0] == 1 && s[i-1] == '*')  
            {  
                dp[i][0] = 1;  
            }
            else
            {  
                dp[i][0] = 0;  
            }
        } 
          
        for(j=1; j<=pLen; ++j)  
        {  
            if(dp[0][j-1] == 1 && p[j-1] == '*')  
            {  
                dp[0][j] = 1;  
            }
            else
            {  
                dp[0][j] = 0;  
            }  
        }  
          
        for(i=1;i<=sLen; ++i)  
        {  
            for(j=1; j<=pLen; ++j)  
            {  
                if(s[i-1] == '*' || p[j-1] == '*')
                {  
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];  
                }
                else if(s[i-1] == '?' || p[j-1] == '?')
                {  
                    dp[i][j] = dp[i-1][j-1];  
                }
                else 
                {  
                    dp[i][j] = ((s[i-1] == p[j-1] ? 1 : 0) && dp[i-1][j-1]);  
                }  
            } 
        } 
          
        return dp[sLen][pLen];  
    }
};

int main()
{
    Solution s;

    /*
    isMatch("aa","a") ¡ú false
    isMatch("aa","aa") ¡ú true
    isMatch("aaa","aa") ¡ú false
    isMatch("aa", "*") ¡ú true
    isMatch("aa", "a*") ¡ú true
    isMatch("ab", "?*") ¡ú true
    isMatch("aab", "c*a*b") ¡ú false
    */

    cout<<"(\"aa\",\"a\")" <<s.isMatch("aa","a")<<endl;
    cout<<"(\"aa\",\"aa\")"<<s.isMatch("aa","aa")<<endl;
    cout<<"(\"aaa\",\"a\")"<<s.isMatch("aaa","aa")<<endl;
    cout<<"(\"aa\",\"*\")" <<s.isMatch("aa","*")<<endl;
    cout<<"(\"aa\",\"a*\")"<<s.isMatch("aa","a*")<<endl;
    cout<<"(\"ab\",\"?b\")"<<s.isMatch("ab","?*")<<endl;
    cout<<"(\"aab\",\"c*a*b\")" <<s.isMatch("aab","c*a*b")<<endl;

    return 0;
}
