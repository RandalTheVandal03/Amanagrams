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

    //end of danny code


    map<string, Texture> textures = loadtextures();

    sf::RenderWindow welcomeWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams", sf::Style::Close);
    welcomeWindow.
        setMouseCursorVisible(true);

    Font font;
    if (!font.loadFromFile("font.ttf"
    )) {

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

                        vector<vector<string>> legalWords;

                        if (isTrie) {
                            //Checks all the legal words from the list of permutations (THIS IS FOR TRIES, A NEW VERSION OF THIS WILL BE MADE WHEN WE MAKE HASH)
                            for (int x = 2; x < orientations.size(); x++) {
                                vector<string> temp;
                                for (int y = 0; y < orientations.at(x).size(); y++) {
                                    if (root.search(orientations.at(x).at(y), root)) {
                                        temp.push_back(orientations.at(x).at(y));
                                    }
                                }
                                legalWords.push_back(temp);
                            }
                        }
                        else {
                            for (int x = 2; x < orientations.size(); x++) {
                                vector<string> temp;
                                for (int y = 0; y < orientations.at(x).size(); y++) {
                                    if (hash.search(orientations.at(x).at(y))) {
                                        temp.push_back(orientations.at(x).at(y));
                                    }
                                }
                                legalWords.push_back(temp);
                            }

                        }

                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        Text gameTitle;
                        gameTitle.setFont(font);
                        gameTitle.setString("AMANagrams");
                        gameTitle.setCharacterSize(35);
                        gameTitle.setFillColor(Color(255, 95, 21));
                        gameTitle.setStyle(Text::Bold | Text::Underlined);
                        Rect<float> gameTitleBounds = gameTitle.getLocalBounds();
                        gameTitle.setOrigin(gameTitleBounds.width / 2.0f, gameTitleBounds.height / 2.0f);
                        gameTitle.setPosition((120), (30));

                        string f = "";
                        for (int i = 0; i < 6; i++) {
                            f += char(toupper(orientations.at(0).at(i)[0]));
                        }

                        Sprite LetterSprite1;
                        LetterSprite1.setTexture(textures[f.substr(0, 1)]);
                        LetterSprite1.setScale(.15f, .15f);
                        LetterSprite1.setPosition(((gameWindow.getSize().x / 2.0f) - 325), (gameWindow.getSize().y / 2.0f) + 100);

                        Rect<float> s1g = LetterSprite1.getGlobalBounds();
                        Sprite LetterSprite2;
                        LetterSprite2.setTexture(textures[f.substr(1, 1)]);
                        LetterSprite2.setScale(.15f, .15f);
                        LetterSprite2.setPosition(((gameWindow.getSize().x / 2.0f) - 202 - 15), (gameWindow.getSize().y / 2.0f) + 100);

                        Rect<float> s2g = LetterSprite2.getGlobalBounds();
                        Sprite LetterSprite3;
                        LetterSprite3.setTexture(textures[f.substr(2, 1)]);
                        LetterSprite3.setScale(.15f, .15f);
                        LetterSprite3.setPosition(((gameWindow.getSize().x / 2.0f) - 94 - 15), (gameWindow.getSize().y / 2.0f) + 100);

                        Rect<float> s3g = LetterSprite3.getGlobalBounds();
                        Sprite LetterSprite4;
                        LetterSprite4.setTexture(textures[f.substr(3, 1)]);
                        LetterSprite4.setScale(.15f, .15f);
                        LetterSprite4.setPosition(((gameWindow.getSize().x / 2.0f) + 14 - 15), (gameWindow.getSize().y / 2.0f) + 100);

                        Rect<float> s4g = LetterSprite4.getGlobalBounds();
                        Sprite LetterSprite5;
                        LetterSprite5.setTexture(textures[f.substr(4, 1)]);
                        LetterSprite5.setScale(.15f, .15f);
                        LetterSprite5.setPosition(((gameWindow.getSize().x / 2.0f) + 122 - 15), (gameWindow.getSize().y / 2.0f) + 100);

                        Rect<float> s5g = LetterSprite5.getGlobalBounds();
                        Sprite LetterSprite6;
                        LetterSprite6.setTexture(textures[f.substr(5, 1)]);
                        LetterSprite6.setScale(.15f, .15f);
                        LetterSprite6.setPosition(((gameWindow.getSize().x / 2.0f) + 230 - 15), (gameWindow.getSize().y / 2.0f) + 100);

                        Rect<float> s6g = LetterSprite6.getGlobalBounds();

                        cout << LetterSprite1.getLocalBounds().height << " " << LetterSprite1.getLocalBounds().width << endl;
                        cout << LetterSprite2.getLocalBounds().height << " " << LetterSprite2.getLocalBounds().width << endl;


                        Timer* timer = new Timer(((gameWindow.getSize().x / 2.0f) + 330), 30);

                        string input = "";
                        Text currentWord;

                        RectangleShape wordBox;
                        wordBox.setPosition((gameWindow.getSize().x / 2.0f - 150), (gameWindow.getSize().y / 2.0f - 105));
                        wordBox.setSize(Vector2f(300, 50));
                        wordBox.setFillColor(Color(35, 43, 43));

                        Text createdWords;
                        createdWords.setFont(font);
                        createdWords.setString("Enter Words:");
                        createdWords.setCharacterSize(25);
                        createdWords.setFillColor(Color(4, 155, 242));
                        createdWords.setStyle(Text::Bold);
                        Rect<float> createdwBounds = createdWords.getLocalBounds();
                        createdWords.setOrigin(createdwBounds.width / 2.0f, createdwBounds.height / 2.0f);
                        createdWords.setPosition((gameWindow.getSize().x / 2.0f), (gameWindow.getSize().y / 2.0f - 125));

                        Text currScore;
                        currScore.setFont(font);
                        currScore.setCharacterSize(20);
                        currScore.setFillColor(Color::Yellow);
                        currScore.setStyle(Text::Bold);

                        vector<string> userWords;

                        while (gameWindow.isOpen()) {

                            Event gameEvent;

                            while (gameWindow.pollEvent(gameEvent)) {

                                if (gameEvent.type == Event::Closed) {

                                    gameWindow.close();
                                }

                                if (timer->getTimerPausedState() == false) {

                                    if (gameEvent.type == Event::TextEntered) {
                                        if (input.length() < 6) {

                                            if (((gameEvent.text.unicode <= 90) && (gameEvent.text.unicode >= 65)) ||
                                                ((gameEvent.text.unicode <= 122) && (gameEvent.text.unicode >= 97))) {

                                                char letter = gameEvent.text.unicode;

                                                for (int i = 0; i < 6; i++) {

                                                    char givenChar = char((orientations.at(0).at(i)[0]));

                                                    if (tolower(letter) == givenChar) {

                                                        input += tolower(letter);


                                                    }
                                                }
                                            }
                                        }

                                    }

                                    if ((gameEvent.type == Event::KeyPressed) && (gameEvent.key.code == Keyboard::BackSpace)) {

                                        if (input.length() > 0) {

                                            input.pop_back();

                                        }
                                    }

                                    if ((gameEvent.type == sf::Event::KeyPressed) && (gameEvent.key.code == sf::Keyboard::Enter)) {

                                        bool validWord = false;

                                        if (input.length() > 2) {

                                            for (int x = 0; x < legalWords.at(input.length() - 3).size(); x++) {

                                                if (input == legalWords.at(input.length() - 3).at(x)) {

                                                    validWord = true;

                                                    for (int y = 0; y < userWords.size(); y++) {

                                                        if (input == userWords.at(y)) {

                                                            validWord = false;
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    
                                                }

                                            }

                                            if (validWord) {

                                                userWords.push_back(input);
                                                input = "";

                                            }

                                        }

                                    }

                                    if (gameEvent.type == Event::MouseButtonPressed) {
                                        switch (gameEvent.mouseButton.button) {
                                        case Mouse::Left: {
                                            pos = Mouse::getPosition(gameWindow);
                                            if ((pos.x >= s1g.left) && (pos.x <= (s1g.left + s1g.width)) && (pos.y >= s1g.top) && (pos.y <= (s1g.top + s1g.height))) {
                                                if (input.length() < 6) {
                                                    input += orientations.at(0).at(0)[0];
                                                }
                                            }
                                            else if ((pos.x >= s2g.left) && (pos.x <= (s2g.left + s2g.width)) && (pos.y >= s2g.top) && (pos.y <= (s2g.top + s2g.height))) {
                                                if (input.length() < 6) {
                                                    input += orientations.at(0).at(1)[0];
                                                }
                                            }
                                            else if ((pos.x >= s3g.left) && (pos.x <= (s3g.left + s3g.width)) && (pos.y >= s3g.top) && (pos.y <= (s3g.top + s3g.height))) {
                                                if (input.length() < 6) {
                                                    input += orientations.at(0).at(2)[0];
                                                }
                                            }
                                            else if ((pos.x >= s4g.left) && (pos.x <= (s4g.left + s4g.width)) && (pos.y >= s4g.top) && (pos.y <= (s4g.top + s4g.height))) {
                                                if (input.length() < 6) {
                                                    input += orientations.at(0).at(3)[0];
                                                }
                                            }
                                            else if ((pos.x >= s5g.left) && (pos.x <= (s5g.left + s5g.width)) && (pos.y >= s5g.top) && (pos.y <= (s5g.top + s5g.height))) {
                                                if (input.length() < 6) {
                                                    input += orientations.at(0).at(4)[0];
                                                }
                                            }
                                            else if ((pos.x >= s6g.left) && (pos.x <= (s6g.left + s6g.width)) && (pos.y >= s6g.top) && (pos.y <= (s6g.top + s6g.height))) {
                                                if (input.length() < 6) {
                                                    input += orientations.at(0).at(5)[0];
                                                }
                                            }

                                        }
                                    }
                                }
                                

                                currScore.setString("Current Score: " + to_string(total_score));
                                Rect<float> currsBounds = currScore.getLocalBounds();
                                currScore.setOrigin(currsBounds.width / 2.0f, currsBounds.height / 2.0f);
                                currScore.setPosition((gameWindow.getSize().x / 2.0f), (gameWindow.getSize().y / 2.0f - 35));

                            } else {



                            }

                        }

                            FloatRect inputBounds = currentWord.getLocalBounds();
                            currentWord.setString(input + "|");
                            currentWord.setStyle(Text::Bold);
                            currentWord.setCharacterSize(30);
                            currentWord.setFillColor(Color(76, 187, 23));
                            currentWord.setFont(font);
                            currentWord.setOrigin((inputBounds.left + inputBounds.width / 2.0f), (inputBounds.top + inputBounds.height / 2.0f));
                            currentWord.setPosition((gameWindow.getSize().x / 2.0f), (gameWindow.getSize().y / 2.0f - 85));

                            timer->updateTimer();

                            gameWindow.clear(Color(35, 43, 43));
                            gameWindow.draw(gameTitle);
                            gameWindow.draw(LetterSprite1);
                            gameWindow.draw(LetterSprite2);
                            gameWindow.draw(LetterSprite3);
                            gameWindow.draw(LetterSprite4);
                            gameWindow.draw(LetterSprite5);
                            gameWindow.draw(LetterSprite6);
                            gameWindow.draw(timer->firstDigitSprite);
                            gameWindow.draw(timer->secondDigitSprite);
                            gameWindow.draw(wordBox);
                            gameWindow.draw(currentWord);
                            gameWindow.draw(createdWords);
                            gameWindow.draw(currScore);
                            gameWindow.display();

                        }
                    }

                    else if ((pos.x >= medglobal.left) && (pos.x <= (medglobal.left + medglobal.width)) &&
                        (pos.y >= medglobal.top) && (pos.y <= (medglobal.top + medglobal.height))) {
                        cout << "medium trie" << endl;
                    }
                    else if ((pos.x >= hardglobal.left) && (pos.x <= (hardglobal.left + hardglobal.width)) &&
                        (pos.y >= hardglobal.top) && (pos.y <= (hardglobal.top + hardglobal.height))) {
                        cout << "hard trie" << endl;
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
                        cout << "easy hash" << endl;
                    }
                    else if ((pos.x >= medglobal.left) && (pos.x <= (medglobal.left + medglobal.width)) &&
                        (pos.y >= medglobal.top) && (pos.y <= (medglobal.top + medglobal.height))) {
                        cout << "medium hash" << endl;
                    }
                    else if ((pos.x >= hardglobal.left) && (pos.x <= (hardglobal.left + hardglobal.width)) &&
                        (pos.y >= hardglobal.top) && (pos.y <= (hardglobal.top + hardglobal.height))) {
                        cout << "hard hash" << endl;
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