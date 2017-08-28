#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition of TreeNode
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
     * http://www.lintcode.com/zh-cn/ladder/6/-第7章-88-最近公共祖先
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        TreeNode * ancestor = NULL;
        if(root==NULL || A==NULL || B==NULL)
            return ancestor;

        vector<TreeNode *> pathA, pathB;
        searchTree(root, A, pathA);
        searchTree(root, B, pathB);

        int sizeA=pathA.size(), sizeB=pathB.size();
        int size = sizeA>sizeB ? sizeB : sizeA, i=0;
        bool find = false;

        for(i=0; i<size; i++)
        {
            if(pathA[i] != pathB[i])
            {
                find = true;
                return ancestor;
            }
            else
                ancestor = pathA[i];
        }
        if(find == false)
            ancestor = pathA[size-1];
        return ancestor;
    }

    bool searchTree(TreeNode *root, TreeNode *node, vector<TreeNode *> &path) {
        if(root==NULL || node==NULL) {  
            return false;  
        }

        path.push_back(root);

        //  找到了
        if(root->val == node->val) {  
            return true;  
        }

        if(root->left != NULL) {  
            if(searchTree(root->left, node, path)) {  
                return true;  
            }  
        }  
        if(root->right != NULL) {  
            if(searchTree(root->right, node, path)) {  
                return true;  
            }  
        }

        //回溯
        path.pop_back(); 
        return false;  
    }

    void displayVector(vector<TreeNode *> order) {
        vector<TreeNode *>::iterator i;
    
        for(i=order.begin(); i!=order.end(); i++)
        {
            cout<<(*i)->val<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    TreeNode t1(4),t2(3),t3(7),t4(5),t5(6);
    t1.left  = &t2;
    t1.right = &t3;

    t3.left  = &t4;
    t3.right = &t5;

    TreeNode * ancestor;

    ancestor = s.lowestCommonAncestor(&t1, &t2, &t4);
    if(ancestor != NULL)
        cout<<"LAC("<<t2.val<<","<<t4.val<<")="<<ancestor->val<<endl;

    ancestor = s.lowestCommonAncestor(&t1, &t4, &t5);
    if(ancestor != NULL)
        cout<<"LAC("<<t4.val<<","<<t5.val<<")="<<ancestor->val<<endl;

    ancestor = s.lowestCommonAncestor(&t1, &t5, &t3);
    if(ancestor != NULL)
        cout<<"LAC("<<t5.val<<","<<t3.val<<")="<<ancestor->val<<endl;

    return 0;
}