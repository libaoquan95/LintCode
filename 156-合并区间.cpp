#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    static bool cmp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }

    /**
     * http://www.lintcode.com/zh-cn/problem/merge-intervals/-156-合并区间
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        int size = intervals.size();
        if (size <= 0) {
            return vector<Interval>();
        }

        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        for (int i = 1; i < size; i++) {
            if (result.back().end >= intervals[i].start) {
                result.back().end = (result.back().end > intervals[i].end) ? result.back().end : intervals[i].end;
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

    void display(vector<Interval> &nums) {
        vector<Interval>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << "[" << (*i).start<< " , " << (*i).end << "]" << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    vector<Interval> nums;
    nums.push_back(Interval(1, 3));
    nums.push_back(Interval(2, 6));
    nums.push_back(Interval(8, 10));
    nums.push_back(Interval(15, 18));
    s.display(nums);
    s.display(s.merge(nums));

    return 0;
}