#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/word-search/-123-µ¥´ÊËÑË÷
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int sizeRow = board.size(), sizeStr = word.size();
        if(sizeRow <= 0 || sizeStr <= 0) {
            return false;
        }

        int sizeCol = board[0].size(), i = 0, j = 0;
        stack<pair<int, int> > path;

        for(i=0; i<sizeRow; i++) {
            for(j=0; j<sizeCol; j++) {
                if(board[i][j] == word[0]) {
                    bool isFind = DFSFind(board, word, i, j, 0);
                    if(isFind) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool DFSFind(vector<vector<char> > &board, string word, int i, int j, int wordStart) {
        if(wordStart == word.size()) {
            return true;
        }
        else if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || 
                board[i][j]!=word[wordStart])
        {
            return false;
        } 

        board[i][j] ^= 255;
        bool result = (DFSFind(board, word, i-1, j,   wordStart+1) 
                    || DFSFind(board, word, i,   j-1, wordStart+1) 
                    || DFSFind(board, word, i+1, j,   wordStart+1) 
                    || DFSFind(board, word, i,   j+1, wordStart+1));

        board[i][j] ^= 255;
        return result;
    }

    void display(string s) {
        for(int i=0; i<s.size(); i++) {
            cout<<s[i];
        }
        cout<<endl;
    }

    void display(vector< vector<char> > &matrix) {
        vector< vector<char> >::iterator i;
        vector<char>::iterator j;

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
    vector<vector<char> > board(3, vector<char>(4, '0'));
    board[0][0]='A'; board[0][1]='B'; board[0][2]='C'; board[0][3]='E';
    board[1][0]='S'; board[1][1]='F'; board[1][2]='C'; board[1][3]='S';
    board[2][0]='A'; board[2][1]='D'; board[2][2]='E'; board[2][3]='E';
    s.display(board);
    
    cout<<s.exist(board, "ABCCED")<<endl;
    
    return 0;
}