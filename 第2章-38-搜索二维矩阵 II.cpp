#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第2章-38-搜索二维矩阵 II
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector< vector<int> > &matrix, int target) {
        // 39ms
        int row_count = matrix.size();      //  行数
        int col_count = 0;                  //  列数
        if(row_count != 0)
            col_count = matrix[0].size();
        int tar_count = 0,i,j;

        for(j=col_count-1; j>=0 && row_count!=0 && col_count!=0; j--)
        {
            int temp = matrix[0][j];
            if(matrix[0][j] == target)
            {
                tar_count++;
            }
            else if(matrix[0][j] < target)
            {
                for(i=1; i<row_count; i++)
                {
                    int temp2 = matrix[i][j];
                    if(matrix[i][j] == target)
                    {
                        tar_count++;
                        break;
                    }
                }
            }
        }
        return tar_count;
    }

    int searchMatrix_1(vector<vector<int> > &matrix, int target) {
        // 36ms
        int row_count = matrix.size();      //  行数
        int col_count = 0;                  //  列数
        if(row_count != 0)
            col_count = matrix[0].size();
        int tar_count = 0,i,j;

        for(i=0; i<row_count && row_count!=0 && col_count!=0; i++)
        {
            for(j=0; j<col_count; j++)
            {
                if(matrix[i][j] == target)
                    tar_count++;
                if(matrix[i][j] > target)
                    break;
            }
        }

        return tar_count;
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
    vector< vector<int> > matrix;
    vector<int> i;
    i.push_back(1);i.push_back(3);i.push_back(5);i.push_back(7);
    matrix.push_back(i);
    i.clear();
    i.push_back(2);i.push_back(4);i.push_back(7);i.push_back(8);
    matrix.push_back(i);
    i.clear();
    i.push_back(3);i.push_back(5);i.push_back(9);i.push_back(10);
    matrix.push_back(i);
  
    //s.display(matrix);
    cout<<s.searchMatrix(matrix, 3)<<endl;

    return 0;
}