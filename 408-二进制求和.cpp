#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/add-binary/-408-二进制求和 
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string a, string b) {
        // write your code here
        int sizeA = a.size(), sizeB = b.size();
        if (sizeA <= 0 || sizeB <= 0) {
            return string();
        }
        reversalString(a);
        reversalString(b);
        string result;
        int i = 0, carry = 0;
        for (i = 0; i<sizeA && i<sizeB; i++) {
            result += '0' + (a[i] - '0' + b[i] - '0');
        }
        for (; i < sizeA; i++) {
            result += a[i];
        }
        for (; i < sizeB; i++) {
            result += b[i];
        }
        for (i = 0; i < result.size(); i++) {
            int temp = result[i] - '0' + carry;
            if (temp == 2) {
                carry = 1;
                result[i] = '0';
            }
            else if (temp == 3) {
                carry = 1;
                result[i] = '1';
            }
            else {
                carry = 0;
                result[i] = temp + '0';
            }
        }
        if (carry == 1) {
            result += '1';
        }
        reversalString(result);
        return result;
    }

    void reversalString(string &str) {
        for (int i = 0; i < str.size() / 2; i++) {
            swap(str[i], str[str.size() - 1 - i]);
        }
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
    string a("11");
    string b("111");
    s.display(a);
    cout << "+" << endl;
    s.display(b);
    cout << "=" << endl;
    s.display(s.addBinary(a, b));
    
    return 0;
}