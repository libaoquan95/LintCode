#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/longest-common-substring/-79-最长公共子串
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size(), i = 0, j = 0;
        int maxLen = 0;

        if(sizeA <= 0 || sizeB <= 0) {
            return 0;
        }

        vector<vector<int> > dpMatrix;
        dpMatrix.resize(sizeA+1);
        for(i=0; i<=sizeA; i++) {
            dpMatrix[i].resize(sizeB+1);
        }
        for(i=0; i<=sizeA; i++) {
            for(j=0; j<=sizeB; j++) {
                dpMatrix[i][j] = 0;
            }
        }

        for(i=1; i<=sizeA; i++) {
            for(j=1; j<=sizeB; j++) {
                if(A[i-1] == B[j-1]) {
                    dpMatrix[i][j] = dpMatrix[i-1][j-1] + 1;
                }
                else {
                    dpMatrix[i][j] = 0;
                }
                maxLen = maxLen >= dpMatrix[i][j] ? maxLen : dpMatrix[i][j];
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution s;

    string A("ABCD");
    string B("CBCE");

    cout<<s.longestCommonSubstring(A, B)<<endl;

    return 0;
}