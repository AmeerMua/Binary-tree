
class TreeNode
{
	int data;
	int key;
	TreeNode *right;
	TreeNode *left;
public:
		TreeNode();
		TreeNode(int,int);
		void setData(int);
		void setKey(int);
		int getKey();
		int getData();
		void setRight(TreeNode*);
		void setLeft(TreeNode*);
		TreeNode* getRight();
		TreeNode* getLeft();
};
