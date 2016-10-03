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
int peakFinder(int** inPeakArray, string pathName, int rows, int columns);									// function to find peak of the matrix and output to a FILE.

int main() 
{
	//intro
	cout << "Welcome to Peak Finder!" << endl;
	cout << " **Note: The file and path cannot contain spaces**" << endl;
	cout << endl;

	string pathNFileName;
	string pathName;
	string fileName;
	cout << "Enter the path of the input (without spaces and ending with '\') and press ENTER" << endl;
	cin >> pathName;
	cout << "Enter the filename with extension (without spaces) and press ENTER" << endl;
	cin >> fileName;
	pathNFileName = pathName + fileName;

	//declaring input file streams
	ifstream inFile;
	
	cout << endl;	
	int rowCount, colCountNew;
	int** inArray = fileToArray(pathNFileName, &rowCount, &colCountNew);

	//   To displaying the array we just imported
	for (int i = 0; i < rowCount; i++)
	{
		for (int k = 0; k < colCountNew; k++)
		{
			cout << inArray[i][k] << " ";
		}
		cout << endl;
	} //*****/
	cout << endl;
	peakFinder(inArray, pathName, rowCount, colCountNew);

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

int peakFinder(int** inPeakArray, string pathName, int rows, int columns)
{
	ofstream outFile;
	string outputFile = pathName + "output.txt";
	outFile.open(outputFile, ios_base::out);

	if (outFile.is_open())
	{
		int halfRows = rows / 2;		// to divide array into 4 quadrants 
		int halfCols = columns / 2;		// to divide array into 4 quadrants
		int temp1;
		int N, S, W, E; // to store north, south, west and east neighbors of an element

		for (int i = 1; i < columns-1; i++)
		{
			for (int j = 1; j < rows-1; j++)
			{
				N = inPeakArray[i - 1][j];
				S = inPeakArray[i + 1][j];
				W = inPeakArray[i][j-1];
				E = inPeakArray[i][j+1];
				if ((inPeakArray[i][j] >= N) && (inPeakArray[i][j] >= S) && (inPeakArray[i][j] >= W) && (inPeakArray[i][j] >= E))
				{
					outFile << "Peak at (" << i+1 << "," << j+1 << ") = " << inPeakArray[i][j] << "\n" << endl;
				}
				else
				{
					//outFile << "No peaks found. \n";
					continue;
				}			
			}
		}


		outFile.close();
		return 0;
	}
	else
	{
		cout << "Unable to save to the destination" << endl;
		return 1;
	}
}
