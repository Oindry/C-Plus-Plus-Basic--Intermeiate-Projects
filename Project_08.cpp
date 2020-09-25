// ****************************************
// Program Title: Sample header file
// Project File: Project_07.cpp
// Name: Ashraf Sehba Tabil Oindry
// Course Section: CPE-211-01 
// Lab Section: 01
// Due Date: 10/18/19 
// program description: Using Function to calculate PI and calculate probability
// ****************************************

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "P08.h"

using namespace std;
// ****************************************************************
// **  This file is the only file that students 
// **  need to modify.  Place code into the functions
// **  shown to perform the operations required
// ****************************************************************

// ################################################################
// For all functions in this file, 
// Use the function prototypes in P08.h to create the paramter 
// declarations required for these functions
// ################################################################


// ****************************************************************
// ****************************************************************
// An input file stream parameter is needed for this function
void OpenInputFile(ifstream& infile)
{
	// This function obtains the name of the input file and opens it.
	// as long as the input file does not exist, continue to prompt for
	// the input file stream until a valid file is entered or the user
	// aborts the program by typing ctrl-c
	cout <<endl<< "Enter in the name of the input file (ctrl-c to exit): ";
	string inFileName;
	cin >> inFileName;
	cout << inFileName << endl << endl;
	infile.open(inFileName.c_str());
	while (infile.fail()) {
		cout << STAR << STAR << STAR << STAR << STAR << endl;
		cout << "==> " << inFileName << " is an invalid file!! Try Again." << endl;
		cout << STAR << STAR << STAR << STAR << STAR << endl << endl;
		infile.clear();
		cout << "Enter in the name of the input file (ctrl-c to exit): ";
		cin >> inFileName;
		cout << inFileName << endl << endl;
		infile.open(inFileName.c_str());
	}
}

// ****************************************************************
// ****************************************************************
// An output file stream parameter is needed for this function
void OpenOutputFile(ofstream& outfile)
{
	// This function obtains the name of the output file and opens it.
	// as long as the output file does not exist, continue to prompt for
	// the output file stream until a valid file is entered or the user
	// aborts the program by typing ctrl-c
	// ===>  use out/file/txt as an output file name that will not open. 
	cout << "Enter in the name of the output file: ";
	string outFileName;
	cin >> outFileName;
	cout << outFileName << endl << endl;
	outfile.open(outFileName.c_str());
	while (outfile.fail()) {
		cout << STAR << STAR << STAR << STAR << STAR << endl;
		cout << "==> " << outFileName << " is an invalid file!! Try Again."<<endl;
		cout << STAR << STAR << STAR << STAR << STAR << endl << endl;
		outfile.clear();
		cout << "Enter in the name of the output file (ctrl-c to exit): ";
		cin >> outFileName;
		cout << outFileName << endl << endl;
		outfile.open(outFileName.c_str());
	}	

}

// ****************************************************************
// ****************************************************************
// An input file stream paramter is needed, and a DirectoryInfo structure
// parameter is needed
bool ReadInformation(ifstream& infile, DirectoryInfo& dirInfo) 
{
	// This function reads the information for a single employee from
	// the jumbled directory.  This information is stored directly into the
	// proper structure member, and the structure is returned back to 
	// the caller of this function.

	// This function returns true if the employee information 
	// in the jumbled directory is read correctly
	static int k = 0;
	k++;
	string text;
	if (k == 1) {
		getline(infile, text);
		dirInfo.employeeName.title = text;
		if (infile.eof()) {
			cout << STAR << STAR << STAR << STAR << STAR << endl;
			cout << "===>  Reading the title of the first employee failed."<<endl;
			cout << "===>  The input file contained a directory title only"<<endl;
			cout << "===>  No employee information was written to the output file"<<endl;
			cout << STAR << STAR << STAR << STAR << STAR << endl << endl;
			return false;
		}
		getline(infile, text);
		dirInfo.employeeAddress.street = text;
		getline(infile, text);
		dirInfo.employeePhone.cell = text;
		getline(infile, text);
		dirInfo.employeeName.last = text;
		getline(infile, text);
		dirInfo.employeePhone.home = text;
		getline(infile, text);
		dirInfo.employeeAddress.cityState = text;
		getline(infile, text);
		dirInfo.employeeName.first = text;
		getline(infile, text);
		dirInfo.employeePhone.work = text;
		getline(infile, text);
		dirInfo.employeeAddress.zipCode = text;
		return true;
	}
	else if ((k > 0)) {
		getline(infile, text);
		dirInfo.employeeName.title = text;
		if (infile.eof()) {
			return false;
		}	
		else {
			getline(infile, text);
			dirInfo.employeeAddress.street = text;
			getline(infile, text);
			dirInfo.employeePhone.cell = text;
			getline(infile, text);
			dirInfo.employeeName.last = text;
			getline(infile, text);
			dirInfo.employeePhone.home = text;
			getline(infile, text);
			dirInfo.employeeAddress.cityState = text;
			getline(infile, text);
			dirInfo.employeeName.first = text;
			getline(infile, text);
			dirInfo.employeePhone.work = text;
			getline(infile, text);
			dirInfo.employeeAddress.zipCode = text;
			return true;
		}
	}
	// dummy value returned until the function definition
	// is written and a real value can be returned
}

// ****************************************************************
// ****************************************************************
// An output file stream paramter is needed, and a DirectoryInfo structure
// parameter is needed
void PrintInformation(ofstream& outfile, DirectoryInfo dirInfo)
{
	// output the employee information stored in a DirectoryInfo structure
	// to the new directory being created in the output file
	// separate the information for each employee by a row of asterisks
	static int i = 1;
	outfile << setw(35) << right << "Employee #" << i << endl;
	outfile << dirInfo.employeeName.title << " ";
	outfile << dirInfo.employeeName.first << " ";
	outfile << dirInfo.employeeName.last << endl;
	outfile << dirInfo.employeeAddress.street << endl;
	outfile << dirInfo.employeeAddress.cityState << ", ";
	outfile << dirInfo.employeeAddress.zipCode << endl;
	outfile << dirInfo.employeePhone.home << "(H)" << endl;
	outfile << dirInfo.employeePhone.cell << "(C)" << endl;
	outfile << dirInfo.employeePhone.work << "(W)" << endl;

	outfile << STAR << STAR << STAR << STAR << STAR << endl;	
	i++;
}
