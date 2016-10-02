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

//int** fileToArray(string inFileName);
int fileToArray(string inFileName);

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

	//int** inArray = fileToArray(pathNFileName);
	fileToArray(pathNFileName);

	//findRowsColumns(pathNFileName);

    return 0;
}


//int** fileToArray(string inFileName)
int fileToArray(string inFileName)
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
		vector <int> getElements; //this vector size will give the column size
		//vector <int> getCol; //this vector size will give the row size
		string tempString, restLine, eachRow;
		char tempChar;
		bool rowStart = false;
		int rowCount = 0, colCount = 0, length = 0;
		//int temp;
		size_t pos1, pos2, pos3, pos4;

		while (inFile.good())
		{
			// getting rid of unwanted text in file 
			getline(inFile, tempString);
			pos1 = tempString.find("[[");
			cout << pos1 << endl;
			restLine = tempString.substr(pos1);
			cout << "The input Matrix from file is:" << endl << endl;
			cout << restLine << endl;					//restLine stores just the array part
			cout << endl;

			//find string length of each row

			pos2 = restLine.find("[");
			pos3 = pos2 + 2;
			pos4 = restLine.find("]") - 2;
			eachRow = restLine.substr(pos3, pos4);
			length = eachRow.length();
			cout << length << endl;

			while (restLine.find("[[[") != 0)				//iterate till the end of restLine to find all rows
			{
				//extracting each row
				pos2 = restLine.find("[");
				pos3 = pos2 + 2;
				pos4 = restLine.find("]") - 2;
				
				eachRow = restLine.substr(pos3, pos4);
				cout << eachRow << endl;
				cout << "end of string is: ";
				cout << restLine.back() << endl;

				// extracting each element of the row

				stringstream lineStream(eachRow);
				string value;
				while (getline(lineStream, value, ','))
				{
					getElements.push_back(stoi(value));
					cout << stoi(value) << endl;
					++colCount;							//increment column count for the array
				}
				++rowCount;								//increment row count for the array
				//int gapCheck = restLine.length() - pos4;
				//if (gapCheck > length-5)
				if (restLine.length() - pos4 > 4)
					restLine = restLine.substr(pos4 + 5);	// shortening the original data extraction
				//if (restLine[0] != '[')
					restLine.insert(0, "[");

				cout << restLine << endl << endl;
				cout << "Row count: "<< rowCount << endl;
				cout << endl;
			}
		}
		cout << "Column count: " << colCount / rowCount << endl;
		inFile.close();
	}
	else
	{
		cout << "fail :( " << endl;
	}
	//return my2DArray;
	return 0;
}
