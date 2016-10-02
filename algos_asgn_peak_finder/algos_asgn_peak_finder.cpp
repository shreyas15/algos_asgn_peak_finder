// algos_asgn_peak_finder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "iomanip"
#include "string"
#include "sstream"
#include "vector"
#include "deque"

using namespace std;

int** fileToArray(string inFileName);

//int inArray[1000][1000];

int main() 
{
	//intro
	cout << "Welcome to Peak Finder!" << endl;
	cout << "Enter the name of the file to be read for input and press ENTER" << endl;
	cout << " **Note: The file and path cannot contain spaces**" << endl;
	cout << endl;

	string pathNFileName;
	cin >> pathNFileName;

	//declaring input and output file streams
	ifstream inFile;
	ofstream outFile;
	cout << endl;	

	int** inArray = fileToArray(pathNFileName);

	//findRowsColumns(pathNFileName);

    return 0;
}


int** fileToArray(string inFileName)
{
	ifstream inFile;
	int row = 1000, col = 1000;
	int** my2DArray = new int*[row];

	// Finding row and column counts
	inFile.open(inFileName, ios_base::in);
	if (inFile.is_open())
	{
		//cout << "success!" << endl;
		string eachLine;
		vector <int> getRow; //this vector size will give the column size
		vector <int> getCol; //this vector size will give the row size
		string tempString;
		char tempChar;
		bool rowStart = false;

		while (inFile.good())
		{
			while (getline(inFile, tempString))
			{
				istringstream ss(tempString);
				while( ss >> tempChar)
				{
					if (((tempChar - '0') == 43)) //this means we found a '['
					{
						continue;
					}
					else if ((tempChar - '0') == 45) //this means we found a ']'
					{
						rowStart = false;
					}
					else if ((tempChar - '0') == -4) //this means we found a ','
					{
						continue;
					}
					else if ((tempChar - '0') == -16) //this means we found a SPACE
					{
						continue;
					}
					else
					{
						rowStart = true;
						getRow.push_back(tempChar - '0');
					}

					/*cout << "This symbol as is " << tempChar << endl;
					cout << "This symbol in decimal is " << tempChar - '0' << endl;
					cout << endl; */
				}
			}
			
		}

		inFile.close();
	}
	else
	{
		cout << "fail :( " << endl;
	}
	return my2DArray;
}
