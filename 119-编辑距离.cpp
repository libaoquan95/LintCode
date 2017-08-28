#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/edit-distance/-119-±‡º≠æ‡¿Î
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int size1 = word1.size(), size2 = word2.size(),i = 0, j = 0;
        if(size1 <= 0 ) {
            return size2;
        }
        else if(size2 <= 0) {
            return size1;
        }

        vector<vector<int> > dp(size1+1, vector<int>(size2+1, 0));
        for(i=1; i<=size1; i++) {
            dp[i][0]= i;
        }
        for(i=1; i<=size2; i++) {
            dp[0][i] = i;
        }
        for(i=1; i<=size1; i++) {
            for(j=1; j<=size2; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = findMin(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])+1;
                }
            }
        }
        display(dp);
        return dp[size1][size2];
    }

    int findMin(int num1, int num2, int num3) {
        int min = num1 > num2 ? num2 : num1;
        return min > num3 ? num3 : min;
    }

    void display(string s) {
        for(int i=0; i<s.size(); i++) {
            cout<<s[i];
        }
        cout<<endl;
    }

    void display(vector< vector<int> > &matrix) {
        vector< vector<int> >::iterator i;
        vector<int>::iterator j;

        for(i=matrix.begin(); i!=matrix.end(); i++)
        {
            for(j=i->begin(); j!=i->end(); j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    Solution s;
    string S("mart");
    string T("karma");
    
    cout<<s.minDistance(S, T)<<endl;
    
    return 0;
}