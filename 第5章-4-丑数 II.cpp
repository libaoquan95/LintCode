#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-ตฺ5ีย-4-ณ๓สý II
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        if(n <= 0)
            return 0;
        int *pivUglyNum = new int[n];
        int *piMul2=pivUglyNum, *piMul3=pivUglyNum, *piMul5=pivUglyNum;
        int nextNumIndex = 1;

        pivUglyNum[0] = 1;
        while(nextNumIndex < n)
        {
            int min = minIn3Num(*piMul2 * 2, *piMul3 * 3, *piMul5 * 5);
            pivUglyNum[nextNumIndex] = min;

            while(*piMul2 * 2 <= pivUglyNum[nextNumIndex])
                piMul2++;
            while(*piMul3 * 3 <= pivUglyNum[nextNumIndex])
                piMul3++;
            while(*piMul5 * 5 <= pivUglyNum[nextNumIndex])
                piMul5++;

            nextNumIndex++;
        }
        int uglyNum = pivUglyNum[nextNumIndex-1];
        delete[] pivUglyNum;
        return uglyNum;
    }

    int minIn3Num(int num1, int num2, int num3)
    {
        int min = (num1 < num2) ? num1 : num2;
        min = (min < num3) ? min : num3;
        return min;
    }
}; 

int main()
{
    Solution s;

    cout<<s.nthUglyNumber(9)<<endl;

    return 0;
}