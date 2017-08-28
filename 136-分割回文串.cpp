#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/palindrome-partitioning/-136-·Ö¸î»ØÎÄ´®
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string> > partition(string s) {
        // write your code here
        int size = s.size();
        if(size <= 0) {
            return vector<vector<string> >();
        }
        vector<vector<string> > result;
        vector<string> temp;

        partition(s, 0, temp, result);

        return result;
    }

    void partition(string s, int current, vector<string> &temp, vector<vector<string> > &result) {
        if(current == s.size()){
            result.push_back(temp);
            return;
        }

        for(int i=current; i<s.size(); i++) {
            if(isPalindrome(s, current, i)) {
                temp.push_back(s.substr(current,i-current+1));
                partition(s, i+1, temp, result);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int begin, int end) {
        for(int i=begin, j=end; i<j; i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void display(string s) {
        for(int i=0; i<s.size(); i++) {
            cout<<s[i];
        }
        cout<<endl;
	}

    void display(vector< vector<string> > &matrix) {
        vector< vector<string> >::iterator i;
        vector<string>::iterator j;

        for(i=matrix.begin(); i!=matrix.end(); i++)
        {
            for(j=i->begin(); j!=i->end(); j++)
            {
                display(*j);
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution s;

    string str("aab");
    s.display(s.partition(str));

    return 0;
}