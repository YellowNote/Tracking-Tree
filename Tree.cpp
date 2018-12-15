#include "stdafx.h"
#include "Tree.h"


void Tree::CreateEvent() {
	static const char alpha[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"1234567890";
	int stringLength = sizeof(alpha) - 1;
	string newevnt = "";
	for (int i = 0; i < 10; i++) {
		char c = alpha[rand() % stringLength];
		newevnt.push_back(c);
	}
	Tree::Event = newevnt;
	
}

void Tree::CreateEvent(string input) {
	Tree::Event = input;
}

string Tree::createID(int position, string parent) {
	if (position == 1)             // if this is our first actual tree we create a random parent ID
	{
		static const char alpha[] =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"1234567890";
		int stringLength = sizeof(alpha) - 1;
		string newevnt = "";
		for (int i = 0; i < 10; i++) {
			char c = alpha[rand() % stringLength];
			newevnt.push_back(c);
		}
		Tree::ParentID = newevnt;
	}
	else
	{
		ParentID = parent;
	}
	string id = hashing(ParentID).substr(0,3) + hashing(Event).substr(0,3);  // the ID is the concatenation of the parent id hashed for the first 4 chars and the has of event for the last 4
	return id;
}

string Tree::hashing(string thingToHash) { // have a generic hashing but we can still make our own
	size_t HashedItem = hash<string>{}(thingToHash);
	oss.clear();
	oss << HashedItem;
	//return oss.str().substr(0,8);
	return thingToHash.substr(0, 8);
}

void Tree::updateParentHash(Tree &childnode, Tree &parentnode) {

	if (childnode.position % 2 == 0) // this is a left child in this case
	{
		parentnode.LHist.push_back(parentnode.LHash); // we update the history before we change the hash
		parentnode.LHash = hashing(childnode.Event);
	}
	else // right tree
	{
		parentnode.RHist.push_back(parentnode.RHash);
		parentnode.RHash = hashing(childnode.Event);
	}


}

void Tree::printNode() {
	cout << "ID: " << this->ID << endl;
	cout << "event: " << this->Event << endl;
	cout << "left hash: " << this->LHash << endl;
	cout << "right hash: " << this->RHash << endl;
	// string s1 = accumulate(begin(this->LHist), end(this->LHist), s1); // s1 is the string made from all of the strings in Lhist
	// string s2 = accumulate(begin(this->RHist), end(this->RHist), s2); // S2 is the string made from all the sting in Rhist
	cout << "left History: last item"  << endl;
	cout << "right History: last item " << endl;

}



// Constructors
Tree::Tree() {  // default constructor for use only with the first node in our tree, will always have a random event for simplicity
	 ID = createID(1, "");
	 CreateEvent();
	 position = 1;
	 
	 


}
Tree::Tree(string parentID, vector<Tree>& finalTree) {  // constructor that allows us to build children passing the parents ID to the child, randomly generating the event, also assigning proper position
	ID = createID(2, parentID);
	CreateEvent();
	position = finalTree.size();
}
// not using this constructor for simplicity
/*
Tree::Tree(string parent, string eventtoadd) { // constructor that allos us to build the children from parent ID and a string event passed as an argument 
	ID = createID(2, parent);
	CreateEvent(eventtoadd);
}
*/



//TODO UpdateHash
//TODO UpdateHistory

