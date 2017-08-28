#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/sort-letters-by-case/-49-×Ö·û´óÐ¡Ð´ÅÅÐò 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int low = 0, high = letters.size()-1;

        while(low < high) {
            while(letters[low]<='z' && letters[low]>='a') {
                low++;
            }
            while(letters[high]<='Z' && letters[high]>='A') {
                high--;
            }
            if(low < high) {
                char temp = letters[low];
                letters[low] = letters[high];
                letters[high] = temp;
                low++;
                high--;
            }
        }
    }
};

int main()
{
    Solution s;

    string str("abAcDfdsIONjVtyvcbshGFUbhbBufvtyU");
    for(int i=0; i<str.size(); i++) {
        cout<<str[i];
    }
    cout<<endl;

    s.sortLetters(str);

    for(i=0; i<str.size(); i++) {
        cout<<str[i];
    }
    cout<<endl;

    return 0;
}