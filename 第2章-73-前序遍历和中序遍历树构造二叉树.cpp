#include <iostream>
#include<vector>
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
     * http://www.lintcode.com/zh-cn/ladder/6/-第2章-72-中序遍历和后序遍历树构造二叉树
     * @param preorder : A list of integers that preorder traversal of a tree
     * @param inorder : A list of integers that inorder traversal of a tree
     * @return : Root of a tree
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        TreeNode *root = NULL;
        vector<int> preorder_l,preorder_r,inorder_l,inorder_r;
        int i,root_index=0;

        if(preorder.empty()!=1 || inorder.empty()!=1)
        {
            root = new TreeNode(preorder[0]); //  在前序队列中找根节点

            //  在中序队列中找出根节点位置
            for(i=0; i<inorder.size(); i++)
            {
                if(preorder[0] == inorder[i])
                    break;
                root_index++;
            }

            //  左右子树的前序、中序队列
            for(i=0; i<root_index; i++)
            {
                preorder_l.push_back(preorder[i+1]);
                inorder_l.push_back(inorder[i]);
            }
            for(i=root_index+1; i<inorder.size(); i++)
            {
                preorder_r.push_back(preorder[i]);
                inorder_r.push_back(inorder[i]);
            }

            root->left = buildTree(preorder_l, inorder_l);
            root->right = buildTree(preorder_r, inorder_r);
        }
        return root;
    }

    void display(TreeNode *TreeRoot) {
        if(TreeRoot == NULL)
        {
            //cout<<"null"<<endl;
        }
        else
        {
            display(TreeRoot->left);
            display(TreeRoot->right);
            cout<<TreeRoot->val<<" ";
        }
    }

    void distroy(TreeNode *TreeRoot)
    {
        if(TreeRoot->left == NULL && TreeRoot->right == NULL)
        {
            delete TreeRoot;
        }
        else
        {
            distroy(TreeRoot->left);
            distroy(TreeRoot->right);
        }
    }
};

int main()
{
    Solution s;

    vector<int> preorder;
    preorder.push_back(1);preorder.push_back(2);preorder.push_back(4);
    preorder.push_back(5);preorder.push_back(9);preorder.push_back(3);
    preorder.push_back(6);preorder.push_back(7);preorder.push_back(8);

    vector<int> inorder;
    inorder.push_back(4);inorder.push_back(2);inorder.push_back(9);
    inorder.push_back(5);inorder.push_back(1);inorder.push_back(3);
    inorder.push_back(7);inorder.push_back(6);inorder.push_back(8);

    TreeNode * root = s.buildTree(preorder, inorder);
    s.display(root);
    s.distroy(root);

    return 0;
}