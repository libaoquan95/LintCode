#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
/**
* Definition for a point.
*/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/max-points-on-a-line/-186-最多有多少个点在一条直线上
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int size = points.size();
        if (size <= 0) {
            return 0;
        }

        map<double, int> map;
        int maxPoints = 0;
        for (int i = 0; i < size; i++) {
            map.clear();
            int samek = 0, maxk = 0;
            for (int j = 0; j < size; j++) {
                // 同一点
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    samek++;
                }
                // 斜率不存在
                else if (points[i].x == points[j].x && points[i].y != points[j].y) {
                    maxk++;
                }
                // 斜率存在
                else {
                    double k = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
                    map[k]++;
                }
            }

            std::map<double, int>::iterator it;
            for (it = map.begin(); it != map.end(); it++) {
                maxPoints = maxPoints > it->second + samek ? maxPoints : it->second + samek;
            }
            maxPoints = maxPoints > maxk + samek ? maxPoints : maxk + samek;
        }
        return maxPoints;
    }

    void display(vector<Point> &nums) {
        vector<Point>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << "(" << (*i).x << "," << (*i).y << ")" << endl;
        }
        cout << endl;
    }

};

int main()
{
    Solution s;

    vector<Point> nums;

    nums.push_back(Point(0, 9));
    nums.push_back(Point(138, 429));
    nums.push_back(Point(115, 359));
    nums.push_back(Point(115, 359));
    nums.push_back(Point(-30, -102));
    nums.push_back(Point(230, 709));
    nums.push_back(Point(-150, -686));
    nums.push_back(Point(-135, -613));
    nums.push_back(Point(-60, -248));
    nums.push_back(Point(-161, -481));
    nums.push_back(Point(207, 639));
    nums.push_back(Point(23, 79));
    nums.push_back(Point(-230, -691));
    nums.push_back(Point(-115, -341));
    nums.push_back(Point(92, 289));
    nums.push_back(Point(60, 336));
    nums.push_back(Point(-105, -467));
    nums.push_back(Point(135, 701));
    nums.push_back(Point(-90, -394));
    nums.push_back(Point(-184, -551));
    nums.push_back(Point(150, 774));

    s.display(nums);
    cout << s.maxPoints(nums) << endl;

    return 0;
}