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
// File translator.cpp written by Group Number: 10
//=================================================

map<string, string> Lexicon;  // Global variable for the lexicon
string saved_lexeme, saved_E_word, saved_token;  // Global variables for word management
ofstream outFile;  // File stream for output
ifstream fin;  // File stream for input

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
// Done by: **Adam Salter** 

// Function to translate Japanese words to English
void getEword() {
    auto it = Lexicon.find(saved_lexeme);
    if (it != Lexicon.end()) {
        saved_E_word = it->second;
    } else {
        saved_E_word = saved_lexeme; // If not found, use the Japanese word as a fallback
    }
}
// Done by: **Adam Salter** 

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
// Done by: **Adam Salter and Alejandro Agustin** 

// Function to get the next token from the input file
void getNextToken() {
    fin >> saved_token >> saved_lexeme;
}

void afterObject();
void afterNoun();
void afterSubject();
void s();
void story();

// Function to handle the <story> rule
void story() {
    s();
    while (fin >> saved_token) {
        fin.putback(saved_token[0]);
        s();
    }
}

// Function to handle the <s> rule
void s() {
    getNextToken();
    if (saved_token == "CONNECTOR") {
        getEword();
        gen("CONNECTOR");
        getNextToken();
    }
    // Assuming <noun> is processed here
    getEword();
    gen("ACTOR");
    afterSubject();
}

// Function to handle the <after subject> rule
void afterSubject() {
    getNextToken();
    if (saved_token == "VERB") {
        getEword();
        gen("ACTION");
        getNextToken(); // Get tense
        gen("TENSE");
        getNextToken(); // Get period
    } else {
        // Assuming <noun> is processed here
        getEword();
        afterNoun();
    }
}

// Function to handle the <after noun> rule
void afterNoun() {
    getNextToken();
    if (saved_token == "BE") {
        gen("DESCRIPTION");
        getNextToken(); // Get tense
        gen("TENSE");
        getNextToken(); // Get period
    } else if (saved_token == "DESTINATION") {
        gen("TO");
        getNextToken(); // Get verb
        getEword();
        gen("ACTION");
        getNextToken(); // Get tense
        gen("TENSE");
        getNextToken(); // Get period
    } else if (saved_token == "OBJECT") {
        gen("OBJECT");
        afterObject();
    }
}

// Function to handle the <after object> rule
void afterObject() {
    getNextToken();
    if (saved_token == "VERB") {
        getEword();
        gen("ACTION");
        getNextToken(); // Get tense
        gen("TENSE");
        getNextToken(); // Get period
    } else if (saved_token == "NOUN") {
        getEword();
        getNextToken(); // Get destination
        gen("TO");
        getNextToken(); // Get verb
        getEword();
        gen("ACTION");
        getNextToken(); // Get tense
        gen("TENSE");
        getNextToken(); // Get period
    }
}

// Driver function
int main() {
    string filename;

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

    story(); // Call the story function to process the input file

    fin.close(); // Close the input file
    outFile.close(); // Close the output file

    return 0;
}
// Done by: **Adam Salter**
// require no other input files!
// syntax error EC requires producing errors.txt of error messages
// tracing On/Off EC requires sending a flag to trace message output functions
