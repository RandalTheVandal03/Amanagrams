#include <SFML/Graphics.hpp>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include "HashTable.h"
#include "TrieNode.h"
#include "Header.h"
#include "Timer.h"
#include "GameWindow.h"
#include "WelcomeWindow.h"

using namespace std;
using namespace sf;


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

    //Change this to test each Data Structure
    bool isTrie = false;

    TrieNode root;
    HashTable hash;
    ifstream dictionary;
    vector<vector<string>> orientations;

    //Opens up the dictionary for reading
    dictionary.open("enable1.txt", ios::out);

    string line;

    //Reads and inserts each word in the dictionary into the Trie
    if (dictionary.is_open()) {
        cout << "Open..." << endl;
        while (!dictionary.eof()) {
            getline(dictionary, line);
            root.insertLetter(line, root);
            hash.insert(line);

        }

        cout << "Done Reading..." << endl;

    }

    //Gets all the permutations with the randomly generated letters
    orientations = getPermutations();
    vector<vector<string>> trieLegalWords;
    vector<vector<string>> hashLegalWords;

    cout << "Start of Load" << endl;
    //Checks all the legal words from the list of permutations (THIS IS FOR TRIES, A NEW VERSION OF THIS WILL BE MADE WHEN WE MAKE HASH)
    for (int x = 2; x < orientations.size(); x++) {
        vector<string> temp;
        for (int y = 0; y < orientations.at(x).size(); y++) {
            if (root.search(orientations.at(x).at(y), root)) {
                temp.push_back(orientations.at(x).at(y));
            }
        }
        trieLegalWords.push_back(temp);
    }

    for (int x = 2; x < orientations.size(); x++) {
        vector<string> temp;
        for (int y = 0; y < orientations.at(x).size(); y++) {
            if (hash.search(orientations.at(x).at(y))) {
                temp.push_back(orientations.at(x).at(y));
            }
        }
        hashLegalWords.push_back(temp);
    }

    cout << "Done Loading Both Data Structures!" << endl;

    map<string, Texture> textures = loadtextures();

    sf::RenderWindow welcomeWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams", sf::Style::Close);
    welcomeWindow.setMouseCursorVisible(true);

    Font font;
    if (!font.loadFromFile("font.ttf")) {

        return -1;
    }

    WelcomeWindow mainWindow(welcomeWindow, font, textures, orientations, trieLegalWords, hashLegalWords);
    mainWindow.open();

    return 0;
}