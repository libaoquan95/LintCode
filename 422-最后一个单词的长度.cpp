#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/length-of-last-word/-422-最后一个单词的长度
     * 
     * @param s: A string
     * @return: the length of last word
     */
    int lengthOfLastWord(string s) {
        // write your code here
        int size = s.size();
        if (size <= 0) {
            return 0;
        }
        int length = 0, flag = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                length++;
                flag = 1;
            }
            else if(s[i] == ' ' && flag == 1){
                break;
            }
        }
        return length;
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }

    void display(vector<string> &nums) {
        vector<string>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            display(*i);
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    cout << s.lengthOfLastWord("Hello World ") << endl;
    return 0;
}