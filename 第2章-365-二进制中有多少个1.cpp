#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第2章-365-二进制中有多少个1
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int num_bit[32]={0};
        int one_count = 0;
        int i,num2 = num;
        //  负数转正，符号位变1
        if(num < 0)
        {
            num = num * -1;
            num_bit[31] = 1;
        }
        //  十进制转二进制
        for(i=0; num; i++)
        {
            num_bit[i] = num%2;
            num /= 2;
        }
        //  负数原码转补码
        if(num2 < 0)
        {
            for(i=30; i>=0; i--)
            {
                if(num_bit[i] == 1)
                    break;
                num_bit[i] = 1;
            }
        }
        for(i=0; i<32; i++)
        {
            if(num_bit[i] == 1)
                one_count++;
        }
        return one_count;
    }
};

int main()
{
    Solution s;
    cout<<s.countOnes(32)<<endl;
    cout<<s.countOnes(5)<<endl;
    cout<<s.countOnes(1023)<<endl;
    cout<<s.countOnes(-1)<<endl;

    return 0;
}