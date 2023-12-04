#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace sf;

map<string, Texture> loadtextures() {
    map<string, Texture> textures;

    textures["aman"].loadFromFile("PNGs/aman.png");
    for (int i = 65; i <= 90; i++) {
        string n = "";
        n.append(1, char(i));
        string name = "PNGs/" + n + ".png";

        textures[n].loadFromFile(name);
    }

    return textures;
}

void showRules(bool& rules_r_open, Font font) {
    RenderWindow ruleswindow(VideoMode((25 * 16), (16 * 16) + 50), "How to Play", Style::Close);
    ruleswindow.setMouseCursorVisible(true);

    Text title;
    title.setFont(font);
    title.setString("HOW TO PLAY");
    title.setCharacterSize(20);
    title.setFillColor(Color(128, 0, 32));
    title.setStyle(Text::Bold | Text::Underlined);
    Rect<float> tbounds = title.getLocalBounds();
    title.setOrigin(tbounds.width / 2.0f, tbounds.height / 2.0f);
    title.setPosition((ruleswindow.getSize().x / 2.0f), ((ruleswindow.getSize().y / 2.0f) - 120));
    Text info;
    info.setFont(font);

    string infotxt = "1.  Use the letters given\n"
        "\tto create words up to\n"
        "\t6 characters in length\n\n"
        "3.  You can use a letter as\n"
        "\tmany times as you want\n\n"
        "4.  Do not repeat words\n\n\n"
        "\t\tGood Luck!!";

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