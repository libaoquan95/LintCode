#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第3章-371-用递归打印数字
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> result;
        if(n <= 0)
            return result;
        
        return result;
    }


    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-打印数字
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion_while(int n) {
        // write your code here
        vector<int> result;
        if(n <= 0)
            return result;

        int *iNum = new int[n];
        for(int i=0; i<n; i++)
        {
            iNum[i] = 0;
        }

        while(increatment(iNum, n))
        {
            result.push_back(toInt(iNum, n));
        }
        delete []iNum;
        return result;
    }
    int increatment(int iNum[], int length)
    {
        int mark=0,i;

        for(i=length-1; i>=0; i--)
        {
            if(++iNum[i] == 10)
            {
                iNum[i] = 0;
            }
            else 
                break;
        }

        for(i=0; i<length; i++)
        {
            mark = mark || iNum[i];
        }

        if(mark == 0)
            return 0;
        else
            return 1;
    }
    int toInt(const int iNum[], int length)
    {
        int mark=0;
        int result=0;
        for(int i=0; i<length; i++)
        {
            result = result * 10 + iNum[i];
        }
        return result;
    }
    void display(const int iNum[], int length)
    {
        int mark=0;
        for(int i=0; i<length; i++)
        {
            if(iNum[i] != 0)
            {
                mark = 1;
                cout<<iNum[i];
            }
            else
            {
                if(mark == 1)
                    cout<<iNum[i];
            }
        }
        if(mark == 0 && iNum[length-1] == 0)
            cout<<iNum[length-1];
        cout<<endl;
    }
};

int main()
{
    Solution s;
    vector<int> vec = s.numbersByRecursion_while(2);
    vector<int>::iterator it;

    for(it=vec.begin();it!=vec.end();it++)
        cout<<*it<<endl;

    return 0;
}