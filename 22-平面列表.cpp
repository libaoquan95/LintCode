#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer,
    // rather than a nested list.
    bool isInteger() {
    }

    // Return the single integer that this NestedInteger holds,
    // if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds,
    // if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/flatten-list/-22-平面列表
     * @param nestedList a list of NestedInteger
     * @return a list of integer
     */
    vector<int> result;
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        int size = nestedList.size();
        for (int i = 0; i < size; i++) {
            if (nestedList[i].isInteger()) {
                result.push_back(nestedList[i].getInteger());
            } else {
               flatten(nestedList[i].getList());
            }
        }
        return result;
    }
};

int main()
{
    Solution s;


    vector<pair<int, double> >  matrix;
    vector<pair<int, double> > ::iterator it;
    
    matrix = s.flatten(15);

    for(it=matrix.begin(); it!=matrix.end();it++)
    {
        cout<<(*it)<<"\t";
    }
    cout<<endl;

    return 0;
}