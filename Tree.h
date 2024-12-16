#include "TreeNode.h"
class Tree
{
private:
		TreeNode* root;
public:
		Tree();
		void insert(int,int);
		bool isEmpty();
		void removeNode(int);
		TreeNode* search(int); //bool or treeNode
		void inorder(TreeNode*);
		void display();

};

