#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/longest-common-prefix/-78-最长公共前缀
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        int size = strs.size(), i = 0, j = 0;
        if(size <= 0) {
            return string();
        }
        if(size == 1) {
            return strs[0];
        }

        string strA, strB;
        strA = strs[0];
        for(i=1; i<size; i++) {
            strB = strs[i];
            string strLCP;
            for(j=0; j<strA.size() && j<strB.size(); j++) {
                if(strA[j] == strB[j]) {
                    strLCP += strA[j];
                }
                else{
                    break;
                }
            }
            strA = strLCP;
        }

        return strA;
    }
};

int main()
{
    Solution s;

    vector<string> strs;
    strs.push_back("ABCDEFG");
    strs.push_back("ABCEFG");
    strs.push_back("ABCEFA");

    string str = s.longestCommonPrefix(strs);

    for(int i=0; i<str.size(); i++) {
        cout<<str[i];
    }
    cout<<endl;

    return 0;
}