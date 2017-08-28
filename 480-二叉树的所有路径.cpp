#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;


/**
* Definition of TreeNode:
*/
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/binary-tree-paths/-480-二叉树的所有路径
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        if (root == NULL) {
            return vector<string>();
        }
        vector<string> result;
        vector<int> path;
        DFS(root, path, result);
        return result;
    }

    void DFS(TreeNode * root, vector<int> &path, vector<string> &result) {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string temp;
            for (int p : path) {
                char pa[256];
                sprintf(pa, "%d", p);
                temp += pa;
                temp += "->";
            }
            result.push_back(temp.substr(0, temp.size()-2));
            return;
        }
        if (root->left != NULL) {
            DFS(root->left, path, result);
            path.pop_back();
        }
        if (root->right != NULL) {
            DFS(root->right, path, result);
            path.pop_back();
        }
    }

    void display(TreeNode *TreeRoot) {
        if (TreeRoot == NULL) {
            //cout<<"null"<<endl;
        }
        else {
            cout << TreeRoot->val << " ";
            display(TreeRoot->left);
            display(TreeRoot->right);
        }
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }

    void display(vector<string> &nums) {
        vector<string>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            display(*i);
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    TreeNode t1(1), t2(2), t3(3), t4(4), t5(5);
    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;

    s.display(s.binaryTreePaths(&t1));

    return 0;
}