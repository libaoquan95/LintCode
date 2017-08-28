#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/n-queens//-33-N皇后问题
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        if(n == 1) {
            vector<vector<string> > result;
            vector<string> strOneRow;
            strOneRow.push_back("Q");
            result.push_back(strOneRow);
            return result;
        }
        else if(n < 4) {
            return vector<vector<string> > ();
        }

        vector<vector<string> > result;
        int i=0, row=0, col=0, j=0, k=0;
        int *pCheckerboard = new int[n];
        for(i=0; i<n; i++) {
            pCheckerboard[i] = -1;
        }

        while(row < n) {
            while(col < n) {
                if(canPlace(row, col, n, pCheckerboard)) {
                    pCheckerboard[row] = col;
                    col = 0;
                    break;
                }
                else {
                    col++;
                }
            }

            if(pCheckerboard[row] == -1) {
                if(row == 0) {
                    break;
                }
                else {
                    row--;
                    col = pCheckerboard[row] + 1;
                    pCheckerboard[row] = -1;
                    continue;
                }
            }

            if(row == n-1) {
                vector<string> strOneRow;
                for(k=0; k<n; k++) {
                    string str;
                    for(j=0; j<n; j++) {
                        str += '.';
                    }
                    if(pCheckerboard[k]>=0 && pCheckerboard[k]<n) {
                        str[pCheckerboard[k]] = 'Q';
                    }
                    strOneRow.push_back(str);

                }
                result.push_back(strOneRow);
                
                col = pCheckerboard[row] + 1;
                pCheckerboard[row] = -1;
                continue;
            }
            row++;
        }
        delete[] pCheckerboard;
        return result;
    }

    /////////////////////////////////////////////////////////////////////////
    ////////////////////////////   Recursively   ////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    vector<vector<string> > solveNQueensRecursively(int n) {
        // write your code here
        if(n == 1) {
            vector<vector<string> > result;
            vector<string> strOneRow;
            strOneRow.push_back("Q");
            result.push_back(strOneRow);
            return result;
        }
        else if(n < 4) {
            return vector<vector<string> > ();
        }

        vector<vector<string> > result;
        int i;

        int *pCheckerboard = new int[n];
        for(i=0; i<n; i++) {
            pCheckerboard[i] = -1;
        }

        queensRecursively(0, n, pCheckerboard, result);

        delete[] pCheckerboard;
        return result;
    }

    void queensRecursively(int row, int n, int *pCheckerboard, vector<vector<string> > &result) {
        int i = 0, j = 0;
        if(n == row) {
            vector<string> strOneRow;
            for(i=0; i<n; i++) {
                string str;
                for(j=0; j<n; j++) {
                    str += '.';
                }
                if(pCheckerboard[i]>=0 && pCheckerboard[i]<n) {
                    str[pCheckerboard[i]] = 'Q';
                }
                strOneRow.push_back(str);

            }
            result.push_back(strOneRow);
        }
        else {
            for(i=0; i<n; i++) {
                if(canPlace(row, i, n, pCheckerboard)) {
                    pCheckerboard[row] = i;
                    queensRecursively(row+1, n, pCheckerboard, result);
                }
            }
        }
    }

    int canPlace(int row, int col, int n, int *pCheckerboard) {
        int i;
        for(i=0; i<n && i!=row; i++) {
            if(pCheckerboard[i] == col) {
                return 0;
            }
            if(abs(row-i) == abs(col-pCheckerboard[i])) {
                return 0;
            }
        }
        return 1;
    }
	void display(string s) {
        for(int i=0; i<s.size(); i++) {
            cout<<s[i];
        }
        cout<<endl;
	}
};

int main()
{
    Solution s;
    vector<vector<string> > result = s.solveNQueens(4);

    vector<vector<string> >::iterator it;
    vector<string>::iterator it2;

    for(it=result.begin(); it!=result.end(); it++) {
        cout<<"方案"<<endl;
        for(it2=it->begin(); it2!=it->end(); it2++) {
            for(int i=0; i<it2->size(); i++) {
                cout<<(*it2)[i]<<'\t';
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}