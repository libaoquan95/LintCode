#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ6ÕÂ-1-A + B ÎÊÌâ
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int result=0,num=0;

        do
        {
            result = a ^ b;
            num = (a & b) << 1;
            a = result;
            b = num;
        }
        while(b != 0);

        return result;
    }
};

int main()
{
    Solution s;

    cout<<s.aplusb(1, 2)<<endl;
    
    return 0;
}