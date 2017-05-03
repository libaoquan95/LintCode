#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ6ÕÂ-53-·­×ª×Ö·û´®
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string word, line;
        int size=s.size();
        int i=size-1, j, begin=size-1, end=size-1;

        if(s.empty())
            return string();

        while(i >= 0)
        {
            while(s[i]==' ' && i>=0)
            {
                begin--;
                end--;
                i--;
            }
            while(s[i]!=' ' && i>=0)
            {
                begin--;
                i--;
            }
            word.resize(0);
            for(j=begin+1; j<=end; j++)
            {
                word.append(1, s[j]);
            }
            if(begin == 0)
                line = line + word;
            else
                line = line + word + " ";
            end = begin;
        }
        return line;
    }
   /* string reverseWords2(string s) {
        // write your code here
        string word, line;
        int i=0, j, size=s.size(), low=0, high=0, end=0;

        if(s.empty())
            return string();

        while(i < size)
        {
            while(s[i] == ' ' && i < size)
            {
                low++;
                high++;
                i++;
            }
            while(s[i] != ' ' && i < size)
            {
                high++;
                i++;
            }
            word.resize(0);
            for(j=high-1; j>=low; j--)
            {
                word.append(1, s[j]);
            }
            if(high == size)
                line = line + word;
            else
                line = line + word + " ";
            low = high;
        }
        return line;
    }*/
};

int main()
{
    Solution s;

    string str = " a bcd c  ";

    cout<<str<<";"<<endl;
    cout<<s.reverseWords(str)<<";"<<endl;
    
    return 0;
}