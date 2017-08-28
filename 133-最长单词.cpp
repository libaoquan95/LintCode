#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/longest-words/-133-×î³¤µ¥´Ê
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int size = dictionary.size(), maxLen = 0;
        if(size <= 0) {
            return vector<string>();
        }

        vector<string> result;
        maxLen = dictionary[0].size();
        result.push_back(dictionary[0]);
        for(int i=1; i<size; i++){
            if(maxLen < dictionary[i].size()) {
                maxLen = dictionary[i].size();
                result.clear();
                result.push_back(dictionary[i]);
            }
            else if(maxLen == dictionary[i].size()) {
                result.push_back(dictionary[i]);
            }
        }

        return result;
    }

    void display(vector<string> &nums) {
        vector<string>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++) {
            display(*i);
        }
        cout<<endl;
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

    vector<string> dictionary;
    dictionary.push_back("dog");
    dictionary.push_back("google");
    dictionary.push_back("facebook");
    dictionary.push_back("internationalization");
    dictionary.push_back("blabla");

    s.display(dictionary);
    cout<<endl;
    s.display(s.longestWords(dictionary));

    return 0;
}