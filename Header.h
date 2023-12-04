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
		//cout << name << endl;

		textures[n].loadFromFile(name);
	}

	return textures;
}