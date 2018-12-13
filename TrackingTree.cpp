// TrackingTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"




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

	// begin program for real htis time
	vector<Tree> finalTree;
	theTree.push_back(Tree());           // tree at position 0 is a default tree
	
	
	
	




















    return 0;
}

void growTree(vector<Tree>& finalTree) {
	finalTree.push_back(Tree());

}





