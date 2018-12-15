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
			finalTree.at(1).updateParentHash(finalTree.at(childposition - 1), finalTree.at(parentposition - 1));  // update the the parent's history
			updateAllParents(finalTree, parentposition); // recursively call updateAllParents on the parent node to percolate to the top`
		}
		else {
			parentposition = (childposition - 1) / 2;
			finalTree.at(1).updateParentHash(finalTree.at(childposition - 1), finalTree.at(parentposition));  // update the the parent's history 
			updateAllParents(finalTree, parentposition); // recursively call updateAllParents on the parent node to percolate to the top`


		}



		

	}

}




void addNewNode(vector<Tree>& finalTree) {
	finalTree.push_back(Tree(finalTree.at(finalTree.size()/2).ID,finalTree));       //create a new node at the end of the vector.
	updateAllParents(finalTree, finalTree.size());   // update all parents based off of the last node updated
}




int main()
{
	srand(time(NULL));
	// begin program for real this time
	vector<Tree> finalTree;
	finalTree.push_back(Tree());           // tree at position 0 is a default tree that should never be referenced. 
	finalTree.push_back(Tree());           // tree at position 1 is a default tree that can be referenced. built using a randomID for root node 
	bool done = false;

	cout << "welcome to the tracking tree record collection program!" << endl;
	int sizeoftree, iter = 1;
	string userentry;
	bool foundNode;
	while (!done) {
		cout << "Current Tree ==================================================" << endl << endl;
		sizeoftree = finalTree.size();
		for (int i = 1; i < sizeoftree; i++) {
			finalTree.at(i).printNode();
			cout << endl;
		}
		cout << "Current Tree ==================================================" << endl;
		cout << "You can add a new node to the tree by typing add, or reference any other node by entering the ID of the node, enter quit to end the program" << endl;
		cin >> userentry;
		if (userentry == "quit" || userentry == "Quit") {
			done = true;
			cout << "Thank you for using the Tracking-Tree" << endl;
		}
		else if (userentry == "add" || userentry == "Add") {
			addNewNode(finalTree); 
			cout << "New Node added" << endl;
		}
		else {
			foundNode = false;
			finalTree.at(iter);
			while (!foundNode) {
				if (finalTree.at(iter).ID == userentry) {
					finalTree.at(iter).printNode();  // print node is broken when printing the history
					foundNode = true;
				}
				else {
					iter++;
					if (iter > finalTree.size()) {
						foundNode = true;
						cout << "Could not find node" << endl;
					}
				}
			}//end while

			cout << "Do you wish to edit this node?(y/n)" << endl;
			cin >> userentry;
			if (userentry.compare(0, 1, "y") == 0 || userentry.compare(0, 1, "Y")) {
				finalTree.at(iter).updateNode();
			}
		}
		
		
	}//end of program and while
	




    return 0;
}








