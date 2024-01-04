#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

string word, target;
vector<string> dictionary;
bool incorrect = false;


string removeChars(string s, int pos, bool f(char c))
{
    if (pos >= s.size()) {
        return s;
    }
    string::iterator end = remove_if(s.begin() + pos, s.end(), f);  

    return s.substr(0, end - s.begin());                            
}

bool isIn(char c) { 

    return target.find(c) != string::npos; 

}


string convert(string w) {
    
    map<char, char> cmap = { {'b','1'}, {'f','1'}, {'p','1'}, {'v','1'},
                           {'c','2'}, {'g','2'}, {'j','2'}, {'k','2'}, {'q','2'}, {'s','2'}, {'x','2'}, {'z','2'},
                           {'d','3'}, {'t','3'},
                           {'l','4'},
                           {'m','5'}, {'n','5'},
                           {'r','6'} };

    string result = w;

    char firstLetter = result[0];

    target = "hw";   
    result = removeChars(result, 1, isIn);

    for (char& c : result) { 
        if (cmap.count(c)) c = cmap[c]; 
    }

    for (int i = 1; i < result.size(); i++) {
        if (result[i] == result[i - 1]) {
            result[i - 1] = '*';
        }
    }
    
    target = "*";   
    result = removeChars(result, 1, isIn);
    

    target = "aeiouy";   
    result = removeChars(result, 1, isIn);

    // Replace first letter
    result[0] = firstLetter;

    // Get correct length and return
    result += "000";
    return result.substr(0, 4);
    

}

bool compare(string r, vector<string> d) {

    bool check = true;
    string conv;

    for (int i = 0; i < d.size(); i++) {

        conv = convert(d[i]);

        if (r == conv) {
            cout << "    " << d[i] << endl;
            check = false;
        }
    }
    
    return check;
}

int main() {

	cin >> word;

	while (word != "*") {

		dictionary.push_back(word);
		cin >> word;

	}

	cin >> word;
	string result;

	while (word != "*") {

        cout << word << ":\n";
		result = convert(word);
        
        if (compare(result, dictionary) == true) {
            cout << "    No match found!" << endl;
        }

        incorrect = false;

        cin >> word;

        if (word != "*") {
            cout << endl;
        }

	}
}