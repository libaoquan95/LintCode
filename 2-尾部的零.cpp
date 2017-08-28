#include <iostream>
using namespace std;
 
class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/trailing-zeros/-2-Î²²¿µÄÁã
     * @param n : description of n 
     * @return: description of return
     * @cankao: http://m.blog.csdn.net/article/details?id=51168272
     */
    long long trailingZeros(long long n) {
        
        long long count = 0, temp = n/5;

        while(temp != 0 ) {
            count += temp;
            temp /= 5;
        }
        return count;
    }
};

int main()
{
    Solution s;

    cout<<s.trailingZeros(11)<<endl;
    cout<<s.trailingZeros(5555550000000)<<endl;

    return 0;
}
