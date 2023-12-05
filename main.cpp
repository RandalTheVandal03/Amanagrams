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
    TrieNode root;
    HashTable hash;
    ifstream dictionary;
    vector<vector<string>> orientations;
    vector<vector<string>> trieLegalWords;
    vector<vector<string>> hashLegalWords;

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
    cout << "Start of Load" << endl;
    Permutations permutation;
    orientations = permutation.getPermutations();
    permutation.updateWords(root, hash, orientations, trieLegalWords, hashLegalWords);
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