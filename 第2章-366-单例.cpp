#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-��2��-366-����
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() 
    {
        static bool ex = false;
        static Solution* one;
        if (ex == false)
        {
             one = new Solution();
             ex = true;
             return one;
        }
        else
            return one;
    }
};

int main()
{
    Solution s;

    return 0;
}