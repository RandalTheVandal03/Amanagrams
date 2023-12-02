#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
using namespace std;


struct TrieNode {

    //Basic variables that can be modified at will
    char letter = ' ';
    vector<TrieNode> connectedLetters;
    bool isEnd = false;

    void insertLetter(string word, TrieNode& node) {
    
        //Checks if the letter already exists, if it does, it recursively calls this function down that letter
        bool isHere = false;
        for (int x = 0; x < node.connectedLetters.size(); x++) {
            if (node.connectedLetters.at(x).letter == word.at(0)) {
                if (word.size() == 1) {
                    //Sets preexisting letter as an ending for searching purposes
                    isEnd = true;
                    return;
                }
                return insertLetter(word.substr(1), node.connectedLetters.at(x));
                bool isHere = true;
            }

        }

        //If letter does not exist, creates a new Trie Node with that letter and recursively calls this function down that letter
        if (isHere == false) {
            TrieNode newNode;
            newNode.letter = word.at(0);

            if (word.size() > 1) {
                node.connectedLetters.push_back(newNode);
            }
            if (word.size() == 1) {
                //Sets the newly created letter as an ending for searching purposes
                newNode.isEnd = true;
                node.connectedLetters.push_back(newNode);
                return;
            }
            return insertLetter(word.substr(1), node.connectedLetters.at(node.connectedLetters.size() - 1));
        }
    }

    bool search(string word, TrieNode& node) {

        //Similar to the Insert function but simpler
        for (int x = 0; x < node.connectedLetters.size(); x++) {
            //Goes down the node's connected letters to see if the desired letter exists
            if (node.connectedLetters.at(x).letter == word.at(0)) {
                //Recursively calls this function if desired letter exists, then checks if the letter is a final letter when checking the final letter of the word (See Insert for More)
                if (word.size() == 1) {
                    if (node.connectedLetters.at(x).isEnd == false) {
                        return false;
                    }
                    return true;
                }
                return search(word.substr(1), node.connectedLetters.at(x));
            }
        }

        return false;

    }
};

vector<vector<string>> permutations(vector<string> letters) {
    //Modifiable Variables
    int size = 6;
    int permNum = 6;
    int index = 0;

    //Initializes the list with the base letters
    vector<vector<string>> permList;
    permList.push_back(letters);


    for (int x = 1; x < permNum; x++) {
        vector<string> temp;
        //Goes through every letter given to the user and adds it to each of the previous size's permutation
        for (int j = 0; j < letters.size(); j++) {
            for (int y = 0; y < permList.at(index).size(); y++) {
                temp.push_back(permList.at(index).at(y) + letters.at(j));
            }
        }

        //increases the index and pushes the smaller list into the larger one
        index++;
        permList.push_back(temp);
    }

    return permList;

}

vector<vector<string>> getPermutations() {
    
    //Random Seed
    srand(time(NULL));

    vector<string> vowels;
    vector<string> consonants;
    set<string> available;

    //Establishes the entire alphabet, if there's a simpler solution, suggest
    vowels.push_back("a");
    vowels.push_back("e");
    vowels.push_back("i");
    vowels.push_back("o");
    vowels.push_back("u");
    consonants.push_back("b");
    consonants.push_back("c");
    consonants.push_back("d");
    consonants.push_back("f");
    consonants.push_back("g");
    consonants.push_back("h");
    consonants.push_back("i");
    consonants.push_back("j");
    consonants.push_back("k");
    consonants.push_back("l");
    consonants.push_back("m");
    consonants.push_back("n");
    consonants.push_back("p");
    consonants.push_back("q");
    consonants.push_back("r");
    consonants.push_back("s");
    consonants.push_back("t");
    consonants.push_back("v");
    consonants.push_back("w");
    consonants.push_back("x");
    consonants.push_back("y");
    consonants.push_back("z");


    //Gets either 2 or 3 vowels and fills the remainder with consonants
    int vowelCounter = rand() % 2 + 2;
    int consonantCounter = 6 - vowelCounter;

    for (int x = 0; x < vowelCounter; x++) {
        int vowelIndex = rand() % vowels.size();
        if (available.find(vowels.at(vowelIndex)) != available.end()) {
            x--;
            continue;
        }
        available.emplace(vowels.at(vowelIndex));
    }

    for (int y = 0; y < consonantCounter; y++) {
        int consonantIndex = rand() % consonants.size();
        if (available.find(consonants.at(consonantIndex)) != available.end()) {
            y--;
            continue;
        }
        available.emplace(consonants.at(consonantIndex));
    }


    vector<string> letters;
    vector<vector<string>> orientations;

    //Makes a set with unique letters that are given to the player
    for (auto it = available.begin(); it != available.end(); it++) {
        letters.push_back(*it);
    }

    //Makes every possible permutation with the given letters
    orientations = permutations(letters);

    return orientations;
}

int main()
{
    TrieNode root;
    ifstream dictionary;
    vector<vector<string>> orientations;

    //Opens up the dictionary for reading
    dictionary.open("enable1.txt", ios::out);

    string line;

    //Reads and inserts each word in the dictionary into the Trie
    if (dictionary.is_open()) {
        cout << "open" << endl;
        while (!dictionary.eof()) {
            getline(dictionary, line);
            root.insertLetter(line, root);
            
        }

        cout << "Done Reading" << endl;

    }

    //Gets all the permutations with the randomly generated letters
    orientations = getPermutations();

    //Prints out the Letters for debugging purposes
    cout << "Given Letters: ";
    for (int x = 0; x < orientations.at(0).size(); x++) {
        cout << orientations.at(0).at(x) << ", ";
    }
    cout << endl;


    //Checks all the legal words from the list of permutations (THIS IS FOR TRIES, A NEW VERSION OF THIS WILL BE MADE WHEN WE MAKE HASH)
    vector<vector<string>> legalWords;

    for (int x = 2; x < orientations.size(); x++) {
        vector<string> temp;
        for (int y = 0; y < orientations.at(x).size(); y++) {
            if (root.search(orientations.at(x).at(y), root)) {
                temp.push_back(orientations.at(x).at(y));
            }
        }
        legalWords.push_back(temp);
    }
    
    //Prints all the legal words for debugging purposes
    for (int x = 0; x < legalWords.size(); x++) {
        cout << "Available Words of Length " << x + 3 << ":" << endl;
        for (int y = 0; y < legalWords.at(x).size(); y++) {
            cout << legalWords.at(x).at(y) << ", ";
        }
        cout << endl;
    }
}
