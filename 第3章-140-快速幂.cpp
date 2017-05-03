#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ3ÕÂ-140-¿ìËÙÃİ
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n==0)  
            return 1%b;  
        if(n==1)  
            return a%b;  
        long long temp = fastPower(a,b,n/2);  
        if(n&1)  
            return ((temp*temp)%b)*a%b;  
        else  
            return temp*temp%b;  
    }
};

int main()
{
    Solution s;

    return 0;
}