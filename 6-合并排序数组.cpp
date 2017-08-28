#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/merge-two-sorted-arrays/-6-合并排序数组
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int sizeA=A.size(), sizeB=B.size();
        int i=0, j=0;

        if(sizeA == 0)
            return B;
        else if(sizeB == 0)
            return A;

        vector<int> result;

        while(i<sizeA && j<sizeB) {
            if(A[i] < B[j]) {
                result.push_back(A[i]);
                i++;
            }
            else if(A[i] > B[j]) {
                result.push_back(B[j]);
                j++;
            }
            else {
                result.push_back(A[i]);
                i++;
                result.push_back(B[j]);
                j++;
            }
        }

        while(i<sizeA) {
            result.push_back(A[i]);
            i++;
        }
        while(j<sizeB) {
            result.push_back(B[j]);
            j++;
        }
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> A;
    A.push_back(1);A.push_back(2);A.push_back(3);A.push_back(4);
    vector<int> B;
    B.push_back(2);B.push_back(4);B.push_back(5);B.push_back(6);

    
    vector<int> order;
    order = s.mergeSortedArray(A, B);

    vector<int>::iterator i;
    for(i=order.begin(); i!=order.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    return 0;
}
