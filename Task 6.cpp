#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// This function splits a given text into words
vector<string> splitTextIntoWords(const string& text) {
    stringstream ss(text);  // I use stringstream to break down the text
    string word;
    vector<string> words;   
    while (ss >> word) {    
        words.push_back(word);  
    }
    return words;  
}

// in this function i format the text to fit a specified width
void wrapTextAccordingToWidth(const vector<string>& words, int lineWidth) {
    int currentWidth = 0;  
    string line;  
    int lineCount = 1;  

    for (const string& word : words) {
        if (currentWidth + word.length() > lineWidth) {
            cout << "line " << lineCount++ << ": " << line << endl;  
            line = word;  
            currentWidth = word.length() + 1; 
        }
        else {
            if (!line.empty()) line += " "; 
            line += word;  
            currentWidth += word.length() + 1; 
        }
    }

    // If there's any text left i print it as the last line.
    if (!line.empty()) {
        cout << "line " << lineCount++ << ": " << line << endl;
    }
}

int main() {
    string text = "Mary loves to sing and perform tapdancing.";  
    int lineWidth = 10;  // I've set the line width to 10 characters.

    cout << "Input Text: " << text << endl << endl;  
    vector<string> words = splitTextIntoWords(text);  

    cout << "Formatted Text Output:" << endl; 
    wrapTextAccordingToWidth(words, lineWidth);

    return 0;
}
