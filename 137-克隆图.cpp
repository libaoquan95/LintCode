#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/clone-graph/-137-¿ËÂ¡Í¼
     *  @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(node == NULL) {
            return node;
        }

        queue<UndirectedGraphNode*> willVisit;
        map<UndirectedGraphNode*, bool> isVisited;
        map<UndirectedGraphNode*, UndirectedGraphNode*> oldToNew;

        UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
        isVisited[node] = true;
        oldToNew[node] = newNode;
        willVisit.push(node);

        while(!willVisit.empty()) {
            node = willVisit.front();
            willVisit.pop();
            for(int i=0; i<node->neighbors.size(); i++) {
                if(isVisited[node->neighbors[i]] == false) {
                    UndirectedGraphNode * temp = new UndirectedGraphNode(node->neighbors[i]->label);
                    isVisited[node->neighbors[i]] = true;
                    oldToNew[node->neighbors[i]] = temp;
                    oldToNew[node]->neighbors.push_back(temp);
                    willVisit.push(node->neighbors[i]);
                }
                else {
                    oldToNew[node]->neighbors.push_back(oldToNew[node->neighbors[i]]);
                }
            }
        }

        return newNode;
    }

    void display(UndirectedGraphNode *node) {
        if(node == NULL) {
            return;
        }

        map<UndirectedGraphNode*, bool> isVisited;
        queue<UndirectedGraphNode*> willVisit;

        willVisit.push(node);
        isVisited[node] = true;

        while(!willVisit.empty()) {
            for(int i=0; i<node->neighbors.size() && isVisited[node->neighbors[i]] == false; i++) {
                willVisit.push(node->neighbors[i]);
                isVisited[node->neighbors[i]] = true;
            }
            node = willVisit.front();
            willVisit.pop();
            cout<<node->label<<" ";
        }

        //displayOfDFS(node, isVisited);
        cout<<endl;

    }
    void displayOfDFS(UndirectedGraphNode *curNode, map<UndirectedGraphNode*, bool> isVisited) {
        if(isVisited.empty() || isVisited[curNode] == false) {
            isVisited[curNode] = true;
            cout<<curNode->label<<" ";
            for(int i=0; i<curNode->neighbors.size(); i++) {
                displayOfDFS(curNode->neighbors[i], isVisited);
            }
        }
    }

};

int main()
{
    Solution s;
    UndirectedGraphNode node0(0);
    UndirectedGraphNode node1(1);
    UndirectedGraphNode node2(2);

    vector<UndirectedGraphNode *> neighbors;
    neighbors.push_back(&node1);
    neighbors.push_back(&node2);
    node0.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node2);
    node1.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node2);
    node2.neighbors = neighbors;

    UndirectedGraphNode *newNode = s.cloneGraph(&node0);

    s.display(&node0);
    s.display(newNode);

    return 0;
}