#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第7章-54-转换字符串到整数
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        str = eraseSpace(str);
        int size=str.size();

        if(size <= 0)
            return 0;

        if(str[0]<='9' && str[0]>='0')
        {
            int num=str[0]-'0', i, dec=str[0]-'0';
            for(i=1; i<size; i++)
            {
                if(str[i]<='9' && str[i]>='0')
                {
                    dec = num;
                    num = num * 10;
                    if(isCrossBorder(num, dec))
                        return 2147483647;

                    dec = num;
                    num += str[i]-'0';
                    if(isCrossBorder(num, dec))
                        return 2147483647;
                }
                else
                {
                    return num;
                }
            }
            return num;
        }
        else if(str[0] == '+')
        {
            int num=0, i, dec=0;
            for(i=1; i<size; i++)
            {
                if(str[i]<='9' && str[i]>='0')
                {
                    dec = num;
                    num = num * 10;
                    if(isCrossBorder(num, dec))
                        return 2147483647;

                    dec = num;
                    num += str[i]-'0';
                    if(isCrossBorder(num, dec))
                        return 2147483647;
                }
                else
                {
                    return num;
                }
            }
            return num;
        }
        else if(str[0] == '-')
        {
            int num=0, i, dec=0;
            for(i=1; i<size; i++)
            {
                if(str[i]<='9' && str[i]>='0')
                {
                    dec = num;
                    num = num * 10;
                    if(isCrossBorder(num, dec))
                        return -2147483648;

                    dec = num;
                    num += str[i]-'0';
                    if(isCrossBorder(num, dec))
                        return -2147483648;
                }
                else
                {
                    return num*-1;
                }
            }
            return num*-1;
        }
        else
        {
            return 0;
        }
    }

    bool isCrossBorder(int num1, int num2) {
        if(num1 < num2)
            return true;
        return false;
    }

    string eraseSpace(string str) {
        int size=str.size(),i=0,mark=0;
        string result;

        for(i=0; i<size; i++)
        {
            if(str[i]==' ' && mark==0)
            {
                continue;
            }
            else if(str[i]!=' ' && mark==0)
            {
                mark = 1;
                result += str[i];
            }
            else if(str[i]!=' ' && mark==1)
            {
                result += str[i];
            }
            else if(str[i]==' ' && mark==1)
            {
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;

    cout<<s.atoi(" 15+4")<<endl;
    cout<<s.atoi("+123")<<endl;
    cout<<s.atoi("-123")<<endl;
    cout<<s.atoi("123123123123123")<<endl;

    return 0;
}