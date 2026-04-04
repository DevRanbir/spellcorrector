#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool isWordCorrect(string word);
string getClosestWord(string word, int& bestDistance);



int main() {
    string inputWord;
    while (true) {
        cout << "\nType a word to spell-check (or type 'exit' to quit): ";
        cin >> inputWord;

        for (char& c : inputWord) {
            c = tolower(c);
        }

        if (inputWord == "exit") {
            break;
        }

        if (isWordCorrect(inputWord)) {
            cout << "The word '" << inputWord << "' is spelled correctly!\n";
        } else {
            int distance = 0;
            string suggestion = getClosestWord(inputWord, distance);
            
            cout << "Oops! '" << inputWord << "' is not in the dictionary.\n";
            cout << "Did you mean: '" << suggestion << "'?\n";
            cout << "Explanation: '" << suggestion << "' was chosen because it has an edit distance of " << distance << " from your input.\n";
        }
    }

    return 0;
}
