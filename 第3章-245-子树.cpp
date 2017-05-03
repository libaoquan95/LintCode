#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition of ListNode
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
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ3ÕÂ-245-×ÓÊ÷
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
         bool result  = false;  
        if (T2 == NULL) {  
            return true;  
        }  
        if (T1 == NULL) {  
            return false;  
        }  
        // write your code here  
        if (T1->val == T2->val) {  
             result = isTree1HasTree2(T1,T2);  
        }  
        if (!result) {  
          result =  isSubtree(T1->left,T2);  
        }  
        if (!result) {  
            result =  isSubtree(T1->right,T2);  
        }  
        return result;  
    }

    bool isTree1HasTree2(TreeNode *T1, TreeNode *T2) {
        if (T1 != NULL && T2!=NULL && T1->val == T2->val) {  
            return isTree1HasTree2(T1->left,T2->left) 
                && isTree1HasTree2 (T1->right,T2->right);  
        }  
        if (T1 == NULL && T2 == NULL) {  
            return true;  
        }  
        return false; 
    }

    void display(TreeNode *TreeRoot) {
        if(TreeRoot == NULL)
        {
            //cout<<"null"<<endl;
        }
        else
        {
            display(TreeRoot->left);
            cout<<TreeRoot->val<<" ";
            display(TreeRoot->right);
        }
    }
};

int main()
{
    Solution s;
    TreeNode t1(8),t2(8),t3(7),t4(9),t5(2),t6(4),t7(7);
    t1.left  = &t2;
    t1.right = &t3;
    t2.left  = &t4;
    t2.right = &t5;
    t5.left  = &t6;
    t5.right = &t7;

    s.display(&t1);
    cout<<endl;

    TreeNode t8(8),t9(9),t10(2);
    t8.left  = &t9;
    t8.right = &t10;
    
    s.display(&t8);
    cout<<endl;

    return 0;
}