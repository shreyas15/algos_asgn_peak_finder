// algos_asgn_peak_finder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "iomanip"
#include "string"
#include "sstream"
#include "vector"

using namespace std;

void findRowsColumns(string inFileName, int& inArray);

int main(int argc, char* argv[]) 
{
	//intro
	cout << "Welcome to Peak Finder!" << endl;
	cout << "Enter the name of the file to be read for input and press ENTER" << endl;
	cout << " **Note: The file and path cannot contain spaces**" << endl;
	cout << endl;

	string inFileName = argv[1];

	//declaring input and output file streams
	ifstream inFile;
	ofstream outFile;

	inFile.open(inFileName);
	cout << endl;

	int inArray[1000][1000] = { {0} };
	
	//Checking for input of more than 1 file. If so, return as error.
	if (argc != 2)
	{
		cerr << "Use only one file as input." << endl;
		return 1;
	}

	/////////////inFile.open(argv[1]); //opening file


	if (inFile.is_open()) //proceed only if file open or valid
	{
		findRowsColumns(inFileName, inArray[1000][1000]);
		
		inFile.close();
	}

	else
	{
		cout << "Please choose a valid input file" << endl << endl;
	}

    return 0;
}


void findRowsColumns(string inFileName, int & inArray)
{
	ifstream inFile;
	inFile.open(inFileName);
	if (inFile.is_open())
	{

	}
	else
	{

	}
	//return 0;
}
