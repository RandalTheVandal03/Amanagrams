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
#include "WelcomeWindow.h"
#include "Permutations.h"

using namespace std;
using namespace sf;

int main()
{
    // Creates the Trie and Hash Table Data Structure Objects
    TrieNode root;
    HashTable hash;
 
    // Creates the 2D Vectors that Stores the Letter and Possible Word Permutations
    vector<vector<string>> orientations;
    vector<vector<string>> trieLegalWords;
    vector<vector<string>> hashLegalWords;

    //Opens up the dictionary for reading
    ifstream dictionary;
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
    cout << "Start of Load" << endl;
    Permutations permutation;

    // Assigns the permutations for the Letter Options and Updates the 2D Containers Storing the Potential
    // Word Options for each Data Structure
    orientations = permutation.getPermutations();
    permutation.updateWords(root, hash, orientations, trieLegalWords, hashLegalWords);
    cout << "Done Loading Both Data Structures!" << endl;

    // Returns a Map with all Loaded Project Assets
    map<string, Texture> textures = loadtextures();

    // Creates the Welcome Window Reference
    RenderWindow welcomeWindow(VideoMode(25 * 32, 16 * 32), "Amanagrams", Style::Close);
    welcomeWindow.setMouseCursorVisible(true);

    // Loads the Font
    Font font;
    if (!font.loadFromFile("font.ttf")) {

        return -1;
    }

    // Creates the Welcome Window Object and Opens it
    WelcomeWindow mainWindow(welcomeWindow, font, textures, orientations, trieLegalWords, hashLegalWords);
    mainWindow.open();

    return 0;
}