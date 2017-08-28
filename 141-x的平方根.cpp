#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/sqrtx-141-x的平方根
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        int low = 0, high = 46341, mid = 0;

        while(low < high) { 
            if (mid == low + (high-low)/2) {  
                break;  
            } 
            mid = low + (high-low)/2;
            int square = mid * mid;

            if(square == x) {
                return mid;
            }
            else if(x > square){
                low =  mid;
            }
            else {
                high = mid;
            }
        }
        return mid;
    }
};

int main()
{
    Solution s;

    cout<<s.sqrt(65536)<<endl;;

    return 0;
}