#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ2ÕÂ-212-¿Õ¸ñÌæ»»-O(n^2)
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank_n2(char string[], int length) {
        // Write your code here
        for(int i=0; i<length; i++)
        {
            if(string[i] == 32)
            {
                for(int j = length+2; j > i+2; j--)
                {
                    string[j] = string[j-2];
                }
                string[i]   = '%';
                string[i+1] = '2';
                string[i+2] = '0';
                length = length + 2;
            }
        }
        return length;
    }
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ2ÕÂ-212-¿Õ¸ñÌæ»»-O(n)
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank_n(char string[], int length) {
        // Write your code here
        int blank_count = 0;
        int new_length = length;
        int i;
        for(i=0; i<length; i++)
        {
            if(string[i] == 32)
            {
                blank_count++;
                new_length += 2;
            }
        }
        //string[new_length] = '\0';
        for(i=length-1; i>=0; i--)
        {
            if(string[i] != 32)
            {
                string[i+blank_count*2] = string[i];
            }
            else
            {
                string[i]   = '%';
                string[i+1] = '2';
                string[i+2] = '0';
                i+=3;
                blank_count--;
            }
        }
        return new_length;
    }
};

int main()
{
    Solution s;
    char string[100] = "Mr John Smith";
    //char string[100] = "null";
    cout<<string<<endl;
    cout<<s.replaceBlank_n(string, 13)<<endl;
    cout<<string<<endl;

    return 0;
}