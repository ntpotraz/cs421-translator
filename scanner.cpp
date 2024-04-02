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
// Done by: *Adam Salter, Nathan Potraz, Alejandro A*
// RE:   **


bool word(string s) {
    string array_of_strings[9] = {"q0", "q1", "qsa", "qy", "qt", "qs", "qc", "q0q1", "q0qy"};

    // q0 = state 0, q1 = state 1, qsa = state 2...
    //

    int state = 0;
    int charpos = 0;
    
    while (s[charpos] != '\0') {
        switch(state) {
            case 0:
                switch(s[charpos]) {
                    case 'V':
                        state = 7;
                        break;
                    case 'n':
                        state = 3;
                        break;
                    case 'd':
                    case 'w':
                    case 'z':
                    case 'y':
                    case 'j':
                        state = 2;
                        break;
                    case 'b':
                    case 'g':
                    case 'h':
                    case 'k':
                    case 'm':
                    case 'p':
                    case 'r':
                        state = 3;
                        break;
                    case 's':
                        state = 5;
                        break;
                    case 't':
                        state = 4;
                        break;
                    case 'c':
                        state = 6;
                        break;
                    default:
                        return false;
                }
                break;
            case 1:
                if (s[charpos] == 'n')
                    state = 0;
                break;
            case 2:
                if (s[charpos] == 'V')
                    state = 7;
                break;
            case 3:
                switch(s[charpos]) {
                    case 'V':
                        state = 7;
                        break;
                    case 'y':
                        state = 2;
                        break;
                }
                break;
            case 4:
                switch(s[charpos]) {
                    case 'V':
                        state = 7;
                        break;
                    case 's':
                        state = 2;
                        break;
                }
                break;
            case 5:
                switch(s[charpos]) {
                    case 'V':
                        state = 7;
                        break;
                    case 'h':
                        state = 2;
                        break;
                }
                break;
            case 6:
                if (s[charpos] == 'h')
                    state = 2;
                break;
            case 7:
                switch(s[charpos]) {
                    case 'V':
                        state = 7;
                        break;
                    case 'n':
                        state = 8;
                        break;
                    case 'd':
                    case 'w':
                    case 'z':
                    case 'y':
                    case 'j':
                        state = 2;
                        break;
                    case 'b':
                    case 'g':
                    case 'h':
                    case 'k':
                    case 'm':
                    case 'p':
                    case 'r':
                        state = 3;
                        break;
                    case 's':
                        state = 5;
                        break;
                    case 't':
                        state = 4;
                        break;
                    case 'c':
                        state = 6;
                        break;
                }
                break;
            case 8:
                switch(s[charpos]) {
                    case 'V':
                        state = 7;
                        break;
                    case 'n':
                        state = 3;
                        break;
                    case 'd':
                    case 'w':
                    case 'z':
                    case 'y':
                    case 'j':
                        state = 2;
                        break;
                    case 'b':
                    case 'g':
                    case 'h':
                    case 'k':
                    case 'm':
                    case 'p':
                    case 'r':
                        state = 3;
                        break;
                    case 's':
                        state = 5;
                        break;
                    case 't':
                        state = 4;
                        break;
                    case 'c':
                        state = 6;
                        break;
                }
                break;
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
	//charpos


  return false;
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: *Nathan Potraz*

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {WORD1, WORD2, PERIOD, ERROR, EOFM, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"WORD1", "WORD2", "PERIOD", "ERROR", "EOFM", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR"}; 
// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
struct wordTable {
  string str;
  tokentype token;
};

wordTable reservedWords[19] = {
  {"masu", tokentype::VERB},
  {"masen", tokentype::VERBNEG},
  {"mashita", tokentype::VERBPAST},
  {"masendeshita", tokentype::VERBPASTNEG},
  {"desu", tokentype::IS},
  {"deshita", tokentype::WAS},
  {"o", tokentype::OBJECT},
  {"wa", tokentype::SUBJECT},
  {"ni", tokentype::DESTINATION},
  {"watashi", tokentype::PRONOUN},
  {"anata", tokentype::PRONOUN},
  {"kare", tokentype::PRONOUN},
  {"kanojo", tokentype::PRONOUN},
  {"sore", tokentype::PRONOUN},
  {"mata", tokentype::CONNECTOR},
  {"soshite", tokentype::CONNECTOR},
  {"shikashi", tokentype::CONNECTOR},
  {"dakara", tokentype::CONNECTOR},
  {"eofm", tokentype::EOFM},
};


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// Done by: *Nathan Potraz* 
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

  return -1;
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

  for(const auto& word : reservedWords) {
    cout << "String: " << word.str << ", TokenType: " << tokenName[word.token] << endl;
  }

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

