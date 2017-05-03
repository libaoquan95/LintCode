#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-��5��-381-�������� II
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int> > generateMatrix(int n) {
        // Write your code here
        if(n <= 0 )
        {
            vector<vector<int> > matrix;
            return matrix;
        }

        vector<int> line(n);
        vector<vector<int> > matrix(n, line);
        int i,j,inc=1;
        int cirCount = (n+1)/2;

        //  ��iȦ
        for(i=0; i<cirCount; i++)
        {
            //  ��������
            for(j=i; j<n-i-1;j++)
            {
                matrix[i][j] = inc++;
            }
            //  ��������
            for(j=i; j<n-i-1;j++)
            {
                matrix[j][n-i-1] = inc++;
            }
            //  ��������
            for(j=i; j<n-i-1;j++)
            {
                matrix[n-i-1][n-j-1] = inc++;
            }
            //  ��������
            for(j=i; j<n-i-1;j++)
            {
                matrix[n-j-1][i] = inc++;
            }
        }
        if(n%2 == 1)
            matrix[n/2][n/2] = inc;

        return matrix;
    }
}; 

int main()
{
    Solution s;
    vector< vector<int> > matrix;
    vector< vector<int> > ::iterator it2;
    vector<int>::iterator it;

    matrix = s.generateMatrix(3);

    for(it2=matrix.begin(); it2!=matrix.end();it2++)
    {
        for(it=it2->begin(); it!=it2->end();it++)
            cout<<*it<<"\t";
        cout<<endl<<endl;
    }

    return 0;
}