#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/majority-number-ii/-47-Ö÷ÔªËØ II
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int size = nums.size(), hashMaxSize = 3, i = 0;
        map<int, int> hashMap;
        map<int, int>::iterator it;
        int result = 0, maxCount = 0;
        
        for(i=0; i<size; i++) {
            if(hashMap.size() < hashMaxSize) {
                it = hashMap.find(nums[i]);
                if(it == hashMap.end()) {
                    hashMap.insert(pair<int, int>(nums[i], 1));
                }
                else {
                    (it->second)++;
                }
            }
            else {
                for(it=hashMap.begin(); it!=hashMap.end(); it++) {
                    (it->second)--;
                }
                for(it=hashMap.begin(); it!=hashMap.end();) {
                    if(it->second == 0) {
                        hashMap.erase(it++);
                    }
                    else {
                        it++;
                    }
                }
            }
        }

        for(it=hashMap.begin(); it!=hashMap.end(); it++) {
            it->second = 0;
        }

        for(i=0; i<size; i++) {
            it = hashMap.find(nums[i]);
            if(it != hashMap.end()) {
                it->second++;
                if(maxCount < it->second) {
                    maxCount = it->second;
                    result = it->first;
                }
            }
        }
        return result;
    }

    void displayVector(vector<int> &order) {
        vector<int>::iterator i;
        for(i=order.begin(); i!=order.end(); i++) {
            cout<<(*i)<<",";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);

    cout<<s.majorityNumber(nums, 4)<<endl;
    return 0;
}