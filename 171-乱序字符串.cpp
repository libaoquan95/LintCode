#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/anagrams/-171-�����ַ���
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        int size = strs.size(), i = 0;
        if (size <= 0) {
            return vector<string>();
        }

        vector<string> result;
        map<string, int> hash;
        for (i = 0; i < size; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            hash[temp]++;
        }
        for (i = 0; i < size; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (hash[temp] > 1) {
                result.push_back(strs[i]);
            }
        }
        return result;
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

    vector<string> nums;
    nums.push_back("lint");
    nums.push_back("intl");
    nums.push_back("inlt");
    nums.push_back("code");

    s.display(nums);
    s.display(s.anagrams(nums));
    return 0;
}