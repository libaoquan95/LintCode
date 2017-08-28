#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/compare-strings/-55-±È½Ï×Ö·û´® 
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int hashA[26]={0}, hashB[26]={0};
        int i = 0;

        for(i=0; i<A.size(); i++) {
            hashA[ A[i] - 'A' ]++;
        }
        for(i=0; i<B.size(); i++) {
            hashB[ B[i] - 'A' ]++;
        }
        
        for(i=0; i<26; i++) {
            if(hashA[i] < hashB[i]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout<<s.compareStrings("ABCD", "ACDO")<<endl;

    return 0;
}