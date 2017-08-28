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
     * http://www.lintcode.com/zh-cn/problem/topological-sorting/-127-Õÿ∆À≈≈–Ú
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        int size = graph.size();
        if(size <= 0) {
            return vector<DirectedGraphNode*>();
        }

        vector<DirectedGraphNode*> result;
        queue<DirectedGraphNode*> noPreNode;
        map<DirectedGraphNode*, int> nodeIndegree;

        getIndegree(graph, nodeIndegree);

        for(int i=0; i<size; i++) {
            if(nodeIndegree[graph[i]] == 0) {
                noPreNode.push(graph[i]);
            }
        }

        while(!noPreNode.empty()) {
            result.push_back(noPreNode.front());
            for(i=0; i<noPreNode.front()->neighbors.size(); i++) {
                if(--nodeIndegree[noPreNode.front()->neighbors[i]] == 0) {
                    noPreNode.push(noPreNode.front()->neighbors[i]);
                }
            }
            noPreNode.pop();
        }
        return result;
    }

    vector<DirectedGraphNode*> topSort_BFS(vector<DirectedGraphNode*> graph) {
        // write your code here
        int size = graph.size();
        if(size <= 0) {
            return vector<DirectedGraphNode*>();
        }

        vector<DirectedGraphNode*> result;
        queue<DirectedGraphNode*> noPreNode;
        map<DirectedGraphNode*, int> nodeIndegree;

        getIndegree(graph, nodeIndegree);

        for(int i=0; i<size; i++) {
            if(nodeIndegree[graph[i]] == 0) {
                noPreNode.push(graph[i]);
            }
        }

        while(!noPreNode.empty()) {
            result.push_back(noPreNode.front());
            for(i=0; i<noPreNode.front()->neighbors.size(); i++) {
                if(--nodeIndegree[noPreNode.front()->neighbors[i]] == 0) {
                    noPreNode.push(noPreNode.front()->neighbors[i]);
                }
            }
            noPreNode.pop();
        }
        return result;
    }

    void getIndegree(vector<DirectedGraphNode*> graph, map<DirectedGraphNode*, int> &nodeIndegree) {
        int size = graph.size();
        for(int i=0; i<size; i++) {
            int size2 = graph[i]->neighbors.size();
            for(int j=0; j<size2; j++) {
                nodeIndegree[graph[i]->neighbors[j]]++;
            }
        }
    }

    /*
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        int size = graph.size();
        if(size <= 0) {
            return vector<DirectedGraphNode*>();
        }

        vector<DirectedGraphNode*> result;
        set<DirectedGraphNode*> visitedNode;
        
        while(visitedNode.size() < size) {
            for(int i=0; i<size; i++) {
                if(!hasPrecursor(graph, visitedNode, graph[i])) {
                    result.push_back(graph[i]);
                    visitedNode.insert(graph[i]);
                }
            }
        }
        return result;
    }

    bool hasPrecursor(vector<DirectedGraphNode*> graph, set<DirectedGraphNode*> visitedNode, DirectedGraphNode* node) {
        int size = graph.size();
        for(int i=0; i<size; i++) {
            set<DirectedGraphNode*>::iterator isVisit = visitedNode.find(graph[i]);
            if(isVisit == visitedNode.end()) {
                int size2 = graph[i]->neighbors.size();
                for(int j=0; j<size2; j++) {
                    if(graph[i]->neighbors[j] == node) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    */
    void display(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode *>::iterator i;
        for(i=graph.begin(); i!=graph.end(); i++) {
            cout<<(*i)->label;

            vector<DirectedGraphNode *>::iterator j;
            for(j=(*i)->neighbors.begin(); j!=(*i)->neighbors.end(); j++) {
                cout<<"->"<<(*j)->label;
            }

            cout<<endl;
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
    DirectedGraphNode node6(6);

    vector<DirectedGraphNode *> neighbors;
    neighbors.push_back(&node2);
    neighbors.push_back(&node3);
    node1.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node4);
    node2.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node4);
    neighbors.push_back(&node6);
    node3.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node5);
    node4.neighbors = neighbors;

    neighbors.clear();
    neighbors.push_back(&node6);
    node5.neighbors = neighbors;

    neighbors.clear();
    node6.neighbors = neighbors;

    graph.push_back(&node1);
    graph.push_back(&node2);
    graph.push_back(&node3);
    graph.push_back(&node4);
    graph.push_back(&node5);
    graph.push_back(&node6);

    s.display(graph);

    /*
    cout<<s.hasPrecursor(graph, &node1)<<endl;
    cout<<s.hasPrecursor(graph, &node2)<<endl;
    cout<<s.hasPrecursor(graph, &node3)<<endl;
    cout<<s.hasPrecursor(graph, &node4)<<endl;
    cout<<s.hasPrecursor(graph, &node5)<<endl;
    cout<<s.hasPrecursor(graph, &node6)<<endl;
    */
    vector<DirectedGraphNode*> result = s.topSort(graph);

    cout<<endl;
    vector<DirectedGraphNode*>::iterator i;
    for(i=result.begin(); i!=result.end(); i++) {
        cout<<(*i)->label<<" ";
    }
    cout<<endl;

    return 0;
}