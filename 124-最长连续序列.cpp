#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/longest-consecutive-sequence/-124-最长连续序列
     * @ param nums: A list of integers
     * @ return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        int size = num.size(),result = 0;
        if(size <= 0) {
            return 0;
        }
        
        set<int> s(num.begin(), num.end());

        for (int i=0; i<size; i++) {
            if(!s.count(num[i])) {
                continue;
            }
            s.erase(num[i]);
            int pre = num[i] - 1, next = num[i] + 1;
            while(s.count(pre)) {
                s.erase(pre--);
            }
            while(s.count(next)) {
                s.erase(next++);
            }
            result = result > next-pre-1 ? result : next-pre-1;
        }
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
        for(i=matrix.begin(); i!=matrix.end(); i++) {
            for(j=i->begin(); j!=i->end(); j++) {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    Solution s;
    
    vector<int> nums;
    nums.push_back(100);
    nums.push_back(4);
    nums.push_back(200);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);

    cout<<s.longestConsecutive(nums)<<endl;
    
    return 0;
}