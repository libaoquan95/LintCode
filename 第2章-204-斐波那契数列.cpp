#include <iostream>
using namespace std;

class Solution{
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第2章-204-斐波那契数列
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) 
    {
        int f1 = 0, f2 = 1, f3 = 0;
        if(n > 0)
        {
            if (n == 1) 
                   return f1;
            else if (n == 2) 
                   return f2;
            else
            {
                for(int i=2; i<n; i++)
                {
                    f3 = f1 + f2;
                    f1 = f2;
                    f2 = f3;
                }
                return f3;
            }
        }
    }
};

int main()
{
    Solution s;

    cout<<s.fibonacci(10)<<endl;

    return 0;
}