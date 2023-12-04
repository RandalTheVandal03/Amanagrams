#include "GameWindow.h"
#include "Timer.h"

GameWindow::GameWindow(RenderWindow& desiredWindow, Font desiredFont, map<string, Texture> desiredTextures,
    vector<vector<string>> desiredOrientations, vector<vector<string>> desiredWords, int time) {

    gameWindow = &desiredWindow;
    font = desiredFont;
    textures = desiredTextures;
    orientations = desiredOrientations;
    legalWords = desiredWords;
    counterTime = time;

}

void GameWindow::open() {

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
    LetterSprite1.setPosition(((gameWindow->getSize().x / 2.0f) - 325), (gameWindow->getSize().y / 2.0f) + 100);

    Rect<float> s1g = LetterSprite1.getGlobalBounds();
    Sprite LetterSprite2;
    LetterSprite2.setTexture(textures[f.substr(1, 1)]);
    LetterSprite2.setScale(.15f, .15f);
    LetterSprite2.setPosition(((gameWindow->getSize().x / 2.0f) - 202 - 15), (gameWindow->getSize().y / 2.0f) + 100);

    Rect<float> s2g = LetterSprite2.getGlobalBounds();
    Sprite LetterSprite3;
    LetterSprite3.setTexture(textures[f.substr(2, 1)]);
    LetterSprite3.setScale(.15f, .15f);
    LetterSprite3.setPosition(((gameWindow->getSize().x / 2.0f) - 94 - 15), (gameWindow->getSize().y / 2.0f) + 100);

    Rect<float> s3g = LetterSprite3.getGlobalBounds();
    Sprite LetterSprite4;
    LetterSprite4.setTexture(textures[f.substr(3, 1)]);
    LetterSprite4.setScale(.15f, .15f);
    LetterSprite4.setPosition(((gameWindow->getSize().x / 2.0f) + 14 - 15), (gameWindow->getSize().y / 2.0f) + 100);

    Rect<float> s4g = LetterSprite4.getGlobalBounds();
    Sprite LetterSprite5;
    LetterSprite5.setTexture(textures[f.substr(4, 1)]);
    LetterSprite5.setScale(.15f, .15f);
    LetterSprite5.setPosition(((gameWindow->getSize().x / 2.0f) + 122 - 15), (gameWindow->getSize().y / 2.0f) + 100);

    Rect<float> s5g = LetterSprite5.getGlobalBounds();
    Sprite LetterSprite6;
    LetterSprite6.setTexture(textures[f.substr(5, 1)]);
    LetterSprite6.setScale(.15f, .15f);
    LetterSprite6.setPosition(((gameWindow->getSize().x / 2.0f) + 230 - 15), (gameWindow->getSize().y / 2.0f) + 100);

    Rect<float> s6g = LetterSprite6.getGlobalBounds();


    Timer* timer = new Timer(((gameWindow->getSize().x / 2.0f) + 330), 30, counterTime);

    string input = "";
    Text currentWord;

    RectangleShape wordBox;
    wordBox.setPosition((gameWindow->getSize().x / 2.0f - 150), (gameWindow->getSize().y / 2.0f - 105));
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
    createdWords.setPosition((gameWindow->getSize().x / 2.0f), (gameWindow->getSize().y / 2.0f - 125));

    Text currScore;
    currScore.setFont(font);
    currScore.setCharacterSize(20);
    currScore.setFillColor(Color::Yellow);
    currScore.setStyle(Text::Bold);

    vector<string> userWords;

    while (gameWindow->isOpen()) {

        Event gameEvent;

        while (gameWindow->pollEvent(gameEvent)) {

            if (gameEvent.type == Event::Closed) {

                gameWindow->close();
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

                            total_score += (input.size() - 2) * 400;

                            userWords.push_back(input);
                            input = "";

                        }

                    }

                }

                if (gameEvent.type == Event::MouseButtonPressed) {
                    switch (gameEvent.mouseButton.button) {
                    case Mouse::Left: {
                        Vector2i pos = Mouse::getPosition(*gameWindow);
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
                currScore.setOrigin(
                    currsBounds.width / 2.0f, currsBounds.height / 2.0f);
                currScore.setPosition((gameWindow->getSize().x / 2.0f), (gameWindow->getSize().y / 2.0f - 35));

            }
            else {



            }

        }

        FloatRect inputBounds = currentWord.getLocalBounds();
        currentWord.setString(input + "|");
        currentWord.setStyle(Text::Bold);
        currentWord.setCharacterSize(30);
        currentWord.setFillColor(Color(76, 187, 23));
        currentWord.setFont(font);
        currentWord.setOrigin((inputBounds.left + inputBounds.width / 2.0f), (inputBounds.top + inputBounds.height / 2.0f));
        currentWord.setPosition((gameWindow->getSize().x / 2.0f), (gameWindow->getSize().y / 2.0f - 85));

        timer->updateTimer();

        gameWindow->clear(Color(35, 43, 43));
        gameWindow->draw(gameTitle);
        gameWindow->draw(LetterSprite1);
        gameWindow->draw(LetterSprite2);
        gameWindow->draw(LetterSprite3);
        gameWindow->draw(LetterSprite4);
        gameWindow->draw(LetterSprite5);
        gameWindow->draw(LetterSprite6);
        gameWindow->draw(timer->firstDigitSprite);
        gameWindow->draw(timer->secondDigitSprite);
        gameWindow->draw(wordBox);
        gameWindow->draw(currentWord);
        gameWindow->draw(createdWords);
        gameWindow->draw(currScore);
        gameWindow->display();
    }

}