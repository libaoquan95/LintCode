#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/problem/largest-number/-184-最大数
    * @param num: A list of non negative integers
    *@return: A string
    */
    string largestNumber(vector<int> &num) {
        // write your code here
        int size = num.size();
        if (size <= 0) {
            return string("");
        }

        sort(num.begin(), num.end(), cmp);
        display(num);
        string result;
        if (num[0] == 0) {
            result = "0";
            return result;
        }
        for (int i = 0; i < num.size(); i++) {
            char temp[50];
            sprintf(temp, "%d", num[i]);
            result += temp;
        }
        return result;
    }

    static bool cmp(int a, int b) {
        char temp[50];
        sprintf(temp, "%d", a);
        string stra = temp;
        sprintf(temp, "%d", b);
        string strb = temp;

        for (int i = 0; i < stra.size() && i < strb.size(); i++) {
            if (stra[i] > strb[i]) {
                return true;
            }
            else if (stra[i] < strb[i]) {
                return false;
            }
        }
        if (stra.size() < strb.size()) {
            return strb[stra.size()] > strb[0] ? false : true;
        }
        if (stra.size() > strb.size()) {
            return stra[strb.size()] > stra[0] ? true : false;
        }
        return false;
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    int A[] = { 41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    cout << endl;
    s.display(s.largestNumber(nums));

    return 0;
}