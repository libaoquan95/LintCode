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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        TreeNode *root = NULL;
        vector<int> inorder_l,inorder_r,postorder_l,postorder_r;
        int i,root_index=0;
        int size = postorder.size();

        if(inorder.empty()!=1 || postorder.empty()!=1)
        {
            root = new TreeNode(postorder[size-1]); //  在后序队列中找根节点

            //  在中序队列中找出根节点位置
            for(i=0; i<inorder.size(); i++)
            {
                if(postorder[size-1] == inorder[i])
                    break;
                root_index++;
            }

            //  左右子树的前序、中序队列
            for(i=0; i<root_index; i++)
            {
                postorder_l.push_back(postorder[i]);
                inorder_l.push_back(inorder[i]);
            }
            for(i=root_index+1; i<inorder.size(); i++)
            {
                postorder_r.push_back(postorder[i-1]);
                inorder_r.push_back(inorder[i]);
            }

            root->left = buildTree(inorder_l, postorder_l);
            root->right = buildTree(inorder_r, postorder_r);
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
            cout<<TreeRoot->val<<" ";
            display(TreeRoot->left);
            display(TreeRoot->right);
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

    vector<int> inorder;
    inorder.push_back(4);inorder.push_back(2);inorder.push_back(9);
    inorder.push_back(5);inorder.push_back(1);inorder.push_back(3);
    inorder.push_back(7);inorder.push_back(6);inorder.push_back(8);

    vector<int> postorder;
    postorder.push_back(4);postorder.push_back(9);postorder.push_back(5);
    postorder.push_back(2);postorder.push_back(7);postorder.push_back(8);
    postorder.push_back(6);postorder.push_back(3);postorder.push_back(1);

    TreeNode * root = s.buildTree(inorder, postorder);
    s.display(root);
    //s.distroy(root);

    return 0;
}