#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/interleaving-positive-and-negative-numbers-144-交错正负数
     *@param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int size = A.size();
        if(size <= 0) {
            return ;
        }

        int p1 = 0, p2 = size - 1;
        while(p1 < p2) {
            if(A[p1] < 0) {
                swap(A[p1], A[p2]);
                p2--;
            }
            else {
                p1++;
            }
        }
       
        if (size % 2 == 0) {
            p1 = 1;
            p2 = size - 2;
        }
        else if(A[size/2]>0){
            p1 = 1;
            p2 = size - 1;
        }
        else{
            p1 = 0;
            p2 = size - 2;
        }
        while (p1 < p2) {
            swap(A[p1], A[p2]);
            p1 = p1 + 2;
            p2 = p2 - 2;
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

    int A[] = {28,2,-22,-27,2,9,-33,-4,-18,26,25,34,-35,-17,2,-2,32,35,-8};
    vector<int> nums(&A[0], &A[19]);
    /*nums.push_back(4);
    nums.push_back(6);
    nums.push_back(-1);
    nums.push_back(5);
    nums.push_back(-3);
    nums.push_back(-2);*/

    s.display(nums);
    s.rerange(nums);
    s.display(nums);

    return 0;
}