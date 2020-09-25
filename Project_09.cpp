// ************************************************************
// Program Title: Project_09
// Project File: Project_09.cpp
// Name: Ashraf Sehba Tabil Oindry
// Course Section: CPE-211-01
// Lab Section: 1
// Due Date: 11/17/19
// program description: Sorts data from file and finds the average, median, and standard deviation, then outputs it.
// ************************************************************
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
//functions
const string ERR1=" File Read Error ";
const string ERR2=" File Open Error ";
const int MSize=50;

void OpenInputFile(ifstream&);
void RInfo(float[],int&, ifstream&, bool&);
void SArray(float[], int&);
float Median(const float[], int&);
float Average(const float[], int&, float&);
float Variance(const float[], int&, float&);

int main()
{	
	ifstream inFile;
	OpenInputFile(inFile);

	int size;
	float numbers[MSize];
	float sum, average, variance;
	bool r = false;
	
	inFile>>size;
//Testing if file is empty
if (inFile.eof())
	{
		cout << string(15,'*') << " Empty Input File " << string(14,'*') << endl;
		cout << "==> Input file is empty." << endl;
		cout << "==> Program terminated." << endl;
		cout << string(47,'*') << endl << endl;
		
		return 1;
	}
	
	else if (inFile.fail())//Testing if file has correct file info
	{
		cout << setfill('*') << setw((47+ERR1.length())/2) <<  ERR1 << string(47-((47+ERR1.length())/2),'*') << endl;		
		cout << "==> Error occurred reading the number of values" << endl;
		cout << "==> present in the input file." << endl;
		cout << "==> Program terminated." << endl;
		cout << string(47,'*') << endl << endl;
		
		return 1;
		
	}
	
	else
	{
	
		RInfo(numbers, size, inFile, r);
		SArray(numbers, size);
	}
	
	
	if (r==true)
		return 1;
//Output of important data
  cout << string(15,'*') << " File Statistics " << string(15,'*') << endl;
  cout << string(47,'*') << endl;
  cout << setw(25) << left << setfill('.') << "Number of Values" << size << endl;
  cout << setw(25) << "Average" << setfill('.') << Average(numbers,size, average) << endl;
  cout << setw(25) << "Median" << setfill('.') << Median(numbers,size) << endl;
  cout << setw(25) << "Variance" << setfill('.') << Variance(numbers,size,average) << endl;
  cout << setw(25) << "Standard Deviation" << setfill('.') <<     pow(Variance(numbers,size,average),0.5) << endl;
  cout << string(47,'*') << endl << endl;
return 0;
}

void OpenInputFile(ifstream& InFile)
{
  string file;
  int x=1;

  while(x==1)
{
  cout<<"\nEnter the name of the input file (ctrl-c to exit): ";
  cin>>file;
  cout<<file<<endl<<endl;
  InFile.open(file.c_str());
  if(InFile.fail())
{
  cout << setfill('*') << setw((47+ERR2.length())/2) <<  ERR2 << string(47-((47+ERR2.length())/2),'*') << endl;
  cout << "==>  Input file could not be opened." << endl;
  cout << "==>  " << file << " is an invalid file!!" << endl;
  cout << "==>  Try Again." << endl;
  cout << string(47,'*') << endl;
		
  InFile.clear();
}
  else
	break;
}

}

void RInfo (float nums[], int& size, ifstream& InFile,bool& r)
{
	for (int i=0; i<size; i++)
	{
		InFile >> nums[i];
		if (InFile.eof())
		{
			cout << setfill('*') << setw((47+ERR1.length())/2) <<  ERR1 << string(47-((47+ERR1.length())/2),'*') << endl;
			cout << "==> Error occurred trying to reading in number #" << i+1 << endl;
			cout << "==> Number was not present in the input file." << endl;
			cout << "==> Program terminated." << endl;
			cout << string(47,'*') << endl << endl;
			r=true;
			break;
		}
		
		else if (InFile.fail())
		{
			cout << setfill('*') << setw((47+ERR1.length())/2) <<  ERR1 << string(47-((47+ERR1.length())/2),'*') << endl;
			cout << "==> Error occurred reading in number #" << i+1 << endl;
			cout << "==> Invalid Character found in file." << endl;
			cout << "==> Program terminated." << endl;
			cout << string(47,'*') << endl << endl;
			r=true;
			break;
		}
		
	}
}	

void SArray (float num[], int& size)
{
	float flipflop;
	
	for (int i=0; i<size; i++)
	{
		for (int j=i+1; j<size; j++)
		{
			if (num[j]<num[i])
			{
				flipflop=num[i];
				num[i]=num[j];
				num[j]=flipflop;
			}
		}	
			
	}		
}

float Average(const float num[], int& size, float& average)
{
	float sum;

	sum=0;
	
	for (int i=0; i<size; i++)
	{
		sum+=num[i];
	}
	
	average=sum/size;
	
	return average;			
}

float Variance(const float num[], int& size, float& average)
{
	float var;
	float sum, add;
	
	sum=0;
	
	for (int i=0; i<size; i++)
	{	
		add=(num[i]-average)*(num[i]-average);
		sum=sum+add;
	}
	
	var=sum/size;
	
	return var;
}

float Median(const float num[], int& size)
{
	float median;
	int position;
	
	if (size%2==0)
	{
		position=size/2;
		median=(num[position]+num[position-1])/2;
	}
	
	else 
	{
		position=size/2;
		median=num[position];
	}
	
	return median;
}


