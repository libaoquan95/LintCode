#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/graph-valid-tree/-178-图是否是树
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        int size = edges.size(), i = 0;
        // 如果图中边的个数不等于点的个数n-1，必然不为树
        if (n - size != 1) {
            return false;
        }
        // 由 edges 得邻接表
        vector<vector<int>> neighbor(n);
        for (i = 0; i < size; i++) {
            int start = edges[i][0], end = edges[i][1];
            neighbor[start].push_back(end);
            neighbor[end].push_back(start);
        }
        // 检测是否有回路
        vector<bool> visited(n, false);
        if (hasCycle(neighbor, visited, -1, 0)) {
            return false;
        }
        // 检测是否有孤立节点
        for (i = 0; i < n; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }

    bool hasCycle(vector<vector<int>> &neighbor, vector<bool> &visited, int par, int kid) {
        if (visited[kid] == true) {
            return true;
        }
        visited[kid] = true;
        for (int i = 0; i < neighbor[kid].size(); i++) {
            // 先排除 par==neighbor[kid][i] 的情况，这种情况其实是neighbor数组定义的时候固有的特性，不算成环
            if (par != neighbor[kid][i] && hasCycle(neighbor, visited, kid, neighbor[kid][i])) {
                return true;
            }
        }
        return false;
    }

    void display(vector< vector<int> > &matrix) {
        vector< vector<int> >::iterator i;
        vector<int>::iterator j;

        for (i = matrix.begin(); i != matrix.end(); i++) {
            for (j = i->begin(); j != i->end(); j++) {
                cout << *j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;

    vector< vector<int> > matrix;
    vector<int> nums;

    nums.push_back(0);
    nums.push_back(1);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(0);
    nums.push_back(2);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(0);
    nums.push_back(3);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(1);
    nums.push_back(4);
    matrix.push_back(nums);

    s.display(matrix);
    cout << s.validTree(5, matrix) << endl;

    return 0;
}