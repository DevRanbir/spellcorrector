#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

int calculateEditDistance(string s1, string s2);

const vector<string>& getDictionary() {
    static vector<string> dict;
    if (dict.empty()) {
        ifstream file("words.csv");
        string line;
        while (getline(file, line)) {
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            if (line.length() >= 2 && line.front() == '"' && line.back() == '"') {
                line = line.substr(1, line.length() - 2);
            }
            if (!line.empty()) {
                for (char& c : line) {
                    c = tolower(c);
                }
                dict.push_back(line);
            }
        }
    }
    return dict;
}

bool isWordCorrect(string word) {
    const vector<string>& dict = getDictionary();
    for (const string& w : dict) {
        if (w == word) return true;
    }
    return false;
}

string getClosestWord(string word, int& bestDistance) {
    const vector<string>& dict = getDictionary();
    string bestWord = dict[0];
    bestDistance = calculateEditDistance(word, bestWord);

    for (const string& w : dict) {
        int dist = calculateEditDistance(word, w);
        if (dist < bestDistance) {
            bestDistance = dist;
            bestWord = w;
        }
    }
    return bestWord;
}
