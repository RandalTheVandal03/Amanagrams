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

// Declares loadtextures() function with map<string, Texture> return Type
map<string, Texture> loadtextures() {

    // Creates empty Textures map
    map<string, Texture> textures;

    // Loads the Aman and Trophy Assets
    textures["aman"].loadFromFile("PNGs/aman.png");
    textures["trophy"].loadFromFile("PNGs/trophy.png");

    // Loads each Alphabetical Letter Asset based on ASCII value
    for (int i = 65; i <= 90; i++) {
        string n = "";
        n.append(1, char(i));
        string name = "PNGs/" + n + ".png";

        textures[n].loadFromFile(name);
    }

    // Returns the Textures Map
    return textures;
}