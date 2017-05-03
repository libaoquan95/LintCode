#include <iostream>
#include<stack>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第4章-12-带最小值操作的栈
     */
    stack<int> mainStack;
    stack<int> helpStack;

    void push(int number) {
        // write your code here
        int top;
        mainStack.push(number);

        if(!helpStack.empty())
            top = helpStack.top();
        else
            top = number;

        if(number > top)
            helpStack.push(top);
        else
            helpStack.push(number);
    }

    int pop() {
        // write your code here
        if(!mainStack.empty())
        {
            int data = mainStack.top();
            mainStack.pop();
            helpStack.pop();
            return data;
        }
    }

    int min() {
        // write your code here
        if(!helpStack.empty())
        {
            int data = helpStack.top();
            return data;
        }
    }
};

int main()
{
    Solution s;

    /*
    //如下操作：push(1)，pop()，push(2)，push(3)，min()， push(1)，min() 
    //返回 1，2，1
    s.push(1); 
    cout<<s.pop()<<" ";
    s.push(2); 
    s.push(3); 
    cout<<s.min()<<" ";
    s.push(1); 
    cout<<s.min()<<" ";
    */

    //push(3), push(2), push(1), min(), pop(), min(), pop(), min()
    //1 1 2 2 3
    s.push(3); 
    s.push(2); 
    s.push(1); 
    cout<<s.min()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.min()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.min()<<" ";
    return 0;
}