#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <stdlib.h>

#include "insultgenerator_12KW32.h"

using namespace std;

InsultGenerator::InsultGenerator() {}

void InsultGenerator::initialize(){
	string line;
	ifstream inputfile("InsultsSource.txt");
	if (inputfile.is_open()){
		int space;
		while (getline(inputfile, line)){
			space = line.find('\t');
			insults1.push_back(line.substr(0,space));

			line = line.substr(space+1);
			space = line.find('\t');
			insults2.push_back(line.substr(0,space));

			line = line.substr(space+1);
			insults3.push_back(line.substr(0));
		}
		inputfile.close();
	}
	else throw FileException("File not found.");
}

string InsultGenerator:: talkToMe()const{
	//A zinger (that's a real zinger!)
	string zinger;
	if (insults1.size()>0 && insults2.size()>0 && insults3.size()>0)
	 zinger = "Thou "+(insults1.at(rand()%50)) + " " + (insults2.at(rand() %50)) + " "
			 + (insults3.at(rand()%50)) + " !";
	else
		throw  FileException("Filename is invalid.");
	return(zinger);
}

vector<string> InsultGenerator::generate(int n)const{
	//Also just another word for an insult, if you're curious
	string zinger;
	vector<string> output;

	if (n>=1 && n<=10000){
		for(int i = 0; i < n; i++){
			zinger = "Thou " + (insults1.at(rand()%50)) + " " + (insults2.at(rand()%50)) + " "
							+ (insults3.at(rand()%50)) + "!";
			if (find(output.begin(), output.end(), zinger) == output.end()){
				output.push_back(zinger);
				i++;
			}
		}
	}
	else
		throw NumInsultsOutOfBounds("Please enter a number between 1 and 10 000.");
	return output;
}

vector<string> InsultGenerator::generateAndSave(string filename, int n)const{
	vector <string>output;
		string insult;
		if (n>0 && n<=10000){
			if (filename.size()>0){
			output = generate(n);
			ofstream mf (filename.c_str());
			for (int i = 0; i <output.size(); i++){
				insult = output.at(i)+"\n";
				mf <<insult<< endl;
				i++;
			}
			mf.close();
			}
			else throw FileException("Filename is invalid.");
		}
		else throw NumInsultsOutOfBounds("Please enter a number between 1 and 10 000");
		return output;
}

FileException::FileException(const string& message) : message(message) {}
string& FileException::what() { return message; }

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message){}
string& NumInsultsOutOfBounds::what() { return message; }

