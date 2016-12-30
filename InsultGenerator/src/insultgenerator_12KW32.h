/*
 * Using textfileioe.h as a reference to help build this, written by Alan McLeod for the CISC/CMPE 320 course at Queen's University
 */
#pragma once

#include <string>
#include <vector>
#include <time.h>
using namespace std;

class FileException {
public:
	//Allow the exception to throw an individualized message
	FileException(const string& message);
	string& what();
private:
	string message;
};

class NumInsultsOutOfBounds {
public:
	//Allow the exception to throw an individualized message
	NumInsultsOutOfBounds(const string& message);
	string& what();
private:
	string message;
};

class InsultGenerator {
public:
	InsultGenerator(); //void constructor for the InsultGenerator
	void initialize(); //populates the insults arrays from the text file
	string talkToMe()const; //generates a single random insult
	vector<string> generate(int n) const; //generates n number of insults
	vector<string> generateAndSave(string filename, int n)const; //generates n number of insults by calling the generate(int n) function
private:
	vector<string> insults1; //used to store the first column of words
	vector<string> insults2; //used to store the second column of words
	vector<string> insults3; //used to store the third column of words
};
