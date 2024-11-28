/*
Author Details: 
  Shital Manoj Patil
  2324001011
  SY B77

Program Details : 
  Sub  : OOP
  Name : Assignment 08 - File Handling
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileStatistics {
    private:
        string filename;
        int charCount;
        int wordCount;
        int lineCount;

        bool isWhitespace(char ch) {
            return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
        }

        void resetCounters() {
            charCount = 0;
            wordCount = 0;
            lineCount = 0;
        }

    public:
        FileStatistics() : charCount(0), wordCount(0), lineCount(0) {}

        bool analyzeFile(const string& fname) {
            resetCounters();
            filename = fname;

            ifstream file(filename);
            
            if (!file.is_open()) {
                cout << "Error: Unable to open file '" << filename << "'." << endl;
                return false;
            }

            string line;
            bool inWord = false;

            while (getline(file, line)) {
                lineCount++;
                charCount += line.length();

                for (char ch : line) {
                    if (!isWhitespace(ch) && !inWord) {
                        wordCount++;
                        inWord = true;
                    } else if (isWhitespace(ch)) {
                        inWord = false;
                    }
                }
            }

            file.close();
            return true;
        }

        void displayStatistics() {
            cout << "\n--- File Statistics for: " << filename << " ---" << endl;
            cout << "Total Characters: " << charCount << endl;
            cout << "Total Words:     " << wordCount << endl;
            cout << "Total Lines:     " << lineCount << endl;
        }
};

int main() {
    FileStatistics stats;
    string filename;

    cout << "Enter the filename to analyze: ";
    getline(cin, filename);

    if (stats.analyzeFile(filename)) {
        stats.displayStatistics();
    }

    return 0;
}
