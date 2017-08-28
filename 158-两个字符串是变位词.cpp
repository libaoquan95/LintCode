#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/two-strings-are-anagrams/-158-两个字符串是变位词
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        int sizeS = s.size(), sizeT = t.size() , i = 0;
        if (sizeS == 0 && sizeT == 0) {
            return true;
        }
        if (sizeS != sizeT) {
            return false;
        }

        int hashS[128] = { 0 };
        int hashT[128] = { 0 };
        for (i = 0; i < sizeS; i++) {
            hashS[s[i]]++;
            hashT[t[i]]++;
        }
        for (i = 0; i < 128; i++) {
            if (hashS[i] != hashT[i]) {
                return false;
            }
        }
        return true;
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    string str1("abc");
    string str2("cab");
    cout << s.anagram(str1, str2) << endl;

    return 0;
}