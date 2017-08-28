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
    * http://www.lintcode.com/zh-cn/problem/cosine-similarity/-445-余弦相似度
    * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size();
        if (sizeA != sizeB) {
            return 0;
        }
        long long AB = 0, A2 = 0, B2 = 0;
        for (int i = 0; i < sizeA; i++) {
            AB += A[i] * B[i];
            A2 += A[i] * A[i];
            B2 += B[i] * B[i];
        }
        if (A2 != 0 && B2 != 0) {
            return (double)(AB / sqrt(A2) / sqrt(B2));
        }
        else {
            return (double)2;
        }
    }
};

int main()
{
    Solution s;
    int A[] = { 1,2,3 };
    //int A[] = { 0};
    vector<int> nums1(&A[0], &A[sizeof(A) / sizeof(int)]);

    int B[] = { 2,3,4 };
    //int B[] = { 0 };
    vector<int> nums2(&B[0], &B[sizeof(B) / sizeof(int)]);

    cout << s.cosineSimilarity(nums1, nums2) << endl;

    return 0;
}