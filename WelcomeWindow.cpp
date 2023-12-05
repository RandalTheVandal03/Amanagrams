#include "WelcomeWindow.h"
#include "GameWindow.h"

WelcomeWindow::WelcomeWindow(RenderWindow& desiredWindow, Font desiredFont, map<string, Texture> desiredTextures,
    vector<vector<string>> desiredOrientations, vector<vector<string>> desiredTrie, vector<vector<string>> desiredHash) {

	welcomeWindow = &desiredWindow;
	font = desiredFont;
	textures = desiredTextures;
    orientations = desiredOrientations;
    trieLegalWords = desiredTrie;
    hashLegalWords = desiredHash;

}


void WelcomeWindow::open() {

    Text title;
    title.setFont(font);
    title.setString("AMANagrams");
    title.setCharacterSize(33);
    title.setFillColor(Color(255, 95, 21));
    title.setStyle(Text::Bold | Text::Underlined);
    Rect<float> tbounds = title.getLocalBounds();
    title.setOrigin(tbounds.width / 2.0f, tbounds.height / 2.0f);
    title.setPosition((
        welcomeWindow->getSize().x / 2.0f), (welcomeWindow->getSize().y / 2.0f) - 225);

    Text words;
    words.setFont(font);
    words.setString("Click the goat (Aman) for rules:");
    words.setCharacterSize(20);
    words.setFillColor(Color(31, 81, 255));
    words.setStyle(Text::Bold | Text::Italic);
    Rect<float> wbounds = words.getLocalBounds();
    words.setOrigin(wbounds.width / 2.0f, wbounds.height / 2.0f);
    words.setPosition((
        welcomeWindow->getSize().x / 2.0f), (welcomeWindow->getSize().y / 2.0f) - 170);

    Sprite amanny;
    amanny.setTexture(textures["aman"]);
    Rect<float> abounds = amanny.getLocalBounds();
    Vector2f dimensions = Vector2f(0.69f, 0.69f);
    amanny.setScale(dimensions);
    amanny.setOrigin(abounds.width / 2.0f, abounds.height / 2.0f);
    amanny.setPosition((
        welcomeWindow->getSize().x / 2.0f), (welcomeWindow->getSize().y / 2.0f) - 30);

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
        welcomeWindow->getSize().x / 2.0f), (welcomeWindow->getSize().y / 2.0f) + 140);

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
        welcomeWindow->getSize().x / 2.0f), (welcomeWindow->getSize().y / 2.0f) + 230);


    Text medtext;
    medtext.setFont(font);
    medtext.setString("MEDIUM");
    medtext.setCharacterSize(35);
    medtext.setFillColor(Color::Yellow);
    medtext.setStyle(Text::Bold);
    Rect<float> mbounds = medtext.getLocalBounds();
    medtext.setOrigin(mbounds.width / 2.0f, mbounds.height / 2.0f);
    medtext.setPosition((
        welcomeWindow->getSize().x / 2.0f), (welcomeWindow->getSize().y / 2.0f) + 180);

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
        medglobal.left - 75.0f), (welcomeWindow->getSize().y / 2.0f) + 180);

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
        medglobal.left + medglobal.width + 75.0f), (welcomeWindow->getSize().y / 2.0f) + 180);

    Rect<float> hardglobal = hardtext.getGlobalBounds();
    bool rules_shown = false;
    int total_score = 0;

    while (welcomeWindow->isOpen()) {
        sf::Event event;
        while (welcomeWindow->pollEvent(
            event)) {

            if (event.type == sf::Event::Closed) {
                welcomeWindow->close();
            }

            if (event.type == Event::MouseButtonPressed && !rules_shown) {
                switch (event.mouseButton.button) {
                    case Mouse::Left: {
                        Vector2i pos = Mouse::getPosition(*welcomeWindow);
                        if ((pos.x >= easyglobal.left) && (pos.x <= (easyglobal.left + easyglobal.width)) &&
                            (pos.y >= easyglobal.top) && (pos.y <= (easyglobal.top + easyglobal.height))) {

                            welcomeWindow->close();

                            sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                            GameWindow easyWindow(gameWindow, font, textures, orientations, trieLegalWords, trieLegalWords, hashLegalWords, 90);
                            easyWindow.open();

                        }

                        else if ((pos.x >= medglobal.left) && (pos.x <= (medglobal.left + medglobal.width)) &&
                            (pos.y >= medglobal.top) && (pos.y <= (medglobal.top + medglobal.height))) {

                            welcomeWindow->close();


                            sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                            GameWindow mediumWindow(gameWindow, font, textures, orientations, trieLegalWords, trieLegalWords, hashLegalWords, 60);
                            mediumWindow.open();
                        }
                        else if ((pos.x >= hardglobal.left) && (pos.x <= (hardglobal.left + hardglobal.width)) &&
                            (pos.y >= hardglobal.top) && (pos.y <= (hardglobal.top + hardglobal.height))) {

                            welcomeWindow->close();


                            sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                            GameWindow hardWindow(gameWindow, font, textures, orientations, trieLegalWords, trieLegalWords, hashLegalWords, 45);
                            hardWindow.open();
                        }
                        else if ((pos.x >= aman_goes_global.left) && (pos.x <= (aman_goes_global.left + aman_goes_global.width)) &&
                            (pos.y >= aman_goes_global.top) && (pos.y <= (aman_goes_global.top + aman_goes_global.height))) {
                            showRules(rules_shown, font);
                        }
                        break;
                    }
                    case Mouse::Right: {
                        Vector2i pos = Mouse::getPosition(*welcomeWindow);
                        if ((pos.x >= easyglobal.left) && (pos.x <= (easyglobal.left + easyglobal.width)) &&
                            (pos.y >= easyglobal.top) && (pos.y <= (easyglobal.top + easyglobal.height))) {

                            welcomeWindow->close();


                            sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                            GameWindow easyWindow(gameWindow, font, textures, orientations, hashLegalWords, trieLegalWords, hashLegalWords, 90);
                            easyWindow.open();

                        }
                        else if ((pos.x >= medglobal.left) && (pos.x <= (medglobal.left + medglobal.width)) &&
                            (pos.y >= medglobal.top) && (pos.y <= (medglobal.top + medglobal.height))) {

                            welcomeWindow->close();

                            sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                            GameWindow mediumWindow(gameWindow, font, textures, orientations, hashLegalWords, trieLegalWords, hashLegalWords, 60);
                            mediumWindow.open();
                        }
                        else if ((pos.x >= hardglobal.left) && (pos.x <= (hardglobal.left + hardglobal.width)) &&
                            (pos.y >= hardglobal.top) && (pos.y <= (hardglobal.top + hardglobal.height))) {

                            welcomeWindow->close();

                            sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                            GameWindow hardWindow(gameWindow, font, textures, orientations, hashLegalWords, trieLegalWords, hashLegalWords, 45);
                            hardWindow.open();

                        }
                        break;
                    }
                }
            }
        }

        welcomeWindow->clear(sf::Color(35, 43, 43));
        welcomeWindow->draw(title);
        welcomeWindow->draw(words);
        welcomeWindow->draw(amanny);
        welcomeWindow->draw(diffwords);
        welcomeWindow->draw(medtext);
        welcomeWindow->draw(hardtext);
        welcomeWindow->draw(easytext);
        welcomeWindow->draw(optiontext);
        welcomeWindow->display();
    }

}

void WelcomeWindow::showRules(bool& rules_r_open, Font font) {
    RenderWindow ruleswindow(VideoMode((25 * 20), (16 * 20) + 50), "How to Play", Style::Close);
    ruleswindow.setMouseCursorVisible(true);

    Text title;
    title.setFont(font);
    title.setString("HOW TO PLAY");
    title.setCharacterSize(20);
    title.setFillColor(Color(128, 0, 32));
    title.setStyle(Text::Bold | Text::Underlined);
    Rect<float> tbounds = title.getLocalBounds();
    title.setOrigin(tbounds.width / 2.0f, tbounds.height / 2.0f);
    title.setPosition((ruleswindow.getSize().x / 2.0f), ((ruleswindow.getSize().y / 2.0f) - 150));
    Text info;
    info.setFont(font);

    string infotxt = 
        "1.  Use the letters given to create\n"
        "\twords up to 6 characters in length.\n\n"
        "2.  You can use a letter as many times\n"
        "\tas you want.\n\n"
        "3.  You cannot repeat words.\n\n"
        "4.  Press Backspace to delete a letter.\n\n"
        "5.  Press Enter to confirm words.\n\n\n"
        "\t\t\tGood Luck!!";

    info.setCharacterSize(18);
    info.setStyle(Text::Bold);
    info.setString(infotxt);
    info.setFillColor(Color(128, 0, 32));
    Rect<float> ibounds = info.getGlobalBounds();
    info.setOrigin(ibounds.width / 2.0f, ibounds.height / 2.0f);
    info.setPosition(((ruleswindow.getSize().x) / 2.0f), (((ruleswindow.getSize().y) / 2.0f) + 15));

    while (ruleswindow.isOpen()) {

        rules_r_open = true;

        Event event;
        while (ruleswindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                ruleswindow.close();
                rules_r_open = false;
            }
        }

        ruleswindow.clear(Color(242, 210, 189));
        ruleswindow.draw(title);
        ruleswindow.draw(info);
        ruleswindow.display();
    }
}