#include <iostream>
#include <queue>
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
     * http://www.lintcode.com/zh-cn/ladder/6/-第8章-7-二叉树的序列化和反序列化
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here

        string result = "";
        TreeNode *node=root;

        if(node == NULL)
            return result;

         preorderTraversal(node, result);

        return result;
    }

    void preorderTraversal(TreeNode *root, string &result) {

        if(root == NULL)
        {
            result += "#,";
        }
        else
        {
            char temp[20];
            sprintf(temp, "%d,", root->val);
            result += temp;
            preorderTraversal(root->left, result);
            preorderTraversal(root->right, result);
        }
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        int size = data.size(),i=0;
        if(size == 0)
            return NULL;

        TreeNode *root;
        vector<string> treeArray = split(data, ",");
        depreorderTraversal(root, treeArray, i, treeArray.size());

        return root;
    }

    void depreorderTraversal(TreeNode *&root, vector<string> &treeArray, int &i, const int size) {
        if(i < size)
        {
            if(treeArray[i].compare("#") == 0)
            {
                root = NULL;
                i++;
            }
            else
            {
                root = (TreeNode*)malloc(sizeof(TreeNode));
                root->val = atoi(treeArray[i].c_str());
                i++;
                depreorderTraversal(root->left,treeArray, i, size);
                depreorderTraversal(root->right,treeArray, i, size);
            }
        }
    }

    vector<string> split(const string &s, const string &seperator){
        vector<string> result;
        typedef string::size_type string_size;
        string_size i = 0;

        while(i != s.size()){
            //找到字符串中首个不等于分隔符的字母；
            int flag = 0;
            while(i != s.size() && flag == 0){
                flag = 1;
                for(string_size x = 0; x < seperator.size(); ++x)
                    if(s[i] == seperator[x]){
                        ++i;
                        flag = 0;
                        break;
                }
            }

            //找到又一个分隔符，将两个分隔符之间的字符串取出；
            flag = 0;
            string_size j = i;
            while(j != s.size() && flag == 0){
                for(string_size x = 0; x < seperator.size(); ++x)
                if(s[j] == seperator[x]){
                    flag = 1;
                    break;
            }
            if(flag == 0) 
                ++j;
            }
            if(i != j){
                result.push_back(s.substr(i, j-i));
                i = j;
            }
        }
        return result;
    }

	void display(TreeNode *TreeRoot) {
		if(TreeRoot == NULL) {
			//cout<<"null"<<endl;
		}
		else {
			cout<<TreeRoot->val<<" ";
			display(TreeRoot->left);
			display(TreeRoot->right);
		}
	}
    
    void displayVector(vector<string> order) {
        vector<string>::iterator i;
    
        for(i=order.begin(); i!=order.end(); i++)
        { 
            for(int j=0; j<i->size(); j++)
                cout<<(*i)[j];
            cout<<" ";

        }
        cout<<endl;
    }
};

int main()
{
    Solution s;
   
    TreeNode t1(3),t2(9),t3(20),t4(15),t5(7);
    t1.left  = &t2;
    t1.right = &t3;

    t3.left  = &t4;
    t3.right = &t5;

    s.display(&t1);
    cout<<endl;

    string serialize = s.serialize(&t1);
    for(int i=0; i<serialize.size(); i++)
        cout<<serialize[i];
    cout<<endl;

    s.display(s.deserialize(serialize));
    //s.deserialize(serialize);
    return 0;
}
