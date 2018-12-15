#pragma once


#include<string>
#include<vector>
#include<iostream>
#include<numeric> // this is used to turn our history into a string for print/debug
#include<functional> //Adds hash
#include<sstream> //Allows for the hash to be put into a string

using namespace std;

struct  Tree
{
	int position;
	int LChildPos;
	int RChildPos;
	int ParentPos;
	string ID;
	string ParentID;
	string Event;
	string LHash;
	string RHash;
	vector<string> LHist, RHist;
	ostringstream oss;

	void CreateEvent();
	void CreateEvent(string input);

	string createID(int position, string parent);
	string hashing(string thingToHash);

	void updateParentHash(Tree& childnode, Tree& parentnode);
	void printNode();
	void updateNode();

	//constructors
	Tree();  // default constructor for use only with the first node in our tree
	Tree(string parent, vector<Tree>& finalTree);  // construct that allows us to build children passing the parents ID to the child, randomly generating the event
	//Tree(string parent, string eventtoadd); // constructor that allos us to build the children from parent ID and a string event passed as an argument 



};





//TODO CreateID             // this is written and needs to be tested. 
//TODO CreateEvent          // this is written and needs to be tested.             
//TODO UpdateHash
//TODO UpdateHistory
// utility functions for trackingTree.cpp


