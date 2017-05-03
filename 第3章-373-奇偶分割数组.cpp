#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-��3��-373-��ż�ָ�����
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        int begin=0, end=size-1;

        while(begin < end)
        {
            while((nums[begin] & 1)==1)    //  ָ������
            {
                begin++;
            }
            while((nums[end] & 1)==0)    //  ָ��ż��
            {
                end--;
            }

            if(begin < end)
            {
                int temp = nums[begin];
                nums[begin] = nums[end];
                nums[end] = temp;
            }
        }
    }
    void partitionArray_0(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        for(int i=0; i<size; i++)
        {
            if(!(nums[i]&0x1))      //  ��ż��
            {
                for(int j=i; j<size-1; j++)
                {
                    nums[j] = nums[j+1];
                }
               nums[size-1] = nums[i];
            }
        }
    }
    void display(vector<int> nums)
    {
        vector<int>::iterator it;

        for(it=nums.begin();it!=nums.end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
};

int main()
{
    Solution s;
    vector<int> nums;

    for(int i=0; i<20; i++)
        nums.push_back(i);

    s.display(nums);
    s.partitionArray(nums);
    s.display(nums);

    nums.clear();
    for(i=0; i<20; i++)
        nums.push_back(i);

    s.display(nums);
    s.partitionArray_0(nums);
    s.display(nums);

    return 0;
}