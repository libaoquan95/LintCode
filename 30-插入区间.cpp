#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition of Interval:
 */
class Interval {
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
     * http://www.lintcode.com/zh-cn/problem/insert-interval/-30-插入区间
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> & intervals, Interval newInterval) {
        // write your code here
        int i = 0, size = intervals.size();

        if(size == 0) {  
            intervals.push_back(newInterval);
            return intervals;
        }
                  
        while(i<size && compareInterval(newInterval, intervals[i])) {
            ++i;
        }

        intervals.insert(intervals.begin()+i, newInterval);
        size = intervals.size();
        for(i=0; i<size-1; i++) {
            // intervals[i+1] 属于 intervals[i]，檫除intervals[i+1]
            if(intervals[i+1].start >= intervals[i].start && intervals[i+1].end <= intervals[i].end) {
                intervals.erase(intervals.begin()+i+1);
                size--;
                i--;
            }
            // intervals[i+1] 与 intervals[i]合并
            else if(intervals[i+1].start <= intervals[i].end){  
                intervals[i].end = intervals[i+1].end;  
                intervals.erase(intervals.begin()+i+1);  
                size--;  
                i--;  
            }
        }  
        return intervals;  
    }
    
    // @return 1:a>b
    // @return 0:a<=b
    bool compareInterval(Interval &a, Interval &b){  
        if(a.start == b.start) { 
            return a.end > b.end;
        }
        return a.start > b.start;      
    }

    void displayVector(vector<Interval> &order) {
        vector<Interval>::iterator i;
        for(i=order.begin(); i!=order.end(); i++) {
            cout<<(*i).start<<","<<(*i).end<<endl;
        }
    }
};

int main()
{
    Solution s;

    vector<Interval> intervals;

    Interval newInterval(4, 8);

    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(9, 12));
    intervals.push_back(Interval(13, 15));

    vector<Interval> matrix = s.insert(intervals, newInterval);
    s.displayVector(matrix);

    return 0;
}