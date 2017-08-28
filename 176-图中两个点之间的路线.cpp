#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

/**
* Definition for Directed graph.
*/
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
    * http://www.lintcode.com/problem/route-between-two-nodes-in-graph/-176-图中两个点之间的路线 
    * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        int size = graph.size(), i = 0;
        if (size <= 0) {
            return false;
        }
        queue<DirectedGraphNode*> queue;
        map<DirectedGraphNode*, bool> map;
        for (i = 0; i < size; i++) {
            map[graph[i]] = false;
            if (s == graph[i]) {
                queue.push(graph[i]);
            }
        }
        while (!queue.empty()) {
            DirectedGraphNode* node = queue.front();
            queue.pop();
            map[node] = true;
            if (node == t) {
                return true;
            }
            for (i = 0; i < node->neighbors.size(); i++) {
                if (map[node->neighbors[i]] == false) {
                    queue.push(node->neighbors[i]);
                }
            }
        }
        return false;
    }

    void display(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode *>::iterator i;
        for (i = graph.begin(); i != graph.end(); i++) {
            cout << (*i)->label;

            vector<DirectedGraphNode *>::iterator j;
            for (j = (*i)->neighbors.begin(); j != (*i)->neighbors.end(); j++) {
                cout << "->" << (*j)->label;
            }

            cout << endl;
        }
    }
};

int main()
{
    Solution s;

    vector<DirectedGraphNode*> graph;
    DirectedGraphNode node1(1);
    DirectedGraphNode node2(2);
    DirectedGraphNode node3(3);
    DirectedGraphNode node4(4);
    DirectedGraphNode node5(5);

    vector<DirectedGraphNode *> neighbors;
    neighbors.push_back(&node2);
    neighbors.push_back(&node4);
    node1.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node3);
    neighbors.push_back(&node4);
    node2.neighbors = neighbors;

    neighbors.clear();
    node3.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node5);
    node4.neighbors = neighbors;

    neighbors.clear();
    node5.neighbors = neighbors;

    neighbors.clear();

    graph.push_back(&node1);
    graph.push_back(&node2);
    graph.push_back(&node3);
    graph.push_back(&node4);
    graph.push_back(&node5);

    s.display(graph);

    cout << endl << s.hasRoute(graph, &node2, &node5) << endl;

    return 0;
}