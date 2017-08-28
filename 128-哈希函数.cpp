#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/hash-function/-128-¹þÏ£º¯Êý
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int size = key.size();
        if(size <= 0) {
            return 0;
        }
        long code = 0; 
        long hashBase = 1;
        for(int i=size-1; i>=0; i--) {
            code = code + (key[i] * hashBase) % HASH_SIZE;
            code %= HASH_SIZE;
            hashBase = hashBase * 33 % HASH_SIZE;
        }
        return code;
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

    //cout<<s.hashCode("abcd", 100)<<endl;
    cout<<s.hashCode("ubuntu", 1007)<<endl;

    return 0;
}