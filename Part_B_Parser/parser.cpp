#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: **
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  
token_type saved_token; //stores last token 
bool token_available = false; //indicates if there was a saved token ava

// Type of error: **
// Done by: ** 
void syntaxerror1( token_type expected, string function ){ 
   cout << "Syntax error: Expected " << tokenName[expected] << " at" << function << endl;
   exit(1);
   }
// Type of error: **
// Done by: ** 
void syntaxerror2( token_type unexpected, string function ) {
   cout << "Syntax error: Unexpected " << tokenName[unexpected] << " in " << function << endl;
   exit(1);
    }

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme
token_type scanner();  // Function to get the next token from scanner

// Purpose: **
// Done by: **
token_type next_token(){
   if(!token_available){
      saved_token = scanner();
      token_available = true;
   }
   return saved_token;
}

// Purpose: **
// Done by: **
boolean match(tokentype expected) {
   if (next_token() != expected){
      syntaxerror1(expected, "Match");
   }else{
      token_available = false;
   }
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **

string filename;

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  //** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
