///////// Binary tree ///////////////////


///////// Implementation ///////////////////
#include <iostream>
#include "Tree.h"
using namespace std;
///////////////////////////Tree Node Implementation ///////////////////

TreeNode::TreeNode(int data,int key)
{
	this->data = data;
	this-> key = key;
	this-> right=NULL;
	this->left=NULL;


}

void TreeNode:: setData(int data)
{
	this-> data = data;
}
void TreeNode:: setKey(int key)
{
	this->key=key;
}
void TreeNode::setLeft(TreeNode *left)
{
	this->left =left;
}
void TreeNode::setRight(TreeNode *right)
{
	this->right= right;
}
int TreeNode::getKey()
{
	return key;
}
TreeNode* TreeNode::getLeft()
{
	return left;
}
TreeNode* TreeNode::getRight()
{
	return right;
}

/////////////////////// Tree Implementation///////////////
Tree:: Tree()
{
	root=NULL;
}

bool Tree :: isEmpty()
{
	if (root ==NULL)
	{
		return true;
	}
	else
	{
		return false;

	}
}
void Tree:: insert(int data, int key)
{
	if(isEmpty())
	{
		TreeNode *temp= new TreeNode(data,key);
		root = temp;
	}
	else
	{
		TreeNode *temp = root;
		TreeNode *parent;
		while(temp!=NULL)
		{
			if(temp->getKey() == key)
			{
				return;
			}
			else if(temp->getKey()>key)
			{
				parent= temp;
				temp= temp->getLeft();
			}
			else if(temp->getKey() < key)
			{
				parent = temp;
				temp= temp->getRight();
			}
		}//end of loop

		TreeNode *newNode= new TreeNode(data, key);
		if(parent->getKey() > key)
		{
			parent->setLeft(temp);
		}
		else if(parent->getKey() < key)
		{
			parent->setRight(temp);
		}
	}
}
TreeNode* Tree::search(int key)
{
	TreeNode *temp=root;
	while(temp!=NULL)
	{
		if(temp->getKey()==key)
		{
			return temp;
		}
		else if(temp->getKey() > key)
		{
			temp = temp->getLeft();
		}
		else
		{
			temp=temp->getRight();
		}
	}//end of loop
	return NULL;
}
void Tree:: inorder(TreeNode *n)
{
	if(n!=NULL)
	{
		inorder(n->getLeft());
		cout<<n->getKey() <<endl;// ager pre order ha to yeh line necha ah jae giy //or ager post ha to sab sa necha ah jae giy
		inorder(n->getRight());
	}
}
void Tree::display()
{
	inorder (root);

}
void Tree:: removeNode(int key)
{
	TreeNode *temp= root;
	TreeNode *parent;
	while(temp!=NULL)
	{
		if(temp->getKey()==key)
		{
			break;
		}
		else if(temp->getKey() > key)
		{
			parent= temp;
			temp= temp-> getLeft();
		}
		else if(temp->getKey() <key)
		{
			parent = temp;
			temp= temp->getRight();
		}
	}//end of loop
	 
	if (temp == NULL) 
	{
        cout << "Key not found in the tree." << endl;
        return;
    }
	

	if(temp->getRight() == NULL && temp->getLeft()==NULL) //nochild
	{
		if(parent->getRight() !=NULL)
		{
			parent->setRight(NULL);
		}
		else
		{
			parent->setLeft(NULL);
		}
		delete temp;
	}
	else if(temp->getRight()==NULL || temp->getLeft() ==NULL)//one child
	{
		if(parent->getRight() == temp)
		{
			if(temp ->getRight()!=NULL)
			{
				parent->setRight(temp->getRight ());
			}
			else
			{
				parent->setRight(temp->getLeft() );
			}
			delete temp;
		}
		else if (parent->getLeft( ) == temp)
		{
			if( temp ->getLeft() !=NULL)
			{
				parent->setLeft(temp->getLeft());
			}
			else
			{
				parent->setLeft(temp->getRight());
			}
			delete temp;
		}
	}
	 //two children
    else 
    {
        
        TreeNode *temp = temp->getRight();
        TreeNode *parent = temp;

        while (temp->getLeft() != NULL) 
        {
            parent = temp;
            temp = temp->getLeft();
        }

        temp->setKey(temp->getKey());

        
        if (parent->getLeft() == temp) 
        {
            parent->setLeft(temp->getRight());
        } 
		else 
        {
            parent->setRight(temp->getRight());
        }

        delete temp;
    }
}
