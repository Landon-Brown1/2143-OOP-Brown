/*****************************************************************************                   
 * Author:           LANDON BROWN						   
 * Email:            LANDONBROWN.COLLEGE@GMAIL.COM			   
 * Label:            Program 1   					   
 * Title:            Bitwise Operators 					   
 * Course:           CMPS 2433			   
 * Semester:         SPRING 2020						   
 *									   
 * Description:								   
 *       does bitwise interpretations 				         				   	   
 *****************************************************************************/


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

const int SIZE = 16;        //size for a 16 bit binary number

//--------------------Prototypes----------------------//
void openFiles (ifstream&, ofstream&);
void closeFiles(ifstream&, ofstream&);
void Solution(ifstream&, ofstream&);

//----------------------Main--------------------------//
int main(){

    ifstream inFile;                //declare ifstream
    ofstream outFile;               //and ofstream
    openFiles(inFile, outFile);             //open files
    Solution(inFile, outFile);              //run solution
    closeFiles(inFile, outFile);            //close files
    return 0;
}

//-----------------Declarations-----------------------//

//openFiles asks for user input and opens files based on that input
//(if they exist)
void openFiles (ifstream& infile, ofstream& outfile){
    char inFileName[40];
    char outFileName[40];
                  
    while(!infile.is_open()){
        if(!infile.is_open()){
            cout << "Enter the input file name: ";
            cin >> inFileName;                  //open input file

            infile.open(inFileName);
            if(infile.is_open()){
                cout << inFileName << " is now open." << endl;
                cout << endl;
            }else{
                cout << "ERROR opening input file" << endl;
            }
        }
    }

    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);                  //open output file
}

//closeFiles just closes the files that it is given
void closeFiles(ifstream& infile, ofstream& outfile){
    infile.close();
    outfile.close();
}

//Solution runs all of our operations and gets the data from its 
//"on off" form, then to its binary form, and finally
// to its decimal form and prints it to a file
void Solution(ifstream& inFile, ofstream& outFile){
    
    string statements[SIZE];                //on off string array
    int bits[SIZE];                         //1 0 integer array
    int decimal = 0;                        //total decimal val
    int count = 0;

    outFile << "Landon M Brown" << endl;    //name for header

    while(!inFile.eof()){                   //until end of file,
        for(int i = SIZE-1; i >= 0; i--){
            inFile >> statements[i];        //read in "off" or "on"
            if(statements[i] == "off"){     //if off make a 0
                bits[i] = 0;
            }else if(statements[i] == "on"){//if on make a 1,
                bits[i] = 1;                //calculate the
                decimal += pow(2,i);        //value of the integer
            }                               //and add it to decimal
        }
        count++;        
        outFile << '\n';
        outFile << "ASSIGNMENT #" << count  
                << " FLAG IS " << decimal;
        outFile << '\n';
        decimal = 0;
    }
}
