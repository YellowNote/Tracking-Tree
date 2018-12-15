// TrackingTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include <time.h>












void updateAllParents(vector<Tree>& finalTree, int childposition) {
	int parentposition = 0;
	if (childposition == 1) {
		cout << "all parents were updated" << endl;        // if this is our root node there are no more trees to update
	}
	else {
		if (childposition % 2 == 0) { // if this is even it is a left child
			parentposition = childposition / 2;
		}
		else {
			parentposition = (childposition - 1) / 2;
		}
		


		finalTree.at(1).updateParentHash(finalTree.at(childposition - 1) , finalTree.at(parentposition));  // update the the parent's history
		updateAllParents(finalTree, parentposition); // recursively call updateAllParents on the parent node to percolate to the top`

	}

}


void addNewNode(vector<Tree>& finalTree) {
	finalTree.push_back(Tree(finalTree.at(finalTree.size()/2).ParentID,finalTree));       //create a new node at the end of the vector.
	updateAllParents(finalTree, finalTree.size());   // update all parents based off of the last node updated
}




int main()
{
	srand(time(NULL));
	// begin program for real this time
	vector<Tree> finalTree;
	finalTree.push_back(Tree());           // tree at position 0 is a default tree that should never be referenced. 
	finalTree.push_back(Tree());           // tree at position 1 is a default tree that can be referenced. built using a randomID for root node 
	addNewNode(finalTree);
	bool done = false;
	cout << "welcome to the tracking tree record collection program!" << endl;
	int userentry;
	string userenteryStr;
	while (!done) {
		userentry = -1;
		cout << "You can add a new node to the tree by typing 0, or reference any other node by entering the number of the node, enter a negative number to end" << endl;


		cin >> userentry;
		if (userentry > 0 ) {
			int sizeoftree = finalTree.size();
			if (userentry < sizeoftree) {     // if this is the case then the user has entered the index of a record that exists
				finalTree.at(userentry).printNode();  // print node is broken when printing the history
			}
			else
			{
				cout << "sorry that node does not exist yet!" << endl;
			}
			cout << "Do you wish to edit this node?(y/n)" << endl;
			cin >> userenteryStr;
			if (userenteryStr.compare(0, 1, "y") == 0 || userenteryStr.compare(0, 1, "Y")) {
				finalTree.at(userentry).updateNode();
			}
		}
		else if (userentry == 0) {
			addNewNode(finalTree); 
			cout << "New Node added" << endl;
		}
		else if (userentry < 0) {
			done = true;
			cout << "Thank you for using the Tracking-Tree" << endl;
		}
		
		
	}
	
	system("pause");
	










    return 0;
}








