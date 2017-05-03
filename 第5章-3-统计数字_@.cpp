#include <iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-��5��-3-ͳ������
     * @param k: As description.
     * @param n: As description.
     * @return : How many k's between 0 and n
     * @��ĳһλ������С��iʱ����ô��λ����i�Ĵ���Ϊ������λ����x��ǰλ��
     * @��ĳһλ�����ֵ���iʱ����ô��λ����i�Ĵ���Ϊ������λ����x��ǰλ��+��λ����+1
     * @��ĳһλ�����ִ���iʱ����ô��λ����i�Ĵ���Ϊ��(����λ����+1)x��ǰλ��.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int res = 0;  
        int base = 1;

        if(n==0 && k==0)
            return 1; 
        
        while(n/base>0)
        {  
            int curBit = (n/base)%10;  
            int low = n - (n/base)*base;  
            int high = n/(base*10); 
            
            if (curBit < k) 
            {  
                res += high*base;                         
            }
            else if (curBit == k)
            {  
                res += high*base+low+1;  
            }
            else
            {  
                if(!(k==0 && high==0))
                {  
                    res += (high+1)*base;  
                }  
            }  
            base *= 10;  
        }  
        return res;
    }
};

int main()
{
    Solution s;

    cout<<s.digitCounts(1, 12)<<endl;
    return 0;
}