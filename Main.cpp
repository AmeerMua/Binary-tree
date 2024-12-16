
#include "Tree.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() 
{
    Tree tree;

    // Inserting nodes into the tree
    cout << "Inserting nodes into the tree..." << endl;
    tree.insert(50, 50);
    tree.insert(30, 30);
    tree.insert(70, 70);
    tree.insert(20, 20);
    tree.insert(40, 40);
    tree.insert(60, 60);
    tree.insert(80, 80);

    // Displaying the tree in inorder traversal
    cout << "Tree elements in inorder traversal:" << endl;
    tree.display();

    // Searching for a node
    cout << "\nSearching for key 40 in the tree..." << endl;
    TreeNode* searchResult = tree.search(40);
    if (searchResult) 
    {
        cout << "Node with key 40 found. Data: " << searchResult->getData() << endl;
    } else 
    {
        cout << "Node with key 40 not found." << endl;
    }

    // Removing a node
    cout << "\nRemoving node with key 30..." << endl;
    tree.removeNode(30);

    // Displaying the tree again after removal
    cout << "Tree elements in inorder traversal after removing key 30:" << endl;
    tree.display();

    getch();
	return 0;
	
}
