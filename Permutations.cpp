#include "Permutations.h"

// Function that Returns a 2D Vector of Calculated Permutations
vector<vector<string>> Permutations::permutations(vector<string> letters) {
    // Modifiable Variables
    int size = 6;
    int permNum = 6;
    int index = 0;

    // Initializes the list with the base letters
    vector<vector<string>> permList;
    permList.push_back(letters);


    for (int x = 1; x < permNum; x++) {
        vector<string> temp;

        // Goes through every letter given to the user and adds it to each of the previous size's permutation
        for (int j = 0; j < letters.size(); j++) {
            for (int y = 0; y < permList.at(index).size(); y++) {
                temp.push_back(permList.at(index).at(y) + letters.at(j));
            }
        }

        // Increases the index and pushes the smaller list into the larger one
        index++;
        permList.push_back(temp);
    }

    return permList;

}

vector<vector<string>> Permutations::getPermutations() {

    // Random Seed
    srand(time(NULL));

    vector<string> vowels;
    vector<string> consonants;
    set<string> available;

    // Establishes the entire alphabet
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

// Function Updates the Data Structures with the Word Options Based on the Letter Options
void Permutations::updateWords(TrieNode& root, HashTable& hash, vector<vector<string>>& desiredOrientations,
    vector<vector<string>>& desiredTrie, vector<vector<string>>& desiredHash) {

    // Passes the 2D Vectors of the Word Options for Each Data Structure by Reference to Modify them
    for (int x = 2; x < desiredOrientations.size(); x++) {
        vector<string> temp;
        for (int y = 0; y < desiredOrientations.at(x).size(); y++) {
            if (root.search(desiredOrientations.at(x).at(y), root)) {
                temp.push_back(desiredOrientations.at(x).at(y));
            }
        }
        desiredTrie.push_back(temp);
    }

    for (int x = 2; x < desiredOrientations.size(); x++) {
        vector<string> temp;
        for (int y = 0; y < desiredOrientations.at(x).size(); y++) {
            if (hash.search(desiredOrientations.at(x).at(y))) {
                temp.push_back(desiredOrientations.at(x).at(y));
            }
        }
        desiredHash.push_back(temp);
    }
}