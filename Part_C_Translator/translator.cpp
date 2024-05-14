#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<sstream>
using namespace std;

/* INSTRUCTION: copy your parser.cpp here
   cp ../ParserFiles/parser.cpp .
   Then, insert or append its contents into this file and edit.
   Complete all ** parts.
*/

//=================================================
// File translator.cpp written by Group Number: **
//=================================================

map<string, string> Lexicon;  // Global variable for the lexicon
string saved_lexeme, saved_E_word, saved_token;  // Global variables for word management
ofstream outFile;  // File stream for output

// Function to load lexicon from a file
void loadLexicon() {
    ifstream lexFile("lexicon.txt");
    if (!lexFile.is_open()) {
        cerr << "Failed to open lexicon.txt" << endl;
        return;
    }

    string line;
    while (getline(lexFile, line)) {
        istringstream iss(line);
        string japWord, engWord;

        // Read the Japanese word (first word on each line)
        iss >> japWord;

        // Read the rest of the line as the English translation
        getline(iss, engWord);

        // Trim leading spaces from the English word
        size_t start = engWord.find_first_not_of(" \t");
        engWord = (start == string::npos) ? "" : engWord.substr(start);

        Lexicon[japWord] = engWord;
    }
    lexFile.close();
}
// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt
//  Done by: **Adam Salter** 

// Function to translate Japanese words to English
void getEword() {
    auto it = Lexicon.find(saved_lexeme);
    if (it != Lexicon.end()) {
        saved_E_word = it->second;
    } else {
        saved_E_word = saved_lexeme; // If not found, use the Japanese word as a fallback
    }
}
//  Done by: **Adam Salter** 

// Function to generate lines of IR and write to translated.txt
void gen(const string& line_type) {
    if (!outFile.is_open()) {
        cerr << "Output file not open for writing." << endl;
        return;
    }
    outFile << line_type << ": ";
    if (line_type == "TENSE") {
        outFile << saved_token; // TENSE uses tokens
    } else {
        outFile << saved_E_word; // Other types use the saved English word
    }
    outFile << endl;
}
//  Done by: *Adam Salter* 

// ---------------- Driver ---------------------------

// The final test driver to start the translator
int main()
{
    string filename;
    ifstream fin;

    loadLexicon(); // Load the lexicon for translations
    outFile.open("translated.txt"); // Open the output file for IR generation
    if (!outFile.is_open()) {
        cerr << "Failed to open translated.txt" << endl;
        return -1;
    }

    cout << "Enter the input file name: ";
    cin >> filename;
    fin.open(filename.c_str());
    if (!fin.is_open()) {
        cerr << "Failed to open input file." << endl;
        outFile.close(); // Close outFile before exiting
        return -1;
    }

    // Placeholder for the call to the <story> function
    // story(); // This function should be defined based on your grammar

    fin.close(); // Close the input file
    outFile.close(); // Close the output file

    return 0;
}
// Done by: **
// ** require no other input files!
// ** syntax error EC requires producing errors.txt of error messages
// ** tracing On/Off EC requires sending a flag to trace message output functions
