#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ6ÕÂ-8-Ðý×ª×Ö·û´®
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if(str.empty())
            return;

        int off = offset % str.size();
        if(off != 0)
        {
            string suffix(off+1, '\0');
            int i, j, size=str.size();
            for(j=0,i=size-off; i<size; i++,j++)
            {
                suffix[j] = str[i];
            }
            for(i=size-off-1; i>=0; i--)
            {
                str[i+off] = str[i];
            }
            for(i=0; i<off; i++)
            {
                str[i] = suffix[i];
            }
        }
    }
};

int main()
{
    Solution s;

    for(int i=0; i<10; i++)
    {
        string str = "abcdefg";
        s.rotateString(str, i);
        cout<<"rotate "<<i<<": "<<str<<endl;
    }
    
    return 0;
}