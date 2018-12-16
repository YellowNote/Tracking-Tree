#pragma once


#include<string>
#include<vector>
#include<iostream>
#include<numeric> // this is used to turn our history into a string for print/debug
#include<functional> //Adds hash
#include<sstream> //Allows for the hash to be put into a string

using namespace std;

struct  Tree
{	//Variables
	int position, LChildPos, RChildPos, ParentPos;
	string ID, ParentID, Event, LHash, RHash, input;
	vector<string> LHist, RHist;

	void CreateEvent();//Auto Creation of event
	void CreateEvent(string input);//Manual Creation of event

	string createID(int position, string parent);//Creates ID
	string hashing(string thingToHash);//Hashes whatever is put into it

	void updateParentHash(Tree& childnode, Tree& parentnode);
	void printNode();
	void updateNode();

	//constructors
	Tree();  // default constructor for use only with the first node in our tree
	Tree(string parent, vector<Tree>& finalTree);  // construct that allows us to build children passing the parents ID to the child, randomly generating the event

};


