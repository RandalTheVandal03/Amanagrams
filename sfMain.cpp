#include <SFML/Graphics.hpp>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include "Header.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include "HashTable.h"
#include "TrieNode.h"
#include "GameWindow.h"


using namespace std;
using namespace sf;



//Start of danny code

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
//^^^^ danny code


int main()
{
    //Start of danny code

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

        cout << "Done Loading All" << endl;

    //end of danny code


    map<string, Texture> textures = loadtextures();

    sf::RenderWindow welcomeWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams", sf::Style::Close);
    welcomeWindow.
        setMouseCursorVisible(true);

    Font font;
    if (!font.loadFromFile("font.ttf")) {

        return -1;
    }

    Text title;
    title.setFont(font);
    title.setString("AMANagrams");
    title.setCharacterSize(33);
    title.setFillColor(Color(255, 95, 21));
    title.setStyle(Text::Bold | Text::Underlined);
    Rect<float> tbounds = title.getLocalBounds();
    title.setOrigin(tbounds.width / 2.0f, tbounds.height / 2.0f);
    title.setPosition((
        welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 225);

    Text words;
    words.setFont(font);
    words.setString("Click the goat (Aman) for rules:");
    words.setCharacterSize(20);
    words.setFillColor(Color(31, 81, 255));
    words.setStyle(Text::Bold | Text::Italic);
    Rect<float> wbounds = words.getLocalBounds();
    words.setOrigin(wbounds.width / 2.0f, wbounds.height / 2.0f);
    words.setPosition((
        welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 170);

    Sprite amanny;
    amanny.setTexture(textures["aman"]);
    Rect<float> abounds = amanny.getLocalBounds();
    Vector2f dimensions = Vector2f(0.69f, 0.69f);
    amanny.setScale(dimensions);
    amanny.setOrigin(abounds.width / 2.0f, abounds.height / 2.0f);
    amanny.setPosition((
        welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 30);

    Rect<float> aman_goes_global = amanny.getGlobalBounds();


    Text diffwords;
    diffwords.setFont(font);
    diffwords.setString("Click Difficulty Below to Start Game!!!");
    diffwords.setCharacterSize(22);
    diffwords.setFillColor(Color(76, 187, 23));
    diffwords.setStyle(Text::Bold);
    Rect<float> dbounds = diffwords.getLocalBounds();
    diffwords.setOrigin(dbounds.width / 2.0f, dbounds.height / 2.0f);
    diffwords.setPosition((
        welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) + 140);

    Text optiontext;
    optiontext.setFont(font);
    optiontext.setString("***Data Structure: Left-click for Trie & Right-click for HashTable***");
    optiontext.setCharacterSize(15
    );
    optiontext.setFillColor(Color(31, 81, 255));
    optiontext.setStyle(Text::Bold
    );
    Rect<float> obounds = optiontext.getLocalBounds();
    optiontext.setOrigin(obounds.width / 2.0f, obounds.height / 2.0f);
    optiontext.setPosition((
        welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) + 230);


    Text medtext;
    medtext.setFont(font);
    medtext.setString("MEDIUM");
    medtext.setCharacterSize(35);
    medtext.setFillColor(Color::Yellow);
    medtext.setStyle(Text::Bold);
    Rect<float> mbounds = medtext.getLocalBounds();
    medtext.setOrigin(mbounds.width / 2.0f, mbounds.height / 2.0f);
    medtext.setPosition((
        welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) + 180);

    Rect<float> medglobal = medtext.getGlobalBounds();

    Text easytext;
    easytext.setFont(font);
    easytext.setString("EASY");
    easytext.setCharacterSize(35);
    easytext.setFillColor(Color::Green);
    easytext.setStyle(Text::Bold);
    Rect<float> ebounds = easytext.getLocalBounds();
    easytext.setOrigin(ebounds.width, ebounds.height / 2.0f);
    easytext.setPosition((
        medglobal.left - 75.0f), (welcomeWindow.getSize().y / 2.0f) + 180);

    Rect<float> easyglobal = easytext.getGlobalBounds();

    Text hardtext;
    hardtext.setFont(font);
    hardtext.setString("HARD");
    hardtext.setCharacterSize(35);
    hardtext.setFillColor(Color::Red);
    hardtext.setStyle(Text::Bold);
    Rect<float> hbounds = hardtext.getLocalBounds();
    hardtext.setOrigin(0, hbounds.height / 2.0f);
    hardtext.setPosition((
        medglobal.left + medglobal.width + 75.0f), (welcomeWindow.getSize().y / 2.0f) + 180);

    Rect<float> hardglobal = hardtext.getGlobalBounds();
    bool rules_shown = false;
    int total_score = 0;

    while (welcomeWindow.isOpen()) {
        sf::Event event;
        while (welcomeWindow.pollEvent(
            event)) {

            if (event.type == sf::Event::Closed) {
                welcomeWindow.close();
            }

            if (event.type == Event::MouseButtonPressed && !rules_shown) {
                switch (event.mouseButton.button) {
                case Mouse::Left: {
                    Vector2i pos = Mouse::getPosition(
                        welcomeWindow);
                    if ((pos.x >= easyglobal.left) && (pos.x <= (easyglobal.left + easyglobal.width)) &&
                        (pos.y >= easyglobal.top) && (pos.y <= (easyglobal.top + easyglobal.height))) {

                        welcomeWindow.close();

                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        GameWindow easyWindow(gameWindow, font, textures, orientations, trieLegalWords, 90);
                        easyWindow.open();

                    }

                    else if ((pos.x >= medglobal.left) && (pos.x <= (medglobal.left + medglobal.width)) &&
                        (pos.y >= medglobal.top) && (pos.y <= (medglobal.top + medglobal.height))) {

                        welcomeWindow.close();


                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        GameWindow mediumWindow(gameWindow, font, textures, orientations, trieLegalWords, 60);
                        mediumWindow.open();
                    }
                    else if ((pos.x >= hardglobal.left) && (pos.x <= (hardglobal.left + hardglobal.width)) &&
                        (pos.y >= hardglobal.top) && (pos.y <= (hardglobal.top + hardglobal.height))) {

                        welcomeWindow.close();


                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        GameWindow hardWindow(gameWindow, font, textures, orientations, trieLegalWords, 45);
                        hardWindow.open();
                    }
                    else if ((pos.x >= aman_goes_global.left) && (pos.x <= (aman_goes_global.left + aman_goes_global.width)) &&
                        (pos.y >= aman_goes_global.top) && (pos.y <= (aman_goes_global.top + aman_goes_global.height))) {
                        showRules(rules_shown, font);
                    }
                    break;
                }
                case Mouse::Right: {
                    Vector2i pos = Mouse::getPosition(welcomeWindow);
                    if ((pos.x >= easyglobal.left) && (pos.x <= (easyglobal.left + easyglobal.width)) &&
                        (pos.y >= easyglobal.top) && (pos.y <= (easyglobal.top + easyglobal.height))) {

                        welcomeWindow.close();


                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        GameWindow easyWindow(gameWindow, font, textures, orientations, hashLegalWords, 90);
                        easyWindow.open();

                    }
                    else if ((pos.x >= medglobal.left) && (pos.x <= (medglobal.left + medglobal.width)) &&
                        (pos.y >= medglobal.top) && (pos.y <= (medglobal.top + medglobal.height))) {

                        welcomeWindow.close();

                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        GameWindow mediumWindow(gameWindow, font, textures, orientations, hashLegalWords, 60);
                        mediumWindow.open();
                    }
                    else if ((pos.x >= hardglobal.left) && (pos.x <= (hardglobal.left + hardglobal.width)) &&
                        (pos.y >= hardglobal.top) && (pos.y <= (hardglobal.top + hardglobal.height))) {

                        welcomeWindow.close();

                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        GameWindow hardWindow(gameWindow, font, textures, orientations, hashLegalWords, 45);
                        hardWindow.open();

                    }
                    break;
                    }
                }
            }

        }

        welcomeWindow.clear(sf::Color(35, 43, 43));
        welcomeWindow.draw(title);
        welcomeWindow.draw(words);
        welcomeWindow.draw(amanny);
        welcomeWindow.draw(diffwords);
        welcomeWindow.draw(medtext);
        welcomeWindow.draw(hardtext);
        welcomeWindow.draw(easytext);
        welcomeWindow.draw(optiontext);

        welcomeWindow.display();
    }

    return 0;
}