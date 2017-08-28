#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/the-smallest-difference/-387-最小差
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size();
        if (sizeA <= 0 || sizeB <= 0) {
            return 0;
        }

        int result = INT_MAX;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (int i = 0; i < sizeA; i++) {
            int low = 0, high = sizeB - 1, target = A[i], mid = 0;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (B[mid] == target) {
                    return 0;
                }
                else if (B[mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            result = min(result, abs(A[i] - B[mid]));
            if(mid > 0) {
                result = min(result, abs(A[i] - B[mid - 1]));
            }
            if (mid < sizeB - 1) {
                result = min(result, abs(A[i] - B[mid + 1]));
            }
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

    int a[] = { 58684,72806,53378,26373,10801,46478,19696,54502,77251,33444,78573,36197,67829,84816,15361,62615,45948,56904,48968,104941,35083,62484,72722,93181,50367,86721,1819,88871,56787,22134,11250,106814,21618,64415,19977,54243,111898,157,56343,111696,5403,78114,13080,108776,28352,26974,93530,46031,89296,36209,97352,35603,70103,84672,9624,46575,51480,39493,50392,39133,89481,78530,63855,62388,54156,28205,14174,25605,10865,97844,76598,87661,14059,9442,69154,70226,73251,93492,91462,245,108530,90077,71965,89029,98238,32004,11412,13036,63116,18858,6519,20666,54400,88617,94687,77080,25732,13820,28375,63635,81697,45248,27473,46115,109395,66166,42297,36133,53476,34812,42284,102811 };
    vector<int> A(&a[0], &a[sizeof(a) / sizeof(int)]);

    int b[] = { 2930,1554,7515,1406,307,3094,57,2649,6102,8240,5584,6073,5849,3261,10617,1344,489,11083,4301,6752,3028,5196,987,3175,10139,3539,9151,3056,1478,10072,7875,7828,6013,9815,1872,2046,8606 };
    vector<int> B(&b[0], &b[sizeof(b) / sizeof(int)]);

    cout << s.smallestDifference(A, B) << endl;

    return 0;
}