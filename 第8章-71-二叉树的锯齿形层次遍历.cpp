#include <iostream>
#include <vector>
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
	 * http://www.lintcode.com/zh-cn/ladder/6/-第8章-71-二叉树的锯齿形层次遍历
	 * @param root: The root of binary tree.
	 * @return: A list of lists of integer include 
	 *          the zigzag level order traversal of its nodes' values 
	 */
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		// write your code here 
		vector<vector<int> > order;
		queue<TreeNode*> queue;
		int len,leaver=1;

		if(root == NULL) {
			return order;
		}

		queue.push(root);
		len = queue.size();

		while(!queue.empty()) {  
			vector<int> base;  
			len = queue.size();
			
			while(len--) {
				TreeNode *tmp=queue.front();  
				base.push_back(tmp->val);
				queue.pop();  
				if(tmp->right)      
					queue.push(tmp->right);  
				if(tmp->left)  
					queue.push(tmp->left);  
			}

			if(leaver%2 == 1)
				reverse(base.begin(),base.end());
			order.push_back(base); 
			leaver++;
		}  
		return order;
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

	vector<vector<int> > order = s.zigzagLevelOrder(&t1);
	vector<vector<int> >::iterator i;
	vector<int>::iterator j;
	
	for(i=order.begin(); i!=order.end(); i++)
	{
		for(j=i->begin(); j!=i->end(); j++)
		{
			cout<<*j<<" ";
		}
		cout<<endl;
	}

	return 0;
}
