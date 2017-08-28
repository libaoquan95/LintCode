#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/sort-colors-ii/-143-ÅÅÑÕÉ« II
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int size = colors.size();
        if(size <= 0) {
            return;
        }

        int index = 0;
        while(index < size) {
            int temp = colors[index] - 1;
            if(colors[index] <= 0){  
                index++;  
            }
            else {
                if(colors[temp] <= 0) {
                    colors[temp]--;
                    colors[index] = 0;
                    index++;
                }
                else {
                    swap(colors[index], colors[temp]);
                    colors[temp] = -1;
                }
            }
        }

        int i = size - 1;  
        while(k > 0) {
            for(int j = 0; j>colors[k-1]; j--) {
                colors[i--] = k;
            }
            k--;
        }
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if(left < right) {
            int i = left, j = right, temp = nums[i];
            while(i < j) {
                while(i < j && nums[j] >= temp) {
                    j--;
                }
                if(i < j) {
                    nums[i] = nums[j];
                    i++;
                }

                while(i < j && nums[i] <= temp) {
                    i++;
                }
                if(i < j) {
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = temp;
            quickSort(nums, left, i-1);
            quickSort(nums, i+1, right);
        }
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++) {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    vector<int> colors;
    colors.push_back(3);
    colors.push_back(2);
    colors.push_back(2);
    colors.push_back(1);
    colors.push_back(4);

    s.display(colors);
    s.sortColors2(colors, 4);
    s.display(colors);

    return 0;
}