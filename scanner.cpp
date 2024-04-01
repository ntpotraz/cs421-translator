#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: *10* 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: *Adam Salter*
// RE:   **


bool word(string s) {
    string array_of_strings[9] = {"q0", "q1", "qsa", "qy", "qt", "qs", "qc", "q0q1", "q0qy"};

    // q0 = state 0, q1 = state 1, qsa = state 2...
    //

    int state = 0;
    int charpos = 0;
    
    while (s[charpos] != '\0') {
        // State q0
        if (state == 0) {
            if (s[charpos] == 'V')
                state = 7;
            else if (s[charpos] == 'n')
                state = 3;
            else if (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'z' || s[charpos] == 'y'  || s[charpos] == 'j')
                state = 2;
	    else if (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'  || s[charpos] == 'n'|| s[charpos] == 'p' || s[charpos] == 'r')
                state = 3;
            else if (s[charpos] == 's')
                state = 5;
            else if (s[charpos] == 't')
                state = 4;
            else if (s[charpos] == 'c')
                state = 6;
            else
                return false;
        }
        
        // State q1
        if (state == 1 && s[charpos] == 'n')
            state = 0;

        // State qsa
        if (state == 2 && s[charpos] == 'V')
            state = 7;
		


        // State qy
        if (state == 3) {
            if (s[charpos] == 'V')
                state = 7;
            else if (s[charpos] == 'y')
                state = 2;
        }

        // State qt
        if (state == 4) {
            if (s[charpos] == 'V')
                state = 7;
            else if (s[charpos] == 's')
                state = 2;
        }

        // State qs
        if (state == 5) {
            if (s[charpos] == 'V')
                state = 7;
            else if (s[charpos] == 'h')
                state = 2;
        }

        // State qc
        if (state == 6 && s[charpos] == 'h')
            state = 2;

        // State q0q1
        if (state == 7) {
            if (s[charpos] == 'V')
                state = 7;
            else if (s[charpos] == 'n')
                state = 8;
	    else if (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'z' || s[charpos] == 'y'  || s[charpos] == 'j')
                state = 2;
	    else if (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'  || s[charpos] == 'n'|| s[charpos] == 'p' || s[charpos] == 'r')
                state = 3;
            else if (s[charpos] == 's')
                state = 5;
            else if (s[charpos] == 'h')
                state = 2;
            else if (s[charpos] == 't')
                state = 4;
            else if (s[charpos] == 'c')
                state = 6;
        }

        // State q0qy
        if (state == 8) {
            if (s[charpos] == 'V')
                state = 7;
            else if (s[charpos] == 'n')
                state = 3;
	    else if (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'z' || s[charpos] == 'y'  || s[charpos] == 'j')
                state = 2;
	    else if (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm'  || s[charpos] == 'n'|| s[charpos] == 'p' || s[charpos] == 'r')
                state = 3;
            else if (s[charpos] == 's')
                state = 5;
            else if (s[charpos] == 't')
                state = 4;
            else if (s[charpos] == 'c')
                state = 6;
            else if (s[charpos] == 'y')
                state = 2;
        }

        charpos++;
    }

    // Where did I end up?
    if (state == 0 || state == 7 || state == 8)
        return true; // End in a final state
    else
        return false;
}

	
	

// PERIOD DFA 
// Done by: **
//

bool period (string s)
{  // complete this **
	charpos


}

// ------ Three  Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {ERROR, };

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { }; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: 
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.   
  
  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.

  4. Return the token type & string  (pass by reference)
  */

}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end

