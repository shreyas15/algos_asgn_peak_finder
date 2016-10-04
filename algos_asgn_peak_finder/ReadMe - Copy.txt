========================================================================
    CONSOLE APPLICATION : algos_asgn_peak_finder Project Overview
========================================================================

//Author: Shreyas Subramanya Bhat
//Student ID: 800958406

Language used: C++ 11
IDE and Compiler : Visual Studio Community 2015

This file contains a summary of what you will find in each of the files that
make up your algos_asgn_peak_finder application.


algos_asgn_peak_finder.cpp
    This is the main application source file.


Description of program design:
------------------------------
The program makes use of strings and string streams in C++ to read and store values into a full fledged 2D array. This array is dynamically allocated memory and is handled throughout by reference. Apart from the Main() function, I am making use of two other functions namely:
1) int** fileToArray(string inFileName, int* rowCount, int* colCount) -> function to convert the input FILE to a 2D array and return to main for further computation.
2) int peakFinder(int** inPeakArray, string pathName, int rows, int columns) -> function to find peak of the matrix and output to a FILE. 

Algorithm implementation
------------------------
To find the peak, the 4 neighbors of an element are checked. The neighbors are those which are to the north, south, west and east of an element in the array. Peaks are not searched for in the boundary of the matrix. A column by column search is performed to find the local peaks. The steps are: 
1) Iterate through columns
2) (m-2) elements of that column are checked, because the boundary is excluded.
3) for each element, the 4 neighbors are checked if lesser than the center element. If so, it's a peak. Go to step 4. Else go to step 5.
4) write the value and associated indices of the value to output.txt
5) continue through the loop until remaining columns are checked.

Data structures and types used
--------------------
String class
StringStream class
Vectors (specialty of C++)
Dynamic 2D array


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named algos_asgn_peak_finder.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

TO INPUT a text file containing array
-------------------------------------

Upon the first prompt "Enter the path of the input as is (without spaces and ending with '\') and press ENTER", 
enter the path ONLY, ending with a \.
	- Ex. D:\Test Files\

Upon the second prompt "Enter the filename with extension (without spaces) and press ENTER", 
enter the name of the file with extension.
	- Ex. test.txt

OUTPUT of the Program
---------------------

Apart from the various console messages, the "output.txt" file is same as that of the program folder.


/////////////////////////////////////////////////////////////////////////////
