#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/delete-digits/-182-删除数字
     * @param A: A positive integer which has N digits, A is a string.
     * @param k: Remove k digits.
     * @return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        int size = A.size();
        if (size <= 0 || size < k) {
            return A;
        }
        string result;
        int newSize = 0;
        for (int i = 0; i < size; i++) {
            while (!result.empty() && result.back() > A[i] && newSize < k) {
                result.pop_back();
                newSize++;
            }
            if (A[i] != '0' || !result.empty()) {
                result.push_back(A[i]);
            }
        }
        if (newSize < k) {
            result.resize(result.size() - k + newSize);
        }
        return result;
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

    s.display(s.DeleteDigits("2017854", 5));

    return 0;
}