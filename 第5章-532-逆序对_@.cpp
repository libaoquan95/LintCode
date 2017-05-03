#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ5ÕÂ-532-ÄæÐò¶Ô
     * @param A an array
     * @return total of reverse pairs
     */
    __int64 reversePairs_n2(vector<int>& A) {
        // Write your code here
        __int64 iCount=0,size=A.size();

        if(size<=0)
            return 0;

        __int64 i,j;

        for(i=0; i<size-1; i++)
        {
            for(j=i+1; j<size; j++)
            {
                if(A[i] > A[j])
                    iCount++;
            }
        }
        return iCount;
    }

    __int64 reversePairs(vector<int>& A) {
        // Write your code here
        __int64 iCount=0,size=A.size();
        __int64 i;

        if(size<=0)
            return 0;

        vector<int> B(size);
        for(i=0; i<size; i++)
            B[i] = A[i];

        iCount = inversePairsCore(A, B, 0, size-1);

        delete[] &B;

        return iCount;
    }

    __int64 inversePairsCore(vector<int>& A, vector<int>& B, __int64 start, __int64 end)
    {
        if(start == end)
        {
            B[start] = A[start];
            return 0;
        }

        __int64 length = (end-start)/2;

        __int64 left = inversePairsCore(A, B, start, start+length);
        __int64 right = inversePairsCore(A, B, start+length+1, end);

        __int64 i = start+length;
        __int64 j = end;
        __int64 indexB = end;
        __int64 count = 0;

        while(i>=start && j>=start+length+1)
        {
            if(A[i] > A[j])
            {
                B[indexB--] = A[i--];
                count += j-start-length;
            }
            else
            {
                B[indexB--] = A[j--];
            }
        }

        for(;i>=start;i--)
        {
            B[indexB--] = A[i];
        }
        for(;j>=start+length+1;j--)
        {
            B[indexB--] = A[j];
        }

        return left+right+count;
    }


    long long reversePairs(vector<int>& A) {
        // Write your code here        
        long long res = 0;
        vector<int> v;
        for (int i = A.size() - 1; i >= 0; --i) {
            int left = 0, right = v.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (A[i] > v[mid]) left = mid + 1;
                else right = mid;
            }
            v.insert(v.begin() + right, A[i]);
            res += right;
        }
        return res;  
    }
}; 

int main()
{
    Solution s;

    return 0;
}