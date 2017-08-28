#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/single-number-ii-83-Âäµ¥µÄÊı II
     * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int bits[32] = {0};
        int size = A.size(), i = 0, j = 0, result = 0;

        if(size <= 0) {
            return 0;
        }
        for(i=0; i<32; i++) {
            for(j=0; j<size; j++) {
                bits[i] += A[j]>>i & 0x00000001;
            }
            bits[i] = bits[i] % 3;

            result = result | bits[i] << i;
        }
        return result;
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
    nums.push_back(8);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(4);

    s.displayVector(nums);
    cout<<s.singleNumberII(nums)<<endl;

    return 0;
}