#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/single-number-iii/-84-Âäµ¥µÄÊý III
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int size = A.size(), ans = 0, i = 0;
        vector<int> res;
        int r1 = 0, r2 = 0, k = 0;

        for(i=0; i<size; ++i) {
            ans ^= A[i];
        }

        while(ans % 2 == 0) {
            k++;
            ans >>= 1;
        }

        for(i=0; i<size; i++) {
            int kbit = ( A[i] >> k ) % 2;
            if(kbit == 0) {
                r1 ^= A[i];
            }
            else {
                r2 ^= A[i];
            }
        }
        
        res.push_back(r1);
        res.push_back(r2);
        return res;
    }

    void displayVector(vector<int> &order) {
        vector<int>::iterator i;
        for(i=order.begin(); i!=order.end(); i++) {
            cout<<(*i)<<",";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(3);

    s.displayVector(nums);
    vector<int> result = s.singleNumberIII(nums);
    s.displayVector(result);

    return 0;
}