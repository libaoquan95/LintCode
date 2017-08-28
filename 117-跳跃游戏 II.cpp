#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/jump-game-ii/-117-ÌøÔ¾ÓÎÏ· II
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int size = A.size();

        if(size <= 0){
            return 0;
        }
        int farthest = 0, end = 0, minJump = 0;
        for(int i=0; i<size; i++) {
            farthest = (farthest > A[i]+i) ? farthest : A[i]+i;

            if(i == end && end < size-1) {
                minJump++;
                end = farthest;
            }
        }

        return minJump;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++) {
            cout<<*i<<" ";
        }
        cout<<endl;
    }

    void display(vector< vector<int> > &matrix) {
        vector< vector<int> >::iterator i;
        vector<int>::iterator j;

        for(i=matrix.begin(); i!=matrix.end(); i++)
        {
            for(j=i->begin(); j!=i->end(); j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution s;
    
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);

    s.display(nums);
    cout<<s.jump(nums)<<endl;
    
    return 0;
}