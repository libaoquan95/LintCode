#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/powx-n/-x的n次幂
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        double pow = 1;
        int i;

        if(isDoubleEqule(x, 0.0))   //  底数为0
        {
            pow = 0.0;
        }
        else                        //  底数不为0
        {
            if(n == 0)     //  指数为0
            {
                pow = 1;
            }
            else if(n > 0) //  指数大于0
            {
                pow = getAbsPow_nlgn(x, n);
            }
            else           //  指数小于0
            {
                pow = getAbsPow_nlgn(x, n*-1);
                pow = 1.0 / pow;
            }
        }
        return pow;
    }
    int isDoubleEqule(double num1, double num2) {
        if(num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001)
            return 1;
        else
            return 0;
    }
    double getAbsPow(double x, int n) {
        double pow = 1.0;
        int i;
        for(i=0; i<n; i++)
        {
            pow *= x;
        }
        return pow;
    }
    double getAbsPow_nlgn(double x, int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;

        double pow = getAbsPow_nlgn(x, n>>1);
        pow *= pow;

        if(n & 0x1 == 1)
            pow *= x;
        return pow;
    }
};

int main()
{
    Solution s;

    cout<<"2^3="<<s.myPow(2, 3)<<endl;
    cout<<"2.5^2="<<s.myPow(2.5, 2)<<endl;
    cout<<"2^100="<<s.myPow(2, 100)<<endl;
    cout<<"2^0="<<s.myPow(2, 0)<<endl;
    cout<<"2^-1="<<s.myPow(2, -1)<<endl;
    cout<<"2^-100="<<s.myPow(2, -100)<<endl;

    return 0;
}