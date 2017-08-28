#include <iostream>
#include <vector>
using namespace std;
 
/**
 * Definition of TreeNode:
 */ 
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/strstr/-13-×Ö·û´®²éÕÒ
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == NULL || target == NULL)
            return -1;
        if(source[0] == '\0' && target[0] == '\0')
            return 0;
        if(target[0] == '\0')
            return 0;
        int sourceLen = strlen(source), targetLen = strlen(target);
        int i=0, j=0;
        if (sourceLen < targetLen)
            return -1;
        
        while(i < sourceLen) {
            if(source[i] == target[j]) {
                i++;
                j++;
            }
            else {
                i = i-j+1;
                j = 0;
            }
            if(target[j] == '\0')
                return i-j;
        }
        return -1;  
    }

    
    int strStr_KMP(const char *source, const char *target) {
        if(source == NULL || target == NULL)
            return -1;
        if(source[0] == '\0' && target[0] == '\0')
            return 0;
        if(target[0] == '\0')
            return 0;

        int sourceLen = strlen(source), targetLen = strlen(target);
        int *next = getNext(target, targetLen);

        int i=0, j=0;
        for (i=0; i<sourceLen; i++) {
            while (j > 0 && source[i] != target[j])  
                j = next[j];
            
            if (source[i] == target[j])  
                j++;

            if (j == targetLen) {
                return i-j+1;
                j = next[j];
            }  
        }
        return -1;  
    }

    int *getNext(const char *target, int targetLen) {
        int *next = new int[targetLen+1];
        int i=0, j=0;

        next[0] = next[1] = 0; 
          
        for(i=1; i<targetLen; i++) {
            while(j>0 && target[i]!=target[j])
                j = next[j];
            if(target[i] ==target[j])
                j++;  
            next[i+1] = j;  
        }  
          
        return next;  
    }
};

int main()
{
    Solution s;

    cout<<s.strStr("source", "target")<<endl;
    cout<<s.strStr_KMP("source", "target")<<endl;

    cout<<s.strStr("abcdabcdefg", "bcd")<<endl;
    cout<<s.strStr_KMP("abcdabcdefg", "bcd")<<endl;

    cout<<s.strStr("", "")<<endl;
    cout<<s.strStr_KMP("", "")<<endl;

    return 0;
}