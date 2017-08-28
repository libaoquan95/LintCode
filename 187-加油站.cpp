#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/gas-station/-187-加油站
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int size = gas.size();
        if (size <= 0) {
            return 0;
        }
        int curGas = 0, start = 0, totalGas = 0, totalCost = 0;
        for (int i = 0; i < size; i++) {
            curGas += gas[i];
            curGas -= cost[i];

            totalGas += gas[i];
            totalCost += cost[i];

            if (curGas < 0) {
                start = i + 1;
                curGas = 0;
            }
        }
        return totalGas >= totalCost ? start : -1;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << (*i) << " ";
        }
        cout << endl;
    }

};

int main()
{
    Solution s;

    vector<int> gas;
    gas.push_back(1);
    gas.push_back(1);
    gas.push_back(3);
    gas.push_back(1);

    vector<int> cost;
    cost.push_back(2);
    cost.push_back(2);
    cost.push_back(1);
    cost.push_back(1);

    cout << "gas : ";
    s.display(gas);
    cout << "cost: ";
    s.display(cost);
    cout << s.canCompleteCircuit(gas, cost) << endl;

    return 0;
}