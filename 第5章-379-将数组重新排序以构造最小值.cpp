#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第5章-379-将数组重新排序以构造最小值
     * @param nums n non-negative integer array
     * @return a string
     */
    void transferToString(string &result,int number){  
        if(number<10)
        {  
            result+=('0'+number);  
            return;  
        }  
        int temp=number%10;  
        transferToString(result,number/10);  
        result+=('0'+temp);  
    }

    bool compare(int num1,int num2){  
        string com1,com2;

        if(num1==0)  
            com1+=('0'+num1%10);
        
        while(num1)
        {  
            com1+=('0'+num1%10);  
            num1/=10;  
        }   
        if(num2==0)  
            com2+=('0'+num2%10);
        
        while(num2)
        {  
            com2+=('0'+num2%10);  
            num2/=10;  
        }

        int len1=com1.size(),len2=com2.size();  

        int i,j;  
        for(i=len1-1,j=len2-1;i>=0&&j>=0;i--,j--)
        {  
            if(com1[i]>com2[j])  
                return true;  
            else if(com1[i]<com2[j])  
                return false;  
        }  
        if(i==-1&&j==-1)  
            return false;  
        if(i==-1)
        {  
            while(j>=0)
            {  
                if(com2[j]<com2[j+1])  
                    return true;  
                else if(com2[j]>com2[j+1])  
                    return false;  
                else  
                    j--;  
            }  
            return false;  
        }  
        else
        {  
            while(i>=0)
            {  
                if(com1[i]<com1[i+1])  
                    return false;  
                else if(com2[i]>com2[i+1])  
                    return true;  
                else  
               i--;  
            }  
            return false;  
        }  
    }

    string minNumber(vector<int>& nums) {  
        // Write your code here  
        string result;  
        if(nums.empty())  
            return result;  
        int n=nums.size();
        int i;
        for(i=0;i<n;i++)
        {  
            for(int j=0;j<n-i-1;j++)
            {  
                if(compare(nums[j],nums[j+1]))
                {  
                    int temp=nums[j];  
                    nums[j]=nums[j+1];  
                    nums[j+1]=temp;  
                }  
            }  
              
        }  
        for(i=0;i<nums.size();i++)
        {
            if(result.empty()&&nums[i]==0)  
                continue;  
            else  
                transferToString(result,nums[i]);

        }
        if(result.empty())  
            result+='0';  
        return result;  
    }  
};

int main()
{
    Solution s;

    //s.minNumber();

    return 0;
}