#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

/**
* Definition of Interval:
*/
class Interval{
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/number-of-airplanes-in-the-sky/-391-数飞机
    * @param intervals: An interval array
    * @return: Count of airplanes are in the sky.
    */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int size = airplanes.size();
        if (size <= 0) {
            return 0;
        }
        map<int, int> airCount;
        set<int> airTime;
        int maxCount = INT_MIN, curCount = 0;
        for (int i = 0; i < size; i++) {
            airCount[airplanes[i].start]++;
            airCount[airplanes[i].end]--;
            airTime.insert(airplanes[i].start);
            airTime.insert(airplanes[i].end);
        }
        for (auto t: airTime) {
            curCount += airCount[t];
            maxCount = max(maxCount, curCount);
        }
        return maxCount;
    }

    void display(vector<Interval> &nums) {
        vector<Interval>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << "[" << (*i).start << " , " << (*i).end << "]   ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    vector<Interval> queries;
    queries.push_back(Interval(1, 10));
    queries.push_back(Interval(2, 3));
    queries.push_back(Interval(4, 7));
    queries.push_back(Interval(5, 8));

    cout << s.countOfAirplanes(queries) << endl;

    return 0;
}