#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ4ÕÂ-374-ÂÝÐý¾ØÕó
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        // Write your code here
        vector<int> order;;
        int tlx,tly,brx,bry;
        int i,j;

        if(matrix.size() == 0)
            return order;
        tlx = tly = 0;
        brx = matrix[0].size();
        bry = matrix.size();

        if(brx >= bry)
        {
            for(j=0; j<matrix.size()/2; j++)
            {
                for(i=tlx; i<brx; i++)
                {
                    order.push_back(matrix[tlx][i]);
                }
                for(i=tly+1; i<bry; i++)
                {
                    order.push_back(matrix[i][brx-1]);
                }
                for(i=brx-2; i>=tlx; i--)
                {
                    order.push_back(matrix[bry-1][i]);
                }
                for(i=bry-2; i>=tly+1; i--)
                {
                    order.push_back(matrix[i][tlx]);
                }
                tlx++;tly++; brx--;bry--;
            }
            if(matrix.size()%2 == 1)
            {
                for(i=tlx; i<brx; i++)
                {
                    order.push_back(matrix[tlx][i]);
                }
            }
        }
        else
        {
            for(j=0; j<matrix[0].size()/2; j++)
            {
                for(i=tlx; i<brx; i++)
                {
                    order.push_back(matrix[tlx][i]);
                }
                for(i=tly+1; i<bry; i++)
                {
                    order.push_back(matrix[i][brx-1]);
                }
                for(i=brx-2; i>=tlx; i--)
                {
                    order.push_back(matrix[bry-1][i]);
                }
                for(i=bry-2; i>=tly+1; i--)
                {
                    order.push_back(matrix[i][tlx]);
                }
                tlx++;tly++; brx--;bry--;
            }
            if(matrix[0].size() %2 == 1)
            {
                for(i=tly; i<bry; i++)
                {
                    order.push_back(matrix[i][brx-1]);
                }
            }
        }
        return order;
    }
};

int main()
{
    Solution s;
    vector<int> line, order;
    vector< vector<int> > matrix;
    vector< vector<int> > ::iterator it2;
    vector<int>::iterator it;
    int row=5,col=4;

    for(int i=0; i<row; i++)
    {
        line.clear();
        for(int j=0; j<col; j++)
        {
            line.push_back(i*row+j+10);
        }
        matrix.push_back(line);
    }

    for(it2=matrix.begin(); it2!=matrix.end();it2++)
    {
        for(it=it2->begin(); it!=it2->end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }


    order = s.spiralOrder(matrix);

    /**/cout<<endl;
    for(it=order.begin(); it!=order.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}