#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Header.h"
#include "Timer.h"

using namespace std;
using namespace sf;

int main()
{

    map<string, Texture> textures = loadtextures();

    sf::RenderWindow welcomeWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams", sf::Style::Close);
    welcomeWindow.setMouseCursorVisible(true);

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
    title.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 225);

    Text words;
    words.setFont(font);
    words.setString("Click the goat (Aman) for rules:");
    words.setCharacterSize(20);
    words.setFillColor(Color(31, 81, 255));
    words.setStyle(Text::Bold | Text::Italic);
    Rect<float> wbounds = words.getLocalBounds();
    words.setOrigin(wbounds.width / 2.0f, wbounds.height / 2.0f);
    words.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 170);

    Sprite amanny;
    amanny.setTexture(textures["aman"]);
    Rect<float> abounds = amanny.getLocalBounds();
    Vector2f dimensions = Vector2f(0.69f, 0.69f);
    amanny.setScale(dimensions);
    amanny.setOrigin(abounds.width / 2.0f, abounds.height / 2.0f);
    amanny.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 30);

    Rect<float> aman_goes_global = amanny.getGlobalBounds();


    Text diffwords;
    diffwords.setFont(font);
    diffwords.setString("Click Difficulty Below to Start Game!!!");
    diffwords.setCharacterSize(22);
    diffwords.setFillColor(Color(76, 187, 23));
    diffwords.setStyle(Text::Bold);
    Rect<float> dbounds = diffwords.getLocalBounds();
    diffwords.setOrigin(dbounds.width / 2.0f, dbounds.height / 2.0f);
    diffwords.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) + 140);

    Text optiontext;
    optiontext.setFont(font);
    optiontext.setString("***Data Structure: Left-click for Trie & Right-click for HashTable***");
    optiontext.setCharacterSize(15);
    optiontext.setFillColor(Color(31, 81, 255));
    optiontext.setStyle(Text::Bold);
    Rect<float> obounds = optiontext.getLocalBounds();
    optiontext.setOrigin(obounds.width / 2.0f, obounds.height / 2.0f);
    optiontext.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) + 230);


    Text medtext;
    medtext.setFont(font);
    medtext.setString("MEDIUM");
    medtext.setCharacterSize(35);
    medtext.setFillColor(Color::Yellow);
    medtext.setStyle(Text::Bold);
    Rect<float> mbounds = medtext.getLocalBounds();
    medtext.setOrigin(mbounds.width / 2.0f, mbounds.height / 2.0f);
    medtext.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) + 180);

    Rect<float> medglobal = medtext.getGlobalBounds();

    Text easytext;
    easytext.setFont(font);
    easytext.setString("EASY");
    easytext.setCharacterSize(35);
    easytext.setFillColor(Color::Green);
    easytext.setStyle(Text::Bold);
    Rect<float> ebounds = easytext.getLocalBounds();
    easytext.setOrigin(ebounds.width, ebounds.height / 2.0f);
    easytext.setPosition((medglobal.left - 75.0f), (welcomeWindow.getSize().y / 2.0f) + 180);

    Rect<float> easyglobal = easytext.getGlobalBounds();

    Text hardtext;
    hardtext.setFont(font);
    hardtext.setString("HARD");
    hardtext.setCharacterSize(35);
    hardtext.setFillColor(Color::Red);
    hardtext.setStyle(Text::Bold);
    Rect<float> hbounds = hardtext.getLocalBounds();
    hardtext.setOrigin(0, hbounds.height / 2.0f);
    hardtext.setPosition((medglobal.left + medglobal.width + 75.0f), (welcomeWindow.getSize().y / 2.0f) + 180);

    Rect<float> hardglobal = hardtext.getGlobalBounds();
    bool rules_shown = false;

    while (welcomeWindow.isOpen()) {
        sf::Event event;
        while (welcomeWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                welcomeWindow.close();
            }

            if (event.type == Event::MouseButtonPressed && !rules_shown) {
                switch (event.mouseButton.button) {
                case Mouse::Left: {
                    Vector2i pos = Mouse::getPosition(welcomeWindow);
                    if ((pos.x >= easyglobal.left) && (pos.x <= (easyglobal.left + easyglobal.width)) &&
                        (pos.y >= easyglobal.top) && (pos.y <= (easyglobal.top + easyglobal.height))) {

                        welcomeWindow.close();
                        sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                        Text gameTitle;
                        gameTitle.setFont(font);
                        gameTitle.setString("AMANagrams");
                        gameTitle.setCharacterSize(20);
                        gameTitle.setFillColor(Color::Black);
                        gameTitle.setStyle(Text::Bold | Text::Underlined);
                        Rect<float> gameTitleBounds = gameTitle.getLocalBounds();
                        gameTitle.setOrigin(gameTitleBounds.width / 2.0f, gameTitleBounds.height / 2.0f);
                        gameTitle.setPosition((80), (30));

                        Texture firstLetterBox;
                        firstLetterBox.loadFromFile("PNGs/gray_square.png");
                        Sprite firstLetterSprite;
                        firstLetterSprite.setTexture(firstLetterBox);
                        firstLetterSprite.setPosition(((gameWindow.getSize().x / 2.0f) - 310), (gameWindow.getSize().y / 2.0f) + 120);

                        Texture secondLetterBox;
                        secondLetterBox.loadFromFile("PNGs/gray_square.png");
                        Sprite secondLetterSprite;
                        secondLetterSprite.setTexture(secondLetterBox);
                        secondLetterSprite.setPosition(((gameWindow.getSize().x / 2.0f) - 202), (gameWindow.getSize().y / 2.0f) + 120);

                        Texture thirdLetterBox;
                        thirdLetterBox.loadFromFile("PNGs/gray_square.png");
                        Sprite thirdLetterSprite;
                        thirdLetterSprite.setTexture(thirdLetterBox);
                        thirdLetterSprite.setPosition(((gameWindow.getSize().x / 2.0f) - 94), (gameWindow.getSize().y / 2.0f) + 120);

                        Texture fourthLetterBox;
                        fourthLetterBox.loadFromFile("PNGs/gray_square.png");
                        Sprite fourthLetterSprite;
                        fourthLetterSprite.setTexture(fourthLetterBox);
                        fourthLetterSprite.setPosition(((gameWindow.getSize().x / 2.0f) + 14), (gameWindow.getSize().y / 2.0f) + 120);

                        Texture fifthLetterBox;
                        fifthLetterBox.loadFromFile("PNGs/gray_square.png");
                        Sprite fifthLetterSprite;
                        fifthLetterSprite.setTexture(fifthLetterBox);
                        fifthLetterSprite.setPosition(((gameWindow.getSize().x / 2.0f) + 122), (gameWindow.getSize().y / 2.0f) + 120);

                        Texture sixthLetterBox;
                        sixthLetterBox.loadFromFile("PNGs/gray_square.png");
                        Sprite sixthLetterSprite;
                        sixthLetterSprite.setTexture(sixthLetterBox);
                        sixthLetterSprite.setPosition(((gameWindow.getSize().x / 2.0f) + 230), (gameWindow.getSize().y / 2.0f) + 120);

                        Timer* timer = new Timer(((gameWindow.getSize().x / 2.0f) + 330), 30);

                        string input = "";
                        Text currentWord;

                        RectangleShape wordBox;
                        wordBox.setPosition((gameWindow.getSize().x / 2.0f - 150), (gameWindow.getSize().y / 2.0f - 90));
                        wordBox.setSize(Vector2f(300, 100));
                        wordBox.setFillColor(Color::Blue);

                        Text createdWords;
                        createdWords.setFont(font);
                        createdWords.setString("Created Words:");
                        createdWords.setCharacterSize(20);
                        createdWords.setFillColor(Color::Black);
                        createdWords.setStyle(Text::Bold);
                        Rect<float> createdwBounds = createdWords.getLocalBounds();
                        createdWords.setOrigin(createdwBounds.width / 2.0f, createdwBounds.height / 2.0f);
                        createdWords.setPosition((gameWindow.getSize().x / 2.0f), (gameWindow.getSize().y / 2.0f - 110));

                        while (gameWindow.isOpen()) {

                            Event gameEvent;

                            while (gameWindow.pollEvent(gameEvent)) {

                                if (gameEvent.type == Event::Closed) {

                                    gameWindow.close();
                                }

                                if (gameEvent.type == Event::TextEntered) {
                                    if (input.length() < 6) {

                                        if (((gameEvent.text.unicode <= 90) && (gameEvent.text.unicode >= 65)) ||
                                            ((gameEvent.text.unicode <= 122) && (gameEvent.text.unicode >= 97))) {

                                            char letter = gameEvent.text.unicode;
                                            input += letter;

                                        }
                                    }

                                }

                                if ((gameEvent.type == Event::KeyPressed) && (gameEvent.key.code == Keyboard::BackSpace)) {

                                    if (input.length() > 0) {

                                        input.pop_back();

                                    }
                                }
                            }

                            FloatRect inputBounds = currentWord.getLocalBounds();
                            currentWord.setString(input + "|");
                            currentWord.setStyle(Text::Bold);
                            currentWord.setCharacterSize(18);
                            currentWord.setFillColor(Color::Yellow);
                            currentWord.setFont(font);
                            currentWord.setOrigin((inputBounds.left + inputBounds.width / 2.0f), (inputBounds.top + inputBounds.height / 2.0f));
                            currentWord.setPosition((gameWindow.getSize().x / 2.0f), (gameWindow.getSize().y / 2.0f - 45));

                            timer->updateTimer();

                            gameWindow.clear(Color::White);
                            gameWindow.draw(gameTitle);
                            gameWindow.draw(firstLetterSprite);
                            gameWindow.draw(secondLetterSprite);
                            gameWindow.draw(thirdLetterSprite);
                            gameWindow.draw(fourthLetterSprite);
                            gameWindow.draw(fifthLetterSprite);
                            gameWindow.draw(sixthLetterSprite);
                            gameWindow.draw(timer->firstDigitSprite);
                            gameWindow.draw(timer->secondDigitSprite);
                            gameWindow.draw(wordBox);
                            gameWindow.draw(currentWord);
                            gameWindow.draw(createdWords);
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