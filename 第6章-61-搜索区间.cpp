#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ6ÕÂ-61-ËÑË÷Çø¼ä
     * @param A : an integer sorted array
     * @param target :  an integer to be inserted
     * return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> result;
        int size = A.size()-1;
        if(A.empty())
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        else
        {
            result.push_back(getFirstTarget(A, target, 0, size));
            result.push_back(getLastTarget(A, target, 0, size));
        }
        return result;
    }

    int getFirstTarget(vector<int> &A, int target, int low, int high) {
        if(low > high)
            return -1;
        int mid = (low+high)/2;
        if(A[mid] == target)
        {
            if((mid>0 && A[mid-1]!=target) || mid==0)
                return mid;
            else
                high = mid-1;
        }
        else if(A[mid] > target)
            high = mid-1;
        else
            low = mid+1;

        return getFirstTarget(A, target, low, high);
    }

    int getLastTarget(vector<int> &A, int target, int low, int high) {
        int size = A.size()-1;
        if(low > high)
            return -1;
        int mid = (low+high)/2;
        if(A[mid] == target)
        {
            if((mid<size && A[mid+1]!=target) || mid==size)
                return mid;
            else
                low = mid+1;
        }
        else if(A[mid] > target)
            high = mid-1;
        else
            low = mid+1;

        return getLastTarget(A, target, low, high);
    }
};

int main()
{
    Solution s;
    int iarray[]={1,3,5,6,8,9};
    int count=sizeof(iarray)/sizeof(int);
    vector<int> order(iarray,iarray+count);

    vector<int> result = s.searchRange(order, 7);

    cout<<result[0]<<","<<result[1]<<endl;

    return 0;
}