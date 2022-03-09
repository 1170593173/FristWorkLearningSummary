#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int m_val) :val(m_val), left(NULL), right(NULL) {};
};
int res = 0;
int getHeigth(TreeNode *node) {
	if (node == NULL) {
		return 0;
	}
	int left = getHeigth(node->left);
	int right = getHeigth(node->right);
	res = (res > (left + right+1)) ? res : (left + right+1);
	return 1 + (left > right ? left : right);
}


int getRes(TreeNode *root) {
	if (root == NULL) 
		return 0;
	getHeigth(root);
	return res;
}

int main() {
	TreeNode*root = new TreeNode(1);
	TreeNode*Node2 = new TreeNode(2);
	TreeNode*Node3 = new TreeNode(3);
	TreeNode*Node4 = new TreeNode(4);
	TreeNode*Node5 = new TreeNode(5);
	TreeNode*Node6 = new TreeNode(6);
	TreeNode*Node7 = new TreeNode(7);
	TreeNode*Node8 = new TreeNode(8);
	TreeNode*Node9 = new TreeNode(9);
	TreeNode*Node10 = new TreeNode(10);

	root->left = Node2;
	root->right = Node3;
	Node2->left = Node4;
	Node2->right = Node5;
	Node4->left = Node9;
	Node5->left = Node7;
	Node5->right = Node6;
	Node7->left = Node8;

	Node9->left = Node10;
	
	int res = getRes(root);

	return 0;
}