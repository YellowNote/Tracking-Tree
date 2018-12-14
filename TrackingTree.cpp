// TrackingTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"













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
	finalTree.push_back(Tree(finalTree.at(finalTree.size()/2).ID));       //create a new node at the end of the vector.
	updateAllParents(finalTree, finalTree.size());   // update all parents based off of the last node updated
}




int main()
{
	// begin program for real this time
	vector<Tree> finalTree;
	finalTree.push_back(Tree());           // tree at position 0 is a default tree that should never be referenced. 
	finalTree.push_back(Tree());           // tree at position 1 is a default tree that can be referenced. 

	cout << "test 1";
	int parentposition = finalTree.size() / 2;
	cout << "parent position is:" << parentposition << endl;
	string parentID = finalTree.at(parentposition).ID;
	addNewNode(finalTree);
	cout << "testing if new node was added" << endl;
	
	cout << "worked?" << endl; 
	system("pause");
	
	
	
	



















    return 0;
}








