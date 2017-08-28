#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/backpack-ii/-125-±≥∞¸Œ Ã‚ II
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int size = A.size(), i = 0, j = 0;
        if(size <= 0) {
            return 0;
        }
        vector<int> dp(m+1, 0);

        for(i=0; i<size+1; i++) {
            for(j=m; j>=0; j--) {
                if(i==0 || j==0){
                    dp[j] = 0;
                }
                else {
                    if(j >= A[i-1]){
                        dp[j] = (dp[j-A[i-1]]+V[i-1] > dp[j])?dp[j-A[i-1]]+V[i-1]:dp[j];
                    }
                    else{
                        dp[j] = dp[j];
                    }

                }
            }
        }

        return dp[m];
    }

    int backPackII_MN(int m, vector<int> A, vector<int> V) {
        // write your code here
        int size = A.size(), i = 0, j = 0;
        if(size <= 0) {
            return 0;
        }
        vector<vector<int> > dp(size+1, vector<int>(m+1, 0));

        for(i=0; i<size+1; i++) {
            for(j=0; j<m+1; j++) {
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
                else {
                    if(j >= A[i-1]){
                        dp[i][j] = (dp[i-1][j-A[i-1]]+V[i-1] > dp[i-1][j])?dp[i-1][j-A[i-1]]+V[i-1]:dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }

                }
            }
        }

        display(dp);
        return dp[size][m];
    }

    void display(vector<vector<int> > matrix) {
        vector< vector<int> >::iterator i;
        vector<int>::iterator j;
        for(i=matrix.begin(); i!=matrix.end(); i++) {
            for(j=i->begin(); j!=i->end(); j++) {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution s;
    
    vector<int> A;
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
    A.push_back(7);

    vector<int> V;
    V.push_back(1);
    V.push_back(5);
    V.push_back(2);
    V.push_back(4);

    cout<<s.backPackII(10, A, V)<<endl;
    
    return 0;
}