// ****************************************
// Program Title: Sample header file
// Project File: Project_07.cpp
// Name: Ashraf Sehba Tabil Oindry
// Course Section: CPE-211-01 
// Lab Section: 01
// Due Date: 10/18/19 
// program description: Using Function to calculate PI and calculate probability.
// ****************************************

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
//Declaring all used functions
int Print_menu();
int Obtain_integer(int& select);
double Calculate_PI( double& PI);
double Flip_Coin(double& coin);
double Toss_Die(double& Die);

int main()//Using user selected option to calculate/do the necessary work for that part
{	int seed;
	int select;
	double PI;
	double coin;
	double Die;
	int i=0;
	// Setup the random number generator starting point by obtaining a seed
	cout << endl<<"Enter in the seed(integer > 0) for the random number generator: ";
	cin >> seed;
	cout << seed<<endl<<endl; // echo print out the value entered
	srand(seed); // use the seed entered to initialize the generator
	Print_menu();
	Obtain_integer(select);
	while(i==0)
	{
		
		if(select==1)//Monte Carlo Method for finding PI has been selected
		{
			Calculate_PI(PI);
		}
		else if(select==2)//Flipping of a fair coin has been selected
		{
			Flip_Coin(coin);
		}
		else if(select==3)//Tossing of a fair 5-sided die has been selected
		{
			Toss_Die(Die);
		}
		else if(select==4)//Exit
		{
			cout<<"Exit selected.  Exiting the program now..."<<endl<<endl;
			return 1;
		}
		else//Checking Valid Selections
		{
			cout<<"*************** Invalid Integer ***************"<<endl;
			cout<<"==> Invalid integer entered."<<endl;
			cout<<"==> Please try again..."<<endl;
			cout<<"***********************************************"<<endl<<endl;
		}
		Print_menu();
		Obtain_integer(select);
	//return 
	}
return 0;
}
int Print_menu()//Prints main menu out
{	
	cout <<string(24,'*')<<endl;
	cout << string(5,'*')<<" Menu Options "<< string(5,'*') <<endl;
	cout <<string(24,'*')<<endl;
	cout << "1) Approximate PI"<<endl;
	cout << "2) Flip a fair coin" <<endl;
	cout << "3) Toss a fair 5-sided die"<<endl;
	cout << "4) Exit"<<endl;
	cout <<string(24,'*')<<endl<<endl;
	
}
int Obtain_integer(int& select)//User's selection stored here
{
	cout << "Enter your choice: ";
	cin  >> select;
	char ch;
	while(cin.fail())
	{	
		cin.clear(); 
		cin >> ch;
		cout << ch << endl<<endl;
		cout<<"************** Invalid Character **************"<<endl;
		cout<<"==> Invalid character(s) entered."<<endl;
		cout<<"==> Please try again..."<<endl;
		cout<<"***********************************************"<<endl<<endl;
		Print_menu();
		cout << "Enter your choice: ";
		cin  >> select;
	}
	cout << select << endl<<endl;
	
	return select;
}
double Calculate_PI(double& PI)//Monte Carlo Method for finding PI
{	int Loop;	
	double circle=0;
	double square=0;
	cout << "Monte Carlo Method for finding PI has been selected"<<endl<<endl;
	cout << "Number of iterations: ";
	cin  >> Loop;
	cout << Loop<<endl<<endl;
	
	cout << string(10,'*')<<" Option 1: Calculating PI "<<string(10,'*')<<endl;
	if(Loop<0)
	{		
		cout << "For "<<Loop<<" iterations, pi is about -0.000000"<<endl;
		cout << string(46, '*')<<endl<<endl;
	}
	if(Loop==0)
	{	cout << "For 0 iterations, pi is about -nan"<<endl;
		cout << string(46,'*')<<endl<<endl;	
	}
	if(Loop>0)
	{	
		for(int i=0;i<Loop;i++)
		{
			double x= double(rand())/double(RAND_MAX); // value is 0 to 1	
			double y= double(rand())/double(RAND_MAX); // value is 0 to 1
			double z= (x*x)+(y*y);
			double z1= sqrt(z);
			
			if(z1<=1.00)
			{
				circle++;
				
			}
			if(z1>1.00)
			{
				square++;
				
			}
		}
		
		double PI= 4*(circle/(circle+square));
		cout << "For "<<Loop<<" iterations, pi is about "<<fixed<<setprecision(6)<<PI<<endl;
		cout << string(46, '*')<<endl<<endl;
	}
}
double Flip_Coin(double& coin)//Flipping of a fair coin. Probability for heads and tails
{	
	int num;
	double tail=0;
	double head=0;
	cout << "Flipping of a fair coin has been selected"<<endl<<endl;
	cout << "How many flips of the coin? ";
	cin  >> num;
	cout << num << endl << endl;

	cout<<string(10,'*')<<" Option 2: Flipping a Coin "<< string(10,'*') <<endl;
	if(num<0)
	{
		cout<<"For "<<num<<" flips of a fair coin:"<<endl;
		cout<<"Heads percentage: -0.0000"<<endl<<"Tails percentage: -0.0000"<<endl;
		cout << string(46, '*')<<endl<<endl;
		return main();
	}
	if(num==0)
	{
		cout<<"For "<<num<<" flips of a fair coin:"<<endl;
		cout<<"Heads percentage: -nan"<<endl<<"Tails percentage: -nan"<<endl;
		cout << string(46, '*')<<endl<<endl;
		return main();
	}
	if(num>0)
	{	
		
		for(int j=0;j<num;j++)
		{	
			double flip= double(rand())/double(RAND_MAX); // value is 0 to 1
			if(flip<=0.5)
			{
				tail++;	        
			}
			if(flip>0.5)
			{
				head++;
			}	
		}
		double Head=(head/(head+tail))*100;
		double Tail=(tail/(head+tail))*100;
		cout<<"For "<<num<<" flips of a fair coin:"<<endl;
		cout<<"Heads percentage: "<<fixed<<setprecision(4)<<Head<<endl<<"Tails percentage: "<<Tail<<endl;
		cout << string(47, '*')<<endl<<endl;
		
	}



}
double Toss_Die(double& Die)//Calculating Probability for different sides of a die to come up when rolled
{
	int roll;
	double side1=0;
	double side2=0;
	double side3=0;
	double side4=0;
	double side5= 0;
	cout<<"Tossing of a fair 5-sided die has been selected"<<endl<<endl;
	cout<<"How many times do you want to roll the die? ";
	cin >>roll; 
	cout<<roll<<endl<<endl;

	cout<<string(10,'*')<<" Option 3: Tossing a Die "<<string(10,'*')<<endl;
	if(roll<0)
	{ 	cout<<"For "<<roll<<" rolls of a fair die:"<<endl;
		cout<<"Side 1 percentage: -0.0000"<<endl;
		cout<<"Side 2 percentage: -0.0000"<<endl;
		cout<<"Side 3 percentage: -0.0000"<<endl;
		cout<<"Side 4 percentage: -0.0000"<<endl;
		cout<<"Side 5 percentage: -0.0000"<<endl;
		
		
	
	}
	if(roll==0)
	{ 	cout<<"For 0 rolls of a fair die:"<<endl;
		cout<<"Side 1 percentage: -nan"<<endl;
		cout<<"Side 2 percentage: -nan"<<endl;
		cout<<"Side 3 percentage: -nan"<<endl;
		cout<<"Side 4 percentage: -nan"<<endl;
		cout<<"Side 5 percentage: -nan"<<endl;
		
	
	}
	if(roll>0)
	{
		for(int k=0;k<roll;k++)
		{	
			double toss= double(rand())/double(RAND_MAX); // value is 0 to 1
			if(toss<0.2)
			{
				side1++;	        
			}
			if(toss>=0.2 && toss<0.4)
			{
				side2++;
			}
			if(toss>=0.4 && toss<0.6)
			{
				side3++;	        
			}
			if(toss>=0.6 && toss<0.8)
			{
				side4++;
			}
			if(toss>=0.8)
			{
				side5++;
			}			
	
		}
		double side=side1+side2+side3+side4+side5;
		double Side1=(side1/side)*100;
		double Side2=(side2/side)*100;
		double Side3=(side3/side)*100;
		double Side4=(side4/side)*100;
		double Side5=(side5/side)*100;
		cout<<"For "<<roll<<" rolls of a fair die:"<<endl;
		cout<<"Side 1 percentage: "<<fixed<<setprecision(4)<<Side1<<endl;
		cout<<"Side 2 percentage: "<<Side2<<endl;
		cout<<"Side 3 percentage: "<<Side3<<endl;
		cout<<"Side 4 percentage: "<<Side4<<endl;
		cout<<"Side 5 percentage: "<<Side5<<endl;
		cout << string(45, '*')<<endl<<endl;
		
	}




}

