#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void verb();
void be();
void tense();
void after_object();
void after_subject();
void noun();
void after_noun();



/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: *10* 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: *Adam Salter, Nathan Potraz*
// RE:   **

string currWord;

bool word(string s) {
    string array_of_strings[9] = {"q0", "q1", "qsa", "qy", "qt", "qs", "qc", "q0q1", "q0qy"};

    // q0 = state 0, q1 = state 1, qsa = state 2...
    //

    int state = 0;
    int charpos = 0;
    currWord = s;

    while (s[charpos] != '\0') {
      // cout << "CharPos: " << s[charpos] << ", State: " << state << endl; // For testing
        switch(state) {
            case 0: // q0
                switch(s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'I':
                    case 'E':
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
            case 1: // q1
                if (s[charpos] == 'n')
                    state = 0;
                break;
            case 2: // qsa
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'I':
                    case 'E':
                        state = 7;
                        break;
                    default:
                        return false;
            case 3: // qy
                switch(s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'I':
                    case 'E':
                        state = 7;
                        break;
                    case 'y':
                        state = 2;
                        break;
                    default:
                        return false;
                }
                break;
            case 4: // qt
                switch(s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'I':
                    case 'E':
                        state = 7;
                        break;
                    case 's':
                        state = 2;
                        break;
                    default:
                        return false;
                }
                break;
            case 5: // qs
                switch(s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'I':
                    case 'E':
                        state = 7;
                        break;
                    case 'h':
                        state = 2;
                        break;
                    default:
                        return false;
                }
                break;
            case 6: // qc
                if (s[charpos] == 'h')
                    state = 2;
                else return false;
                break;
            case 7: // q0q1
                switch(s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'I':
                    case 'E':
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
                    default:
                        return false;
                }
                break;
            case 8: // q0qy
                switch(s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'I':
                    case 'E':
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
        }
        charpos++;
    }

    // Where did I end up?
    // cout << "State: " << state << endl; // For Testing
    if (state == 0 || state == 7 || state == 8)
        return true; // End in a final state
    else
        return false;
}

// PERIOD DFA 
// Done by: Alejandro Agustin
//


bool period(string s) {
    int state = 0;
    int charpos = 0;


    while (s[charpos] != '\0') {
        switch (state) {
            case 0:
                if (s[charpos] == '.')
                    state = 1;
                else
                    return false; // Not a period
                break;
            case 1:
                return false; // Already encountered a period, so any additional characters are invalid
                break;
        }
        charpos++;
    }

    // Where did I end up?
    if (state == 1)
        return true; // End in a final state (period encountered)
    else
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
  {"masu", VERB},
  {"masen", VERBNEG},
  {"mashita", VERBPAST},
  {"masendeshita", VERBPASTNEG},
  {"desu", IS},
  {"deshita", WAS},
  {"o", OBJECT},
  {"wa", SUBJECT},
  {"ni", DESTINATION},
  {"watashi", PRONOUN},
  {"anata", PRONOUN},
  {"kare", PRONOUN},
  {"kanojo", PRONOUN},
  {"sore", PRONOUN},
  {"mata", CONNECTOR},
  {"soshite", CONNECTOR},
  {"shikashi", CONNECTOR},
  {"dakara", CONNECTOR},
  {"eofm", EOFM},
};


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// Done by: *Nathan Potraz* 
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin

  fin >> w;

	cout << "Scanner called using word: " << w << endl;

  // 1. If it is eofm, return right now.   
  if(w == "eofm") {
    tt = EOFM;
    return tt;
  }

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

  if(word(w)) {
    bool foundWord = false;

    for(int i = 0; i < sizeof(reservedWords); i++) {
      if(reservedWords[i].str == w) {
        tt = reservedWords[i].token;
        foundWord = true;
        break;
      }
    }

    if(!foundWord) {
      char lastLetter = w[w.length() - 1];

      switch (lastLetter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'n':
          tt = WORD1;
          break;
        case 'I':
        case 'E':
          tt = WORD2;
          break;
        default:
          tt = ERROR;
          break;
      }
    }

  } else if(period(w)) {
      tt = PERIOD;
  } else {
    tt = ERROR;
    cout << "\nLexical error: " << w << " not a valid token" << endl;
  }

  return tt;
}//the end of scanner


// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
// int main()
// {
//   tokentype thetype;
//   string theword; 
//   string filename;
//
//   cout << "Enter the input file name: ";
//   cin >> filename;
//
//   fin.open(filename.c_str());
//
//   // the loop continues until eofm is returned.
//    while (true)
//     {
//        scanner(thetype, theword);  // call the scanner which sets
//                                    // the arguments  
//        if (theword == "eofm") break;  // stop now
//
//        cout << "Type is:" << tokenName[thetype] << endl;
//        cout << "Word is:" << theword << endl;   
//     }
//
//    cout << "End of file is encountered." << endl;
//    fin.close();
//
// }// end

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

// ------------------------------- Parser --------------------------------------

//=================================================
// File parser.cpp written by Group Number: *10*
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  
tokentype saved_token; //stores last token 
bool token_available = false; //indicates if there was a saved token ava

// Type of error: **
// Done by: Alejandro Agustin 
void syntaxerror1( tokentype expected, string function ){ 
   cout << "\nSYNTAX ERROR: Expected " << tokenName[expected] << " at" << function << endl;
   exit(1);
}
// Type of error: **
// Done by: Alejandro Agustin 
void syntaxerror2( tokentype unexpected, string function ) {
   cout << "\nSYNTAX ERROR: Unexpected " << currWord << " in " << function << endl;
   exit(1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: **
// Done by: Alejandro Agustin
tokentype next_token(){
		string saved_lexeme; // The current word being looked at
    if(!token_available){
        scanner(saved_token, saved_lexeme);
        if(saved_token == EOFM) {
          cout << "\nSuccessfully parsed <story>" << endl;
          exit(0);
        }
        token_available = true;
   }
   return saved_token;
}

// Purpose: **
// Done by: Alejandro Agustin
bool match(tokentype expected) {
   if (next_token() != expected){
        syntaxerror1(expected, "Match");
        return false;
   } else {
        token_available = false;
				cout << "Matched " << tokenName[expected] << endl;
        return true;
   }
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **

// Processing <s>
// Done by: Adam Salter
void s() {
    cout << "Processing <s>" << endl;
    if (next_token() == CONNECTOR) {  // Optional CONNECTOR
        match(CONNECTOR);
    }
    noun();
    match(SUBJECT);
    after_subject();
}

// Processing <noun>
// Done by: Adam Salter
void noun() {
    cout << "Processing <noun>" << endl;
    if (next_token() == WORD1 || next_token() == PRONOUN) {
        match(next_token()); // Matches either WORD1 or PRONOUN
    } else {
        syntaxerror2(next_token(), "<noun>");
    }
}

// Processing <after subject>
// Done by: Adam Salter
void after_subject() {
    cout << "Processing <after subject>" << endl;
    switch(next_token()) {
        case WORD2:
        case VERB:
            verb();
            tense();
            match(PERIOD);
            s();
            break;
        case WORD1:
        case PRONOUN:
            noun();
            after_noun();
            break;
        default:
            syntaxerror2(next_token(), "<after subject>");
    }
}

// Processing <verb>
// Done by: Adam Salter
void verb() {
    cout << "Processing <verb>" << endl;
    match(WORD2); // Assuming VERB corresponds to WORD2
}

// Processing <tense>
// Done by: Adam Salter
void tense() {
    cout << "Processing <tense>" << endl;
    if (next_token() == VERBPAST || next_token() == VERBPASTNEG || next_token() == VERB || next_token() == VERBNEG) {
        match(next_token()); // Matches any valid tense
    } else {
        syntaxerror2(next_token(), "<tense>");
    }
}

// Processing <after noun>
// Done by: Adam Salter
void after_noun() {
    cout << "Processing <after noun>" << endl;
    switch(next_token()) {
        case IS:
        case WAS:
            be();
            match(PERIOD);
            s();
            break;
        case DESTINATION:
            match(DESTINATION);
            verb();
            tense();
            match(PERIOD);
            s();
            break;
        case OBJECT:
            match(OBJECT);
            after_object();
            break;
        default:
            syntaxerror2(next_token(), "<after noun>");
    }
}

// Processing <be>
// Done by: Adam Salter
void be() {
    cout << "Processing <be>" << endl;
    if (next_token() == IS || next_token() == WAS) {
        match(next_token());
    } else {
        syntaxerror2(next_token(), "<be>");
    }
}

// Processing <after object>
// Done by: Adam Salter
void after_object() {
    cout << "Processing <after object>" << endl;
    switch(next_token()) {
        case WORD2:
        case VERB:
            verb();
            tense();
            match(PERIOD);
            s();
            break;
        case WORD1:
        case PRONOUN:
            noun();
            match(DESTINATION);
            verb();
            tense();
            match(PERIOD);
            s();
            break;
        default:
            syntaxerror2(next_token(), "<after object>");
    }
}


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
    
  cout << "Processing <story>\n" << endl;
	s();

	fin.close();
  return 0;
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
