// ****************************************
// Program Title: Sample header file
// Project File: Cpp_header.cpp
// Name: Ashraf Sehba Tabil Oindry
// Course Section: CPE-211-01 
// Lab Section: 01
// Due Date: 10/07/19 
// program description: Takes input and output files from command line and reads inputfile and creates outputfile
// Checks for valid input and output files to work with.
// For files that contain student and their scores, creates output data in a modified way
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char*argv[])
{
	if(argc!=3) //Command line argument check
	{
		cout<<endl<<"Incorrect number of command line arguments provided."<<endl;
		cout<<"This program requires 2 command line arguments:"<<endl;
		cout<<"An input filename and an output filename"<<endl<<endl;
		cout<<"Program usage is:"<<endl;
		cout<<"./Project_06 InputFileName OutputFileName"<<endl<<endl;
	return 1;
	}
	//Command line user defined command's variable declaration
	string value0=argv[0];
	string infile=argv[1];
	string outfile=argv[2];
	
	ifstream file;
	ofstream out;
	
	//Opens input file
	file.open(infile.c_str());
	cout<<endl<<"Opening Input File: "<<infile;
	//Checks if the inputfile is valid and asks user to put valid file till it is not a valid inputfile.
	while(file.fail())  
	{	
		cout << endl<<endl<<string(15,'*') <<" File Open Error "<< string(15,'*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << infile<< endl;
		cout << "==> Please try again..."<<endl;
		cout << string(47,'*') << endl<<endl;
		infile.clear();
		cout<<"Enter the name of the input file: ";
		cin>>infile;
		file.open(infile.c_str());
		cout<<infile;	
	}
		

	out.open(outfile.c_str());	
	cout<<endl<<endl<<"Opening Output File: "<<outfile<<endl<<endl;
	//Checks if the outputfile is valid and asks user to put valid file till it is not a valid outputfile.
	while(out.fail())
	{
		cout << string(15,'*') <<" File Open Error "<< string(15,'*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outfile<< endl;
		cout << "==> Please try again..."<<endl;
		cout << string(47,'*') << endl<<endl;
			
		outfile.clear();
		cout<<"Enter the name of the output file: ";
		cin>>outfile;
		out.open(outfile.c_str());
		cout<<outfile<<endl<<endl;
	}
	
	//Variable Declaration for reading inputfile and creating outputfile
	int quiznum,HWnum,Examnum,quiztot,HWtot,Examtot;
	file>>quiznum>>HWnum>>Examnum;
	float Keytotal,Studenttotal,Keytotal1,ClassAvg,Classtotal=0;
	int quiz,HW,Exam,quiz1,HW1,Exam1;
	float KeyAvg;
	string Key,Max,first,last;
	float i=-1; 
	int r=-1;
	file>>Max>>Key;
	if(file.eof()) // Checks if the file is Empty and prints a message for the user if the file is empty
	{
		cout << string(13,'*') << " Input File Is Empty "<< string(13,'*') << endl;
		cout << "==> The input file is empty.\n";
		cout << "==> Terminating the program.\n";
		cout << string(47,'*') << endl << endl;
		out  << "Input file "<<infile<<" is empty."<<endl;
	return 0;
	}
	//Prints 1st line of outputfile for inputfiles that has data
	out<< left << setw(3) << "#" << left << setw(12) << "Last" << left << setw(7) << "First";
	out<< left << setw(6) << "Quiz" << left <<setw(6) << "HW" << left << setw(6) << "Exam";
	out<< left << setw(7) << "Total" << left << setw(9) << "Average" << endl;
	out<< left << setw(3) << "-" << left << setw(12) << "----------" << left << setw(7) << "-----";
	out<< left << setw(6) << "----" << left << setw(6) << "---" << left << setw(6) << "----";
	out<< left << setw(7) << "-----" << left << setw(9) << "-------" << endl;

	//Reads inputfile each lines and creats outputfile useing if,loop and count controlled loop
	while(file)
	{ 	
		quiz=HW=Exam=0;
		Max=Max.substr(0,10);
		Key=Key.substr(0,5);
		r++;
		i++;
		quiztot=0,HWtot=0,Examtot=0,Keytotal=0,Studenttotal=0,KeyAvg=0,Keytotal=0;
		//Calculation for quiz total of each student
		for(int quizcount=0;quizcount<quiznum;quizcount++)
		{
			
			file>>quiz;
			quiztot+=quiz;
			
		}
		//Calculation for Homework's total of each student
		for(int HWcount=0;HWcount<HWnum;HWcount++)
		{
		
			file>>HW;
			HWtot+=HW;
			
			
		}
		//Calculation for Exam's total of each student
		for(int Examcount=0;Examcount<Examnum;Examcount++)
		{	
			
			file>>Exam;
			Examtot=Exam+Examtot;	
			
			
		}
		Keytotal= quiztot+HWtot+Examtot;
	//Prints Key line of the outputfile that contains highest scores in different sections	
	if(r==0)
	{out<< left << setw(3)<<" ";
	Keytotal1=Keytotal;
	KeyAvg=100;	
	out<<setw(12) << Max << left <<left << setw(7) << Key;
	out<< left << setw(6) << quiztot << left <<setw(6) << HWtot << left << setw(6) << Examtot;
	out<< left << setw(7) << fixed<< setprecision(0)<< Keytotal1 << setprecision(2) << left << setw(9) << KeyAvg << endl;
	out<<left << setw(3) << "-" << left << setw(12) << "----------" << left << setw(7) << "-----";
	out<< left << setw(6) << "----" << left << setw(6) << "---" << left << setw(6) << "----";
	out<< left << setw(7) << "-----" << left << setw(9) << "-------" << endl;

	}
	//Prints all student's data
	while(r!=0)
	{out<< left << setw(3)<<setprecision(0)<<i;
	Studenttotal= quiztot+HWtot+Examtot;
	KeyAvg= (Studenttotal/Keytotal1)*100;
	Classtotal+=KeyAvg;
	out<<setw(12) << Max << left <<left << setw(7) << Key;
	out<< left << setw(6) << quiztot << left <<setw(6) << HWtot << left << setw(6) << Examtot;
	out<< left << setw(7) << fixed<< setprecision(0)<< Studenttotal << setprecision(2) << left << setw(9) << KeyAvg << endl;
	r=0;
	}
	
	file>>Max>>Key;
	}
	
	//Checks if there is any student in the file
	if(i<=1)
	{	
		cout<<"Input file did not contain any students"<<endl;
		out<<"Input file did not contain any students"<<endl;
	return 0;
	}
	//Dashes at the end of the outputfile
	out<<left << setw(3) << "-" << left << setw(12) << "----------" << left << setw(7) << "-----";
	out<< left << setw(6) << "----" << left << setw(6) << "---" << left << setw(6) << "----";
	out<< left << setw(7) << "-----" << left << setw(9) << "-------";
	ClassAvg=0;
	ClassAvg=Classtotal/i;
	//Class Average
	out<< endl<<endl<<left<<setprecision(2)<<"Class Average = "<<ClassAvg<<endl;
	
return 0;
}
