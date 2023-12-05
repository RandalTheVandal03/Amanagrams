#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TrieNode.h"
#include "HashTable.h"

using namespace sf;
using namespace std;

class WelcomeWindow {

private:

	RenderWindow* welcomeWindow;
	Font font;
	map<string, Texture> textures;
	vector<vector<string>> orientations;
	vector<vector<string>> trieLegalWords;
	vector<vector<string>> hashLegalWords;

public:
	WelcomeWindow(RenderWindow& desiredWindow, Font desiredFont, map<string, Texture>& desiredTextures,
		vector<vector<string>>& desiredOrientations, vector<vector<string>>& desiredTrie, vector<vector<string>>& desiredHash);
	void open();
	void showRules(bool& rules_r_open, Font font);

};