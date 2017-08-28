#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/evaluate-reverse-polish-notation/-81-数据流中位数
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size <= 0) {
            return vector<int>();
        }
        // maxSet存的是到目前为止较小的那一半数，minSet存的是到目前为止较大的那一半数
        // maxSet使用反向遍历，达到最大堆效果
        multiset<int> minSet, maxSet;
        vector<int> result;
        bool flag = true;
        for (int i = 0; i < size; i++) {
            int temp = nums[i];
            // minSet与maxSet交替使用，保证两个堆的大小之差不超过1
            if (flag) {
                // 新数大于minSet的堆顶元素时，说明新数在所有数的下半部分
                if (!minSet.empty() && nums[i] > *minSet.begin()) {
                    minSet.insert(nums[i]);
                    temp = *minSet.begin();
                    minSet.erase(minSet.find(temp));
                }
                // 新数小于minSet的堆顶元素时，说明新数在所有数的上半部分
                // 或将原minSet的堆顶元素放在maxSet中
                maxSet.insert(temp);
            }
            else {
                // 新数小于minSet的堆顶元素时，说明新数在所有数的上半部分
                if (!maxSet.empty() && nums[i] < *maxSet.rbegin()) {
                    maxSet.insert(nums[i]);
                    temp = *maxSet.rbegin();
                    maxSet.erase(maxSet.find(temp));
                }
                // 新数大于minSet的堆顶元素时，说明新数在所有数的下半部分
                // 或将原maxSet的堆顶元素放在minSet中
                minSet.insert(temp);
            }
            flag = !flag;
            result.push_back(*maxSet.rbegin());
        }
        return result;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    int A[] = { 4, 5, 1, 3, 2, 6, 0 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(s.medianII(nums));

    return 0;
}