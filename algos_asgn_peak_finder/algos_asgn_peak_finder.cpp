// algos_asgn_peak_finder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
using namespace std;

int findRowsColumns(string inputFile);

int main(int argc, char* argv[]) //Input file from command-line. 
{
	cout << "Welcome to Peak Finder!" << endl;

	//declaring input and output file streams
	ifstream inFile;
	ofstream outFile;

	//Checking for input of more than 1 file. If so, return as error.
	if (argc != 2)
	{
		cerr << "Use only one file as input." << endl;
		return 1;
	}

	inFile.open(argv[1]); //opening file


	if (inFile.is_open()) //proceed only if file open or valid
	{
		//findRowsColumns();
		
		inFile.close();
	}

	else
	{
		cout << "Please choose a valid input file" << endl << endl;
	}

    return 0;
}

int findRowsColumns(string inputFile)
{

	return 0;
}
