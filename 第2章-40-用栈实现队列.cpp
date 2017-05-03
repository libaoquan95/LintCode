#include <iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第2章-40-用栈实现队列
     */
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int data;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                data = stack1.top();
                stack2.push(data);
                stack1.pop();
            }
        }
    
        data = stack2.top();
        stack2.pop();
        return data;
    }

    int top() {
        // write your code here
        int data;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                data = stack1.top();
                stack2.push(data);
                stack1.pop();
            }
        }
        else
            data = stack2.top();
        return data;
    }
};

int main()
{
    MyQueue q;

    for(int i=0; i<10; i++)
        q.push(i);

    for(i=0; i<5; i++)
        cout<<q.pop()<<" ";
    
    for(i=10; i<20; i++)
        q.push(i);

    for(i=0; i<10; i++)
        cout<<q.pop()<<" ";
    cout<<endl;

    cout<<q.top()<<endl;
    cout<<q.top()<<endl;
    cout<<q.top()<<endl;

    return 0;
}