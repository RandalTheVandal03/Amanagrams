#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Header.h"

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
    title.setCharacterSize(25);
    title.setFillColor(Color::Magenta);
    title.setStyle(Text::Bold | Text::Underlined);
    Rect<float> tbounds = title.getLocalBounds();
    title.setOrigin(tbounds.width / 2.0f, tbounds.height / 2.0f);
    title.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 215);

    Text words;
    words.setFont(font);
    words.setString("Click the goat (Aman) for rules:");
    words.setCharacterSize(20);
    words.setFillColor(Color::Magenta);
    words.setStyle(Text::Bold | Text::Italic);
    Rect<float> wbounds = words.getLocalBounds();
    words.setOrigin(wbounds.width / 2.0f, wbounds.height / 2.0f);
    words.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 175);

    Sprite amanny;
    amanny.setTexture(textures["aman"]);
    Rect<float> abounds = amanny.getLocalBounds();
    Vector2f dimensions = Vector2f(0.70f, 0.70f);
    amanny.setScale(dimensions);
    amanny.setOrigin(abounds.width / 2.0f, abounds.height / 2.0f);
    amanny.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) - 40);

    Text diffwords;
    diffwords.setFont(font);
    diffwords.setString("Click Difficulty Below to Start Game");
    diffwords.setCharacterSize(20);
    diffwords.setFillColor(Color::Red);
    diffwords.setStyle(Text::Bold);
    Rect<float> dbounds = diffwords.getLocalBounds();
    diffwords.setOrigin(dbounds.width / 2.0f, dbounds.height / 2.0f);
    diffwords.setPosition((welcomeWindow.getSize().x / 2.0f), (welcomeWindow.getSize().y / 2.0f) + 130);

  



    while (welcomeWindow.isOpen())
    {
        sf::Event event;
        while (welcomeWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {

                welcomeWindow.close();

                sf::RenderWindow gameWindow(sf::VideoMode(25 * 32, 16 * 32), "Amanagrams Gameplay", sf::Style::Close);

                Text gameTitle;
                gameTitle.setFont(font);
                gameTitle.setString("AMANagrams");
                gameTitle.setCharacterSize(25);
                gameTitle.setFillColor(Color::Black);
                gameTitle.setStyle(Text::Bold | Text::Underlined);
                Rect<float> gameTitleBounds = gameTitle.getLocalBounds();
                gameTitle.setOrigin(gameTitleBounds.width / 2.0f, gameTitleBounds.height / 2.0f);
                gameTitle.setPosition((gameWindow.getSize().x / 2.0f), (gameWindow.getSize().y));

                while (gameWindow.isOpen()) {

                    Event gameEvent;

                    while (gameWindow.pollEvent(gameEvent)) {

                        if (gameEvent.type == Event::Closed) {

                            gameWindow.close();
                        }

                    }

                    gameWindow.clear(Color::White);
                    gameWindow.draw(gameTitle);
                    gameWindow.display();

                }
            }
        }

        welcomeWindow.clear(sf::Color::Blue);
        welcomeWindow.draw(title);
        welcomeWindow.draw(words);
        welcomeWindow.draw(amanny);
        welcomeWindow.draw(diffwords);
        welcomeWindow.display();
    }

    return 0;
}