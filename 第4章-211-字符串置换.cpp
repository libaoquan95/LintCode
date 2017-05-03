#include <iostream>
#include<stack>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ4ÕÂ-211-×Ö·û´®ÖÃ»»
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        int asciiA[127] = {0};
        int asciiB[127] = {0};
        int i;

        if(A.size() != B.size())
            return false;
        for(i=0; i<A.size(); i++)
        {
            asciiA[A[i]]++;
            asciiB[B[i]]++;
        }
        for(i=0; i<127; i++)
        {
            if(asciiA[i] != asciiB[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;

    string A("abcd");
    string B("bca4");
    cout<<s.stringPermutation(A, B)<<endl;

    return 0;
}