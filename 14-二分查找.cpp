#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/first-position-of-target/-14-¶þ·Ö²éÕÒ
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int size = array.size();
        int low = 0, high = size-1, mid = (high + low) / 2;
        int find = -1;

        if(array[low]>target || array[high]<target){  
            return -1;  
        }

        while(low <= high) {
            if(array[mid] == target) {
                find = mid;
                break;
            }
            else if(array[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;

            mid = (high + low) / 2;
        }

        while(find > 0) {
            if(array[find-1] == target)
                find--;
            else
                break;
        }

        return find;
    }
};

int main()
{
    Solution s;

    vector<int> order;
    order.push_back(1);
    order.push_back(2);
    order.push_back(3);
    order.push_back(3);
    order.push_back(4);
    order.push_back(5);
    order.push_back(10);

    cout<<s.binarySearch(order, 3)<<endl;
    cout<<s.binarySearch(order, 8)<<endl;

    return 0;
}