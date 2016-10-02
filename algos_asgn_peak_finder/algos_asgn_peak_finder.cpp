// algos_asgn_peak_finder.cpp : Defines the entry point for the console application.
//Author: Shreyas Subramanya Bhat
//Student ID: 800958406
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

int** fileToArray(string inFileName, int* rowCount, int* colCount); // function to convert the input FILE to a 2D array and return to main for further computation.

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
	int rowCount = 0, colCountNew = 0;
	int** inArray = fileToArray(pathNFileName, &rowCount, &colCountNew);

	/*****    To displaying the array we just imported
	for (int i = 0; i < rowCount; i++)
	{
		for (int k = 0; k < colCountNew; k++)
		{
			cout << inArray[i][k] << " ";
		}
		cout << endl;
	} */

    return 0;
}


//int** fileToArray(string inFileName)
int** fileToArray(string inFileName, int* rowCount, int* colCountNew)
{
	ifstream inFile;

	// Finding row and column counts
	inFile.open(inFileName, ios_base::in);

	if (inFile.is_open())
	{
		
		string eachLine;
		vector <int> getElements; //this vector size will give the column size
		
		string tempString, restLine, eachRow;
		*rowCount = 0;
		int colCount = 0;
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
			cout << restLine << endl;						//restLine stores just the array part
			cout << endl;

			//iterate till the end of restLine to find all rows and store inside the vector getElements.
			while (restLine.find("[[[") != 0)				
			{
				//extracting each row
				pos2 = restLine.find("[");
				pos3 = pos2 + 2;
				pos4 = restLine.find("]") - 2;
				
				eachRow = restLine.substr(pos3, pos4);
				cout << "Fetching next row of the input Array: " << eachRow << endl;

				// extracting each element of the row
				stringstream lineStream(eachRow);
				string value;
				cout << "storing each value: " << endl;
				while (getline(lineStream, value, ','))
				{
					getElements.push_back(stoi(value));
					cout << stoi(value) << endl;
					++colCount;								//increment column count for the array
				}
				++(*rowCount);									//increment row count for the array

				if (restLine.length() - pos4 > 4)
					restLine = restLine.substr(pos4 + 5);	// shortening the original data extraction
					restLine.insert(0, "[");

				if (restLine.find("[[[") != 0)
					cout << restLine << endl << endl;
				
			}
		}
		cout << endl;
		cout << "Row count: " << *rowCount << endl;
		*colCountNew = colCount / *rowCount;
		cout << "Column count: " << *colCountNew << endl;
		inFile.close();

		
		//initializing array
		int** my2dArray = new int* [*rowCount];
		for (int i = 0; i < *rowCount; ++i)
		{
			my2dArray[i] = new int[*colCountNew];
		}

		//Reading vector and storing values in a 2D Array.
		auto iElementLocator = getElements.begin();
		while (iElementLocator != getElements.end())
		{
			for (int j = 0; j < *rowCount; j++)
			{
				for (int k = 0; k < *colCountNew; k++)
				{
					my2dArray[j][k] = *iElementLocator;
					iElementLocator++;
				}
			}			
		}		
		return my2dArray;
	}
	else
	{
		cout << "fail :( " << endl;
	}
}
