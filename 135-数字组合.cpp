#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/combination-sum/-135-Êý×Ö×éºÏ
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        int size = candidates.size();
        if(size <= 0) {
            return vector<vector<int> >();
        }
        vector<vector<int> > result;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());  
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end()); 
        combinationSum(candidates, temp, 0, 0, target, result);

        return result;
    }

    void combinationSum(vector<int> &candidates, vector<int> &temp, int sum, int current, int target, vector<vector<int> > &result) {
        if(sum == target) {
            result.push_back(temp);
            return ;
        }
        else if(sum > target) {
            return ;
        }
        
        for(int i=current; i<candidates.size(); i++) {  
            temp.push_back(candidates[i]);
            sum += candidates[i];
            combinationSum(candidates, temp, sum, i, target, result);  
            sum -= temp[temp.size()-1];  
            temp.pop_back();  
        } 
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++) {
            cout<<*i<<" ";
        }
        cout<<endl;
    }

    void display(vector< vector<int> > &matrix) {
        vector< vector<int> >::iterator i;
        vector<int>::iterator j;

        for(i=matrix.begin(); i!=matrix.end(); i++)
        {
            for(j=i->begin(); j!=i->end(); j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution s;

    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);

    s.display(candidates);
    cout<<endl;
    s.display(s.combinationSum(candidates, 7));

    return 0;
}