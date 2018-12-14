// TrackingTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"













void updateAllParents(vector<Tree>& finalTree, int childposition) {
	if (childposition == 1) {
		cout << "all parents were updated" << endl;        // if this is our root node there are no more trees to update
	}
	else {
		int parentposition = -1;
		if (childposition % 2 == 0) { // if this is even it is a left child
			parentposition = childposition / 2;
		}
		else {
			parentposition = (childposition - 1) / 2;
		}
		finalTree.at(0).updateParentHash(finalTree.at(childposition), finalTree.at(parentposition));  // update the the parent's history
		updateAllParents(finalTree, parentposition); // recursively call updateAllParents on the parent node to percolate to the top`

	}

}


void addNewNode(vector<Tree>& finalTree, int parentposition) {
	std::vector<Tree>::iterator it = finalTree.begin() + parentposition;                               // needs to be able to accesss an empty part of teh vector without crashing will work on it
	if (it._Ptr == NULL ) {       // if the tree at position parent *2 doesn't exist 
		finalTree.at(parentposition * 2) = Tree(finalTree.at(parentposition).ParentID);  // add a child there aka left node
		updateAllParents(finalTree, (parentposition / 2));
	}
	else {
		finalTree.at(parentposition * 2 + 1) = Tree(finalTree.at(parentposition).ParentID); // if there is a left child already add a right child
		updateAllParents(finalTree, (parentposition * 2 + 1));
	}


}




int main()
{
	
	vector<Tree> theTree;
	cout << "stop0" << endl;
	cout << "stop1" << endl; 
	theTree.push_back(Tree());
	theTree.push_back(Tree("parenthashing"));
	theTree.push_back(Tree("parenthas", "this is the event i want to have hashed"));
	
	cout << "yes";
	string testevent = theTree.at(0).Event;
	string testevent1 = theTree.at(1).Event;
	string testevent2 = theTree.at(2).Event;
	cout << "stop2" << endl;
	cout << testevent << endl;
	cout << testevent1 << endl;
	cout << testevent2 << endl;
	system("pause");                                             // constructors work as intended 

	// begin program for real this time
	vector<Tree> finalTree;
	theTree.push_back(Tree());           // tree at position 0 is a default tree that should never be referenced. 
	theTree.push_back(Tree());           // tree at position 1 is a default tree that can be referenced. 
	addNewNode(finalTree, 1);
	cout << "testing if new node was added" << endl;
	cout << finalTree.at(2).Event << endl;
	cout << "worked?" << endl; 
	
	
	
	



















    return 0;
}








