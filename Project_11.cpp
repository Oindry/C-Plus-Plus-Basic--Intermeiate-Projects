// ****************************************
// Program Title: Sample header file
// Project File: Cpp_header.cpp
// Name: Ashraf Sehba Tabil Oindry
// Course Section: CPE-211-01 
// Lab Section: 1
// Due Date: 12/06/19
// program description: Description of  Edit as necessary
// What the program does
// ****************************************

#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

int main()
{    //declaring variables
    int lineNum=0, numUpper, numUpperTotal=0, numLower, numLowerTotal=0, numDigit, numDigitTotal=0, numPunct, numPunctTotal=0, numSpace, numSpaceTotal=0, numChar, numCharTotal=0, numNewline, numNewlineTotal = 0;
    float perUp, perLow, perDigit, perPunct, perSpace, perOther;
    string line, fileName;
    ifstream file;
    
    cout << endl << "Enter in the name of the input file: ";
    cin >> fileName;
    cout << fileName << endl;
    file.open(fileName.c_str());
    while (file.fail()) {
        cout << endl << string(15, '*') << " File Open Error " << string(15, '*') << endl;
        cout << "==> Input file failed to open properly!!\n";
        cout << "==> Attempted to open file: " << fileName << endl;
        cout << "==> Please try again...\n";
        cout << string(47, '*') << endl << endl;
        file.clear();
        cout << "Enter in the name of the input file: ";
        cin >> fileName;
        cout << fileName << endl;
        file.open(fileName.c_str());
    }
    
    getline(file, line);
    
    if (file.eof()) {
        cout << endl << string(13, '*') << " Input File Is Empty " << string(13, '*') << endl;
        cout << "==> The input file is empty.\n";
        cout << "==> Terminating the program.\n";
        cout << string(47, '*') << endl << endl;
        return 0;
    }
    else {
        cout << endl << left << setw(15) << "Line number" << setw(10) << "Upper";
        cout << setw(10) << "Lower" << setw(10) << "Digits";
        cout << setw(10) << "Punct" << setw(10) << "Spaces";
        cout << setw(10) << "Other" << "Total" << endl;
        cout << setw(15) << string(11, '-') << setw(10) << string(5, '-');
        cout << setw(10) << string(5,'-') << setw(10) << string(6,'-');
        cout << setw(10) << string(5,'-') << setw(10) << string(6,'-');
        cout << setw(10) << string(5,'-') << string(5,'-') << endl;

        while(!(file.eof())) {
            numUpper = 0;
            numLower = 0;
            numDigit = 0;
            numPunct = 0;
            numSpace = 0;
            lineNum++;
            numChar = (line.size()) +1;
            numCharTotal = numCharTotal + numChar;
            for (int i = 0; i < line.size(); i++) {
                char ch = line[i];
                if (isupper(ch)) {
                    numUpper++;
                    numUpperTotal++;
                }
                if (islower(ch)) {
                    numLower++;
                    numLowerTotal++;
                }
                if (isdigit(ch)) {
                    numDigit++;
                    numDigitTotal++;
                }
                if (ispunct(ch)) {
                    numPunct++;
                    numPunctTotal++;
                }
                if (isspace(ch)) {
                    numSpace++;
                    numSpaceTotal++;
                }
            }
            numNewline = 1;
            numNewlineTotal++;
            
            cout << left << setw(15) << lineNum << setw(10) << numUpper;
            cout << setw(10) << numLower << setw(10) << numDigit;
            cout << setw(10) << numPunct << setw(10) << numSpace;
            cout << setw(10) << numNewline << numChar << endl;
            
            getline(file, line);
        }
        //outputting the totals
        cout << string(80, '-') << endl;
        cout << left << setw(15) << "Totals" << setw(10) << numUpperTotal;
        cout << setw(10) << numLowerTotal << setw(10) << numDigitTotal;
        cout << setw(10) << numPunctTotal << setw(10) << numSpaceTotal;
        cout << setw(10) << numNewlineTotal << numCharTotal << endl;
        //calculating percents
        perUp = 100*(float(numUpperTotal)/float(numCharTotal));
        perLow = 100*(float(numLowerTotal)/float(numCharTotal));
        perDigit = 100*(float(numDigitTotal)/float(numCharTotal));
        perPunct = 100*(float(numPunctTotal)/float(numCharTotal));
        perSpace = 100*(float(numSpaceTotal)/float(numCharTotal));
        perOther = 100*(float(numNewlineTotal)/float(numCharTotal));
        //outputting the last line
        cout << fixed << setprecision(2) << setw(15) << "Percent" << setw(10) << perUp;
        cout << setw(10) << perLow << setw(10) << perDigit;
        cout << setw(10) << perPunct << setw(10) << perSpace;
        cout << setw(10) << perOther << endl << endl;
    }        
    return 0;
}



