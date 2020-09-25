// ****************************************
// Program Title: Sample header file
// Project File: Project_05.cpp
// Name: Ashraf Sehba Tabil Oindry
// Course Section: CPE-211-01 
// Lab Section: 01
// Due Date: 09/27/19
// program description: Project_05
//Package delivery Cost Calculation based on reading user input files
// ****************************************
#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{ 	//Variable Declaration
	float BR,TotalCost,LF,WF,cost;
	int Length,Width,Height, Weight,TotalLength;
	string Pack,filename;
	ifstream file;
	cout<<endl;
	cout<<"Enter the name of the input file: "; //User defined file
	cin>>filename;
	cout<<filename<<endl<<endl;
	file.open(filename.c_str());//Opens user defined file to read
	file.ignore(100000,'\n');//Ignores the 1st line

	if(file.fail()) // Checks if there is any error while opening the file and prints out error message if it founds any error.
	{
		cout << string(15,'*') <<" File Open Error "<< string(15,'*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " <<filename << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl<<endl;
	return 1;
	}	

	else if(file.eof()) // Checks if the file is Empty and prints a message for the user if the file is empty
	{
		cout << string(16,'*') << " File Is Empty "<< string(16,'*') << endl;
		cout << "==> Input file is empty.\n";
		cout << "==> No information to process.\n";
		cout << "==> Terminating program.\n";
		cout << string(47,'*') << endl << endl;
	return 1;
	}
	
	getline(file,Pack);//Reads the second line that contains package type
	string P = "parcel",M="media",B="bulk"; //Valid package types assigned in a string to comapare after reading the second line
	
	if (Pack!=P && Pack!=M && Pack!=B)// Checks if the package type is correct
	{
		cout << string(12,'*') <<" Invalid Package Type "<< string(13,'*') << endl;
		cout << "==> Error in data file!!!\n";
		cout << "==> The package type is incorrect"<< endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl<<endl;
	return 1;
	}
	else //When the package type is correct, selects out the base rate for it
	{
		if(Pack=="parcel")
			BR=2.25;
		if(Pack=="media")
			BR=3.50;
		if (Pack=="bulk")
			BR=4.75;
	}
	//Reads line3,line4,line5,line6 and takes Length,Width,Height and Weight as inputs accordingly
	file>>Length;
	file>>Width;
	file>>Height;
	file>>Weight;	
	//Checks if there is any value(Character) other than integer
	//If there is any character or string other than integer the program goes to the fail state and the 1st if statement applies
	if(file.fail()) 
	{
		cout << string(15,'*') << " File Read Error "<< string(15,'*') << endl;
		cout << "==> Reading of one or more package\n";
		cout << "==> parameters failed!!\n";
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl << endl;
		return 1;
	}	
	else if(Length<=0 || Width<=0 || Height<=0 || Weight<=0)//Checks if all the values are possitive. If no then prints out the statements for the user
	{
		cout << string(11,'*') << " Package Parameter Error "<< string(11,'*') << endl;
		cout << "==> One or more of the package parameters\n";
		cout << "==> has a negative value!!!\n";
		cout << "==> Terminating program!!!\n";
		cout << string(47,'*') << endl << endl;
		return 1;
	}	

	//After checking everything, if the program does not get terminated in any step, then it calculates the following outputs by selecting the proper Weight and Length Adjusment Factors
	else{	
		//Finds Proper Weight Adjustment Factor
		if(Weight<10)
			WF=1.00;
		if(Weight>=10 && Weight<25)	
			WF=3.00;	
		if(Weight>=25)
			WF=4.50;
		//Calculates Total Length
		TotalLength=int (Length+Width+Height);
		//Checks the Proper Total Length to get the Length Adjustment Factor
		if(TotalLength<40)
			LF= 1.00;
		if(TotalLength>=40 && TotalLength<60)
			LF=2.50;
		if(TotalLength>=60)
			LF=3.75;
		//Output for a file containing all valid input lines
		cout<<string(50,'-')<<endl;
		cout<<"The package attributes are:"<<endl;
		cout<<setfill('.')<<setw(30)<<left<<"Package Type"<<right<<Pack<<endl;
		cout<<setfill('.')<<setw(30)<<left<<"Total Length"<<right<<TotalLength<<" inches"<<endl;
		cout<<setfill('.')<<setw(30)<<left<<"Weight"<<right<< Weight<<" pounds"<<endl;

		cost= BR*LF*WF;
		cout<<string(50,'-')<<endl;
		cout<<"The package rate factors are:"<<endl;
		cout<<fixed<<setprecision(2);
		cout<<setfill('.')<<setw(30)<<left<<"Package Base Rate"<<right<<BR<<" dollars"<<endl;
		cout<<setfill('.')<<setw(30)<<left<<"Length Factor Used"<<right<<LF<<endl;
		cout<<setfill('.')<<setw(30)<<left<<"Weight Factor Used"<<right<<WF<<endl;
		cout<<string(50,'-')<<endl;
		cout<<"The final cost of mailing the package is: $"<<cost<<endl<<endl;
				
	}				

return 0;
}
//Why else if not working
//Why order matters
//Why last logic not working
//Why there is a gap after filename in output 


