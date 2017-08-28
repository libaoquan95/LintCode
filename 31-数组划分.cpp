#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition of Interval:
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/partition-array/-31-数组划分
     */ 
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int size = nums.size();
        if(size < 1)
            return 0;

        vector<int> temp = nums;
        int  i= 0, index = 0;
        for(i=0; i<size; i++) {
            if(nums[i] < k) {
                index++;
            }
        }

        int low = 0, high = index;
        for(i=0; i<size; i++) {
            if(temp[i] < k) {
                nums[low] = temp[i];
                low++;
            }
            else {
                nums[high] = temp[i];
                high++;
            }
        }
        return index;
    }

    void displayVector(vector<int> &order) {
        vector<int>::iterator i;
        for(i=order.begin(); i!=order.end(); i++) {
            cout<<(*i)<<",";
        }
        cout<<endl;
    }
	 int partitionArray2(vector<int> &nums, int k) {
        // write your code here
        int size = nums.size();
        if(size < 1)
            return 0;

        int  i= 0, index = 0;
        for(i=0; i<size; i++) {
            if(nums[i] < k) {
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                index++;
            }
        }
        return index;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);

    int index = s.partitionArray(nums, 2);
    s.displayVector(nums);
    cout<<index<<endl;

    return 0;
}