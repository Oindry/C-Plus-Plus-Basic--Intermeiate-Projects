// ****************************************
// Program Title: Sample header file
// Project File: Project_03.cpp
// Name: Ashraf Sehba Tabil Oindry
// Course Section: CPE-211-01 
// Lab Section: 01
// program description: Description of Project-03
// This program will compute the savings account balance using four different types of interest computing methods.
// ****************************************
#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;
int main()
{	double P,R,T; 
	cout<<endl;
	cout<<"Input the starting balance: "; // P = Principle Amount
	cin>>P;
	cout<<P<<endl;
	cout<<"Input the interest rate (Ex: 5 for 5%): ";// R = Simple Interest
	cin>>R;
	cout<<R<<endl;
	cout<<"Input the number of years: ";// T = Number of years invested
	cin>>T;
	cout<<T<<endl;
	cout<<endl;

	cout<<"For a principle of $"<<std::fixed << std::setprecision(2)<<P<<endl; //Description of inputs
	cout<<"at an interest rate of "<<R<<"%"<<endl;
	cout<<"for a period of "<<T<<" years,"<<endl;
	cout<<"the final account balance would be:"<<endl<<endl; //Double line space before outputs
	

	double Simple_Interest,R1; //Simple_Intetrest = Balance using Simple Interest Calculation 
	R1=R/100; // Divide R1 by 100 for getting its decimal equivalent for the equation
	Simple_Interest= P*(1+T*R1);// Equation to calculate Balance
	// output 
	cout<<"Simple Interest:"<<"\n"<<"\t"<<"Balance = $"<<Simple_Interest<<endl;// output line
	cout<<endl;// 1 line Space before next section
	
	double Comp_Monthly_Balance,Comp_Reff,Comp_Balance_Reff;// Variables Declared for Compound Interest Calculation (Monthly)
	Comp_Monthly_Balance=P*pow((1+(R1/12)),(12*T));// Comp_Monthly_Balance = Balance using Simple Interest Calculation (Monthly)
	Comp_Reff=((pow((1+(R1/12)),(12*T))-1)/T)*100; // Comp_Reff = Effective rate for compound interest calculation (Monthly)
	Comp_Balance_Reff=(P*(1+T*(Comp_Reff/100))); // Comp_Balance_Reff = Balance using Simple Interest at the Effective Rate (Monthly)
	// output 
	cout<<"Compounded Monthly:"<<"\n"<<"\t"<<"Balance = $"<<Comp_Monthly_Balance<<endl;
	cout<<"\t"<<"The Effective Simple Interest Rate: "<<Comp_Reff<<"%"<<endl;
	cout<<"\t"<<"Balance using Simple Interest at the Effective Rate = $"<<Comp_Balance_Reff<<endl;
	cout<<endl;// 1 line Space before next section

	double Comp_Daily_Balance,Comp_Daily_Reff,Comp_Daily_Balance_Reff;// Variables Declared for Compound Interest Calculation (Daily)
	Comp_Daily_Balance=P*pow((1+(R1/365)),(365*T)); // Comp_Daily_Balance = Balance using Simple Interest Calculation for Compound Interest (Daily)
	Comp_Daily_Reff=((pow((1+(R1/365)),(365*T))-1)/T)*100; // Comp_Daily_Reff = Effective rate for compound interest calculation (Daily)
	Comp_Daily_Balance_Reff=(P*(1+T*(Comp_Daily_Reff/100))); //Comp_Daily_Balance_Reff =  Balance using Simple Interest at the Effective Rate (Daily)
	// Output
	cout<<"Compounded Daily:"<<"\n"<<"\t"<<"Balance = $"<<Comp_Daily_Balance<<endl;
	cout<<"\t"<<"The Effective Simple Interest Rate: "<<Comp_Daily_Reff<<"%"<<endl;
	cout<<"\t"<<"Balance using Simple Interest at the Effective Rate = $"<<Comp_Daily_Balance_Reff<<endl;
	cout<<endl;// 1 line Space before next section

	double Comp_Con_Balance,Comp_Con_Reff,Comp_Con_Balance_Reff,e; // Variables Declared for Continuously Compounded Interest Calculation 
	e=exp(1); // Declaring "e" before using exponential
	Comp_Con_Balance=P*pow(e,(R1*T));// Comp_Con_Balance = Balance using Simple Interest Calculation for Continuously Compounded Interest
	Comp_Con_Reff=((pow(e,(R1*T))-1)/T)*100;// Comp_Con_Reff = Effective Rate for Continuously Compounded Interest
	Comp_Con_Balance_Reff=(P*(1+T*(Comp_Con_Reff/100)));// Comp_Con_Balance_Reff = Balance using Simple Interest at the Effective Rate for Continuously Compounded Interest
	// Output
	cout<<"Compounded Continuously:"<<"\n"<<"\t"<<"Balance = $"<<Comp_Con_Balance<<endl;
	cout<<"\t"<<"The Effective Simple Interest Rate: "<<Comp_Con_Reff<<"%"<<endl;
	cout<<"\t"<<"Balance using Simple Interest at the Effective Rate = $"<<Comp_Con_Balance_Reff<<endl;
	cout<<endl;// Last Space 	
return 0;
}
