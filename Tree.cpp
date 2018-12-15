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
	string idpart1 = hashing(ParentID).substr(0, 4);
	string idpart2 = hashing(Event).substr(0, 4);
	string id = idpart1 + idpart2;  // the ID is the concatenation of the parent id hashed for the first 4 chars and the has of event for the last 4
	return id;
}

string Tree::hashing(string thingToHash) { // have a generic hashing but we can still make our own
	size_t HashedItem = hash<string>{}(thingToHash);
	oss.clear();
	oss << HashedItem;
	return oss.str().substr(0,8);
	//return thingToHash.substr(0, 8);
}

void Tree::updateParentHash(Tree &childnode, Tree &parentnode) {

	if (childnode.position % 2 == 0) // this is a left child in this case
	{	
		if (parentnode.LHash != hashing(childnode.Event)){ // if the hash of the child node is different than what the parent had stored before
		parentnode.LHist.push_back(parentnode.LHash); // we update the history before we change the hash
		parentnode.LHash = hashing(childnode.Event); // then we change the hash
		
		}
	}
	else // right tree
	{
		if (parentnode.RHash != hashing(childnode.Event)) {
		parentnode.RHist.push_back(parentnode.RHash);
		parentnode.RHash = hashing(childnode.Event);
		
		}
	}


}

void Tree::printNode() {
	cout << "Position, Left Child Position, Right Child Position, Parent Position:  " << this->position << ", " << this->LChildPos << ", " << this->RChildPos << ", " << this->ParentPos << endl;
	cout << "ID: " << this->ID << endl;
	cout << "event: " << this->Event << endl;
	cout << "left hash: " << this->LHash << endl;
	cout << "right hash: " << this->RHash << endl;
	
	
	if (!LHist.empty()) {
		string s1 = "Left History: ";
		for (int i = 0; i < LHist.size() - 1; i++) {
			s1 = s1 + LHist.at(i);
		}
		cout << s1 << endl;
	}
	else {
		cout << "empty!" << endl;
	}
	if (!RHist.empty()) {
		string s2 = "Right History: ";
		for (int i = 0; i < RHist.size() - 1; i++) {
			s2 = s2 + RHist.at(i);
		}
		cout << s2 << endl;
	}
	else {
		cout << "empty!" << endl;
	}
}

void Tree::updateNode() {	
	cout << "Current Event:" << endl;
	cout << Event << endl;
	cout << "Enter modified event: " << endl;

	cin >> Event;
}

// Constructors
Tree::Tree() {  // default constructor for use only with the first node in our tree, will always have a random event for simplicity
	 CreateEvent();
	 ID = createID(1, "");
	 position = 1;
	 RChildPos = position * 2 + 1;
	 LChildPos = position * 2;
	 ParentPos = 1;
	 
	 


}
Tree::Tree(string parentID, vector<Tree>& finalTree) {  // constructor that allows us to build children passing the parents ID to the child, randomly generating the event, also assigning proper position
	CreateEvent();
	ID = createID(2, parentID);
	position = finalTree.size();
	RChildPos = position * 2 + 1;
	LChildPos = position * 2;
	ParentPos = position / 2;
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

