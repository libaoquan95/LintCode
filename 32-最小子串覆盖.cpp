#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/minimum-window-substring/-32-×îÐ¡×Ó´®¸²¸Ç
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        int sizeSource = source.size(), sizeTarget = target.size();
        if(sizeSource == 0) {
            return string("");
        }

        int i, countSource[128], countTarget[128];
        for(i=0; i<128; i++) {
            countSource[i] = 0;
            countTarget[i] = 0;
        }

        for(i=0; i<sizeTarget; i++) {
            countTarget[target[i]]++;
        }

        int begin = -1, end = sizeSource, start = 0, found = 0, minLen = sizeSource;
        for(i=0,start=i; i<sizeSource; i++) {
            countSource[source[i]]++;

            if (countSource[source[i]] <= countTarget[source[i]]) {  
                found++;
            }
 
            if (found == sizeTarget) {  
                while (start < i && countSource[source[start]] > countTarget[source[start]]) {  
                    countSource[source[start]]--;  
                    start++;  
                }
                
                if (i - start < minLen) {  
                    minLen = i - start;  
                    begin = start;  
                    end = i;  
                }

                countSource[source[start++]]--;  
                found--;  
            }
        }

        if (begin == -1) {
            return string("");
        }
        else {
            return source.substr(begin, end - begin + 1);
        }
    }
};

int main()
{
    Solution s;
    string source("ADOBECODEBANC");
    string target("ABC");
    string result = s.minWindow(source, target);

    cout<<result.c_str()<<endl;

    return 0;
}