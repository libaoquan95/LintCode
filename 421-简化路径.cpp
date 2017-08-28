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
    * http://www.lintcode.com/zh-cn/problem/simplify-path/-421-简化路径
    * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string path) {
        // write your code here
        int size = path.size();
        if (size <= 0) {
            return string("");
        }
        // 分割路径
        path += '/';
        vector<string> pathVector;
        string p;
        for (int i = 0; i <= size; i++) {
            if (path[i] == '/') {
                if (!p.empty()) {
                    pathVector.push_back(p);
                    p.clear();
                }
            }
            else {
                p += path[i];
            }
        }
        display(pathVector);
        // 简化路径
        stack<string> parhStack;
        for (int i = 0; i < pathVector.size(); i++) {
            if (pathVector[i] != "." && pathVector[i] != "..") {
                parhStack.push(pathVector[i]);
            }
            else if (pathVector[i] == ".." && !parhStack.empty()) {
                parhStack.pop();
            }
        }
        // 重写路径
        string result;
        if (parhStack.empty()) {
            return string("/");
        }
        while (!parhStack.empty()) {
            result.insert(0, "/" + parhStack.top());
            parhStack.pop();
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
    /*s.display(s.simplifyPath("/home/"));
    s.display(s.simplifyPath("/a/./b/..//../c/"));
    s.display(s.simplifyPath("/../"));
    s.display(s.simplifyPath("/home//foo/"));*/

    s.display(s.simplifyPath("/..."));
    return 0;
}